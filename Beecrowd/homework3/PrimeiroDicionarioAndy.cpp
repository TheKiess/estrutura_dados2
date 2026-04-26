#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

struct objPalavra
{
  string dsPalavra;
};

bool sortMaior(const objPalavra &a, const objPalavra &b)
{
  return a.dsPalavra < b.dsPalavra;
}

int main()
{
  vector<objPalavra> arrPalavra;
  char dsChar;
  string dsPalavraCompleta;

  while (cin.get(dsChar))
  {
    bool idAcho = false;
    objPalavra Palavra;

    if (isalpha(dsChar))
      dsPalavraCompleta += tolower(dsChar);
    else if (dsPalavraCompleta.size() > 0)
    {
      Palavra.dsPalavra = dsPalavraCompleta;

      for (objPalavra &dsPalavraResposta : arrPalavra)
      {
        if (dsPalavraCompleta == dsPalavraResposta.dsPalavra)
        {
          idAcho = true;
          break;
        }
      }

      if (!idAcho)
        arrPalavra.push_back(Palavra);

      dsPalavraCompleta.clear();
    }
  }

  sort(arrPalavra.begin(), arrPalavra.end(), sortMaior);

  for (objPalavra &dsPalavraResposta : arrPalavra)
    cout << dsPalavraResposta.dsPalavra << endl;

  return 0;
}