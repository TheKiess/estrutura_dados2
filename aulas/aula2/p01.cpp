#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream dsArq("gpl3.txt"); // Assim faz a mesma coisa do open;
  char dsChar;
  int qtChars = 0;

  if (!dsArq)
  {
    cout << "Erro ao abrir o arquivo. Favor verificar" << endl;
    return 1;
  }

  // while(dsArq >> dsPalavra) Palavra a palavra até o EoF (End of File)
  // while(getline(dsArq, nrLinha)) Linha a linha até o EoF
  while (dsArq.get(dsChar)) // Extrair um caracter.
  {
    cout << dsChar << endl;
    qtChars++;
  }

  dsArq.close();

  cout << "Quantidade de caracteres: " << qtChars << endl;

  return 0;
}