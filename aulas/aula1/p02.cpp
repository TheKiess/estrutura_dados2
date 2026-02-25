#include <iostream>
#include <fstream> // biblioteca para manipulação de dados.

using namespace std;

int main()
{
  int nrEscolhido;

  cout << "Digite o nome do arquivo" << endl;
  string nmArquivo; getline(cin, nmArquivo);

  ifstream dsArq;
  dsArq.open("concat/" + nmArquivo); // tentativa de abrir o arquivo dentro.

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