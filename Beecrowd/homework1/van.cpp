#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pessoa
{
  string nome;
    char regiao;
     int distancia;
};

bool comparar(const Pessoa &a, const Pessoa &b)
{
  return (a.distancia < b.distancia)                         || 
         (a.distancia == b.distancia && a.regiao < b.regiao) ||
         (a.distancia == b.distancia && a.regiao == b.regiao && a.nome < b.nome);
}

int main()
{
  int Q;

  while (cin >> Q)
  {
    vector<Pessoa> pessoas(Q);
  
    for (int i = 0; i < Q; i++)
      cin >> pessoas[i].nome >> pessoas[i].regiao >> pessoas[i].distancia;
  
    sort(pessoas.begin(), pessoas.end(), comparar);
  
    for (auto &p : pessoas)
      cout << p.nome << endl;
  }

  return 0;
}
