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
//==================================================


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
    int cod; // 0-Deletado ou Não cadastrado | 1-Cadastrado
    int senha;
    char nome[50];
    int idade;
    int cpf;
    char endereco[25];
    double telefone;
    char cargo[11];
    int crm;  // Primary key {Medico}
    int idSecrt; // Primary key {Secretária}
    double taxa; // Para Médico valor da Consulta | Para Secretária valor do salário
    char especialidade[20];
    //int diaConsulta[5]={0,0,0,0,0};
    int turno;// 0 - manhâ | 1  - tarde | manhã/tarde
    //int numConsultaDia[3]; // Se for 0 número de consultas manhã... | 1 - número de consultas pela tarde | 2 - número de consultas manhã e tarde
    int totConsulta; // Total de consultas atendidas pelo médico
}clinica;
typedef struct{
  int crm;
  char cpfCli[12];
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
    do{
        clrscr();
        cout<<"\tManipulação de arquivos\n\n";
        cout<<"\t 1 - Medicos \n";
        cout<<"\t 2 - listar medicos \n";
        cout<<"\t 3 - Agenda consultas--meu grupo!\n";
        cout<<"\t 4 - Cadastro Clientes\n";
        cout<<"\t 5 - Lista Clientes\n";
        cout<<"\t 6 - Sair \n";
        cout<<"\n\n \tInforme uma opção: ";
        op =  getchar();
        switch(op){
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

      }
    }while(op!='6');

}


void cadConsulta(){
    cliente lerCliente;
    clinica dadoMedico;
    consulta insereConsulta, readConsulta;

    char cpf[12],dataConsulta[11];
    int crm;

    int localizado=0,valida=0,turno,validaTurno=-1,numConsulta=0;
    clrscr();
    fflush(stdin);

    ifstream lerArquivo,lerConsulta;
    ofstream criaArquivo;
    fstream criaConsulta;


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
          cin.getline(dataConsulta,11);
          cout<<"\n\t\tCRM do medico..........: ";
          cin>>crm;
//============================================================
          lerArquivo.open("consultas.txt", ios::in);
          if (criaConsulta.fail()){
              criaArquivo.open("consultas.txt",ios::out);
              criaArquivo.close();
          }
            lerArquivo.read((char*)(&readConsulta),sizeof(consulta));
            while(lerArquivo&&!lerArquivo.eof())
                if((crm == readConsulta.crm)&&(strcmp(dataConsulta,readConsulta.dataConsulta)==0)&&(turno == readConsulta.turno)){
                  numConsulta++;
                lerArquivo.read((char*)(&readConsulta),sizeof(consulta));
            }

          lerArquivo.close();
//=============================================================
        if(numConsulta>=2){
            cout<<"\n\t\t\t\tHorário e dia indisponivel!\n";
            Sleep(2000);
            cadConsulta();
        }
        else{
              lerArquivo.open("medicos.txt",ios::in);
                lerArquivo.read((char*)(&dadoMedico), sizeof(clinica));
                if (lerArquivo.fail())
                    exit(1);
                while(lerArquivo && !lerArquivo.eof()){
                    if( crm== dadoMedico.crm){
                      validaTurno = dadoMedico.turno;
                    }
                    lerArquivo.read((char*)(&dadoMedico), sizeof(clinica));
                }
              lerArquivo.close();

                if (validaTurno==0){
                    cout<<"\n\t\t\t Consulta marcada pela manhã\n";
                }
                else if(validaTurno==1)
                 cout<<"\n\t\t\t Consulta marcada pela tarde\n";
                else{
                  do{
                    fflush(stdin);
                    cout<<"\n\t\t\t [0] - Manhã\n";
                    cout<<"\n\t\t\t [1] - Tarde\n";
                    cout<<"\t\t\t\t Digite o turno : ";
                    cin>>validaTurno;
                    if (validaTurno!=0 && validaTurno!=1){
                      cout<<"\n\n\t\tTurno inválido!";
                      Sleep(1000);
                      cout<<"\n\n\n";
                    }

                  }while(validaTurno!=0 && validaTurno!=1);
                  if (validaTurno==0)
                    cout<<"\n\t\t\t Consulta marcada pela manhã\n";
                  else
                    cout<<"\n\t\t\t Consulta marcada pela tarde\n";
                }
                system("pause");
                insereConsulta.crm=crm;
                strcpy(insereConsulta.cpfCli,cpf);
                strcpy(insereConsulta.dataConsulta,dataConsulta);
                insereConsulta.turno=validaTurno;

                criaConsulta.open("consultas.txt",ios::in|ios::out|ios::app);
                    if (criaConsulta.fail()){
                        criaArquivo.open("consultas.txt",ios::out);
                        criaArquivo.close();
                    }
                    criaConsulta.write((const char*)(&insereConsulta),sizeof(consulta));
                criaConsulta.close();
            }
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
  /*
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
   */
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


        /*cout<<"\n\tDia de atendimento : \n";
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

        }*/
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


