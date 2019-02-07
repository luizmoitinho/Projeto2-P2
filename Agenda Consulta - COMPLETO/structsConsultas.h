
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
    int totConsulta=0; // Total de consultas atendidas pelo médico
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
  char obs[50];
  double taxa;
}consulta;
