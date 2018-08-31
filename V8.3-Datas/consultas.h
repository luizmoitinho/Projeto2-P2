void dados(int cpf);
void cadConsulta(char cpfCli[],int cpfSec);
void cadastraClientes(char cpfCli[]);
void agendaConsulta(char cpfCli[],int cpfSec);
int mostraConsulta(int cpfSec,char cpfCli[],int &cont1);
void mostraInfCliente(char cpf[],int cpfSec);//aqui o cpf não pode ser por referencia, Wedson!!
void dataConsulta(int crm,char cpfCli[],int cpfSec,int cont);
void tratamentoData(int &diaU, int &mesU, int &anoU,int &cont);
void dateSystem(string &diaS, string &mesS, string &anoS);
int converterParaInt(string str);
void dia31(int &diaU,int mesU,int anoU,int cont);
void dia30(int &diaU,int mesU,int anoU,int cont);

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

            //criaMenu(10,93,5,19,COR_LETRA2,COR_LETRA1);
            gotoxy(40,20);
            textcolor(RED);
            cout << "CPF não encontrado!";
            textcolor(BLACK);
            gotoxy(40,21);
            cout << "[1] Cadastrar novo cliente";
            gotoxy(40,22);
            cout << "[2] Voltar ao menu";

            criaMenu(3,24,39,24,COR_LOGO,COR_LETRA2);
            gotoxy(40,25);
            cout << "Selecione uma opção: ";
            opc = getchar();

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
            }
          }
}

void cadastraClientes(char cpfCli[]){
    cliente cadCliente;
  fstream preencheArquivo;
  int *tam;
  tam = new int(0);
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

        criaMenu(1,5,80,24,COR_LOGO,COR_LETRA2);
        gotoxy(81,24);
        cout << "CEP ";

        criaMenu(1,13,50,28,COR_LOGO,COR_LETRA2);
        gotoxy(51,28);
        cout << "OBSERVAÇÕES ";


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
        criaMenu(1,11,86,24,COR_FUNDO,COR_LETRA1);
        criaMenu(1,20,64,28,COR_FUNDO,COR_LETRA1);

        gotoxy(22,20);
        cin.getline(cadCliente.nome,40);

        gotoxy(22,22);
        cin.getline(cadCliente.sexo,15);

        gotoxy(22,24);
        cin.getline(cadCliente.cpf,12);

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

        gotoxy(86,24);
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
    char  *opc;
    char espec[20];
    opc = new char;

    criaMenu(4,93,5,16,COR_LOGO,COR_LETRA2);
    gotoxy(50 - (6/2), 17);
    cout << "OPÇÕES";
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
    gotoxy(40,25);
    cout<<"Selecione uma opcao: ";
    *opc = getchar();

    switch(*opc){
        case '1':
            crm = mostraConsulta(cpfSec,cpfCli,cont);
            dataConsulta(crm,cpfCli,cpfSec,cont);
        break;

        case '2':
          //reagendar consulta
        break;

        case '3':
          //agendar retorno
        break;

        default:
            gotoxy(62, 17);
            cout << "Opção Inválida";
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

int mostraConsulta(int crm, char cpfCli[],int&cont1){

    char espec[20];
    char armazena[25][30], aux[20] = " ";// lembrar de deixar aux, espec e armazena como vetores dinâmicos

    int i = 0;
    int x = 7, y = 19;
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
                criaMenu(3, leng, x, y, COR_LOGO, COR_LETRA2);
                gotoxy(x, y + 1);
                cout << armazena[j];
                //cont = (leng + cont) + 5;

                if(x < 92)
                {
                  x = x + strlen(armazena[j]) + 5;
                }
                else
                {
                    y = y + 4;
                    x = 7;
                }
          }
      }

//==================================================================================

    int localizar = 0;

    fflush(stdin);

    do{
        criaMenu(1,25,34,17, COR_LOGO,COR_LETRA2);
        gotoxy(35,17);
        cout << "Informe a especialidade: ";
        fflush(stdin);
        criaMenu(1,1,61,17, COR_FUNDO,COR_LETRA2);
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
                cout << "Profissão Válida!";
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
                    cout << "Profissão Inválida!";
                    Sleep(1000);
                    textcolor(WHITE);
                    criaMenu(1,19,60,17, COR_LETRA2,COR_LETRA2);
                }

    }   while(localizar == 0);

//=====================================================================================

    lerConsultas.open("medicos.txt", ios::in);

    criaMenu(14,93,5,16,COR_LETRA2,COR_LETRA1);
    criaMenu(3,93,5,16,COR_LOGO,COR_LETRA2);
    gotoxy(50-(13/2), 17);
    cout << "ESPECIALISTAS";

    lerConsultas.read((char *) (&medico), sizeof(clinica));
    while( lerConsultas && !lerConsultas.eof()){
        if( strcmp(medico.especialidade, espec) == 0){

            criaMenu(5, 87, 8, 20 + cont1, COR_LOGO, COR_LETRA2);
            int cmp = 0;
            cmp = strlen(medico.nome);
            gotoxy(50 - (cmp/2),21 + cont1);
            cout << "NOME: " << medico.nome;
            gotoxy(50 - (cmp/2),22 + cont1);
            cout <<"CRM: " << medico.crm;
            gotoxy(50 - (cmp/2),23 + cont1);
            cout <<"HORARIO: " << medico.turno;
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
        criaMenu(1,4,62,18 + cont1 + 2,COR_FUNDO,COR_LETRA2);
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
                cout << "CRM Inválido!";
                Sleep(1000);
                criaMenu(1,13,62,18 + cont1 + 2, COR_LETRA2,COR_LETRA2);
            }

    }while(localizado == 0);

}



void dataConsulta(int crm, char cpfCli[],int cpfSec, int cont)
{
    cliente lerCliente;
    clinica dadoMedico;
    consulta insereConsulta, readConsulta;
    char cpf[12],consultaData[11]=" ";
    int localizado=0,valida=0,turno,validaTurno=-1,numConsulta=0;
    int dia,mes,ano;
    char diaChar[2],mesChar[2],anoChar[2];
    fflush(stdin);
    ifstream lerArquivo,lerConsulta;
    ofstream criaArquivo;
    fstream criaConsulta;
    cont+=20;
    criaMenu(10,93,5,cont,COR_LETRA2,COR_LETRA1);
    gotoxy(40,cont);
    cout<<"Informe a data da consulta: ";


    cont++;
    criaMenu(3,15,43,cont,COR_FUNDO,COR_LETRA1);
    gotoxy(47,cont+1);
    cout << "/";
    gotoxy(52,cont+1);
    cout << "/";
    gotoxy(44,cont+1);
    cin>>dia;
    gotoxy(49,cont+1);
    cin>>mes;
    gotoxy(54,cont+1);
    cin>>ano;
    criaMenu(3,15,43,cont+3,COR_LETRA2,RED);
    tratamentoData(dia,mes,ano,cont);
    //converter essas datas para char, verificar na função e só ai poder
    //marcar a consulta

    itoa(dia,diaChar,10);
    itoa(mes, mesChar,10);
    itoa(ano, anoChar,10);
    for(int i=0,c=0;i<9;i++){
      if (i<2){
        consultaData[i]=diaChar[c];
        c++;
      }
    }
    cout<<consultaData;
    getch();


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
        cout<<"\n\t\t\t\tHorário e dia indisponivel!\n";
        Sleep(2000);
           // cadConsulta();
    }
    else
    {
        lerArquivo.open("medicos.txt",ios::in);
        lerArquivo.read((char*)(&dadoMedico), sizeof(clinica));
        if (lerArquivo.fail())
            exit(1);
        while(lerArquivo && !lerArquivo.eof())
        {
            if( crm== dadoMedico.crm)
            {
                validaTurno = dadoMedico.turno;
            }
            lerArquivo.read((char*)(&dadoMedico), sizeof(clinica));
        }
        lerArquivo.close();

        if (validaTurno==0)
        {
            cout<<"\n\t\t\t Consulta marcada pela manhã\n";
        }
        else
        {
            if(validaTurno==1)
                cout<<"\n\t\t\t Consulta marcada pela tarde\n";
            else
            {
                do{
                    fflush(stdin);
                    cout<<"\n\t\t\t [0] - Manhã\n";
                    cout<<"\n\t\t\t [1] - Tarde\n";
                    cout<<"\t\t\t\t Digite o turno : ";
                    cin>>validaTurno;
                    if (validaTurno!=0 && validaTurno!=1)
                    {
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
                strcpy(insereConsulta.dataConsulta,consultaData);
                insereConsulta.turno=validaTurno;

                criaConsulta.open("consultas.txt",ios::in|ios::out|ios::app);
                    criaConsulta.write((const char*)(&insereConsulta),sizeof(consulta));
                criaConsulta.close();
        }

    }
}

void dateSystem(string &diaS, string &mesS, string &anoS)
{
    char dataAtual[9];
    _strdate(dataAtual);
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
}

int converterParaInt(string str)
{
    std::istringstream iss(str);
    int retorno;
    iss >> retorno;
    return retorno;
}

void tratamentoData(int &diaU, int &mesU, int &anoU,int &cont)
{
    fflush(stdin);
    int diaC,mesC,anoC;
    int valida=1;
    string diaS, mesS, anoS;
    char c[2];
    gotoxy(40,3);
    dateSystem(diaS, mesS, anoS);
    diaC=converterParaInt(diaS);
    mesC=converterParaInt(mesS);
    anoC=converterParaInt(anoS);
    do{
      switch(mesU){
        case 1:
          if(diaU<1 || diaU>31 ){
            gotoxy(45,cont);
            dia31(diaU,mesU,anoU,cont+2);
          }
        break;
        case 2:
          //no bissexto
          if((anoU % 4 == 0 && (anoU % 400 == 0 || anoU % 100 != 0)) && diaU<1 || diaU>29){
            while(diaU<1 || diaU>29){
              gotoxy(45,cont+2);
              cout<<"Dia informado é inválido!";
              Sleep(1000);
              gotoxy(44,cont+2);
              clreol();
              gotoxy(47,cont);
              clreol();

              gotoxy(47,cont);
              cout << "/";
              gotoxy(52,cont);
              cout << "/";
              gotoxy(44,cont);
              cout<<mesU;
              gotoxy(49,cont);
              cout<<anoU;
              gotoxy(54,cont);
              cin>>diaU;
            }
          }
          if((anoU % 4 != 0 && (anoU % 400 != 0 || anoU % 100 != 0)) && diaU<1 || diaU>28){
            while(diaU<1 || diaU>28){
              gotoxy(45,cont+2);
              cout<<"Dia informado é inválido!";
              Sleep(1000);
              gotoxy(44,cont+2);
              clreol();
              gotoxy(47,cont);
              clreol();
              gotoxy(47,cont);
              cout << "/";
              gotoxy(52,cont);
              cout << "/";
              gotoxy(44,cont);
              cout<<mesU;
              gotoxy(49,cont);
              cout<<anoU;
              gotoxy(54,cont);
              cin>>diaU;
              }
          }
        break;
        case 3:
          if(diaU<1 && diaU>31 ){
            dia31(diaU,mesU,anoU,cont);
          }
        break;
        case 4:
          if(diaU<1 && diaU>30){
            dia30(diaU,mesU,anoU,cont);
          }
        break;
        case 5:
          if(diaU<1 && diaU>31){
            dia31(diaU,mesU,anoU,cont);
            getch();
          }
        break;
        case 6:
          if(diaU<1 || diaU>30 ){
            dia30(diaU,mesU,anoU,cont);
            getch();
          }
        break;
        case 7:
          if(diaU<1 || diaU>31){
            dia31(diaU,mesU,anoU,cont);
            getch();
          }
        break;
        case 8:
          if(diaU<1 || diaU>31){
            dia31(diaU,mesU,anoU,cont);
            getch();
          }
        break;
        case 9:
          if(diaU<1 || diaU>30){
            dia30(diaU,mesU,anoU,cont);
            getch();
          }
        break;
        case 10:
          if(diaU<1 || diaU>31){
            dia31(diaU,mesU,anoU,cont);
          }
        break;
        case 11:
          if(diaU<1 || diaU>30){
            dia30(diaU,mesU,anoU,cont);
          }
        break;
        case 12:
          if(diaU<1 || diaU>31){
            dia31(diaU,mesU,anoU,cont);
          }
        break;
      default:
          gotoxy(42,cont+2);
          cout<<"Mes inválido!";
          Sleep(1000);
          gotoxy(42,cont);
          clreol();
          gotoxy(42,cont+2);
          clreol();
          gotoxy(47,cont);
          cout << "/";
          gotoxy(52,cont);
          cout << "/";
          gotoxy(44,cont);
          cout<<diaU;
          gotoxy(49,cont);
          cin>>mesU;
          gotoxy(54,cont);
          cout<<anoU;
      }

    }while(valida==0);

    while(anoU<anoC  || anoU>anoC+1){
        criaMenu(3,15,43,cont+5,COR_LETRA2,LIGHTRED);
        gotoxy(35,cont+3);
        cout<<"Ano informado é inválido, digite os dois últimos digitos ";
        if(anoU<anoC){
          gotoxy(45,cont+5);
          cout<<"Ano digitado já passou";
        }
        else{
          gotoxy(35,cont+5);
          cout<<"Ano digitado está muito distante ";
        }
          Sleep(2000);
          gotoxy(35,cont+3);
          clreol();
          gotoxy(45,cont+5);
          gotoxy(42,cont-3);
          clreol();
          criaMenu(3,15,43,cont-3,COR_FUNDO,COR_LETRA1);
          gotoxy(47,cont-3);
          cout << "/";
          gotoxy(52,cont-3);
          cout << "/";
          gotoxy(44,cont-3);
          cout<<diaU;
          gotoxy(49,cont-3);
          cout<<mesU;
          gotoxy(52,cont-3);
          cin>>anoU;
    }
    gotoxy(44,cont+4);
    cout<<"data é totalmente válida!!";
    getch();

}


void dia31(int &diaU, int mesU, int anoU,int cont){
   while(diaU<1 || diaU>31){
      gotoxy(45,cont+2);
      cout<<"Dia informado é inválido!";
      Sleep(1000);
      gotoxy(44,cont+2);
      clreol();
      gotoxy(47,cont);
      clreol();
      gotoxy(47,cont);
      cout << "/";
      gotoxy(52,cont);
      cout << "/";
      gotoxy(44,cont);
      cout<<mesU;
      gotoxy(49,cont);
      cout<<anoU;
      gotoxy(54,cont);
      cin>>diaU;
    }
}

void dia30(int &diaU, int mesU, int anoU,int cont){
   while(diaU<1 || diaU>30){
      gotoxy(45,cont+2);
      cout<<"Dia informado é inválido!";
      Sleep(1000);
      gotoxy(44,cont+2);
      clreol();
      gotoxy(47,cont);
      clreol();
      gotoxy(47,cont);
      cout << "/";
      gotoxy(52,cont);
      cout << "/";
      gotoxy(44,cont);
      cout<<mesU;
      gotoxy(49,cont);
      cout<<anoU;
      gotoxy(54,cont);
      cin>>diaU;
    }
}
