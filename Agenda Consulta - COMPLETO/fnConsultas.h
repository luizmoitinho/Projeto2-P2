void dados(int *cpf);
void cadConsulta(char cpfCli[],int *cpfSec);
void cadastraClientes(char cpfCli[]);
void agendaConsulta(char cpfCli[],int *cpfSec);
int mostraConsulta(int *cpfSec,char cpfCli[],int cont1);
void mostraInfCliente(const char cpf[]);
void dataConsulta(int *crm,char cpfCli[],int *cpfSec,int cont,int *opc);
void tratamentoData(int &diaU, int &mesU, int &anoU,int cont);
void dma(int &diaU, int &mesU, int &anoU, int cont, int p);
void conclui(int *crm,int cont);
typedef int *Point;
namespace data {
int converterParaInt(string str);
  void dateSystem(int &diaC, int &mesC, int &anoC){
      char dataAtual[9];
      _strdate(dataAtual);
      string diaS, mesS, anoS;
      for(int i=0; i<9; i++)
      {
          if (dataAtual[i]!='/')
          {
              if(i<2)
                  mesS+=dataAtual[i];
              else if(i<5)
                  diaS+=dataAtual[i];
              else
                  anoS+=dataAtual[i];
          }
      }
      diaC=converterParaInt(diaS);
      mesC=converterParaInt(mesS);
      anoC=converterParaInt(anoS);
  }

  int converterParaInt(string str){
    std::istringstream iss(str);
    int retorno;
    iss >> retorno;
    return retorno;
}

}
using namespace data;




void consultas(int *cpfSec){

  setlocale(LC_ALL,"portuguese");
  textbackground(COR_FUNDO);
  clrscr();
  textcolor(BLACK);
  char cpfCli[12]=" ";
  logo();
  barraNotificacao();
  dados(cpfSec);
  fflush(stdin);

  criaMenu(3,80,10,16,COR_LOGO,COR_LETRA2);
  gotoxy(47,17);
  cout<<"CONSULTAS";
  criaMenu(7,80,10,19,COR_LETRA2,BLACK);
  criaMenu(3,5,44,21,COR_LOGO,COR_LETRA2);
  gotoxy(45,22);
  cout<<"CPF ";
  criaMenu(3,13,50,21,DARKGRAY,COR_LETRA2);
  gotoxy(51,22);
  cin.getline(cpfCli,12);
  cadConsulta(cpfCli,cpfSec);

  getch();
}

void dados(int *cpfSec){

  clinica lerSecretaria;
  fstream arquivo;
    arquivo.open("secretaria.txt",ios::in);

      arquivo.read((char *)(&lerSecretaria),sizeof(clinica));
      while(!arquivo.eof()){
        if(*cpfSec == lerSecretaria.cpf){
          break;
        }
        arquivo.read((char *)(&lerSecretaria),sizeof(clinica));

    }
  arquivo.close();

  criaMenu(3,30,5,7,COR_LOGO,COR_LETRA2);
  gotoxy(17,8);
  cout<<"Dados";
  criaMenu(5,30,5,10,COR_LETRA2,COR_LETRA1);
  gotoxy(7,11);
  cout<<"Nome  : "<<lerSecretaria.nome;
  gotoxy(7,12);
  cout<<"CPF   : "<<lerSecretaria.cpf;

}


void cadConsulta(char cpfCli[],int *cpfSec){
    system("cls");
    setlocale(LC_ALL,"portuguese");
    system("cls");
    setlocale(LC_ALL,"portuguese");
    textbackground(COR_FUNDO);
    clrscr();
    textcolor(BLACK);
    logo();
    barraNotificacao();
    dados(cpfSec);

    cliente lerClientes;

    int localizado = 0;
    char opc;
    //opc = new char;

    fstream verificaCadastro;
    verificaCadastro.open("clientes.txt", ios::in);

    if(verificaCadastro.fail())
        cout<<"\n\nfalha ao carregar arquivo";

        verificaCadastro.read((char*)(&lerClientes), sizeof(cliente));
          while(verificaCadastro && !verificaCadastro.eof()){
              if(strcmp(cpfCli,lerClientes.cpf) == 0){
                  localizado = 1;
                  break;
              }
              verificaCadastro.read((char*)(&lerClientes), sizeof(cliente));
          }
        verificaCadastro.close();

          if (localizado == 1){
              agendaConsulta(cpfCli,cpfSec);
          }
          else{

                criaMenu(3,80,10,16,COR_LOGO,COR_LETRA2);
                gotoxy(47,17);
                cout<<"CONSULTAS";
                criaMenu(10,80,10,19,COR_LETRA2,BLACK);

                gotoxy(40,20);
                textcolor(RED);
                cout << "CPF não encontrado!";
                textcolor(BLACK);
                gotoxy(40,21);
                cout << "[1] Cadastrar novo cliente";
                gotoxy(40,22);
                cout << "[2] Voltar ao menu";


            do{
                criaMenu(3,24,39,24,COR_LOGO,COR_LETRA2);
                gotoxy(40,25);
                cout << "Selecione uma opção: ";
                cin >> opc;

                switch(opc)
                    {
                    case '1':
                        cadastraClientes(cpfCli);
                        consultas(cpfSec);
                      break;
                    case '2':
                        fflush(stdin);
                        consultas(cpfSec);
                        break;
                    default:
                        criaMenu(3,8,62,24,COR_LOGO,COR_LETRA2);
                        gotoxy(60,25);
                        textcolor(RED);
                        cout << "INVÁLIDO";
                        Sleep(1000);
                        textcolor(WHITE);
                        criaMenu(3,8,62,24,COR_LOGO,COR_LETRA2);
                        break;
                    }

                } while(opc != '1' && opc != '2');
            }
}

void cadastraClientes(char cpfCli[]){
  cliente cadCliente;
  fstream preencheArquivo;

    fflush(stdin);
        //CRIA CAIXA ATRÁS
        criaMenu(20,93,5,16,COR_LETRA2,COR_LETRA1);

        criaMenu(3,93,5,16,COR_LOGO,COR_LETRA2);
        gotoxy(38,17);
        cout<<"CADASTRAR CLIENTES";

        criaMenu(1,15,6,20,COR_LOGO,COR_LETRA2);
        gotoxy(7,20);
        cout << "NOME COMPLETO ";

        criaMenu(1,6,6,22,COR_LOGO,COR_LETRA2);
        gotoxy(7,22);
        cout << "SEXO ";

        criaMenu(1,6,6,24,COR_LOGO,COR_LETRA2);
        gotoxy(7,24);
        cout << "CPF ";

        criaMenu(1,12,6,26,COR_LOGO,COR_LETRA2);
        gotoxy(7,26);
        cout << "NASCIMENTO ";

        criaMenu(1,9,6,28,COR_LOGO,COR_LETRA2);
        gotoxy(7,28);
        cout << "NOME PAI ";

        criaMenu(1,9,50,20,COR_LOGO,COR_LETRA2);
        gotoxy(51,20);
        cout << "NOME MÃE ";

        criaMenu(1,9,50,22,COR_LOGO,COR_LETRA2);
        gotoxy(51,22);
        cout << "ENDEREÇO ";

        criaMenu(1,8,50,26,COR_LOGO,COR_LETRA2);
        gotoxy(51,26);
        cout << "BAIRRO ";

        criaMenu(1,2,90,20,COR_LOGO,COR_LETRA2);
        gotoxy(91,20);
        cout << "UF ";

        criaMenu(1,8,50,24,COR_LOGO,COR_LETRA2);
        gotoxy(51,24);
        cout << "CIDADE";

        criaMenu(1,5,83,24,COR_LOGO,COR_LETRA2);
        gotoxy(84,24);
        cout << "CEP ";



      //entrada de dados
        criaMenu(1,20,22,20,COR_FUNDO,COR_LETRA1);
        criaMenu(1,15,22,22,COR_FUNDO,COR_LETRA1);
        criaMenu(1,11,22,24,COR_FUNDO,COR_LETRA1);
        criaMenu(1,10,22,26,COR_FUNDO,COR_LETRA1);
        criaMenu(1,20,62,26,COR_FUNDO,COR_LETRA1);
        criaMenu(1,20,22,28,COR_FUNDO,COR_LETRA1);
        criaMenu(1,26,62,20,COR_FUNDO,COR_LETRA1);
        criaMenu(1,30,62,22,COR_FUNDO,COR_LETRA1);
        criaMenu(1,2,95,20,COR_FUNDO,COR_LETRA1);
        criaMenu(1,15,62,24,COR_FUNDO,COR_LETRA1);
        criaMenu(1,8,89,24,COR_FUNDO,COR_LETRA1);


        gotoxy(22,20);
        cin.getline(cadCliente.nome,40);

        gotoxy(22,22);
        cin.getline(cadCliente.sexo,15);

        int tamanho, verifica = 0;
        tamanho = strlen(cadCliente.cpf);

        do{
        gotoxy(22,24);
        cin.getline(cadCliente.cpf,12);

        tamanho = strlen(cadCliente.cpf);

        if (tamanho == 11)
        {
            verifica = 1;
            break;
        }else{
            criaMenu(1,11,22,24,COR_FUNDO,COR_LETRA1);
            gotoxy(22,24);
            textcolor(RED);
            cout << "INVÁLIDO";
            Sleep(1000);
            textcolor(BLACK);
            criaMenu(1,11,22,24, COR_FUNDO, COR_LETRA1);
        }
        } while(verifica == 0);

        gotoxy(22,26);
        cin.getline(cadCliente.dataNasc,12);

        gotoxy(22,28);
        cin.getline(cadCliente.nomePai,40);

        gotoxy(62,20);
        cin.getline(cadCliente.nomeMae,40);

        gotoxy(95,20);
        cin.getline(cadCliente.UF,3);

        gotoxy(62,22);
        cin.getline(cadCliente.endRua,40);

        gotoxy(62,24);
        cin.getline(cadCliente.cidade,25);

        gotoxy(89,24);
        cin.getline(cadCliente.cep,10);

        gotoxy(62,26);
        cin.getline(cadCliente.endBairro,30);

        //strcpy(cadCliente.cpf,cpfCli);

        preencheArquivo.open("clientes.txt", ios::out|ios::app);
        preencheArquivo.write((const char*)(&cadCliente), sizeof(cliente));
        preencheArquivo.close();

        criaMenu(2,20,64,33,COR_LETRA2,GREEN);
        gotoxy(35,33);
        cout<<"CADASTRO FINALIZADO COM SUCESSO!";
        Sleep(2000);
}



void agendaConsulta(char cpfCli[],int *cpfSec){
    Point crm,opc;
    int cont;
    opc = new int;
    crm = new int;

    criaMenu(4,93,5,16,COR_LOGO,COR_LETRA2);
    gotoxy(50 - (6/2), 17);
    cout << "OPÇÕES";
    mostraInfCliente(cpfCli);
    criaMenu(10,93,5,19,COR_LETRA2,COR_LETRA1);
    gotoxy(50 - (19/2),20);
    cout<<"[1] Nova consulta";
    gotoxy(50 - (19/2),21);
    cout<<"[2] Agendar retorno";
    fflush(stdin);
    gotoxy(40,24);
    criaMenu(3,24,39,24,COR_LOGO,COR_LETRA2);

    do{
        gotoxy(40,25);
        cout<<"Selecione uma opcao: ";
        cin >> *opc;

        switch(*opc){
            case 1:
                *crm = mostraConsulta(cpfSec,cpfCli,cont);
                *opc =1;
                dataConsulta(crm,cpfCli,cpfSec,cont,opc);
            break;
            case 2: // Retorno
                *opc =2;
                *crm = mostraConsulta(cpfSec,cpfCli,cont);
                dataConsulta(crm,cpfCli,cpfSec,cont,opc);
            break;

            default:
                criaMenu(3,8,61,24,COR_LOGO,COR_LETRA2);
                gotoxy(61,25);
                textcolor(RED);
                cout << "INVÁLIDO";
                Sleep(1000);
                textcolor(WHITE);
                criaMenu(3,8,61,24,COR_LOGO,COR_LETRA2);
                break;
        }
    }while(*opc != 1 && *opc != 2 );
}



void mostraInfCliente(const char cpfCli[]){
    ifstream lerCliente;
    lerCliente.open("clientes.txt", ios::in);
    cliente testeclientes;

    //MOSTRAR INFORMAÇÃO DO CLIENTE
    while( lerCliente && !lerCliente.eof()){
        if(strcmp(testeclientes.cpf, cpfCli) == 0){
        criaMenu(3,30,44,7,COR_LOGO,COR_LETRA2);
        gotoxy(53,8);
        cout<<"Dados Cliente";
        criaMenu(5, 30, 44, 10, COR_LETRA2, COR_LETRA1);
        gotoxy(46,11);
        cout << "NOME : " << testeclientes.nome << endl;
        gotoxy(46,12);
        cout << "CPF  : " << testeclientes.cpf << endl;
        }
        lerCliente.read((char *) (&testeclientes), sizeof(cliente));
    }
    lerCliente.close();
}



typedef char *charVet;
int mostraConsulta(int *crm, char cpfCli[],int cont1){
    char espec[20];
    char aux[20] = " ";// lembrar de deixar aux, espec e armazena como vetores dinâmicos
    int i = 0,tot=0;
    int x = 7, y = 20;
    int soma = 10,secCRM,cont=0,leng=0;
    clinica medico;
    ifstream lerConsultas;
    charVet * armazena;
    lerConsultas.open("medicos.txt", ios::in);
    lerConsultas.read((char *) (&medico), sizeof(clinica));
        while( lerConsultas && !lerConsultas.eof()){
              if(medico.cod!=0)
                tot++;
              lerConsultas.read((char *) (&medico), sizeof(clinica));
          }
    lerConsultas.close();

    armazena = new charVet[tot];
    lerConsultas.open("medicos.txt", ios::in);
    lerConsultas.read((char *) (&medico), sizeof(clinica));
        while( lerConsultas && !lerConsultas.eof()){
              if(medico.cod!=0){
                armazena[i]= new char[20];
                strcpy(armazena[i],medico.especialidade);
                i++;
              }
            lerConsultas.read((char *) (&medico), sizeof(clinica));
        }
    lerConsultas.close();
    criaMenu(14,93,5,16,COR_LETRA2,COR_LETRA1);
      textcolor(BLACK);
      int tam,c=20;
    //===========================================================
      for(int j=0; j<i ;j++){
          for(int k=0; k<i; k++){
            if(strcmp(armazena[j],armazena[k])<0){
              strcpy(aux,armazena[j]);
              strcpy(armazena[j],armazena[k]);
              strcpy(armazena[k],aux);
            }
         }
      }

    for(int j=0; j<tot;j++){
            leng = strlen(armazena[j]);
            if((x + strlen(armazena[j])) < 96){
                criaMenu(3, leng + 2, x, y -1, COR_LOGO, COR_LETRA2);
                gotoxy(x + 1, y);
                cout <<armazena[j];
                x = x + strlen(armazena[j]) + 4;
            }else{
                    y = y + 4;
                    x = 7;
                    criaMenu(3, leng + 2, x, y -1, COR_LOGO, COR_LETRA2);
                    gotoxy(x + 1, y);
                    cout << armazena[j];
                    x = x + strlen(armazena[j]) + 4;
            }
      }
//==================================================================================

    int localizar = 0;
    fflush(stdin);
    do{
        criaMenu(1,25,34,17, COR_FUNDO,COR_LETRA1);
        gotoxy(35,17);
        cout << "Informe a especialidade: ";
        fflush(stdin);
        criaMenu(1,1,61,17, COR_FUNDO,COR_LETRA1);
        gotoxy(61,17);
        cin.getline(espec,20);
        char aux[20];
        strcpy(aux,espec);
        for (int i=0;i<strlen(espec);i++){
            espec[i] = toupper(aux[i]);
        }
      for(int j=0;j<tot;j++){
            if(strcmp(armazena[j],espec) == 0){
                gotoxy(61, 17);
                textcolor(GREEN);
                cout << "Profissão Válida!";
                Sleep(1000);
                textcolor(WHITE);
                localizar = 1;
                break;
        }

    }

            if (localizar == 0)
                {
                    gotoxy(60, 17);
                    textcolor(RED);
                    cout << "Profissão Inválida!";
                    Sleep(1000);
                    textcolor(WHITE);
                    criaMenu(1,19,60,17, COR_LETRA2,COR_LETRA2);
                }

    }while(localizar == 0);
//=====================================================================================
//  Conta o tamanho da tela de fundo.
    for(int j;j<tot;j++){
        if( strcmp(armazena[j], espec) == 0){
            cont1 += 6;
        }
    }
//=====================================================================================

    criaMenu(cont1 + 5,93,5,19,COR_LETRA2,COR_LETRA1);
    criaMenu(3,93,5,16,COR_LOGO,COR_LETRA2);
    gotoxy(50-(13/2), 17);
    cout << "ESPECIALISTAS";
    cont1 = 0;
    char turno[12];
    lerConsultas.open("medicos.txt", ios::in);

    for(int j=0;j<tot;j++){
        lerConsultas.read((char*) (&medico), sizeof(clinica));
        while(lerConsultas && !lerConsultas.eof())
        {
            if(strcmp(medico.especialidade,espec) == 0){
                criaMenu(5, 87, 8, 20 + cont1, COR_LOGO, COR_LETRA2);
                int cmp = 0;
                cmp = strlen(medico.nome);
                gotoxy(50 - (cmp/2),21 + cont1);
                cout <<"NOME...: " << medico.nome;
                gotoxy(50 - (cmp/2),22 + cont1);
                cout <<"CRM....: " << medico.crm;
                switch(medico.turno)
                {
                case 0:
                    strcpy(turno, "Manhã");
                    break;
                case 1:
                    strcpy(turno, "Tarde");
                    break;
                case 2:
                    strcpy(turno, "Manhã/Tarde");
                    break;
                }

                gotoxy(50 - (cmp/2),23 + cont1);
                cout <<"HORARIO: " << turno;
                cont1 += 6;
              break;
            }
           lerConsultas.read((char*) (&medico), sizeof(clinica));
      }
    }
      lerConsultas.close();


//=====================================================================================

    int localizado = 0;

    do{
        criaMenu(1, 21,40, 18 + cont1 + 2,COR_LOGO,COR_LETRA2);
        gotoxy(40, 18 + cont1 + 2);
        cout << "INFORME CRM DESEJADO:";
        fflush(stdin);
        criaMenu(1,4,62,18 + cont1 + 2,COR_FUNDO,COR_LETRA1);
        gotoxy(62, 18 + cont1 + 2);
        cin >> secCRM;

        lerConsultas.open("medicos.txt", ios::in);
        lerConsultas.read((char *) (&medico), sizeof(clinica));
        while(lerConsultas && !lerConsultas.eof())
        {
            if(medico.crm == secCRM)
                {
                    localizado = 1;
                    return secCRM;
                }
                lerConsultas.read((char *) (&medico), sizeof(clinica));
        }
        lerConsultas.close();
            if(localizado == 0 )
            {
                gotoxy(62, 18 + cont1 + 2);
                textcolor(RED);
                cout << "CRM Inválido!";
                Sleep(1000);
                criaMenu(1,13,62,18 + cont1 + 2, COR_LETRA2,COR_LETRA2);
            }

    }while(localizado == 0);

}


void dataConsulta(int *crm, char cpfCli[],int *cpfSec, int cont, int *opc)
{
    cliente lerCliente;
    clinica dadoMedico;
    consulta insereConsulta, readConsulta;
    char cpf[12],consultaData[11];
    int turno,validaTurno,numConsulta=0,formPag;
    int dia,mes,ano;


    char diaChar[2],mesChar[2],anoChar[2];
    fflush(stdin);
    ifstream lerArquivo;
    fstream criaArquivo;
    fstream criaConsulta;
    cont+=20;
    criaMenu(10,93,5,cont,COR_LETRA2,COR_LETRA1);
    cont++;

    tratamentoData(dia,mes,ano,cont);
    cout<<dia<<" "<<mes<<ano;
    getch();
    //marcar a consulta
      sprintf(consultaData,"%d%s%d%s%d",dia,"/",mes,"/",ano);
    //desaloca

    lerArquivo.open("consultas.txt",ios::in);
    lerArquivo.read((char*)(&readConsulta),sizeof(consulta));
    while(lerArquivo && !lerArquivo.eof()){
      if((*crm == readConsulta.crm)&&(strcmp(consultaData,readConsulta.dataConsulta)==0)&&(turno == readConsulta.turno))
          numConsulta++;
      lerArquivo.read((char*)(&readConsulta),sizeof(consulta));
    }
    lerArquivo.close();
//=============================================================
    if(numConsulta>=5)
    {
        textcolor(BLACK);
        gotoxy(32,cont+5);
        cout<<"Horário indisponivel!";
        Sleep(2000);
        cadConsulta(cpfCli,cpfSec);
    }
    else
    {
    lerArquivo.open("medicos.txt",ios::in);
      lerArquivo.read((char*)(&dadoMedico), sizeof(clinica));
        while(lerArquivo && !lerArquivo.eof())
          {
            if( *crm== dadoMedico.crm){
              validaTurno = dadoMedico.turno;
              break;
            }
            lerArquivo.read((char*)(&dadoMedico), sizeof(clinica));
        }
    lerArquivo.close();
        if (validaTurno==0)
            conclui(crm,cont);

        else if(validaTurno==1)
          conclui(crm,cont);



        else{

               int opTurno;
                do{
                    criaMenu(20,93,5,cont+7,COR_LETRA2,COR_LETRA1);
                    criaMenu(8,20,40,cont+7,COR_LOGO,COR_LETRA2);
                    gotoxy(45,cont+8);
                    cout<<"[0] - Manhã";
                    gotoxy(45,cont+9);
                    cout<<"[1] - Tarde";
                    gotoxy(42,cont+11);
                    cout<<"Digite o turno : ";
                    fflush(stdin);
                    cin>>opTurno;
                    if (opTurno<0 || opTurno>1)
                    {
                        gotoxy(45,cont+12);
                        cout<<"Turno inválido!";
                        Sleep(1000);

                        gotoxy(45,cont+12);
                        cout<<"               ";
                        gotoxy(42,cont+11);
                        cout<<"                 ";

                    }
                  }while(opTurno<0 || opTurno>1);
                   conclui(crm,cont);
            }

                 textcolor(BLACK);
                cout<<consultaData;
                getch();

                insereConsulta.tipoConsulta=*opc;
                insereConsulta.crm=*crm;
                strcpy(insereConsulta.cpfCli,cpfCli);
                strcpy(insereConsulta.dataConsulta,consultaData);
                insereConsulta.turno=validaTurno;
                insereConsulta.taxa = dadoMedico.taxa;

                criaConsulta.open("consultas.txt",ios::in|ios::out|ios::app);
                    criaConsulta.write((const char*)(&insereConsulta),sizeof(consulta));
                criaConsulta.close();


                criaArquivo.open("medicos.txt",ios::in|ios::out);
                criaArquivo.read((char*)(&dadoMedico), sizeof(clinica));
                  while(lerArquivo && !lerArquivo.eof())
                  {
                      if( *crm== dadoMedico.crm){
                          dadoMedico.totConsulta++;
                          break;
                      }
                      lerArquivo.read((char*)(&dadoMedico), sizeof(clinica));
                  }
                criaArquivo.close();

    }
  //função thiago
}

void conclui(int *crm , int cont){
  char opc;
      fflush(stdin);
      criaMenu(10,93,5,cont+7,COR_LETRA2,COR_LETRA1);
      gotoxy(32,cont+7);
      cout<<"Desejar confirmar a consulta? [s/n]:";
      cin>>opc;
      if (opc =='s' || opc=='S'){
        for(int i=0;i<5;i++){
          criaMenu(3,45,28,cont+9,BLUE,COR_LETRA2);
          gotoxy(35,cont+10);
          cout<<"CONSULTA REALIZADA COM SUCESSO!!";
          Sleep(400);
          criaMenu(3,45,28,cont+9,COR_LETRA2,BLUE);
          gotoxy(35,cont+10);
          cout<<"CONSULTA REALIZADA COM SUCESSO!!";
          Sleep(400);
        }
        return;
      }
      else{
          exit(1);
      }
}



void tratamentoData(int &diaU, int &mesU, int &anoU, int cont)
{
    fflush(stdin);
    int diaC,mesC,anoC;
    gotoxy(40,3);
    dateSystem(diaC, mesC, anoC);

    do
    {
        criaMenu(3,15,43,cont+3,COR_LETRA2,BLACK);
        gotoxy(37,cont-1);
        cout<<"Informe a data da consulta";
        criaMenu(3,15,43,cont,COR_FUNDO,COR_LETRA1);
        gotoxy(47,cont+1);
        cout << "/";
        gotoxy(52,cont+1);
        cout << "/";
        gotoxy(44,cont+1);
        cin>>diaU;
        gotoxy(49,cont+1);
        cin>>mesU;
        gotoxy(54,cont+1);
        cin>>anoU;
        criaMenu(3,15,43,cont+3,COR_LETRA2,RED);

        switch(mesU)
        {
            case 1:
                //while(diaU<1 || diaU>31)
                    dma(diaU,mesU,anoU,cont,31);
            break;
            case 2:
              //no bissexto
                if((anoU % 4 == 0 && (anoU % 400 == 0 || anoU % 100 != 0))){
                    //while(diaU<1 || diaU>29)
                    dma(diaU,mesU,anoU,cont,29);
                }
                if((anoU % 4 != 0 && (anoU % 400 != 0 || anoU % 100 != 0))){
                    //while(diaU<1 || diaU>28)
                    dma(diaU,mesU,anoU,cont,28);
                }

            break;
            case 3:
                //while(diaU<1 || diaU>31 )
                dma(diaU,mesU,anoU,cont,31);

            break;
            case 4:
                //while(diaU<1 || diaU>30)
                dma(diaU,mesU,anoU,cont,30);

            break;
            case 5:
                //while(diaU<1 || diaU>31)
                dma(diaU,mesU,anoU,cont,31);

            break;
            case 6:
                //while(diaU<1 || diaU>30)
                dma(diaU,mesU,anoU,cont,30);

            break;
            case 7:
                //while(diaU<1 || diaU>31)
                dma(diaU,mesU,anoU,cont,31);

            break;
            case 8:
                //while(diaU<1 || diaU>31)
                dma(diaU,mesU,anoU,cont,31);

            break;
            case 9:
                //while(diaU<1 || diaU>30)
                dma(diaU,mesU,anoU,cont,30);

            break;
            case 10:
                //while(diaU<1 || diaU>31)
                dma(diaU,mesU,anoU,cont,31);

            break;
            case 11:
                //while(diaU<1 || diaU>30)
                dma(diaU,mesU,anoU,cont,30);
            break;
            case 12:
                //while(diaU<1 || diaU>31)
                dma(diaU,mesU,anoU,cont,31);

            break;
            default:
                criaMenu(3,15,43,cont+3,COR_LETRA2,LIGHTRED);
                gotoxy(42,cont+3);
                cout<<"Mês inválido!";
                textcolor(COR_LETRA1);
                Sleep(1000);
                gotoxy(42,cont+3);
                cout<<"             ";
        }

    }while(mesU<1 || mesU>12);

        gotoxy(40,cont+4);
        cout<<"Data é totalmente válida!!";
        Sleep(1000);
}

void dma(int &diaU, int &mesU, int &anoU, int cont, int p)
{
    int diaS, mesS, anoS, j=0;
    bool validar=0;

    dateSystem(diaS,mesS,anoS);

    while((validar==0) || (diaU<1||diaU>p) || (anoU>anoS+1))
    {
        j++;
        int levelCheck = 0;
        ( diaS <= diaU ) ? levelCheck++ : levelCheck = levelCheck ;

        ( mesS <= mesU ) ? levelCheck++ : levelCheck = levelCheck ;

        ( anoS <= anoU ) ? levelCheck++ : levelCheck = levelCheck ;

        ((( diaS <= diaU ) && ( anoS <= anoU ) )) ? levelCheck++ : levelCheck = levelCheck ;

        ((( diaS <= diaU ) && ( mesS <= mesU) )) ? levelCheck++ : levelCheck = levelCheck ;

        ( anoS < anoU ) ? levelCheck++ : levelCheck = levelCheck ;

        if( j > 1)
        {
            j = 0;
            validar=0;
            gotoxy(44,cont+3);
            cout << "Data inválida!";
            Sleep(2000);
            gotoxy(44,cont+3);
            cout << "               ";
            criaMenu(3,15,43,cont,COR_FUNDO,COR_LETRA1);
            gotoxy(47,cont+1);
            cout << "/";
            gotoxy(52,cont+1);
            cout << "/";
            gotoxy(44,cont+1);
            cin>>diaU;
            gotoxy(49,cont+1);
            cin>>mesU;
            gotoxy(54,cont+1);
            cin>>anoU;
            criaMenu(3,15,43,cont+3,COR_LETRA2,RED);
        }
        else
        {
            if(((levelCheck >= 2) && (anoS < anoU)||(levelCheck == 5)))
            {
                validar = 1;
            }
            else
            {
                validar=0;
                gotoxy(44,cont+3);
                cout << "Data inválida!";
                Sleep(2000);
                gotoxy(44,cont+3);
                cout << "               ";
            }
        }
    }
}

/*
void reagendarConsulta(char cpfCli[], int *cpfSec)
{
    fstream lerConsulta;
    consulta readConsulta;

    criaMenu(4,93,5,16,COR_LOGO,COR_LETRA2);
    gotoxy(50 - (14/2), 17);
    cout<<"REAGENDAMENTO";
    mostraInfCliente(cpfCli,cpfSec);
    criaMenu(10,93,5,19,COR_LETRA2,COR_LETRA1);

    lerConsulta.open("consultas.txt",ios::in);
        lerConsulta.read((char*)(&readConsulta),sizeof(consulta));
    while(lerConsulta && !lerConsulta.eof()){
        if(strcmp(cpfCli,readConsulta.cpfCli)==0){
            textcolor(BLACK);
            gotoxy(30,20);
            cout<<readConsulta.dataConsulta;
            gotoxy(30,21);
            cout<<readConsulta.crm;
            gotoxy(30,22);
            cout<<readConsulta.cpfCli;
            gotoxy(30,23);
            cout<<readConsulta.tipoConsulta;
            gotoxy(30,24);
            cout<<readConsulta.turno;
            break;
        }
        lerConsulta.read((char*)(&readConsulta),sizeof(consulta));
    }
    lerConsulta.close();


}
*/

