
#define COR_LOGO CYAN
#define COR_FUNDO LIGHTGRAY
#define COR_LETRA1 BLACK
#define COR_LETRA2 WHITE

void logo();
void barraNotificacao();

void criaMenu(int altura,int largura,int cordX,int cordY,int corFundo,int corLetra){
int i,j;

    for (i=0;i<altura;i++){
          for (j=0;j<largura;j++){
            textbackground(corFundo);
            gotoxy(cordX+j,cordY+i);
            cout<<" ";
          }
    }
  textcolor(corLetra);
}


void logo(){
  criaMenu(5,100,1,1,COR_LOGO,COR_LETRA2);
  gotoxy(39,3);
  cout<<"CLÍNICA - SECRETARIA";

}


void barraNotificacao(){
  char horas[1];
  _strtime(horas);
  criaMenu(3,4,94,7,COR_LETRA2,GREEN);
  gotoxy(95,8);
  cout<<"ON";
  criaMenu(3,10,84,7,COR_LOGO,COR_LETRA2);
  gotoxy(85,8);
  cout<<horas;
}


