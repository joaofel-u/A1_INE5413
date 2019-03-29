#include <iostream>

#include "./include/SimpleGraph.h"
using namespace std;

int main(int argc, char const *argv[])
{
    if (argc > 1) {
        string arquivo = argv[1];
        GrafoSimples* grafo = new GrafoSimples(arquivo);
    } else {
        cout << "Argumentos insuficientes para execução do programa\n";
    }

    return 0;
}
