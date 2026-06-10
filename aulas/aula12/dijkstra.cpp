#include <climits>
#include <algorithm>
#include "graph5x5.cpp"

int find_next(int arrNrDistancia[N], bool idVisitado[N])
{
  int nrMenorIndice = -1;
  int nrMaioIndice  = INT_MAX;

  for (int i = 0; i < N; i++)
  {
    if (!idVisitado[i] && arrNrDistancia[i] <= nrMaioIndice)
    {
      nrMaioIndice  = arrNrDistancia[i];
      nrMenorIndice = i;
    }
  }
  
  return nrMenorIndice;
}

void dijkstra(int graph[N][N], int origin, int arrNrDistancia[N], int arrNrPredecessor[N])
{
  bool idVisitado[N];

  std::fill_n(idVisitado,       N, false);
  std::fill_n(arrNrPredecessor, N, -1);
  std::fill_n(arrNrDistancia,   N, INT_MAX);

  arrNrDistancia[origin] = 0; // Custo para chegar na própria origem é zero;

  while(true)
  {
    int nrAtual = find_next(arrNrDistancia, idVisitado);

    if (nrAtual == -1)
      break;
    
    idVisitado[nrAtual] = true;

    for (int v = 0; v < N; v++)
    {
      if (
        graph[nrAtual][v] != 0 && !idVisitado[v] && arrNrDistancia[nrAtual] != INT_MAX &&
        arrNrDistancia[nrAtual] + graph[nrAtual][v] < arrNrDistancia[v]
      )
      {
        arrNrDistancia[v]   = arrNrDistancia[nrAtual] + graph[nrAtual][v];
        arrNrPredecessor[v] = nrAtual;
      }
    }
  }
}