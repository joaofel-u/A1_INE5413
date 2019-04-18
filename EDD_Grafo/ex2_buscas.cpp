#include "include/SimpleGraph.h"

using namespace std;


int main(int argc, char const *argv[]) {

	// Checagem do arquivo passado por parametro
    ifstream myReadFile;
    if (argc < 3) {
        cout << "Insira o nome do arquivo / vertice inicial\n";
        return 1;
    }

	// verificar se o construtor conseguiu criar o grafo e senao retornar erro


	// criacao do grafo e populacao do mesmo utilizando o metodo de leitura de arquivo (argv[1])
	GrafoSimples* grafo;
	int vertice_origem = stoi(argv[2]);

	// verifica se o vertice passado por parametro existe dentro do grafo
	if (vertice_origem > grafo->qtdVertices()) {
		cout << "O vértice " << vertice_origem << " não existe no grafo " << argv[1] << endl;
		return 1;
	}


	// busca em largura
	


	return 0;
}
