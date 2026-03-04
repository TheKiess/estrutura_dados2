#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

int main()
{
  ifstream dsArq("gpl3.txt");
  char dsChar;
  int qtLetras  = 0,
      qtDigitos = 0, 
      qtSpace   = 0,
      qtOutros  = 0,
      qtTotalCh = 0;

  if (!dsArq)
  {
    cout << "Erro ao abrir o arquivo. Favor verificar" << endl;
    return 1;
  }

  while (dsArq.get(dsChar))
  {
    if (isalpha(dsChar))
      qtLetras++;
    else if (isdigit(dsChar))
      qtDigitos++;
    else if (isspace(dsChar))
      qtSpace++;
    else
      qtOutros++;
    
    qtTotalCh++;
  }

  dsArq.close();

  cout << "Quantidade de Letras: "            << qtLetras
       << " (" << fixed << setprecision(2)    << qtLetras  * 100.0/qtTotalCh << "%)" << endl
       << "Quantidade de caracteres: "        << qtDigitos
       << " (" << fixed << setprecision(2)    << qtDigitos * 100.0/qtTotalCh << "%)" << endl
       << "Quantidade de Espaços em branco: " << qtSpace
       << " (" << fixed << setprecision(2)    << qtSpace   * 100.0/qtTotalCh << "%)" << endl
       << "Restante: "                        << qtOutros
       << " (" << fixed << setprecision(2)    << qtOutros  * 100.0/qtTotalCh << "%)" << endl
       << "Quantidade Total de caracteres: "  << qtTotalCh                           << endl;

  return 0;
}