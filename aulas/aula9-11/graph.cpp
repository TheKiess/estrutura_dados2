/// biblioteca para grafos
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <queue>

namespace graph
{
  class digraph
  {
    private:
      // nodos do grafo - VERTÍCES
      struct node
      {
        std::string value; // valor
        std::vector<node*> links; //lista de ponteiros p/ os nodos vizinhos - ARESTAS
      };

      // tabela hash, que mapeia o rótulo do nó para o objeto node
      // <chave>, <valor>
      std::unordered_map<std::string, node> nodes;
      std::unordered_set<node*> visited;


    public:
     //Insere um novo nó no grafo com o rótulo s
      void insert_nodo(const std::string& s)
      {
        node aux;

        aux.value = s;
        nodes[s]  = aux;
      }

      //retorna a quantidade de nós (vertices) do grafo
      size_t size()
      {
        return nodes.size();
      }

      //busca um nó pelo seu rótulo e retorna o endereço do nodo 
      node* find(const std::string& s)
      {
        auto it = nodes.find(s); // Este find é do unnordered_map
        return it==nodes.end() ?  nullptr : &it->second;
      }

      //Insere um aresta dirigida de 'from' para 'to'
      bool insert_link(const std::string& from, const std::string& to)
      {
        auto objOrigem = find(from);

        if(objOrigem == nullptr)
          return false; // nó de origem ñ existe

        auto objDestino = find(to);

        if(objDestino == nullptr)
          return false; // nó de destino ñ existe

        objOrigem->links.push_back(objDestino); //Adiciona a aresta na lista de adjacencia
        return true;
      }

      // Numero de arestas que saem de um vértice
      size_t outdegree(const std::string& dsNode)
      {
        auto objOrigem = find(dsNode);

        if (objOrigem == nullptr)
          return 0;

        return objOrigem->links.size();
      }

      // Numero de arestas que chegam a um vértice
      size_t indegree(const std::string& dsNode)
      {
        auto objDestino  = find(dsNode);
        size_t qtArestas = 0;

        if (objDestino == nullptr)
          return qtArestas;

        for (auto objNode : nodes)
          for (auto arrVizinho : objNode.second.links)
            if (arrVizinho->value == objDestino->value)
              qtArestas++;

        return qtArestas;
      }

      // Numero total de arestas conectadas de um vértice
      size_t degree(const std::string& dsNode)
      {
        return outdegree(dsNode) + indegree(dsNode);
      }

      void export2dot(const std::string& fileName)
      {
        std::ofstream dot(fileName);

        dot << "digraph\n{";

        for (auto objNode : nodes)
        {
          dot << "\t" << objNode.first; 

          if (!objNode.second.links.empty())
          {
            dot << " -> {";

            for (auto arrVizinho : objNode.second.links)
              dot << arrVizinho->value << " ";

            dot << "}";
          }

          dot << ";\n";
        }

        dot << "}\n";
      }

      void draw()
      {
        export2dot("graphED2.dot");
        std::system("dot -Tx11 graphED2.dot");

      }

      void remove_link(const std::string &from, const std::string &to)
      {
        auto objOrigem = find(from);

        if(!objOrigem)
          return;

        auto objDestino = find(to);

        if(!objDestino)
          return;

        auto it = std::find(objOrigem->links.begin(),objOrigem->links.end(),objDestino);

        if(it == objOrigem->links.end())
           return;

        objOrigem->links.erase(it);
      }

      void remove_nodo(const std::string &key)
      {
        auto objChave = find(key);

        if(!objChave)
          return;

        for (auto &[k,nd]: nodes)
        {
          auto it = std::find(nd.links.begin(), nd.links.end(),objChave);

          if(it != nd.links.end())
            nd.links.erase(it);
        }

        nodes.erase(key);
      }

      void recursive_DFS(node* p, int level = 0)
      {
        if(visited.count(p) > 0)
          return;

        std::cout << std::string(level,'\t')
                  << p->value << std::endl;

        visited.insert(p);

        for (auto ln : p->links)
          recursive_DFS(ln,level+1);
      }

      void DFS_from(const std::string& s)
      {
        auto p = find(s);

        if(!p)
          return;

        visited.clear();
        recursive_DFS(p);
      }

      void BFS_from(const std::string& s)
      {
        auto p = find(s);

        if(!p)
          return;

        visited.clear();

        std::queue<node*> objFila;
        objFila.push(p);
        visited.insert(p);

        while (!objFila.empty())
        {
          auto current = objFila.front();
          objFila.pop();

          std::cout << current->value << " ";

          for (auto& vizinho : current->links)
            if (visited.count(vizinho) == 0)
            {
              objFila.push(vizinho);
              visited.insert(vizinho);
            }
        }

        std::cout << std::endl;
      }

      std::vector<std::string> shortest_path(const std::string& from, const std::string& to)
      {
        std::vector<std::string> arrCaminhos;

        auto objOrigem    = find(from),
             objDestino   = find(to);
        bool idEncontrado = false;

        if(!objOrigem || !objDestino)
          return arrCaminhos;

        std::unordered_map<node*, node*> source;
        std::queue<node*> filaNode;

        filaNode.push(objOrigem);
        source[objOrigem] = nullptr;

        while (!filaNode.empty())
        {
          auto current = filaNode.front();
          filaNode.pop();

          if (current == objDestino)
          {
            idEncontrado = true;
            break;
          }

          for (auto& vizinho : current->links)
          {
            if (source.count(vizinho) == 0)
            {
              filaNode.push(vizinho);
              source[vizinho] = current;
            }


          }
        }

        if (idEncontrado)
        {
          auto p = objDestino;
          while (p != nullptr)
          {
            arrCaminhos.push_back(p->value);
            p = source[p];
          }
        }
      }
  }; /// fim da classe digraph
} //fim do namespace