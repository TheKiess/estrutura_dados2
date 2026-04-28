// map: chave → valor via árvore rubro-negra.
// Busca/inserção O(log n). Chaves sempre ordenadas.
// Use quando precisar iterar em ordem ou range queries.
#include <map>
#include <string>
#include <iostream>

using namespace std;

map<string, int> score;

int main ()
{
  score["alice"] = 95;
  score["bob"]   = 87;
  score["carol"] = 91;

  // find retorna iterator; end() = não achou
  auto it = score.find("bob");
  if (it != score.end())
    score.erase(it);           // erase por iterator é O(1)

  // lower_bound: primeiro elemento >= chave
  auto lb = score.lower_bound("b");

  for (auto& [k, v] : score)   // sai em ordem: alice, carol
    cout << k << ": " << v << "\n";

  return 0;
}