#include <iostream>
#include <list>
#include <string>

#define HASH_TABLE_SIZE 10

using namespace std;

struct Aluno
{
  string nm_aluno;
  int nr_matricula;
  string ds_email;
};

list<Aluno> hashTable[HASH_TABLE_SIZE];

int funcao_dispercao(int nrMatricula)
{
  return nrMatricula % HASH_TABLE_SIZE;
}

void inserirAluno(Aluno objAluno)
{
  hashTable[funcao_dispercao(objAluno.nr_matricula)].push_back(objAluno);
}

Aluno buscarAluno(int nrMatricula)
{
  int nrIndice = funcao_dispercao(nrMatricula);

  for (auto it = hashTable[nrIndice].begin(); it != hashTable[nrIndice].end(); it++)
    if (it->nr_matricula == nrMatricula)
      return *it; // ponteiro volta o valor, no caso, o Aluno...

  return Aluno();
}

void removerAluno(int nrMatricula)
{
  int nrIndice = funcao_dispercao(nrMatricula);

  for (auto it = hashTable[nrIndice].begin(); it != hashTable[nrIndice].end(); it++)
    if (it->nr_matricula == nrMatricula)
    {
      hashTable[nrIndice].erase(it);
      break;
    }
}

void imprimirAluno()
{
  for (int i = 0; i < HASH_TABLE_SIZE; i++)
    for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++)
    {
      cout << "Matricula: " << it->nr_matricula << endl
           << "Nome: "      << it->nm_aluno     << endl
           << "Email: "     << it->ds_email     << endl;
    }
}

int main()
{
  Aluno aluno1 = {"Emanuel", 1, "emanuel@email.com"};
  Aluno aluno2 = {"Carlos",  2, "carlos@email.com"};
  Aluno aluno3 = {"Rafael",  3, "rafael@email.com"};
  Aluno aluno4 = {"Joaquim", 4, "joaquim@email.com"};
  Aluno aluno5 = {"Gustavo", 5, "gustavo@email.com"};

  inserirAluno(aluno1);
  inserirAluno(aluno2);
  inserirAluno(aluno3);
  inserirAluno(aluno4);
  inserirAluno(aluno5);

  Aluno objAlunoEncontrado = buscarAluno(aluno1.nr_matricula);

  if (objAlunoEncontrado.nm_aluno.empty())
  {
    cout << "Aluno não encontrado!" << endl;
    return 1;
  }

  cout << "Nome: "      << objAlunoEncontrado.nm_aluno     << endl
       << "Matrícula: " << objAlunoEncontrado.nr_matricula << endl
       << "Email: "     << objAlunoEncontrado.ds_email     << endl;

  imprimirAluno();
  removerAluno(2);
  imprimirAluno();

  return 0;
}