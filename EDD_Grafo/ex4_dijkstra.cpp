#include "include/SimpleGraph.h"
#include <queue>

#include <unistd.h>

using namespace std;


int main(int argc, char const *argv[]) {

	// Checagem do arquivo passado por parametro
    ifstream myReadFile;
    if (argc < 3) {
        cout << "Insira o nome do arquivo / vertice inicial\n";
        return 1;
    }


    // criacao do grafo e leitura do arquivo de entrada para populacao
    GrafoSimples* grafo = new GrafoSimples();

    if (!grafo->ler(argv[1])) {
        cout << "Arquivo inexistente\n";
    }


	// definicao do vertice de origem da busca
	int s = stoi(argv[2]);
    int num_vertices = grafo->qtdVertices();

	// verifica se o vertice passado por parametro existe dentro do grafo
	if (s > num_vertices || s == 0) {
		cout << "O vértice " << s << " não existe no grafo " << argv[1] << endl;
		return 1;
	}


	// Dijkstra
    // Inicializacao
    int* d = new int[num_vertices+1];
    int* a = new int[num_vertices+1];
    bool* c = new bool[num_vertices+1];

    for (int i = 0; i <= num_vertices; i++) {
        d[i] = INFINITE_INT;
        c[i] = false;
    }

    d[s] = 0;
    a[s] = NULL;

    bool existeCvFalse = true;
    while(existeCvFalse) {

        int min = INFINITE_INT;
        int min_index;
        for (int v = 1; v <= num_vertices; v++) {
            if (!c[v] && (d[v] < min)) {
                min = d[v];
                min_index = v;
            }
        }

        int u = min_index;
        c[u] = true;

        for (int v : grafo->vizinhos(u)) {
            if (!c[v]) {
                int sumDUW = d[u] + grafo->peso(u,v);
                if (d[v] > sumDUW) {
                    d[v] = sumDUW;
                    a[v] = u;
                }
            }
        }

        existeCvFalse = false;
        //cout << "u: " << u << " | c[u]: " << c[u] << "\n";
        for(int v = 1; v <= num_vertices; v++){
            if (!c[v]) {
                existeCvFalse = true;
                //cout << "false: " << v << "\n";
                break;
            }
        }
        //sleep(1);
    }

    for(int v = 1; v <= num_vertices; v++){
//        cout << "a: " << a[v] << " | ";
    }

    // Saida
    for (int i = 1; i <= num_vertices; i++) {

        int aux = i;
        string caminho = to_string(aux);
        //cout << "\n" << i << ": ";
        while(aux != s) {
            //cout << aux << ", ";
            // pegar de tras ra frente
            aux = a[aux];
            caminho = to_string(aux) + "," + caminho;
            //cout << "\n" << i << "----------\n";
        }
        //caminho = to_string(s) + ", " + caminho;
        //cout << s << "; d = " << d[i];
        cout << i << ": " << caminho << "; d=" << d[i] << "\n";
        //cout << "\n" << i << " : " << caminho << "; d=" << d[i];
        //cout << "aaa";
    }
    cout << "\n";
    // na hora de imprimir lembrar de utilizar vertice+1


	return 0;
}
