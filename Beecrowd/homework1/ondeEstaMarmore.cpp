#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N      = 0, 
      Q      = 0,
      nrCaso = 1;

  while (cin >> N >> Q && (N != 0 || Q != 0))
  {
    vector<int> arrMarmores(N); // Vetor (array) com a quantidade de mármores

    for (int i = 0; i < N; i++)
      cin >> arrMarmores[i];

    sort(arrMarmores.begin(), arrMarmores.end());

    cout << "CASE# " << nrCaso++ << ":" << endl;

    for (int i = 0; i < Q; i++)
    {
      int nrConsulta; cin >> nrConsulta;

      /* lower_bound serve para apontar para o primeiro índice que visualizar (nesse caso o nrConsulta), ele deve ser chamado como interator... */
      auto pontInterador = lower_bound(arrMarmores.begin(), arrMarmores.end(), nrConsulta);

      if (pontInterador != arrMarmores.end() && *pontInterador == nrConsulta)
        cout << nrConsulta << " found at " << (pontInterador - arrMarmores.begin()) + 1 << endl;
      else
        cout << nrConsulta << " not found" << endl;
    }
  }

  return 0;
}