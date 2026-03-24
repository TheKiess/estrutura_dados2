#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  int N; cin >> N;

  for (int i = 0; i < N; i++)
  {
    int M; cin >> M;

    vector<string> arrProdutos(M);
    vector<double> vlPrecos(M);

    for (int j = 0; j < M; j++)
      cin >> arrProdutos[j] >> vlPrecos[j];

    int p; cin >> p;

    double vlTotal = 0.0;

    for (int j = 0; j < p; j++)
    {
      string dsProduto;
      int qtProduto;
      cin >> dsProduto >> qtProduto;

      for (int k = 0; k < M; k++)
        if (arrProdutos[k] == dsProduto)
        {
          vlTotal += vlPrecos[k] * qtProduto;
          break;
        }
    }

    cout << "R$ " << fixed << setprecision(2) << vlTotal << endl;
  }

  return 0;
}