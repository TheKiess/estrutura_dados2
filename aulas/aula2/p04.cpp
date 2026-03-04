#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

int main()
{
  cout << "Digite o nome do arquivo: ";

  string nmArquivo; getline(cin, nmArquivo);
  ifstream dsArq(nmArquivo);

  char dsChar;
  int arrCont[256] = {};

  if (!dsArq)
  {
    cout << "Erro ao abrir o arquivo. Favor verificar" << endl;
    return 1;
  }

  while (dsArq.get(dsChar))
    arrCont[int(dsChar)]++;

  ofstream dsTab("contagem_caracteres.csv");

  if (!dsTab)
  {
    cout << "Erro ao criar o arquivo. Favor verificar" << endl;
    return 1;
  }

  for (int i = 0; i < 256; i++)
    if (arrCont[i] > 0)
      dsTab << char(i) << ";" << arrCont[i] << ";" << endl;
      
  dsTab.close();
  return 0;
}