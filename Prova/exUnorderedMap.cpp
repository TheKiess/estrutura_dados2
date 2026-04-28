// unordered_map: chave → valor via hash table.
// Busca/inserção O(1) médio. Não mantém ordem.
// Use quando só precisa de acesso rápido por chave.
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

unordered_map<string, int> freq;

int main()
{
  freq["apple"]++;          // insere/incrementa
  freq["banana"] = 3;        // atribui direto
  freq["cherry"] += 2;       // incrementa por valor

  if (freq.count("apple"))   // 1 se existe, 0 se não
      freq.erase("apple");    // remove a chave

  cout << freq.size() << "\n"; // nº de pares

  for (auto& [k, v] : freq)   // ordem imprevisível
      cout << k << ": " << v << "\n";

  return 0;
}