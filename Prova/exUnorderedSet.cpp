// unordered_set: conjunto via hash table.
// Sem duplicatas, sem ordem. Busca/inserção O(1) médio.
// Use para checar existência rapidamente.
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

unordered_set<int> visited;

int main()
{
  visited.insert(10);
  visited.insert(20);
  visited.insert(10);  // ignorado: já existe

  if (!visited.count(30))    // ainda não visitado?
    visited.insert(30);

  visited.erase(20);          // remove elemento

  cout << visited.size() << "\n"; // 2

  for (int x : visited)        // ordem imprevisível
    cout << x << "\n";

  return 0;
}