//Exemplo utilizando o unordered_set
//diferente do map o set armazena apenas chave 
//e não chave,valor
//ambos usam tabela hash;
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
  unordered_set<string> arrAlunos;
  arrAlunos.insert("fulano");
  arrAlunos.insert("beltrano");
  arrAlunos.insert("ciclana");

  cout << arrAlunos.size() << endl;;

  for(const auto& aluno: arrAlunos)
      cout << aluno << endl;

    //Buscar valores
    //o metodo find retorna um iterator para o elemento - caso encontre
    //Caso não encontre: retorna um iterator para o final do container
    if(arrAlunos.find("fulano") != arrAlunos.end())
        cout << "Esta no container\n";
    else
        cout << "Não esta!\n";
    

    return 0 ;
}