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

objPalavra buscarPalavra(string dsPalavra, bool idIncrementarContagem = false)
{
  int nrIndice = hashfn(dsPalavra);

  for (auto& objPalavra : hashTable[nrIndice])
  {
    if (objPalavra.dsPalavra == dsPalavra)
    {
      if (idIncrementarContagem)
        objPalavra.qtContagem++;

      return objPalavra;
    }
  }

  return objPalavra();
}

int main()
{
  char dsChar;
  string dsPalavraCompleta;
  ifstream dsArq("clarissa.txt");

  while (dsArq.get(dsChar))
  {
    if (isalpha(dsChar))
      dsPalavraCompleta += tolower(dsChar);
    else if (dsPalavraCompleta.size() > 0)
    {
      objPalavra dsPalavraEncontrada = buscarPalavra(dsPalavraCompleta, true);
      
      auto nrIndice = hashfn(dsPalavraCompleta);

      if (dsPalavraEncontrada.dsPalavra.empty())
      {
        dsPalavraEncontrada.dsPalavra = dsPalavraCompleta;
        inserirPalavra(dsPalavraEncontrada);
      }

      dsPalavraCompleta.clear();
    }
  }

  dsArq.close();

  while (true)
  {
    cout << "Digite a palavra a ser buscada (ou '0' para encerrar): "; cin >> dsPalavraCompleta;

    if (dsPalavraCompleta == "0")
      break;

    objPalavra dsPalavraEncontrada = buscarPalavra(dsPalavraCompleta);

    if (dsPalavraEncontrada.dsPalavra.empty())
    {
      cout << "A palavra '" << dsPalavraCompleta << "' não foi encontrada." << endl;
      continue;
    }

    cout << "A palavra '"                  << dsPalavraEncontrada.dsPalavra << "' foi encontrada " 
         << dsPalavraEncontrada.qtContagem << " vezes."                     << endl;
  }

  return 0;
}