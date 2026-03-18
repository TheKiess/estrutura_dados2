#include <cstdlib> // apenas para gerar numeros randomicos
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
  unordered_set<int> conjunto;
  conjunto.max_load_factor(1);

  for(int i=0; i<100;i++)
  {
    conjunto.insert(rand());
    cout << i                   << endl
         << "Size: "            << conjunto.size()            << endl
         << "Bucket count: "    << conjunto.bucket_count()    << endl
         << "Load factor: "     << conjunto.load_factor()     << endl
         << "Max load factor: " << conjunto.max_load_factor() << endl;
  } 

  for(int i = 0; i < conjunto.bucket_count(); i++)
    cout << " " << i << ": " << conjunto.bucket_size(i) << endl;

  return 0;
}