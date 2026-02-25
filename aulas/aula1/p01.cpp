#include <iostream>
#include <fstream> // biblioteca para manipulação de dados.

using namespace std;

int main()
{
  int nrEscolhido;
  ifstream dsArq;
  dsArq.open("numeros.txt"); // tentativa de abrir o arquivo.

  if (!dsArq) // Se não abriu o arquivo
  {
    cout << "Não foi possível abrir o arquivo!" << endl;
    exit(1);
  }

  while (dsArq >> nrEscolhido) // de bit a bit ele vai passando ao nrEscolhido
    cout << nrEscolhido * 3 << endl;

  dsArq.close();

  return 0;
}