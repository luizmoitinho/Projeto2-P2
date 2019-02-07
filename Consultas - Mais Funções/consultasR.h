void consultas(int cpfSec);

void cadConsulta(char cpfCli[],int cpfSec);
void cadastraClientes(char cpfCli[]);

void cadAlerta();

void agendaConsulta(char cpfCli[],int cpfSec);
void mostraConsulta(char cpfCli[],int cpfSec);
void mostraInfCliente(char cpf[],int cpfSec);//aqui o cpf não pode ser por referencia, Wedson!!

void dados(int cpf);

void dados(int cpfSec){

  clinica lerSecretaria;
  fstream arquivo;
    arquivo.open("secretaria.txt",ios::in);

      arquivo.read((char *)(&lerSecretaria),sizeof(clinica));
      while(!arquivo.eof()){
        if(cpfSec == lerSecretaria.cpf){
          break;
        }
        arquivo.read((char *)(&lerSecretaria),sizeof(clinica));

    }
  arquivo.close();

  criaMenu(2,30,5,7,COR_LOGO,COR_LETRA2);
  gotoxy(17,8);
  cout<<"Dados";
  criaMenu(4,30,5,9,COR_LETRA2,COR_LETRA1);
  gotoxy(7,10);
  cout<<"Nome  : "<<lerSecretaria.nome;
  gotoxy(7,11);
  cout<<"CPF   : "<<lerSecretaria.cpf;

}



void consultas(int cpfSec){
  setlocale(LC_ALL,"portuguese");
  textbackground(COR_FUNDO);
  clrscr();
  textcolor(BLACK);
  char cpfCli[12]=" ";
  logo();
  barraNotificacao();
  dados(cpfSec);
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
//============= MENINAS ==================
void cadConsulta(char cpfCli[],int cpfSec){
    system("cls");
    setlocale(LC_ALL,"portuguese");
    textbackground(COR_FUNDO);
    clrscr();
    textcolor(BLACK);
    logo();
    barraNotificacao();
    dados(cpfSec);
    int localizado=0;
    cliente lerClientes;
    fstream verificaCadastro;
    verificaCadastro.open("clientes.txt", ios::in);
    if(verificaCadastro.fail())
        cout<<"\n\nfalha ao carregar arquivo";
        verificaCadastro.read((char*)(&lerClientes), sizeof(cliente));
          while(verificaCadastro && !verificaCadastro.eof()){
              if(strcmp(cpfCli,lerClientes.cpf) == 0){
                  localizado=1;
                  break;
              }
              verificaCadastro.read((char*)(&lerClientes),sizeof(cliente));
          }
          if (localizado==1){
              /*
                Area destinada : Erick, Wedson, Daniel e Luiz
              */
              agendaConsulta(cpfCli,cpfSec);
          }
          else{
            /*
            Area destinada : Liliane, ALessandra e Jessica
            */
            cadAlerta();
            cadastraClientes(cpfCli);
            agendaConsulta(cpfCli,cpfSec);
          }
 }

void cadAlerta(){
  criaMenu(5,93,5,16,COR_LETRA2,LIGHTRED);
  gotoxy(30,18);
  cout<<"O CPF informado não foi encontrado no sistema!!";
  Sleep(2000);

}

void cadastraClientes(char cpfCli[]){
  cliente cadCliente;
  ofstream preencheArquivo;
  int *tam;
  tam = new int(0);
    fflush(stdin);
        //CRIA CAIXA ATRÁS
        criaMenu(20,93,5,16,COR_LETRA2,COR_LETRA1);

        criaMenu(3,93,5,15,COR_LOGO,COR_LETRA2);
        gotoxy(38,16);
        cout<<"CADASTRAR CLIENTES";

        criaMenu(1,15,6,20,COR_LOGO,COR_LETRA2);
        gotoxy(7,20);
        cout << "NOME COMPLETO ";

        criaMenu(1,6,6,22,COR_LOGO,COR_LETRA2);
        gotoxy(7,22);
        cout << "SEXO ";
        criaMenu(1,12,6,24,COR_LOGO,COR_LETRA2);
        gotoxy(7,24);
        cout << "NASCIMENTO ";
        criaMenu(1,12,6,26,COR_LOGO,COR_LETRA2);
        gotoxy(7,26);
        cout << "NOME PAI ";
        criaMenu(1,12,6,28,COR_LOGO,COR_LETRA2);
        gotoxy(7,28);
        cout << "NOME MÃE ";

        criaMenu(1,10,50,20,COR_LOGO,COR_LETRA2);
        gotoxy(51,20);
        cout << "ENDEREÇO ";

        criaMenu(1,8,50,22,COR_LOGO,COR_LETRA2);
        gotoxy(51,22);
        cout << "BAIRRO ";

        criaMenu(1,4,84,20,COR_LOGO,COR_LETRA2);
        gotoxy(85,20);
        cout << "UF ";

        criaMenu(1,8,50,24,COR_LOGO,COR_LETRA2);
        gotoxy(51,24);
        cout << "CIDADE";

        criaMenu(1,5,76,24,COR_LOGO,COR_LETRA2);
        gotoxy(76,24);
        cout << " CEP ";

        criaMenu(1,8,50,26,COR_LOGO,COR_LETRA2);
        gotoxy(51,26);
        cout << "E-MAIL ";

        criaMenu(1,13,50,28,COR_LOGO,COR_LETRA2);
        gotoxy(51,28);
        cout << "OBSERVAÇÕES ";


      //entrada de dados
        criaMenu(1,20,22,20,COR_FUNDO,COR_LETRA1);
        criaMenu(1,15,22,22,COR_FUNDO,COR_LETRA1);
        criaMenu(1,15,22,24,COR_FUNDO,COR_LETRA1);
        criaMenu(1,20,22,26,COR_FUNDO,COR_LETRA1);
        criaMenu(1,20,22,28,COR_FUNDO,COR_LETRA1);
        criaMenu(1,20,62,20,COR_FUNDO,COR_LETRA1);
        criaMenu(1,20,62,22,COR_FUNDO,COR_LETRA1);
        criaMenu(1,5,89,20,COR_FUNDO,COR_LETRA1);
        criaMenu(1,12,62,24,COR_FUNDO,COR_LETRA1);
        criaMenu(1,11,82,24,COR_FUNDO,COR_LETRA1);
        criaMenu(1,25,62,26,COR_FUNDO,COR_LETRA1);
        criaMenu(1,20,64,28,COR_FUNDO,COR_LETRA1);

        gotoxy(23,20);
        cin.getline(cadCliente.nome,40);
        gotoxy(23,22);
        cin.getline(cadCliente.sexo,15);
        gotoxy(23,24);
        cin.getline(cadCliente.dataNasc,12);
        gotoxy(23,26);
        cin.getline(cadCliente.nomePai,40);
        gotoxy(23,28);

        cin.getline(cadCliente.nomePai,40);
        gotoxy(63,20);
        cin.getline(cadCliente.endRua,40);
        gotoxy(89,20);
        cin.getline(cadCliente.UF,3);
        gotoxy(63,22);
        cin.getline(cadCliente.endBairro,30);
        gotoxy(63,24);
        cin.getline(cadCliente.cidade,25);
        gotoxy(82,24);
        cin.getline(cadCliente.cep,10);
        gotoxy(63,26);
        cin.getline(cadCliente.email,40);
        gotoxy(65,28);
        cin.getline(cadCliente.obs,50);
        strcpy(cadCliente.cpf,cpfCli);

        preencheArquivo.open("clientes.txt", ios::in|ios::out|ios::app);
          preencheArquivo.write((const char*)(&cadCliente), sizeof(cliente));
        preencheArquivo.close();

        criaMenu(2,20,64,33,COR_LETRA2,GREEN);
        gotoxy(30,33);
        cout<<"CADASTRO FINALIZADO COM SUCESSO!!";
        Sleep(2000);
}

void agendaConsulta(char cpfCli[],int cpfSec){


    char  *opc;
    char espec[20];
    opc = new char;
    criaMenu(4,80,10,16,COR_LOGO,COR_LETRA2);
    mostraInfCliente(cpfCli,cpfSec);
    criaMenu(10,80,10,19,COR_LETRA2,COR_LETRA1);
    gotoxy(20,20);
    cout<<"[1] Nova consulta";
    gotoxy(20,21);
    cout<<"[2] Reagendar consulta";
    gotoxy(20,22);
    cout<<"[3] Agendar retorno";
    fflush(stdin);
    gotoxy(20,24);
    criaMenu(3,24,20,24,COR_LOGO,COR_LETRA2);
    gotoxy(20,25);
    cout<<"Selecione uma opcao: ";
    *opc = getchar();
    switch(*opc){
        case '1':
            mostraConsulta(cpfCli,cpfSec);
        break;

        case '2':
          //reagendar consulta
        break;

        case '3':
          //agendar retorno
        break;
    }

}

void mostraInfCliente(char cpfCli[],int cpfSec){
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

void mostraConsulta(char cpfCli[],int cpfSec){
    char espec[20];
    char armazena[20][20], aux[20]=" ";// lembrar de deixar aux, espec e armazena como vetores dinâmicos
    int i=0;
    clinica testeclinica;
    ifstream lerConsultas;
        lerConsultas.open("medicos.txt", ios::in);
        lerConsultas.read((char *) (&testeclinica), sizeof(clinica));

        //faz a busca das especialidades cadastradas e passa para um vetor de char auxiliar
        while( lerConsultas && !lerConsultas.eof()){
              strcpy(armazena[i],testeclinica.especialidade);
              i++;
              lerConsultas.read((char *) (&testeclinica), sizeof(clinica));
            }
      lerConsultas.close();

      for(int j=0; j<=i ;j++){
          for(int k=0; k<=i; k++){
            if(strcmp(armazena[j],armazena[k])<0){
              strcpy(aux,armazena[j]);
              strcpy(armazena[j],armazena[k]);
              strcpy(armazena[k],aux);
            }
         }
      }

      int cont = 0;
      int leng = 0;
      criaMenu(14,93,5,16,COR_LETRA2,COR_LETRA1);
      for(int j=0; j<=i ;j++){
          if(strcmp(armazena[j],armazena[j+1])!=0){
                leng = strlen(armazena[j]);
                criaMenu(1, leng, 6 + cont,17, COR_LOGO, COR_LETRA1);
                gotoxy(6 + cont,17);
                cout << armazena[j];
                cont = (leng + cont) + 10;
          }
      }


    lerConsultas.open("medicos.txt", ios::in);
      fflush(stdin);
      gotoxy(35,15);
      cout << "Informe a especialidade: ";
      cin.getline(espec,20);

    int cont1=0;
      criaMenu(14,93,5,16,COR_LETRA2,COR_LETRA1);
      lerConsultas.read((char *) (&testeclinica), sizeof(clinica));
        while( lerConsultas && !lerConsultas.eof()){
            if( strcmp(testeclinica.especialidade, espec) == 0){
                criaMenu(1, 5, 7 + cont1,17, COR_LOGO, COR_LETRA1);
                gotoxy(7 + cont1,17);
                cout << "NOME: " << testeclinica.nome;
                criaMenu(1, 4, 7 + cont1,18, COR_LOGO, COR_LETRA1);
                gotoxy(7 + cont1,18);
                cout <<"CRM: " << testeclinica.crm;
                criaMenu(1, 8, 7 + cont1,19, COR_LOGO, COR_LETRA1);
                gotoxy(7 + cont1,19);
                cout <<"HORARIO: " << testeclinica.turno;
                cont1 = cont1 + 20;
            }
            lerConsultas.read((char *) (&testeclinica), sizeof(clinica));
          }

    lerConsultas.close();
}







