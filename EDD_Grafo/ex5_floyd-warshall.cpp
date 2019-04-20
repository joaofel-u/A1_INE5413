#include "include/SimpleGraph.h"
#include <algorithm>

using namespace std;


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

	// FLOYD-WARSHALL
	// Inicializacao da matriz
	float** d = new float*[num_vertices];
	for (int i = 0; i < num_vertices; i++)
		d[i] = new float[num_vertices];

	for (int i = 0; i < num_vertices; i++) {
		for (int j = i; j < num_vertices; j++) {
			float peso = grafo->peso(i+1, j+1);
			d[i][j] = peso;
			d[j][i] = peso;
		}
	}

	// Fluxo principal
	for (int k = 0; k < num_vertices; k++) {
		for (int i = 0; i < num_vertices; i++) {
			for (int j = i; j < num_vertices; j++) {
				float val = min(d[i][j], (d[i][k] + d[k][j]));
				d[i][j] = val;
				d[j][i] = val;
			}
		}
	}


	// Saida
	for (int i = 0; i < num_vertices; i++) {
		cout << (i+1) << ": ";

		for (int j = 0; j < num_vertices-1; j++) {
			cout << d[i][j] << ",";
		}

		cout << d[i][num_vertices-1] << endl;
	}


	return 0;
}
