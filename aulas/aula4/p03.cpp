#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
  unordered_map<int, string> alunos;
  alunos[9090] = "FULANO DE TAL";
  alunos[9091] = "BELTRANA";
  alunos[9092] = "CICLANA";

  int nrMatricula;

  cout << "Informe a matrícula (0 para sair)" << endl;

  while (cin >> nrMatricula && nrMatricula != 0)
  {
    if (alunos.count(nrMatricula) > 0)
      cout << alunos[nrMatricula] << endl;
    else
      cout << "Error 404" << endl;
  }

  return 0;
}