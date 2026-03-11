#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int N; cin >> N;
  queue<int> nrResposta;
  
  cin >> ws; // ACEITAR WHITESPACES!
  for (int i = 0; i < N; i++)
  {
    string dsFrase; getline(cin, dsFrase);

    int qtDiamanteEsquerda = 0,
        qtDiamanteDireita  = 0;

    for (int j = 0; j < dsFrase.size(); j++)
    {
      if (dsFrase[j] == '<')
        qtDiamanteEsquerda++;
      else if (dsFrase[j] == '>')
        if (qtDiamanteEsquerda > 0)
        {
          qtDiamanteEsquerda--;
          qtDiamanteDireita++;
        }
    }

    nrResposta.push(qtDiamanteDireita);
  }

  while (!nrResposta.empty())
  {
    cout << nrResposta.front() << endl;
    nrResposta.pop();
  }

  return 0;
}
