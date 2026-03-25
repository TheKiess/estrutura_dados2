#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <cctype>
#include <iomanip>

using namespace std;

const int HASH_SIZE = 97;

struct objPalavra
{
  string dsPalavra;
  int qtContagem = 0;
};

list<objPalavra> hashTable[HASH_SIZE];

size_t hashfn(const string $dsPalavra)
{
  size_t nrSoma = 0;
  for (auto dsChar : $dsPalavra)
    nrSoma += (size_t) dsChar;

  return nrSoma % HASH_SIZE;
}

void inserirPalavra(objPalavra obPalavra)
{
  hashTable[hashfn(obPalavra.dsPalavra)].push_back(obPalavra);
}

objPalavra buscarPalavra (string dsPalavra)
{
  int nrIndice = hashfn(dsPalavra);

  for (auto it = hashTable[nrIndice].begin(); it != hashTable[nrIndice].end(); it++)
  {
    if (it->dsPalavra == dsPalavra)
    {
      hashTable[nrIndice].erase(it);
      it->qtContagem++;
      return *it;
    }
  }

  return objPalavra();
}

int main()
{
  vector<objPalavra> arrPalavra;
  char dsChar;
  string dsPalavraCompleta;
  ifstream dsArq("teste.txt");

  while (dsArq.get(dsChar))
  {
    if (isalpha(dsChar))
      dsPalavraCompleta += tolower(dsChar);
    else if (dsPalavraCompleta.size() > 0)
    {
      objPalavra dsPalavraEncontrada = buscarPalavra(dsPalavraCompleta);
      
      if (dsPalavraEncontrada.dsPalavra.empty())
      {
        dsPalavraEncontrada.dsPalavra = dsPalavraCompleta;
        inserirPalavra(dsPalavraEncontrada);
      }


      cout << dsPalavraEncontrada.dsPalavra << " " << dsPalavraEncontrada.qtContagem << endl;

      dsPalavraCompleta.clear();
    }
  }

  dsArq.close();

  return 0;
}