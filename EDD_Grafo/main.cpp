#include <iostream>


#include "./include/SimpleGraph.h"
using namespace std;

int main()
{
    GrafoSimples g;

    //criação de vértices
    for (int i=0; i<3; i++){
        g.inserirVertice();
    }

    //criação das arestas
    g.inserirAresta(0, 1);
    g.inserirAresta(1, 2);

    if(g.pertAresta(0, 1)){
        cout<<"Achou 0 -- 1\n";
    }else{
        cout<<"Nao achou 0 -- 1\n";
    }
    g.imprimir();

    return 0;
}
