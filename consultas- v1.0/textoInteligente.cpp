#include<iostream>
#include<conio2.h>
#include<stdio.h>
using namespace std;



int main(){
  int x,y,i;
  char a,palavra[20];
  x=30;
  y=10;
  i=0;


  while(a=getchar()){
    palavra[i]=a;
    gotoxy(x,y);
    cout<<a;
    i++;
    x++;
    if (x>40){
      x=30;
      y++;
    }

  }


}
