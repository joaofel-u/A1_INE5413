#include "include/SimpleGraph.h"
#include <algorithm>
#include <list>

using namespace std;

bool buscarSubcicloEuleriano(GrafoSimples* g, int v, int** c, list<int>* ciclo);

int main(int argc, char const *argv[]) {

	// Checagem do arquivo passado por parametro
    ifstream myReadFile;
    if (argc < 2) {
        cout << "Insira o nome do arquivo\n";
        return 1;
    }


    // criacao do grafo e leitura do arquivo de entrada para populacao
    GrafoSimples* grafo = new GrafoSimples();

    if (!grafo->ler(argv[1])) {
        cout << "Arquivo inexistente\n";
    }


    int num_vertices = grafo->qtdVertices();
    int num_arestas = grafo->qtdArestas();

	// CICLO EULERIANO (algoritmo de Hierholzer)
    // Inicializacao
    int** c = new int*[num_vertices+1];

    // Inicializacao
    for (int i = 0; i <= num_vertices; i++)
        c[i] = new int[num_vertices+1];

    // populacao
    for (int i = 1; i <= num_vertices; i++) {
        for(int j = i; j <= num_vertices; j++) {
            if (grafo->haAresta(i, j)) {
                c[i][j] = 0;
                c[j][i] = 0;
            } else {
                c[i][j] = -1;
                c[j][i] = -1;
            }
        }

    }

    int v = 1;

    list<int>* ciclo = new list<int>();
    if(buscarSubcicloEuleriano(grafo, v, c, ciclo)) {
        string caminho;
        auto final = ciclo->end()--;
        auto it = ciclo->begin();

        for(; it != final; it++)
            caminho += to_string(*it) + ",";

        caminho += to_string(*it);

        cout << "1\n" << caminho << endl;
    } else {
        cout << "0\n";
    }

	return 0;
}

bool buscarSubcicloEuleriano(GrafoSimples* g, int v, int** c, list<int>* ciclo) {
    ciclo->push_back(v);
    int t = v;
    do {
        int u = -1;
        for (int viz : g->vizinhos(v)) {
            if (!c[viz][v]) {
                u = viz;
                break;
            }
        }

        // Só prossegue se existir uma aresta não-visitada conectada a ciclo.
        if (u == -1) {
            return false;
        } else {
            // {v,u} ← selecionar uma aresta e ∈ E tal que Ce=false
            // Caso entre no else, a aresta que satisfaz a condicao
            // acima, a aresta ja esta selecionada em u
            c[u][v] = 1;
            c[v][u] = 1;
            v = u;
            // Adiciona o vértice v ao final do ciclo.
            ciclo->push_back(v);
        }
    } while (v != t);


    // verifica se existem subciclos independentes dentro do ciclo maior
    for(auto it = ciclo->begin(); it != ciclo->end(); it++) {
        int w = *it;

        for (int viz : g->vizinhos(w)) {
            if (!c[viz][w]) {
                list<int>* subciclo = new list<int>();

                if (buscarSubcicloEuleriano(g, v, c, subciclo)) {
                    for(auto sub_it = (subciclo->begin())++; sub_it != subciclo->end(); sub_it++)
                        it = ciclo->insert(it, *sub_it);
                }
            }
        }
    }


    return true;
}
