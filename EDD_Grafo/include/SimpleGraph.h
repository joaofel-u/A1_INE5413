#ifndef SIMPLEGRAPH_H
#define SIMPLEGRAPH_H

#include<vector>
#include<unordered_set>
#include <iostream>
using namespace std;

class GrafoSimples
{
    public:
        GrafoSimples();
        ~GrafoSimples();
        vector< unordered_set< int> > adjs;

        //retorna o id do vertice inserido
        int inserirVertice(){
            adjs.push_back( unordered_set<int>() );
        }

        //inserir nova aresta
        void inserirAresta(int u, int v){
            adjs[u].insert(v);
            adjs[v].insert(u);
        }

        //grau do vértice
        int grau(int v){
            return adjs[v].size();
        }
        //pertinencia de arestas
        bool pertAresta(int u, int v){
            return adjs[u].find(v) != adjs[u].end();

        }

        void imprimir(){
            for(int v=0; v<adjs.size(); v++){
                cout<<v<<": ";
                for (auto pr: adjs[v]){
                    cout<<pr<<",";
                }
                cout<<"\n";
            }
        }
};

#endif // SIMPLEGRAPH_H
