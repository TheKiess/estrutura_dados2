#include <iostream>
#include <map> // map é árvore, unordered_map é listas

using namespace std;

struct aluno
{
  string nmAluno;
  string dsEmail;
  int nrIdade;
};

int main()
{
  map<string, aluno> mapTable;
  string nmProduto;
  float vlPreco;

  while(cin >> nmProduto && nmProduto != "exit")
  {
  }

  for (auto objTable : mapTable)
    cout << objTable.first << " " << objTable.second << endl;

  return 0;
}