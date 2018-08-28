#include<iostream>
#include<fstream>
#include<conio2.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

using namespace std;
void medicos();
void listaMedicos();
void cadCliente();
//void deletaMedico();
void listaCliente();
void cadConsulta();

void secretaria();
void listaSecretaria ();

//==================================================
typedef struct{
    int cod; // 0-Deletado ou Não cadastrado | 1-Cadastrado
    int senha;
    char nome[50];
    int idade;
    int cpf;
    char endereco[25];
    int telefone;
    char cargo[11];
    int crm;  // Primary key {Medico}
    int idSecrt; // Primary key {Secretária}
    double taxa; // Para Médico valor da Consulta | Para Secretária valor do salário

    char especialidade[20];
    int diaConsulta[5]={0,0,0,0,0};
    int turno;// 0 - manhâ | 1  - tarde | manhã/tarde

    int numConsultaDia[3]; // Se for 0 número de consultas manhã... | 1 - número de consultas pela tarde | 2 - número de consultas manhã e tarde
    int totConsulta; // Total de consultas atendidas pelo médico
}clinica;

typedef struct{
char nome[40]=" ";
  char cpf[12]=" ";
  char sexo[15]=" ";
  char dataNasc[15]=" ";
  char telefone[20]=" ";
  char nomePai[40]=" ";
  char nomeMae[40]=" ";
  char endRua[40]=" ";
  char endBairro[30]=" ";
  char cidade[25]=" ";
  char UF[3]=" ";
  char email[40]=" ";
  char obs[50]=" ";
  char cep[10]=" ";
}cliente;

typedef struct{
  int crm;
  char cpfCli[12];
  char data[10];
  char diaConsulta[1];
  char dataConsulta[10];
  int turno;

}consulta;

int main()
{
    textbackground(BLACK);
    textcolor(WHITE);
    clrscr();
    char op;
    setlocale(LC_ALL,"portuguese");
    do
    {
        clrscr();
        cout<<"\tManipulação de arquivos\n\n";
        cout<<"\t 1 - Medicos \n";
        cout<<"\t 2 - listar medicos \n\n";
        cout<<"\n\t 3 - Agenda consultas\n";
        cout<<"\t 4 - Cadastro Clientes\n";
        cout<<"\t 5 - Lista Clientes\n";
        cout<<"\t 7 - Cadastro Secretaria\n";
        cout<<"\t 8 - Lista Secretaria\n";
        cout<<"\t 9 - Sair \n";
        cout<<"\n\n \tInforme uma opção: ";
        op =  getchar();
        switch(op)
        {
        case '1':
            medicos();
            break;
        case '2':
            listaMedicos();
            break;
        case '3':
          cadConsulta();
        break;
        case '4':
          cadCliente();
        break;
        case '5':
          listaCliente();
        break;
        case '7':
          secretaria();
        break;
        case '8':
          listaSecretaria();
        break;
        case '9':
          exit(1);
        break;



        }
    }while(op!='6');

}


void cadConsulta(){
    cliente lerCliente;
    clinica dadoMedico;
    consulta insereConsulta;

    char cpf[12],dataConsulta[11],crm;

    int localizado=0,valida=0,turno;

    clrscr();
    fflush(stdin);

    ifstream lerArquivo,lerConsulta;
    ofstream criaConsulta;

    cout<<"\t\t Cadastro de consultas "<<endl;
    cout<<"\n\t\tInforme o CPF do paciente: ";
    cin.getline(cpf,12);
    lerArquivo.open("clientes.txt",ios::in);
      if (lerArquivo.fail()){
          cout<<"Erro na execução do programa. Falha no arquivo \"clientes.txt\" \n";
          system("pause");
          return;
      }
      lerArquivo.read((char*)(&lerCliente), sizeof(cliente));
      while(!lerArquivo.eof()){
          if(strcmp(cpf,lerCliente.cpf)==0){
            localizado=1;
            break;
          }
          lerArquivo.read((char*)(&lerCliente), sizeof(cliente));
      }

    lerArquivo.close();
      if(localizado==0){
          cout<<"\n\t\tCPF informado não foi encontrado!\n";
          system("pause");
          return;
      }
      else{
          cout<<"\n\t\tNome................: "<<lerCliente.nome;
          cout<<"\n\t\tCPF.................: "<<lerCliente.cpf;
          cout<<"\n\t\tInforme a data da consulta: ";
          cin.getline(insereConsulta.dataConsulta,11);
          cout<<"\n\t\tCRM do medico..........: ";
          cin>>crm;
          cout<<"\n\t\t\t [0] - Manhã\n";
          cout<<"\n\t\t\t [1] - Tarde\n";
          cout<<"\n\t\t\t [2] - Manhã/Tarde\n";
          fflush(stdin);
          cout<<"\n\t\tTurno..........: ";
          cin>>turno;
          //jogar numa função
          lerArquivo.open("medicos.txt",ios::in);
          lerArquivo.read((char*)(&lerCliente), sizeof(cliente));
            while(!lerArquivo.eof()){
                if(crm==dadoMedico.crm && dadoMedico.turno==turno){
                  valida=1;
                  insereConsulta.crm=dadoMedico.crm;
                  insereConsulta.turno=turno;
                  strcpy(insereConsulta.cpfCli,lerCliente.cpf);
                  break;
                }
                lerArquivo.read((char*)(&lerCliente), sizeof(cliente));
            }
            if(valida==0)
              cout<<"\n\n\t\t\tO medico não atende neste horario!!";
          lerArquivo.close();
          //===============================
          lerConsulta.open("cadConsultas.txt",ios::in);
              if (lerConsulta.fail()){
                  criaConsulta.open("cadConsultas.txt",ios::out);
                  criaConsulta.close();
              }
              else{
                 criaConsulta.open("cadConsultas.txt",ios::out|ios::app);
                    criaConsulta<<insereConsulta.crm<<";"
                      <<insereConsulta.turno<<";"
                      <<lerCliente.cpf;
                 criaConsulta.close();

              }
          lerConsulta.close();
          getch();
      }

}







//======================================================
void medicos(){
    int crm,dia,turno;
    char ans;
    clinica medico, lerMedico;
    clrscr();
    fstream arquivo;
    //verifica quantos medicos tem listados, para não poder sobrepor
    arquivo.open("medicos.txt",ios::in);
    if (arquivo.fail()){
        cout<<"Erro na execução do programa. Falha ao carregar o arquivo!!";
        system("pause");
       return;
    }
    arquivo.read((char*)(&lerMedico), sizeof(clinica));
    while(!arquivo.eof()){
        arquivo.read((char*)(&lerMedico),sizeof(clinica));
    }
    arquivo.close();
    fflush(stdin);
    //=================================================================
    cout<<"\t\t Cadastro de médicos "<<endl;
    cout<<"Nome........................: ";
    cin.getline(medico.nome,50);
    cout<<"Especialidade...............: ";
    cin.getline(medico.especialidade,20);
        cout<<"\n\t\t\t\tInforme o turno de atendimento: ";
        cout<<"\n\t\t\t [0] - Manhã";
        cout<<"\n\t\t\t [1] - Tarde";
        cout<<"\n\t\t\t [2] - Manhã/Tarde";
        cout<<"\n\t\t\t Selecione o turno: ";
      do{
        cin>>turno;
        if(turno !=0 && turno!=1 && turno!=2){
          cout<<"\n\t\t\t\tTurno digitado e inválido!!\n";
          Sleep(1000);
          cout<<"\n\t\t\t Selecione o turno: ";
        }
      }while(turno !=0 && turno!=1 && turno!=2);
      if(turno==0)
          medico.turno=0;
      else if(turno==1)
          medico.turno=1;
      else
        medico.turno=2;
    //================================================================
    cout<<"CRM.........................: ";
    cin>>medico.crm;
    cout<<"Dia de consulta.........................: ";
    cout<<"\n\t\t\t\tInforme o dia de atendimento: ";
      cout<<"\n\t\t\t [0] - segunda";
      cout<<"\n\t\t\t [1] - terça";
      cout<<"\n\t\t\t [2] - Quarta";
      cout<<"\n\t\t\t [3] - Quinta";
      cout<<"\n\t\t\t [4] - Sexta";
   do{

      cout<<"\n\t\t\t Selecione o dia: ";
      fflush(stdin);
      cin>>dia;
      for(int i=0;i<5;i++){
          if (i==dia)
            medico.diaConsulta[dia]=1;
      }
      cout<<"Deseja acrescentar mais um dia?";
      cin>>ans;
      ans=toupper(ans);
   }while(ans=='S');
    arquivo.open("medicos.txt",ios::in|ios::out|ios::app);
      arquivo.write((const char*)(&medico),sizeof(clinica));
    arquivo.close();
}
//==================================================================================
void cadCliente(){
    cliente insereCli;
    clrscr();
    fstream arquivo;
    arquivo.open("clientes.txt",ios::in);
      if (arquivo.fail()){
          cout<<"Erro na execução do programa. Falha ao carregar o arquivo!!";
         system("pause");
         return;
      }
    arquivo.close();
    arquivo.open("clientes.txt",ios::in|ios::out|ios::app);
      fflush(stdin);
      cout<<"\t\t Cadastro de Clientes "<<endl;
      cout<<"Nome........................: ";
      cin.getline(insereCli.nome,50);
      cout<<"CPF.........................: ";
      cin.getline(insereCli.cpf,12);
    arquivo.write((const char*)(&insereCli),sizeof(cliente));
    arquivo.close();
}
//======================== SECRETÁRIA ==========================
void secretaria(){
    clinica insereSecretaria;
    clrscr();
    fstream arquivo;
    arquivo.open("secretaria.txt",ios::in);
      if (arquivo.fail()){
          cout<<"Erro na execução do programa. Falha ao carregar o arquivo!!";
         system("pause");
         return;
      }
    arquivo.close();

      fflush(stdin);
      cout<<"\t\t Cadastro de Secretaria "<<endl;
      cout<<"Nome........................: ";
      cin.getline(insereSecretaria.nome,50);
      cout<<"CPF.........................: ";
      cin>>insereSecretaria.cpf;
    arquivo.open("secretaria.txt",ios::in|ios::out|ios::app);
      arquivo.write((const char*)(&insereSecretaria),sizeof(clinica));
    arquivo.close();
}
void listaSecretaria (){
  clinica listaSecretaria;
  fstream arquivo;
  clrscr();
    arquivo.open("secretaria.txt",ios::in);
      if(arquivo.fail()){
          cout<<"Falha ao carregar o arquivo!!";
          return;
      }
      arquivo.read((char *)(&listaSecretaria),sizeof(clinica));
      while(!arquivo.eof()){
        cout<<"Nome....:"<<listaSecretaria.nome<<endl;
        cout<<"CPF....:"<<listaSecretaria.cpf<<endl;
        cout<<"_____________________________________________\n\n";
        arquivo.read((char *)(&listaSecretaria),sizeof(clinica));

      }
   arquivo.close();
   cout<<endl;
   system("pause");


}
//======================================================================================================
void listaMedicos(){
    clinica lerMedico;
    clrscr();
    ifstream arquivo;
    arquivo.open("medicos.txt",ios::in);
    if (arquivo.fail()){
        cout<<"Erro na execução do programa. Falha ao carregar o arquivo!!";
        exit(1);
    }
    fflush(stdin);
    cout<<"\t\tMÉDICOS CADASTRADOS\n\n";

    arquivo.read((char*)(&lerMedico), sizeof(clinica));
    while(!arquivo.eof()){
       if (lerMedico.crm!=0){
        cout<<"\tNome........................: "<<lerMedico.nome;
        cout<<"\n\tEspecialidade...............: "<<lerMedico.especialidade;
        cout<<"\n\tCRM.........................: "<<lerMedico.crm;

        if (lerMedico.turno==0)
            cout<<"\n\tTurno......................: Manhã : 8:00 - 12:00";
        else if (lerMedico.turno==1)
            cout<<"\n\tTurno......................: Tarde : 14:00 - 17:00";
        else
            cout<<"\n\tTurno......................: Manhã e Tarde : [8:00-12:00] e [14:00 - 17:00]";


        cout<<"\n\tDia de atendimento : \n";
        for(int i=0;i<5;i++){
          if(lerMedico.diaConsulta[i]==1){
              switch(i){
                case 0:
                  cout<<"\t\tSegunda\n";
                break;
                case 1:
                  cout<<"\t\tTerça\n";
                break;
                case 2:
                  cout<<"\t\tQuarta\n";
                break;
                case 3:
                  cout<<"\t\tQuinta\n";
                break;
                case 4:
                  cout<<"\t\tSexta\n";
                break;
              }
          }

        }
        cout<<"\n\t_______________________________________________________________________________\n\n";
       }
        arquivo.read((char*)(&lerMedico), sizeof(clinica));
    }
    arquivo.close();
    system("pause");

}
//=====================================================================================================
void listaCliente(){
    cliente lerCliente;
    clrscr();
    ifstream arquivo;
    arquivo.open("clientes.txt",ios::in);
      if (arquivo.fail()){
          cout<<"Erro na execução do programa. Falha ao carregar o arquivo!!";
          exit(1);
      }
      fflush(stdin);
      cout<<"\t\tCLIENTES CADASTRADOS\n\n";
      arquivo.read((char*)(&lerCliente), sizeof(cliente));
      while(!arquivo.eof()){
          cout<<"\tNome................: "<<lerCliente.nome;
          cout<<"\n\tCPF.................: "<<lerCliente.cpf;
          cout<<"\n\t_______________________________________________________________________________\n\n";
          arquivo.read((char*)(&lerCliente), sizeof(cliente));
      }
    arquivo.close();
    system("pause");

}


//============================================================================
/*
void deletaMedico(){
    clinica lerMed;
    int crm,posicao=0;

    clrscr();
    fstream arquivo;
    arquivo.open("medicos.txt",ios::in|ios::out);
      if (arquivo.fail()){
          cout<<"Erro na execução do programa. Falha ao carregar o arquivo!!";
          return;
      }
      fflush(stdin);
      cout<<"\t\tCLIENTES CADASTRADOS\n\n";
      cout<<"Informe o crm do medico: ";
      cin>>crm;
      getch();
      arquivo.read((char*)(&lerMed), sizeof(clinica));
      while(!arquivo.eof()){
          if(crm==lerMed.crm){
            break;
          }
        posicao++;
        arquivo.read((char*)(&lerMed), sizeof(clinica));
      }
    arquivo.close();

    arquivo.open("medicos.txt",ios::out|ios::in);
      arquivo.seekp((posicao)*sizeof(clinica));
      lerMed.crm=-1;
      arquivo.write((const char*)(&lerMed),sizeof(clinica));
    arquivo.close();
    system("pause");

}
*/
