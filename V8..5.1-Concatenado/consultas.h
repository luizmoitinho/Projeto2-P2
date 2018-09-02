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
bool dma(int &diaU, int &mesU, int &anoU,int cont);


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

        criaMenu(1,5,83,24,COR_LOGO,COR_LETRA2);
        gotoxy(84,24);
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

    do{
        gotoxy(40,25);
        cout<<"Selecione uma opcao: ";
        cin >> *opc;

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
                criaMenu(3,8,61,24,COR_LOGO,COR_LETRA2);
                gotoxy(61,25);
                textcolor(RED);
                cout << "INVÁLIDO";
                Sleep(1000);
                textcolor(WHITE);
                criaMenu(3,8,61,24,COR_LOGO,COR_LETRA2);
                break;
        }
    }while(*opc != '1' && *opc != '2' && *opc != '3');

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
                cout << "CRM Inválido!";
                Sleep(1000);
                criaMenu(1,13,62,18 + cont1 + 2, COR_LETRA2,COR_LETRA2);
            }

    }while(localizado == 0);

}

//=============================================================
void dataConsulta(int crm, char cpfCli[],int cpfSec, int cont){
     cliente lerCliente;
    clinica dadoMedico;
    consulta insereConsulta, readConsulta;
    char cpf[12],consultaData[11];
    int localizado=0,valida=0,turno,validaTurno=-1,numConsulta=0;
    int dia,mes,ano;
    char diaChar[2],mesChar[2],anoChar[2];
    fflush(stdin);
    ifstream lerArquivo,lerConsulta;
    ofstream criaArquivo;
    fstream criaConsulta;
    cont+=20;
    criaMenu(10,93,5,cont,COR_LETRA2,COR_LETRA1);
    gotoxy(37,cont);
    cout<<"Informe a data da consulta";
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
            if( crm== dadoMedico.crm)
            {
                validaTurno = dadoMedico.turno;
            }
            lerArquivo.read((char*)(&dadoMedico), sizeof(clinica));
        }
        lerArquivo.close();

        if (validaTurno==0)
        {
            gotoxy(32,cont+5);
            cout<<"Consulta marcada pela manhã";
        }
        else
        {
            if(validaTurno==1){
                gotoxy(32,cont+5);
                cout<<"Consulta marcada pela tarde";
            }
            else
            {
                do{
                    fflush(stdin);
                    gotoxy(45,cont+7);
                    cout<<"[0] - Manhã";
                    gotoxy(45,cont+8);
                    cout<<"[1] - Tarde";
                    gotoxy(42,cont+10);
                    cout<<"Digite o turno : ";
                    cin>>validaTurno;
                    if (validaTurno!=0 && validaTurno!=1)
                    {
                        gotoxy(45,cont+11);
                        cout<<"Turno inválido!";
                        Sleep(1000);
                        gotoxy(45,cont+11);
                        clreol();
                    }
                  }while(validaTurno!=0 && validaTurno!=1);

                  if (validaTurno==0){
                    gotoxy(45,cont+13);
                    cout<<"Consulta marcada pela manhã\n";
                  }
                  else{
                    gotoxy(45,cont+13);
                    cout<<"Consulta marcada pela tarde\n";
                  }
            }
                //fim do programa
                cout<<"\n\n";
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

void tratamentoData(int &diaU, int &mesU, int &anoU,int &cont){
    fflush(stdin);
    int diaC,mesC,anoC;
    int valida;
    char c[2];
    gotoxy(40,3);
    dateSystem(diaC, mesC, anoC);
    do{
        valida=0;
      switch(mesU){
        case 1:
          if(diaU<1 || diaU>31){
            gotoxy(45,cont);
            dia31(diaU,mesU,anoU,cont);
          }
        break;
        case 2:
          //no bissexto
          if((anoU % 4 == 0 && (anoU % 400 == 0 || anoU % 100 != 0)) && diaU<1 || diaU>29){
            while(diaU<1 || diaU>29){
              criaMenu(3,15,43,cont+3,COR_LETRA2,LIGHTRED);
              gotoxy(45,cont+3);
              cout<<"Dia informado é inválido!";
              Sleep(1000);
              textcolor(COR_LETRA1);
              criaMenu(3,15,43,cont,COR_FUNDO,COR_LETRA1);
              gotoxy(44,cont+3);
              clreol();
              gotoxy(47,cont-1);
              clreol();

              gotoxy(47,cont-1);
              cout << "/";
              gotoxy(52,cont-1);
              cout << "/";
              gotoxy(49,cont-1);
              cout<<mesU;
              gotoxy(54,cont-1);
              cout<<anoU;
              gotoxy(44,cont-1);
              cin>>diaU;
            }
          }
          if((anoU % 4 != 0 && (anoU % 400 != 0 || anoU % 100 != 0)) && diaU<1 || diaU>28){
            while(diaU<1 || diaU>28){
              criaMenu(3,15,43,cont+3,COR_LETRA2,LIGHTRED);
              gotoxy(45,cont+3);
              cout<<"Dia informado é inválido!";
              Sleep(1000);
              textcolor(COR_LETRA1);
              criaMenu(3,15,43,cont,COR_FUNDO,COR_LETRA1);
              gotoxy(44,cont+3);
              clreol();
              gotoxy(47,cont-1);
              clreol();
              gotoxy(47,cont-1);
              cout << "/";
              gotoxy(52,cont-1);
              cout << "/";
              gotoxy(49,cont-1);
              cout<<mesU;
              gotoxy(54,cont-1);
              cout<<anoU;
              gotoxy(44,cont-1);
              cin>>diaU;
              }
          }
        break;
        case 3:
          if(diaU<1 || diaU>31 ){
            dia31(diaU,mesU,anoU,cont);
          }
        break;
        case 4:
          if(diaU<1 || diaU>30){
            dia30(diaU,mesU,anoU,cont);
          }
        break;
        case 5:
          if(diaU<1 || diaU>31){
            dia31(diaU,mesU,anoU,cont);
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
          criaMenu(3,15,43,cont+3,COR_LETRA2,LIGHTRED);
          gotoxy(42,cont+3);
          cout<<"Mes inválido!";
          textcolor(COR_LETRA1);
          criaMenu(3,15,43,cont,COR_FUNDO,COR_LETRA1);
          Sleep(1000);
          gotoxy(42,cont+3);
          clreol();

          gotoxy(42,cont-1);
          clreol();
          gotoxy(47,cont-1);
          cout << "/";
          gotoxy(52,cont-1);
          cout << "/";
          gotoxy(44,cont-1);
          cout<<diaU;
          gotoxy(54,cont-1);
          cout<<anoU;
          gotoxy(49,cont-1);
          cin>>mesU;

      }
		valida = dma(diaU,mesU,anoU,cont);
    }while(valida==0);

    while((anoU<anoC  &&  anoU>anoC+1) || valida==0){
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
        criaMenu(3,15,43,cont+1,COR_FUNDO,COR_LETRA1);
        Sleep(2000);
        gotoxy(35,cont+3);
        clreol();
        gotoxy(45,cont+5);
        gotoxy(42,cont-1);
        clreol();

		valida=dma(diaU,mesU,anoU,cont);
    }
    gotoxy(40,cont+4);
    cout<<"data é totalmente válida!!";
    Sleep(1000);
}
void dia31(int &diaU, int mesU, int anoU,int cont){
   while(diaU<1 || diaU>31){
      criaMenu(3,15,43,cont+3,COR_LETRA2,LIGHTRED);
      gotoxy(45,cont+3);
      cout<<"Dia informado é inválido!";
      Sleep(1000);
      textcolor(COR_LETRA1);
      criaMenu(3,15,43,cont,COR_FUNDO,COR_LETRA1);
      gotoxy(44,cont+3);
      clreol();
      gotoxy(47,cont-1);
      clreol();
      gotoxy(47,cont-1);
      cout << "/";
      gotoxy(52,cont-1);
      cout << "/";
      gotoxy(49,cont-1);
      cout<<mesU;
      gotoxy(54,cont-1);
      cout<<anoU;
      gotoxy(44,cont-1);
      cin>>diaU;
    }
}

void dia30(int &diaU, int mesU, int anoU,int cont){
   while(diaU<1 || diaU>30){
      criaMenu(3,15,43,cont+3,COR_LETRA2,LIGHTRED);
      gotoxy(45,cont+3);
      cout<<"Dia informado é inválido!";
      Sleep(1000);
      textcolor(COR_LETRA1);
      criaMenu(3,15,43,cont,COR_FUNDO,COR_LETRA1);
      gotoxy(44,cont+3);
      clreol();
      gotoxy(47,cont-1);
      clreol();
      gotoxy(47,cont-1);
      cout << "/";
      gotoxy(52,cont-1);
      cout << "/";
      gotoxy(44,cont-1);
      cout<<mesU;
      gotoxy(54,cont-1);
      cout<<anoU;
      gotoxy(47,cont-1);
      cin>>diaU;
    }
}

bool dma(int &diaU, int &mesU, int &anoU,int cont)
{
    int diaS, mesS, anoS;
    bool validar=1;

    dateSystem(diaS,mesS,anoS);

    while((diaU<diaS) && (mesU<mesS) || (anoU<=anoS))
    {
        gotoxy(37,cont+3);
        cout << "Data inferior a data atual!";
        Sleep(2000);

        gotoxy(37,cont+3);
        cout << "                           ";

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

    return validar;
}
