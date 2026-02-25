#include <iostream>
#include <fstream> // biblioteca para manipulação de dados.

using namespace std;

int main()
{
  string nrLinha; // Aqui pegará a string

  cout << "Digite o nome do arquivo" << endl;
  string nmArquivo; getline(cin, nmArquivo);

  ifstream dsArq;
  dsArq.open("concat/" + nmArquivo); // tentativa de abrir o arquivo dentr.

  if (!dsArq) // Se não abriu o arquivo
  {
    cout << "Não foi possível abrir o arquivo!" << endl;
    exit(1);
  }

  while (getline(dsArq, nrLinha)) // Aqui ele pegará toda a linha teste do numeros2.txt
    cout << nrLinha << endl;

  dsArq.close();

  return 0;
}