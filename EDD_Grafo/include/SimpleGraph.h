#ifndef SIMPLEGRAPH_H
#define SIMPLEGRAPH_H

#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <limits>
#include<fstream>

using namespace std;

class GrafoSimples
{
private:
    vector< unordered_map<int, float> > adjs;
    vector<string> rotulos;
    int qtdArestas_;

public:
    GrafoSimples();
    ~GrafoSimples();

    // le o arquivop
    int readFile(string fileName);

    //retorna o id do vertice inserido
    int inserirVertice(string rotulo);

    //inserir nova aresta
    void inserirAresta(int u, int v, float peso);

    // imprime o grafo
    void imprimir();

    // retorna a quantidade de vertices do grafo
    int qtdVertices();

    // retorna a quantidade de arestas do grafo
    int qtdArestas();

    // retorna o grau de um vertice v
    int grau(int v);

    // retorna o rotulo de um vertice v
    string rotulo(int v);

    // retorna a lista de vizinhos de um vertice v
    vector<int> vizinhos(int v);

    // retorna true caso exista uma aresta de u para v
    bool haAresta(int u, int v);

    // retorna o peso da aresta que liga u e v
    float peso(int u, int v);
};

#endif // SIMPLEGRAPH_H
