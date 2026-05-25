#include <iostream>
#include <vector>

using namespace std;

bool verificarCaminho(vector<vector<bool>>& arrTunel, vector<int>& arrCaminho)
{
  int qtSaloesCaminho = arrCaminho.size();

  for (int i = 0; i < qtSaloesCaminho - 1; i++)
    if (!arrTunel[arrCaminho[i]][arrCaminho[i + 1]])
      return false;

  return true;
}

int main()
{
  int qtSaloes, qtTuneis;
  cin >> qtSaloes >> qtTuneis;

  vector<vector<bool>> arrTunel(qtSaloes + 1, vector<bool>(qtSaloes + 1, false));

  for (int i = 0; i < qtTuneis; i++)
  {
    int nrX,
        nrY; cin >> nrX >> nrY;

    arrTunel[nrX][nrY] = true;
    arrTunel[nrY][nrX] = true;
  }

  int qtSugestoes,
      qtPossiveis = 0;

  cin >> qtSugestoes;

  for (int i = 0; i < qtSugestoes; i++)
  {
    int qtSaloesCaminho;
    cin >> qtSaloesCaminho;

    vector<int> arrCaminho(qtSaloesCaminho);

    for (int j = 0; j < qtSaloesCaminho; j++)
      cin >> arrCaminho[j];

    if (verificarCaminho(arrTunel, arrCaminho))
      qtPossiveis++;
  }

  cout << qtPossiveis << endl;

  return 0;
}