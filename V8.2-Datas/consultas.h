void dados(int cpf);
void cadConsulta(char cpfCli[],int cpfSec);
void cadastraClientes(char cpfCli[]);
void agendaConsulta(char cpfCli[],int cpfSec);
int mostraConsulta(int cpfSec,char cpfCli[]);
void mostraInfCliente(char cpf[],int cpfSec);//aqui o cpf não pode ser por referencia, Wedson!!
void consultaII(int crm, char cpfCli[],int cont);
void tratamentoData(/*int dia, int mes, int ano*/);
void dateSystem(string &diaS, string &mesS, string &anoS);
int converterParaInt(string str);


void consultas(int cpfSec)
{
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

void dados(int cpfSec)
{
    clinica lerSecretaria;
    fstream arquivo;
    arquivo.open("secretaria.txt",ios::in);

    arquivo.read((char *)(&lerSecretaria),sizeof(clinica));
    while(!arquivo.eof())
    {
        if(cpfSec == lerSecretaria.cpf)
        {
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
void cadConsulta(char cpfCli[],int cpfSec)
{
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
    while(verificaCadastro && !verificaCadastro.eof())
    {
        if(strcmp(cpfCli,lerClientes.cpf) == 0)
        {
            localizado=1;
            break;
        }
        verificaCadastro.read((char*)(&lerClientes), sizeof(cliente));
    }
    verificaCadastro.close();

        if (localizado==1)
        {
              /*
                Area destina a : Erick, Wedson, Daniel e Luiz
              */
              agendaConsulta(cpfCli,cpfSec);
        }
        else
        {
            /*
            Area destinada a : Liliane, ALessandra e Jessica
            */
            cadastraClientes(cpfCli);
            cadConsulta(cpfCli,cpfSec);
        }
}

void cadastraClientes(char cpfCli[])
{
    cliente cadCliente;
    ofstream preencheArquivo;
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

        preencheArquivo.open("clientes.txt", ios::out|ios::app);
          preencheArquivo.write((const char*)(&cadCliente), sizeof(cliente));
        preencheArquivo.close();

        criaMenu(2,20,64,33,COR_LETRA2,GREEN);
        gotoxy(30,33);
        cout<<"CADASTRO FINALIZADO COM SUCESSO!!";
        Sleep(2000);
}

void agendaConsulta(char cpfCli[],int cpfSec)
{
    int crm;
    char  *opc;
    char espec[20];
    opc = new char;

    criaMenu(4,93,5,16,COR_LOGO,COR_LETRA2);
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

    switch(*opc)
    {
        case '1':
            crm = mostraConsulta(cpfSec,cpfCli);
            consultaII(crm,cpfCli,cpfSec);
        break;

        case '2':
          //reagendar consulta
        break;

        case '3':
          //agendar retorno
        break;
    }
}

void mostraInfCliente(char cpfCli[],int cpfSec)
{
    ifstream lerCliente;
    lerCliente.open("clientes.txt", ios::in);
    cliente testeclientes;
    //MOSTRAR INFORMAÇÃO DO CLIENTE
    while( lerCliente && !lerCliente.eof())
    {
        if(strcmp(testeclientes.cpf, cpfCli) == 0)
        {
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

int mostraConsulta(int crm, char cpfCli[])
{
    char espec[20];
    char armazena[25][30], aux[20] = " ";// lembrar de deixar aux, espec e armazena como vetores dinâmicos

    int i = 0;
    int x = 7, y = 18;
    int soma = 10,secCRM,cont1=0,cont=0,leng=0;

    clinica testeclinica;
    ifstream lerConsultas;
    lerConsultas.open("medicos.txt", ios::in);

    //faz a busca das especialidades cadastradas e passa para um vetor de char auxiliar
    lerConsultas.read((char *) (&testeclinica), sizeof(clinica));
    while( lerConsultas && !lerConsultas.eof())
    {
        strcpy(armazena[i],testeclinica.especialidade);
        lerConsultas.read((char *) (&testeclinica), sizeof(clinica));
        i++;
    }
    lerConsultas.close();

    for(int j=0; j<i ;j++)
    {
        for(int k=0; k<i; k++)
        {
            if(strcmp(armazena[j],armazena[k])<0)
            {
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
            criaMenu(1, leng, 7 + cont, 18, COR_LOGO, COR_LETRA2);
            gotoxy(7 + cont,18);
            cout << armazena[j];
            cont = (leng + cont) + 5;

            if(x < 92)
            {
                x = x + strlen(armazena[j]) + 5;
            }
            else
            {
                y = y + 2;
                x = 7;
            }
        }
    }

//==================================================================================
    int localizar = 0;
    do{
    fflush(stdin);
    gotoxy(35,16);
    cout << "Informe a especialidade: ";
    cin.getline(espec,20);

    lerConsultas.open("medicos.txt", ios::in);
    lerConsultas.read((char *) (&testeclinica), sizeof(clinica));

    while(lerConsultas && !lerConsultas.eof())
    {
        if(strcmp(testeclinica.especialidade, espec) == 0)
        {

            gotoxy(60, 16);
            textcolor(GREEN);
            cout << "Profissão Válida!";
            Sleep(2000);
            textcolor(WHITE);
            localizar = 1;
            break;
        }
        lerConsultas.read((char*) (&testeclinica), sizeof(clinica));
    }
            gotoxy(60, 16);
            textcolor(RED);
            cout << "Profissão Inválida!";
            Sleep(2000);

        }while(localizar == 0);
        cout << "É valida";

    lerConsultas.close();

//=====================================================================================

    lerConsultas.open("medicos.txt", ios::in);
    criaMenu(14,93,5,16,COR_LETRA2,COR_LETRA1);

    lerConsultas.read((char *) (&testeclinica), sizeof(clinica));
    while( lerConsultas && !lerConsultas.eof())
    {
        if( strcmp(testeclinica.especialidade, espec) == 0)
        {

            criaMenu(5, 73, 15, 18 + cont1, COR_LOGO, COR_LETRA2);
            int cmp = 0;
            cmp = strlen(testeclinica.nome);
            gotoxy(50 - (cmp/2),19 + cont1);
            cout << "NOME: " << testeclinica.nome;
            gotoxy(50 - (cmp/2),20 + cont1);
            cout <<"CRM: " << testeclinica.crm;
            gotoxy(50 - (cmp/2),21 + cont1);
            cout <<"HORARIO: " << testeclinica.turno;
            cont1 = cont1 + 6;
        }
        lerConsultas.read((char *) (&testeclinica), sizeof(clinica));
    }

    lerConsultas.close();

//=====================================================================================

    lerConsultas.open("medicos.txt", ios::in);
    lerConsultas.read((char *) (&testeclinica), sizeof(clinica));

    gotoxy(50 - (22/2), 16 + cont1 + 2);
    cout << "INFORME CRM DESEJADO: ";
    fflush(stdin);
    cin >> secCRM;

    int localizado = 0;
    while(lerConsultas && !lerConsultas.eof())
    {
        if(testeclinica.crm == secCRM)
        {
            gotoxy(50 - (22/2), 16 + cont1 + 4);
            localizado = 1;
            return secCRM;
            break;
        }
        lerConsultas.read((char *) (&testeclinica), sizeof(clinica));
    }
    lerConsultas.close();
}

void consultaII(int crm, char cpfCli[], int cont)
{
    cliente lerCliente;
    clinica dadoMedico;
    consulta insereConsulta, readConsulta;

    char cpf[12],dataConsulta[11];

    //cout<<dia<<"/"<<mes<<"/"<<ano;
    //getch();
    //int crm;

    int localizado=0,valida=0,turno,validaTurno=-1,numConsulta=0;
    clrscr();
    fflush(stdin);

    ifstream lerArquivo,lerConsulta;
    ofstream criaArquivo;
    fstream criaConsulta;

//    cout<<"Data atual: "<<dataAtual<<endl;
    cout<<"\n\t\tInforme a data da consulta: ";
    //gotoxy();cout<<"/";  cout<<"/";
    cin.getline(dataConsulta,11);

//=====================================void dados(int cpf);=======================
    lerArquivo.open("consultas.txt",ios::in);
    lerArquivo.read((char*)(&readConsulta),sizeof(consulta));
    while(lerArquivo && !lerArquivo.eof())
    {
        if((crm == readConsulta.crm)&&(strcmp(dataConsulta,readConsulta.dataConsulta)==0)&&(turno == readConsulta.turno))
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
                strcpy(insereConsulta.dataConsulta,dataConsulta);
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

void tratamentoData(/*int dia, int mes, int ano*/)
{
    int diaU,mesU,anoU;
    int diaC,mesC,anoC;
    string diaS, mesS, anoS;
    char c[2];
    gotoxy(40,3);
    cout << "Informe a data: ";

    dateSystem(diaS, mesS, anoS);
    diaC=converterParaInt(diaS);
    mesC=converterParaInt(mesS);
    anoS=converterParaInt(anoS);
    do
    {
        gotoxy(42,5);
        cout << "/";
        gotoxy(45,5);
        cout << "/";
        gotoxy(40,5);
        cin>>diaU;
        if(diaU<diaC||diaU>31){
            gotoxy(40,7);
            cout<<"Dia invalido";
            Sleep(1000);
            gotoxy(40,5);
            clreol();
            gotoxy(40,7);
            clreol();      }
    }while(diaU<diaC||diaU>31);

    do
    {
        gotoxy(40,5);
        cout<<diaU;
        gotoxy(42,5);
        cout << "/";
        gotoxy(45,5);
        cout << "/";
        gotoxy(43,5);
        cin>>mesU;
        if(mesU<1||mesU>12){
            gotoxy(40,7);
            cout<<"Mes invalido";
            Sleep(1000);
            gotoxy(40,5);
            clreol();
            gotoxy(40,7);
            clreol();      }
    }while(mesU<1 || mesU>12);


    do
    {
        gotoxy(40,5);
        cout<<diaU;
        gotoxy(42,5);
        cout << "/";
        gotoxy(43,5);
        cout<<mesU;
        gotoxy(45,5);
        cout << "/";
        gotoxy(46,5);
        cin>>anoU;
        if((anoU<anoC || anoU>anoC+1) || (anoU<2000+anoC || anoU>2000+anoC+1))
        {
            gotoxy(40,7);
            cout<<"Ano invalido";
            Sleep(1000);
            gotoxy(40,5);
            clreol();
            gotoxy(40,7);
            clreol();
        }
    }while((anoU<anoC || anoU>anoC+1) || (anoU<2000+anoC || anoU>2000+anoC+1));

    gotoxy(46,5);
    cin>>anoU;
}
