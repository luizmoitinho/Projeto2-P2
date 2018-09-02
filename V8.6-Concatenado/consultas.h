void dados(int cpf);
void cadConsulta(char cpfCli[],int cpfSec);
void cadastraClientes(char cpfCli[]);
void agendaConsulta(char cpfCli[],int cpfSec);
int mostraConsulta(int cpfSec,char cpfCli[],int &cont1);
void mostraInfCliente(char cpf[],int cpfSec);//aqui o cpf n�o pode ser por referencia, Wedson!!
int converterParaInt(string str);
void dataConsulta(int crm,char cpfCli[],int cpfSec,int cont,int *opc);
void tratamentoData(int &diaU, int &mesU, int &anoU,int cont);
void dma(int &diaU, int &mesU, int &anoU, int cont, int p);
void reagendarConsulta(char cpfCli[], int cpfSec);
void pagamento(int cr,int cont);


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




void consultas(int cpfSec){
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
                cout << "CPF n�o encontrado!";
                textcolor(BLACK);
                gotoxy(40,21);
                cout << "[1] Cadastrar novo cliente";
                gotoxy(40,22);
                cout << "[2] Voltar ao menu";

            do{
                criaMenu(3,24,39,24,COR_LOGO,COR_LETRA2);
                gotoxy(40,25);
                cout << "Selecione uma op��o: ";
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
                        cout << "INV�LIDO";
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
  int *tam;
  tam = new int(0);
    fflush(stdin);
        //CRIA CAIXA ATR�S
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
        cout << "NOME M�E ";

        criaMenu(1,9,50,22,COR_LOGO,COR_LETRA2);
        gotoxy(51,22);
        cout << "ENDERE�O ";

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

        criaMenu(1,13,50,28,COR_LOGO,COR_LETRA2);
        gotoxy(51,28);
        cout << "OBSERVA��ES ";


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
        criaMenu(1,20,64,28,COR_FUNDO,COR_LETRA1);

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
            cout << "INV�LIDO";
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

        gotoxy(64,28);
        cin.getline(cadCliente.obs,50);

        //strcpy(cadCliente.cpf,cpfCli);

        preencheArquivo.open("clientes.txt", ios::out|ios::app);
        preencheArquivo.write((const char*)(&cadCliente), sizeof(cliente));
        preencheArquivo.close();

        criaMenu(2,20,64,33,COR_LETRA2,GREEN);
        gotoxy(30,33);
        cout<<"CADASTRO FINALIZADO COM SUCESSO!";
        Sleep(2000);
}



void agendaConsulta(char cpfCli[],int cpfSec){
    int crm,cont=0;
    int  *opc;
    char espec[20];
    opc = new int;

    criaMenu(4,93,5,16,COR_LOGO,COR_LETRA2);
    gotoxy(50 - (6/2), 17);
    cout << "OP��ES";
    mostraInfCliente(cpfCli,cpfSec);
    criaMenu(10,93,5,19,COR_LETRA2,COR_LETRA1);
    gotoxy(50 - (19/2),20);
    cout<<"[1] Nova consulta";
    gotoxy(50 - (19/2),21);
    cout<<"[2] Reagendar consulta";
    gotoxy(50 - (19/2),22);
    cout<<"[3] Agendar retorno";
    fflush(stdin);
    gotoxy(40,24);
    criaMenu(3,24,39,24,COR_LOGO,COR_LETRA2);

    do{
        gotoxy(40,25);
        cout<<"Selecione uma opcao: ";
        cin >> *opc;

        switch(*opc){
            case 1:

                crm = mostraConsulta(cpfSec,cpfCli,cont);
                *opc =1;
                dataConsulta(crm,cpfCli,cpfSec,cont,opc);
            break;

            case 2:
                //reagendar consulta
                *opc =1;
                reagendarConsulta(cpfCli,cpfSec);
            break;

            case 3: // Retorno
                *opc =2;
                crm = mostraConsulta(cpfSec,cpfCli,cont);
                dataConsulta(crm,cpfCli,cpfSec,cont,opc);
            break;

            default:
                criaMenu(3,8,61,24,COR_LOGO,COR_LETRA2);
                gotoxy(61,25);
                textcolor(RED);
                cout << "INV�LIDO";
                Sleep(1000);
                textcolor(WHITE);
                criaMenu(3,8,61,24,COR_LOGO,COR_LETRA2);
                break;
        }
    }while(*opc != 1 && *opc != 2 && *opc != 3);
}



void mostraInfCliente(char cpfCli[],int cpfSec){
    ifstream lerCliente;
    lerCliente.open("clientes.txt", ios::in);
    cliente testeclientes;

    //MOSTRAR INFORMA��O DO CLIENTE
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





int mostraConsulta(int crm, char cpfCli[],int&cont1){

    char espec[20];
    char armazena[25][30], aux[20] = " ";// lembrar de deixar aux, espec e armazena como vetores din�micos

    int i = 0;
    int x = 7, y = 20;
    int soma = 10,secCRM,cont=0,leng=0;

    clinica medico;
    ifstream lerConsultas;
        lerConsultas.open("medicos.txt", ios::in);

//faz a busca das especialidades cadastradas e passa para um vetor de char auxiliar
        lerConsultas.read((char *) (&medico), sizeof(clinica));
        while( lerConsultas && !lerConsultas.eof()){
              strcpy(armazena[i],medico.especialidade);
              lerConsultas.read((char *) (&medico), sizeof(clinica));
              i++;
            }
      lerConsultas.close();

      for(int j=0; j<i ;j++){
          for(int k=0; k<i; k++){
            if(strcmp(armazena[j],armazena[k])<0){
              strcpy(aux,armazena[j]);
              strcpy(armazena[j],armazena[k]);
              strcpy(armazena[k],aux);
            }
         }
      }


      criaMenu(14,93,5,16,COR_LETRA2,COR_LETRA1);
      for(int j=0; j<i ;j++)
        {
          if(strcmp(armazena[j],armazena[j+1])!=0)
          {
            leng = strlen(armazena[j]);
            if((x + strlen(armazena[j])) < 96)
            {
                criaMenu(3, leng + 2, x, y -1, COR_LOGO, COR_LETRA2);
                gotoxy(x + 1, y);
                cout << armazena[j];
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

        lerConsultas.open("medicos.txt", ios::in);

        lerConsultas.read((char*) (&medico), sizeof(clinica));
        while(lerConsultas && !lerConsultas.eof())
    {
            if(strcmp(medico.especialidade, espec) == 0)
            {
                gotoxy(61, 17);
                textcolor(GREEN);
                cout << "Profiss�o V�lida!";
                Sleep(1000);
                textcolor(WHITE);
                localizar = 1;
                break;
        }
        lerConsultas.read((char*) (&medico), sizeof(clinica));
    }
    lerConsultas.close();

            if (localizar == 0)
                {
                    gotoxy(60, 17);
                    textcolor(RED);
                    cout << "Profiss�o Inv�lida!";
                    Sleep(1000);
                    textcolor(WHITE);
                    criaMenu(1,19,60,17, COR_LETRA2,COR_LETRA2);
                }

    }   while(localizar == 0);

//=====================================================================================
//  Conta o tamanho da tela de fundo.

    lerConsultas.open("medicos.txt", ios::in);

    lerConsultas.read((char *) (&medico), sizeof(clinica));
    while( lerConsultas && !lerConsultas.eof()){
        if( strcmp(medico.especialidade, espec) == 0){
            cont1 = cont1 + 6;
        }
        lerConsultas.read((char *) (&medico), sizeof(clinica));
    }
   lerConsultas.close();

//=====================================================================================

    criaMenu(cont1 + 5,93,5,19,COR_LETRA2,COR_LETRA1);
    criaMenu(3,93,5,16,COR_LOGO,COR_LETRA2);
    gotoxy(50-(13/2), 17);
    cout << "ESPECIALISTAS";

    cont1 = 0;

    char turno[12];
    lerConsultas.open("medicos.txt", ios::in);

    lerConsultas.read((char *) (&medico), sizeof(clinica));
    while( lerConsultas && !lerConsultas.eof()){
        if( strcmp(medico.especialidade, espec) == 0){

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
                strcpy(turno, "Manh�");
                break;
            case 1:
                strcpy(turno, "Tarde");
                break;
            case 2:
                strcpy(turno, "Manh�/Tarde");
                break;
            }

            gotoxy(50 - (cmp/2),23 + cont1);
            cout <<"HORARIO: " << turno;
            cont1 = cont1 + 6;

        }
        lerConsultas.read((char *) (&medico), sizeof(clinica));
    }
   lerConsultas.close();



//=====================================================================================

    int localizado = 0;

    do{
        lerConsultas.open("medicos.txt", ios::in);

        criaMenu(1, 21,40, 18 + cont1 + 2,COR_LOGO,COR_LETRA2);
        gotoxy(40, 18 + cont1 + 2);
        cout << "INFORME CRM DESEJADO:";
        fflush(stdin);
        criaMenu(1,4,62,18 + cont1 + 2,COR_FUNDO,COR_LETRA1);
        gotoxy(62, 18 + cont1 + 2);
        cin >> secCRM;

        while(lerConsultas && !lerConsultas.eof())
        {
            if(medico.crm == secCRM)
                {
                    return secCRM;
                    localizado = 1;
                    break;
                }
                lerConsultas.read((char *) (&medico), sizeof(clinica));
        }
        lerConsultas.close();

            if(localizado == 0)
            {
                gotoxy(62, 18 + cont1 + 2);
                textcolor(RED);
                cout << "CRM Inv�lido!";
                Sleep(1000);
                criaMenu(1,13,62,18 + cont1 + 2, COR_LETRA2,COR_LETRA2);
            }

    }while(localizado == 0);

}

//=============================================================

void dataConsulta(int crm, char cpfCli[],int cpfSec, int cont, int *opc)
{
    cliente lerCliente;
    clinica dadoMedico;
    consulta insereConsulta, readConsulta;
    char cpf[12],consultaData[11];
    int localizado=0,valida=0,turno,validaTurno,numConsulta=0,formPag;
    int dia,mes,ano;
    char diaChar[2],mesChar[2],anoChar[2];
    fflush(stdin);
    ifstream lerArquivo;
    ofstream criaArquivo;
    fstream criaConsulta;
    cont+=20;
    criaMenu(10,93,5,cont,COR_LETRA2,COR_LETRA1);
    cont++;

    tratamentoData(dia,mes,ano,cont);

    //marcar a consulta
    sprintf(consultaData,"%d%s%d%s%d",dia,"/",mes,"/",ano);
    //informar o turno
//=====================================void dados(int cpf);=======================
    lerArquivo.open("consultas.txt",ios::in);
        lerArquivo.read((char*)(&readConsulta),sizeof(consulta));
    while(lerArquivo && !lerArquivo.eof())
    {
        if((crm == readConsulta.crm)&&(strcmp(consultaData,readConsulta.dataConsulta)==0)&&(turno == readConsulta.turno))
            numConsulta++;
        lerArquivo.read((char*)(&readConsulta),sizeof(consulta));
    }
    lerArquivo.close();
//=============================================================
    if(numConsulta>=5)
    {
        textcolor(BLACK);
        gotoxy(32,cont+5);
        cout<<"Hor�rio indisponivel!";
        Sleep(2000);
        cadConsulta(cpfCli,cpfSec);
    }
    else
    {
        lerArquivo.open("medicos.txt",ios::in);
          lerArquivo.read((char*)(&dadoMedico), sizeof(clinica));
          while(lerArquivo && !lerArquivo.eof())
          {
              if( crm== dadoMedico.crm){
                  validaTurno = dadoMedico.turno;
                  cout<<validaTurno;
                  getch();
                  break;
              }
              lerArquivo.read((char*)(&dadoMedico), sizeof(clinica));
          }
        lerArquivo.close();

        if (validaTurno==0)
            pagamento(crm,cont);
        else if(validaTurno==1)
            pagamento(crm,cont);
        else{

               int opTurno;
                do{
                    criaMenu(20,93,5,cont+7,COR_LETRA2,COR_LETRA1);
                    criaMenu(8,20,40,cont+8,COR_LOGO,COR_LETRA2);
                    gotoxy(45,cont+7);
                    cout<<"[0] - Manh�";
                    gotoxy(45,cont+8);
                    cout<<"[1] - Tarde";
                    gotoxy(42,cont+10);
                    cout<<"Digite o turno : ";
                    fflush(stdin);
                    cin>>opTurno;
                    if (opTurno<0 || opTurno>1)
                    {
                        gotoxy(45,cont+11);
                        cout<<"Turno inv�lido!";
                        Sleep(1000);

                        gotoxy(45,cont+11);
                        cout<<"               ";
                        gotoxy(42,cont+10);
                        cout<<"                 ";

                    }
                  }while(opTurno<0 || opTurno>1);

                   pagamento(crm,cont);
                  if (opTurno==0){
                    cout<<"Consulta marcada pela manh�\n";
                  }
                  else{
                    cout<<"Consulta marcada pela tarde\n";
                  }
            }

                system("pause");


                insereConsulta.tipoConsulta=*opc;
                insereConsulta.crm=crm;
                strcpy(insereConsulta.cpfCli,cpfCli);
                strcpy(insereConsulta.dataConsulta,consultaData);
                insereConsulta.turno=validaTurno;


                criaConsulta.open("consultas.txt",ios::in|ios::out|ios::app);
                    criaConsulta.write((const char*)(&insereConsulta),sizeof(consulta));
                criaConsulta.close();

    }
}

void pagamento(int crm,int cont){
  fstream readMed;
  clinica lerMedicos;
  double valorConsulta;
  int formPag;
  char opPagamento;
  readMed.open("medicos.txt",ios::in);
    readMed.read((char *)(&lerMedicos),sizeof(clinica));
    while(readMed && !readMed.eof()){
        if (crm == lerMedicos.crm)
          break;
      readMed.read((char *)(&lerMedicos),sizeof(clinica));
    }
  readMed.close();
  criaMenu(20,93,5,cont+9,COR_LETRA2,COR_LETRA1);
  criaMenu(10,45,28,cont+7,COR_LOGO,COR_LETRA2);
  gotoxy(35,cont+8);
  cout<<"Valor da consulta : " <<valorConsulta ;
  gotoxy(32,cont+10);
  cout<<" [1] - � vista ";
  gotoxy(32,cont+11);
  cout<<" [2] - Parcelado [3x] ";
  do{
    gotoxy(35,cont+13);
    cout<<"Informe a forma de pagamento : ";
    cin>>formPag;
    if (formPag!=1 && formPag!=2){
        gotoxy(35,cont+15);
        textcolor(YELLOW);
        cout<<"Op��o informada � inv�lida!!";
        Sleep(2000);

        gotoxy(35,cont+13);
        cout<<"                                     ";
        gotoxy(35,cont+15);
        cout<<"                              ";

        textcolor(COR_LETRA2);
    }
  }while(formPag!=1 && formPag!=2);
  switch(formPag){
    case 1:
      fflush(stdin);
      gotoxy(32,cont+14);
      cout<<"Desejar confirmar o pagamento ? [s/n]:";
      opPagamento = getchar();
      if (opPagamento=='s'|| opPagamento=='S'){
        for(int i=0;i<5;i++){
          criaMenu(3,45,28,cont+17,BLUE,COR_LETRA2);
          gotoxy(35,cont+18);
          cout<<"PAGAMENTO EFETUADO COM SUCESSO!!";
          Sleep(400);
          criaMenu(3,45,28,cont+17,COR_LETRA2,BLUE);
          gotoxy(35,cont+18);
          cout<<"PAGAMENTO EFETUADO COM SUCESSO!!";
          Sleep(400);
        }
          return;
          exit(1);
      }

      else
        pagamento(crm,cont);
    break;
    case 2:
      int qtdParcelas;
      fflush(stdin);
      do{
        criaMenu(6,45,28,cont+14,COR_LOGO,COR_LETRA2);
        gotoxy(32,cont+14);
        cout<<"Quantidade de parcelas [at� 3x]: ";
        cin>>qtdParcelas;
        if (qtdParcelas<1 || qtdParcelas>3){
             textcolor(YELLOW);
          gotoxy(32,cont+16);
          cout<<"Quantidade parcelas inv�lidas";
          Sleep(2000);
          gotoxy(32,cont+16);
          cout<<"                             ";
          gotoxy(32,cont+14);
          cout<<"                               ";
        }
      }while(qtdParcelas<1 || qtdParcelas>3);
      gotoxy(32,cont+17);
      while(qtdParcelas<1 || qtdParcelas>3);
      cout<<qtdParcelas<<" parcelas de "<< valorConsulta/qtdParcelas;
      fflush(stdin);
      gotoxy(32,cont+18);
      cout<<"Desejar confirmar o pagamento ? [s/n]:";
      opPagamento = getchar();
      if (qtdParcelas =='s' || opPagamento=='S'){
        for(int i=0;i<5;i++){
          criaMenu(3,45,28,cont+20,BLUE,COR_LETRA2);
          gotoxy(35,cont+21);
          cout<<"PAGAMENTO EFETUADO COM SUCESSO!!";
          Sleep(400);
          criaMenu(3,45,28,cont+20,COR_LETRA2,BLUE);
          gotoxy(35,cont+21);
          cout<<"PAGAMENTO EFETUADO COM SUCESSO!!";
          Sleep(400);
        }
          return;
          exit(1);
      }

    break;



  }
  getch();
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
                cout<<"M�s inv�lido!";
                textcolor(COR_LETRA1);
                Sleep(1000);
                gotoxy(42,cont+3);
                cout<<"             ";
        }

    }while(mesU<1 || mesU>12);

        gotoxy(40,cont+4);
        cout<<"Data � totalmente v�lida!!";
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
            cout << "Data inv�lida!";
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
                cout << "Data inv�lida!";
                Sleep(2000);
                gotoxy(44,cont+3);
                cout << "               ";
            }
        }
    }
}

void reagendarConsulta(char cpfCli[], int cpfSec)
{
    fstream lerConsulta;
    consulta readConsulta;

    criaMenu(4,93,5,16,COR_LOGO,COR_LETRA2);
    gotoxy(50 - (14/2), 17);
    cout << "REAGENDAMENTO";
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

