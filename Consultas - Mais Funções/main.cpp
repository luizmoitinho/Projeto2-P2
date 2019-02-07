#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

#include<sstream>

#include <fstream>

#include <conio2.h>

#include<time.h>

using namespace std;
#include"structs.h"
#include"design.h"
#include"consultas.h"

int main(){
  setlocale(LC_ALL,"portuguese");
  //Chama a biblioteca do nosso grupo!!
  int cpf=521;
  consultas(cpf);
}
