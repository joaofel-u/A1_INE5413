#include "include/SimpleGraph.h"

using namespace std;


int main(int argc, char** argv) {

    GrafoSimples* grafo = new GrafoSimples();

    // Checagem do arquivo passado por parametro
    if (argc < 2) {
        std::cout << "Insira o nome do arquivo" << '\n';
        return 1;
    }
    if (grafo->readFile(argv[1])) {
        std::cout << "Arquivo inexistente" << '\n';
    }

    // teste dos metodos criados
    grafo->imprimir();
    /*
    cout << "Vertices: " << grafo->qtdVertices() << endl << "Arestas: " << grafo->qtdArestas() << endl;
    cout << "Grau(30) = " << grafo->grau(30) << endl;
    cout << "Rotulo(30) = " << grafo->rotulo(30) << endl;

    cout << "Vizinhos(30) = {";
    for (int v : grafo->vizinhos(30))
        cout << v << ", ";
    cout << "}\n";

    cout << grafo->haAresta(13, 12) << endl;
    cout << grafo->haAresta(33, 34) << endl << endl;

    cout << grafo->peso(12,13) << endl;
    cout << grafo->peso(33,34) << endl;
    */

    return 0;
}
