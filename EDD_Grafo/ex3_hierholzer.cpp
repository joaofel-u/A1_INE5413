#include "include/SimpleGraph.h"
#include <algorithm>
#include <vector> 

using namespace std;

vector<int> buscarSubcicloEuleriano(GrafoSimples* g, int v, int** c);

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
    int** c = new int*[num_vertices];

    for (int i = 1; i <= num_vertices; i++) {
        c[i] = new int[num_vertices];
        for(int j = i; j < num_vertices; j++) {
            if (grafo->haAresta(i, j)) {
                c[i][j] = 0;
                c[j][i] = 0;
            } else {
                c[i][j] = -1;
                c[j][i] = -1;
            }
        }
        
    }

    int v = 0;
    bool r = false;

    vector<int> ciclo;
    ciclo = buscarSubcicloEuleriano(grafo, v, c);

    // saida
    // testar se n tem nd no ciclo dai retorna false '0'
    string caminho;
    int tamanhoCiclo;
    for(int i = 0; i < tamanhoCiclo; i++) {
        caminho += ciclo[i];
    }
    


	return 0;
}

vector<int> buscarSubcicloEuleriano(GrafoSimples* g, int v, int** c) {
    int iteredorCiclo = -1;
    vector<int> ciclo = *new vector<int>();
    ciclo.push_back(v);
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
            return *new vector<int>();
        } else {
            // {v,u} ← selecionar uma aresta e ∈ E tal que Ce=false
            // Caso entre no else, a aresta que satisfaz a condicao
            // acima, a aresta ja esta selecionada em u
            c[u][v] = 1;
            c[v][u] = 1;
            v = u;
            // Adiciona o vértice v ao final do ciclo.
            ciclo.push_back(v);
        }
    } while (v != t);

    //ver q diabos significa aquele ultimo foreach
    for(int i = 0; i < ciclo.size(); i++) {
        int w = ciclo[i];
        for (int viz : g->vizinhos(w)) {
            if (!c[viz][w]) {
                
            }
        }
    }
    

    //ciclo
    return;
}

