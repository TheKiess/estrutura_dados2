#include <queue>
#include <iostream>

using namespace std;

int main()
{
  queue<int> FilaEntrada;

  int N           = 0,
      nrEntrada   = 0,
      nrSaida     = 0,
      M           = 0,
      nrGambiarra = 1;

  bool idAtletaSaiu[100001] = {false};

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> nrEntrada;
    FilaEntrada.push(nrEntrada);
  }

  cin >> M;
  for (int j = 0; j < M; j++)
  {
    cin >> nrSaida;
    idAtletaSaiu[nrSaida] = true;
  }

  while (!FilaEntrada.empty())
  {
    if (!idAtletaSaiu[FilaEntrada.front()])
    {
      if (nrGambiarra != 1)
        cout << " ";

      cout << FilaEntrada.front();
      nrGambiarra++;
    }

    FilaEntrada.pop();
  }

  cout << endl;
  return 0;
}