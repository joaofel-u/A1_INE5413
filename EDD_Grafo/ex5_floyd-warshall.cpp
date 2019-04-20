#include "include/SimpleGraph.h"
#include <queue>

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
	

    // na hora de imprimir lembrar de utilizar vertice+1


	return 0;
}
