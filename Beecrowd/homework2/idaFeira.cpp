#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

int main()
{
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++)
  {
    int m;
    std::cin >> m;

    std::vector<std::string> produtos(m);
    std::vector<double> precos(m);

    for (int j = 0; j < m; j++)
    {
      std::cin >> produtos[j] >> precos[j];
    }

    int p;
    std::cin >> p;

    double total = 0.0;

    // Ler P produtos que Dona Parcinova deseja comprar
    for (int j = 0; j < p; j++)
    {
      std::string produto;
      int quantidade;
      std::cin >> produto >> quantidade;

      // Buscar o produto na lista
      for (int k = 0; k < m; k++)
      {
        if (produtos[k] == produto)
        {
          total += precos[k] * quantidade;
          break;
        }
      }
    }

    std::cout << "R$ " << std::fixed << std::setprecision(2) << total << std::endl;
  }

  return 0;
}