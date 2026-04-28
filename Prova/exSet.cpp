// set: conjunto via árvore rubro-negra.
// Sem duplicatas, elementos sempre em ordem crescente.
// Use quando precisar do menor/maior ou iterar em ordem.
#include <set>
#include <string>
#include <iostream>


using namespace std;

set<int> nums;

int main()
{
  nums.insert(30);
  nums.insert(10);
  nums.insert(20);
  nums.insert(10);  // ignorado: já existe

  cout << *nums.begin()  << "\n"; // menor: 10
  cout << *nums.rbegin() << "\n"; // maior: 30

  // lower_bound: primeiro elemento >= valor
  auto it = nums.lower_bound(15); // aponta para 20

  nums.erase(10);

  for (int x : nums)   // sai em ordem: 20, 30
    cout << x << "\n";

  return 0;
}