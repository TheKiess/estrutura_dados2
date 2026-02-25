#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
  ofstream dsTab;
  dsTab.open("tabela.txt");

  for (int i = 0; i < 100; i++)
    // dsTab << i << endl;
    dsTab << dec << i         << " "
          << hex << uppercase << i
          << endl; 

  dsTab.close(); 

  return 0;
}