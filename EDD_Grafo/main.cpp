#include "include/SimpleGraph.h"

using namespace std;


int main(int argc, char** argv) {

    GrafoSimples* grafo = new GrafoSimples();

    // Checagem do arquivo passado por parametro
    if (argc < 2) {
        cout << "Insira o nome do arquivo" << '\n';
        return 1;
    }

    if (!grafo->ler(argv[1])) {
        cout << "Arquivo inexistente" << '\n';
        return 1;
    }


    grafo->imprimir();

    delete grafo;

    return 0;
}
