#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include<sstream>
#include <fstream>
#include <conio2.h>
#include<time.h>
using namespace std;

#include"structsConsultas.h"
#include"designConsultas.h"
#include"fnConsultas.h"

int main(){
  setlocale(LC_ALL,"portuguese");
  //Chama a biblioteca do nosso grupo!!
  int *cpf;
  cpf = new int;
  *cpf =521;
  consultas(cpf);
}
