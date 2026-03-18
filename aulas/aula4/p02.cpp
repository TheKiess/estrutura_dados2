#include <iostream>
#include <unordered_map>

using namespace std;

int main ()
{
  unordered_map<string, float> notas; // array simples com chave => valor;
  notas["fulano"]   = 9.5;
  notas["beltrano"] = 10;
  notas["ciclano"]  = 7.8;

  cout << notas["beltrano"]                        << endl // retornará o valor!
       << "Tamanho da estrutura: " << notas.size() << endl << endl;

  cout << notas["ele"] << endl; // Fazer isso adiciona, não fazer...

  cout << "Percorrendo a tabela hash" << endl;

  for(auto arrNotas : notas)
    cout << arrNotas.first << ": " << arrNotas.second << endl;

  return 0;
}