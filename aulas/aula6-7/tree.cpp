//BIblioteca de arvore
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>

namespace tree
{
  //struct de cada nodo da árvore
  struct node
  {
      std::string value; //INFORMAÇÃO
      node *left;  //FILHO DA ESQUERDA
      node *right; //FILHO DA DIREITA
  };

  node *create_node(const std::string &str_value)
  {
    node *p  = new node;
    p->value = str_value;
    p->left  = nullptr;
    p->right = nullptr;

    return p;
  }

  //Função que retornar o tamanho da árvore
  //root é a raiz
  int height(node *root)
  {
    if(root == nullptr)
        return -1;

    return std::max(height(root->left),height(root->right))+1;
  }

  void showEstudo(node *root)
  {
    if (root->left == nullptr && root->right == nullptr)
      return;

    if (root->left != nullptr)
    {
      std::cout << "Nodo atual: "           << root->value       << std::endl;
      std::cout << "  Branch da esquerda: " << root->left->value << std::endl;
      showEstudo(root->left);
    }

    if (root->right != nullptr)
    {
      std::cout << "Nodo atual: "          << root->value        << std::endl;
      std::cout << "  Branch da direita: " << root->right->value << std::endl;
      showEstudo(root->right);
    }

    return;
  }

  void show(node *root)
  {
    if(!root)
      return;

    std::cout << root->value << std::endl;
    show(root->left);
    show(root->right);
  }

  void show2(node *root, std::string prefixo, int nivel)
  {
    if(!root)
      return;

    std::cout << std::string(nivel,' ') << prefixo << root->value << std::endl;
    show2(root->left, "/", nivel+1);
    show2(root ->right, "\\", nivel+1);
  }

  //Percorrer em pré ordem
  void DFS_pre(node *root)
  {
    if(!root)
      return;

    std::cout << root->value << " "; // Exibe o nodo
    DFS_pre(root->left);// chama a função passando o nodo filho a esq
    DFS_pre(root->right);// chama a função passando o nodo filho a dir
  }

  //Percorrer em in order
  void DFS_in(node *root)
  {
    if(!root) return;
    DFS_in(root->left);
    std::cout<< root->value << " ";
    DFS_in(root->right);
  }

  //Percorrer em post order
  void DFS_post(node *root)
  {
      if(!root)
        return;

      DFS_post(root->left);
      DFS_post(root->right);
      std::cout << root->value << " ";
  }

  void BST(node *root)
  {
    if (!root)
      return;

    std::queue<node*> fila; // Guardará o endereço de memória do nodo -> *

    fila.push(root);

    while (!fila.empty())
    {
      node *aux = fila.front();

      std::cout << aux->value << " ";
      fila.pop();

      if (aux->left != nullptr)
        fila.push(aux->left);

      if (aux->right != nullptr)
        fila.push(aux->right);
    }
  }

  // INSERÇÃO NA ÁRVORE
  void BST_insert(node *&root, std::string &dsValor)
  {
    if (!root)
      root = create_node(dsValor);
    else if (dsValor < root->value) // esquerda por ser menor
      BST_insert(root->left, dsValor);
    else if (dsValor > root->value) // maior a direita
      BST_insert(root->right, dsValor);
  }

  node *BST_find(node* root, const std::string &dsValor)
  {
    if(!root || root->value == dsValor)
      return root;

    if(dsValor < root->value)
        return BST_find(root->left, dsValor);

    return BST_find(root->right, dsValor);
  }

  void rotateRight(node *&pai)
  {
    node *novoPai  = pai->left;
    pai->left      = novoPai->right;
    novoPai->right = pai;
    pai            = novoPai;
  }

  void rotateLeft(node *&pai)
  {
    node *novoPai = pai->right;
    pai->right    = novoPai->left;
    novoPai->left = pai;
    pai           = novoPai;
  }

  void rotateLeftRight (node *&pai)
  {
    node *filho = pai->left;
    rotateLeft(filho);
    pai->left = filho;
    rotateRight(pai);
  }

  void rotateRightLeft(node *&pai)
  {
    node *filho = pai->right;
    rotateRight(filho);
    pai->right = filho;
    rotateLeft(pai);
  }
}