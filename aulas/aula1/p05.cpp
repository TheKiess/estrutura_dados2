#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ofstream dsTab;
  dsTab.open("tabela.csv");

  for(int i = 0; i < 100; i++)
        dsTab << dec    << i         << ";" 
              << i * 10 << ";" 
              << hex    << uppercase << i
              << endl;

  dsTab.close();

  return 0;
}