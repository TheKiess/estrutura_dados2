#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <vector>

using namespace std;

struct objPalavra
{
  string dsPalavra;
  int qtContagem = 0;
};

int main()
{
  cout << "Digite o nome do arquivo: ";

  string nmArquivo; getline(cin, nmArquivo);
  ifstream dsArq(nmArquivo);
  vector<objPalavra> arrPalavra;
  char dsChar;
  string dsPalavraCompleta;

  if (!dsArq)
  {
    cout << "Erro ao abrir o arquivo. Favor verificar" << endl;
    return 1;
  }

  while (dsArq.get(dsChar))
  {
    bool idAcho = false;
    objPalavra Palavra;

    if (isalpha(dsChar))
      dsPalavraCompleta += tolower(dsChar);
    else if (dsPalavraCompleta.size() > 0)
    {
      Palavra.dsPalavra = dsPalavraCompleta;
      Palavra.qtContagem++;

      for (objPalavra &dsPalavraResposta : arrPalavra)
      {
        if (dsPalavraCompleta == dsPalavraResposta.dsPalavra)
        {
          dsPalavraResposta.qtContagem++;
          idAcho = true;
          break;
        }
      }

      if (!idAcho)
        arrPalavra.push_back(Palavra);

      dsPalavraCompleta.clear();
    }
  }

  ofstream dsTab("contagem_palavras.csv");

  if (!dsTab)
  {
    cout << "Erro ao criar o arquivo. Favor verificar" << endl;
    return 1;
  }

  for (objPalavra &dsPalavraResposta : arrPalavra)
      dsTab << dsPalavraResposta.dsPalavra << ";" << dsPalavraResposta.qtContagem << ";" << endl;
      
  dsTab.close();
  return 0;
}