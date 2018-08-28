void dados(int cpf);
void cadConsulta(char cpfCli[],int cpfSec);
void cadastraClientes();
void agendaConsulta(char cpfCli[],int cpfSec);
void mostraConsulta(char cpfCli[],int cpfSec);
void mostraInfCliente(char cpf[],int cpfSec);//aqui o cpf não pode ser por referencia, Wedson!!


void agendaConsulta(int cpfSec){
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

  criaMenu(3,30,5,7,COR_LOGO,COR_LETRA2);
  gotoxy(17,8);
  cout<<"Dados";
  criaMenu(5,30,5,10,COR_LETRA2,COR_LETRA1);
  gotoxy(7,11);
  cout<<"Nome  : "<<lerSecretaria.nome;
  gotoxy(7,12);
  cout<<"CPF   : "<<lerSecretaria.cpf;

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

    cliente lerClientes;

    int localizado=0;
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
              verificaCadastro.read((char*)(&lerClientes), sizeof(cliente));
          }
          if (localizado==1){
              /*
                Area destina a : Erick, Wedson, Daniel e Luiz
              */
              agendaConsulta(cpfCli,cpfSec);
          }
          else{
            /*
            Area destinada a : Liliane, ALessandra e Jessica
            */
            cadastraClientes();
          }

 }

 void cadastraClientes(){
    cliente cadClientes;
    fflush(stdin);

        //CRIA CAIXA ATRÁS
        criaMenu(14,93,5,16,COR_LETRA2,COR_LETRA1);

        criaMenu(1,15,6,17,COR_LOGO,COR_LETRA1);
        gotoxy(7,17);
        cout << "NOME COMPLETO ";
        criaMenu(1,1,22,17,COR_FUNDO,COR_LETRA2);
        gotoxy(22,17);
        cin.getline(cadClientes.nome,40);

        criaMenu(1,5,6,19,COR_LOGO,COR_LETRA1);
        gotoxy(7,19);
        cout << "CPF ";
        criaMenu(1,1,12,19,COR_FUNDO,COR_LETRA2);
        gotoxy(12,19);
        cin.getline(cadClientes.cpf, 12);

        criaMenu(1,6,6,21,COR_LOGO,COR_LETRA1);
        gotoxy(7,21);
        cout << "SEXO ";
        criaMenu(1,1,13,21,COR_FUNDO,COR_LETRA2);
        gotoxy(13,21);
        cin.getline(cadClientes.sexo,15);

        criaMenu(1,12,6,23,COR_LOGO,COR_LETRA1);
        gotoxy(7,23);
        cout << "NASCIMENTO ";
        criaMenu(1,1,19,23,COR_FUNDO,COR_LETRA2);
        gotoxy(19,23);
        cin.getline(cadClientes.dataNasc,15);

        criaMenu(1,10,6,25,COR_LOGO,COR_LETRA1);
        gotoxy(7,25);
        cout << "TELEFONE ";
        criaMenu(1,1,17,25,COR_FUNDO,COR_LETRA2);
        gotoxy(17,25);
        cin.getline(cadClientes.telefone,20);

        criaMenu(1,13,6,27,COR_LOGO,COR_LETRA1);
        gotoxy(7,27);
        cout << "NOME PAI ";
        criaMenu(1,1,20,27,COR_FUNDO,COR_LETRA2);
        gotoxy(20,27);
        cin.getline(cadClientes.nomePai,40);

        criaMenu(1,13,6,29,COR_LOGO,COR_LETRA1);
        gotoxy(7,29);
        cout << "NOME MÃE ";
        criaMenu(1,1,20,29,COR_FUNDO,COR_LETRA2);
        gotoxy(20,29);
        cin.getline(cadClientes.nomeMae,40);

        criaMenu(1,10,46,17,COR_LOGO,COR_LETRA1);
        gotoxy(47,17);
        cout << "ENDEREÇO ";
        criaMenu(1,1,57,17,COR_FUNDO,COR_LETRA2);
        gotoxy(57,17);
        cin.getline(cadClientes.endRua,40);

        criaMenu(1,8,46,19,COR_LOGO,COR_LETRA1);
        gotoxy(47,19);
        cout << "BAIRRO ";
        criaMenu(1,1,55,19,COR_FUNDO,COR_LETRA2);
        gotoxy(55,19);
        cin.getline(cadClientes.endBairro,30);

        criaMenu(1,4,84,19,COR_LOGO,COR_LETRA1);
        gotoxy(85,19);
        cout << "UF ";
        criaMenu(1,1,89,19,COR_FUNDO,COR_LETRA2);
        gotoxy(89,19);
        cin.getline(cadClientes.UF,3);

        criaMenu(1,8,46,21,COR_LOGO,COR_LETRA1);
        gotoxy(47,21);
        cout << "CIDADE ";
        criaMenu(1,1,55,21,COR_FUNDO,COR_LETRA2);
        gotoxy(55,21);
        cin.getline(cadClientes.cidade,25);

        criaMenu(1,5,70,21,COR_LOGO,COR_LETRA1);
        gotoxy(71,21);
        cout << "CEP ";
        criaMenu(1,1,76,21,COR_FUNDO,COR_LETRA2);
        gotoxy(76,21);
        cin.getline(cadClientes.cep,10);

        criaMenu(1,8,46,23,COR_LOGO,COR_LETRA1);
        gotoxy(47,23);
        cout << "E-MAIL ";
        criaMenu(1,1,55,23,COR_FUNDO,COR_LETRA2);
        gotoxy(55,23);
        cin.getline(cadClientes.email,40);

        criaMenu(1,13,46,25,COR_LOGO,COR_LETRA1);
        gotoxy(47,25);
        cout << "OBSERVAÇÕES ";
        criaMenu(1,1,60,25,COR_FUNDO,COR_LETRA2);
        gotoxy(60,25);

        //if (strlen(cadClientes.obs) > )
        //  cout<<"\n";
        cin.getline(cadClientes.obs,50);

        fstream arquivo;
        arquivo.open("clientes.txt", ios::in | ios::out);
        arquivo.write((const char*) (&cadClientes), sizeof(cliente));
        arquivo.close();
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



