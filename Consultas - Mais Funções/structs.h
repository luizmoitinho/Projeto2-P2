typedef struct{
    int cod; // 0-Deletado ou N�o cadastrado | 1-Cadastrado
    int senha;
    char nome[50];
    int idade;
    int cpf;
    char endereco[25];
    double telefone;
    char cargo[11];
    int crm;  // Primary key {Medico}
    int idSecrt; // Primary key {Secret�ria}
    double taxa; // Para M�dico valor da Consulta | Para Secret�ria valor do sal�rio

    char especialidade[20];
    //int diaConsulta[5]={0,0,0,0,0};
    int turno;// 0 - manh� | 1  - tarde | manh�/tarde

    //int numConsultaDia[3]; // Se for 0 n�mero de consultas manh�... | 1 - n�mero de consultas pela tarde | 2 - n�mero de consultas manh� e tarde
    int totConsulta; // Total de consultas atendidas pelo m�dico
}clinica;

typedef struct{
  char nome[40];
  char cpf[12];
  char sexo[15];
  char dataNasc[15];
  char telefone[20];
  char nomePai[40];
  char nomeMae[40];
  char endRua[40];
  char endBairro[30];
  char cidade[25];
  char UF[3];
  char email[40];
  char obs[50];
  char cep[10];
  int ativo;
}cliente;

typedef struct{
  int crm;
  char cpfCli[12];
  char dataConsulta[10];
  int turno;
  int ativo;
  int tipoConsulta; // se  1 = retorno, se 2 = consulta
}consulta;
