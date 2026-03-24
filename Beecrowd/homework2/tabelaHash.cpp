#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
  int N; cin >> N;

  while (N--)
  {
    int M, C; cin >> M >> C;

    unordered_map<int, vector<int>> arrTabela;

    for (int i = 0; i < M; i++)
      arrTabela[i] = vector<int>();

    for (int i = 0; i < C; i++)
    {
      int X; cin >> X;

      int nrIndice = X % M;
      arrTabela[nrIndice].push_back(X);
    }

    for (int i = 0; i < M; i++)
    {
      cout << i << " -> ";

      for (int valor : arrTabela[i])
        cout << valor << " -> ";

      cout << "\\" << endl; //Só funciona assim... Por causa da quebra de linha.
    }

    if (N)
      cout << endl;
  }

  return 0;
}