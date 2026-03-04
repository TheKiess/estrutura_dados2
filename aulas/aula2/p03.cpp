#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

int main()
{
  ifstream dsArq("gpl3.txt");
  char dsChar;
  int arrCont[256] = {};

  if (!dsArq)
  {
    cout << "Erro ao abrir o arquivo. Favor verificar" << endl;
    return 1;
  }

  while (dsArq.get(dsChar))
  {
    arrCont[int(dsChar)]++;

    //cout << dsChar << " - " << int(dsChar) << endl;
  }

  dsArq.close();

  for (int i = 0; i < 256; i++)
  {
    if (arrCont[i] > 0)
      cout << i << " - " << (isprint(i) ? char(i) : ' ') << " - " << arrCont[i] << endl; // Não são printáveis; 
  }

  return 0;
}