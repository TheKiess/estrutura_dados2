#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int nrRepeticoes = 0; cin >> nrRepeticoes;
  queue<int> nrResposta;
  
  for (int i = 0; i < nrRepeticoes; i++)
  {
    string dsConta; cin >> dsConta;
    char dsLetra = dsConta[1];

    if (dsConta.size() == 3 && isalpha(dsLetra))
    {
      int nrPrimeiro = dsConta[0] - '0', 
          nrSegundo  = dsConta[2] - '0';

      if (nrPrimeiro == nrSegundo)
        nrResposta.push(nrSegundo * nrPrimeiro);
      else if (isupper(dsLetra))
        nrResposta.push(nrSegundo - nrPrimeiro);
      else if (islower(dsLetra))
        nrResposta.push(nrSegundo + nrPrimeiro);
    }
  }

  while (!nrResposta.empty())
  {
    cout << nrResposta.front() << endl;
    nrResposta.pop();
  }


  return 0;
}