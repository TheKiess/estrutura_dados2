#include <stack>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int N = 0; cin >> N;

  string dsPrimeiroConjunto,
         dsSegundoConjunto;
  queue<string> dsResposta;

  if (N <= 1001)
  {
    for (int i = 0; i < N; i++)
    {
      cin >> dsPrimeiroConjunto >> dsSegundoConjunto;

      int qtCharPrimeiro = dsPrimeiroConjunto.size(),
          qtCharSegundo  = dsSegundoConjunto.size();
      bool idEncaixo     = false;
      stack<char> PilhaChars;

      if (qtCharPrimeiro >= qtCharSegundo)
      {
        for (int i = 0; i < qtCharSegundo; i++)
          PilhaChars.push(dsSegundoConjunto[i]);

        for (int i = qtCharPrimeiro - 1; i >= qtCharPrimeiro - qtCharSegundo; i--)
        {
          if (dsPrimeiroConjunto[i] != PilhaChars.top())
            break;

          PilhaChars.pop();

          if (PilhaChars.empty())
          {
            dsResposta.push("encaixa");
            idEncaixo = true;
          }
        }
      }

      if (!idEncaixo)
        dsResposta.push("nao encaixa");
    }

    while (!dsResposta.empty())
    {
      cout << dsResposta.front() << endl;
      dsResposta.pop();
    }
  }

  return 0;
}