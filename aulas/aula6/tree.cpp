//BIblioteca de arvore
#include <string>
#include <algorithm>
#include <iostream>

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

  void show(node *root)
  {
    if (root->left == nullptr && root->right == nullptr)
      return;

    if (root->left != nullptr)
    {
      std::cout << "Nodo atual: "           << root->value       << std::endl;
      std::cout << "  Branch da esquerda: " << root->left->value << std::endl;
      show(root->left);
    }

    if (root->right != nullptr)
    {
      std::cout << "Nodo atual: "          << root->value        << std::endl;
      std::cout << "  Branch da direita: " << root->right->value << std::endl;
      show(root->right);
    }

    return;
  }
}