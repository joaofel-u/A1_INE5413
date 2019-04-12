#include<iostream>
#include<fstream>
#include<string>

#include "include/SimpleGraph.h"

using namespace std;

int main(int argc, char** argv) {

    GrafoSimples* grafo = new GrafoSimples();

    // Checagem do arquivo passado por parametro
    ifstream myReadFile;
    if (argc < 2) {
        std::cout << "Insira o nome do arquivo" << '\n';
        return 1;
    }

    myReadFile.open(argv[1]);
    if (myReadFile.fail()) {
        std::cout << "Arquivo inexistente" << '\n';
        return 1;
    }

    // Leitura do arquivo e construcao do grafo
    string output;
    int vertices;

    if (myReadFile.is_open()) {
        myReadFile >> output; //descarta string *vertices
        myReadFile >> output; //pega a quantidade de vertices
        vertices = stoi(output);

        for (size_t i = 0; i < vertices; i++) {
            int vertice;
            string rotulo;
            myReadFile >> vertice >> rotulo;
            grafo->inserirVertice(rotulo);
        }

        myReadFile >> output; //descarta string *edges

        while (true) {
            int verticeOrigem, verticeDestino;
            float peso;
            myReadFile >> verticeOrigem >> verticeDestino >> peso;
            if (myReadFile.eof())
            break;
            grafo->inserirAresta(verticeOrigem, verticeDestino, peso);
        }
    }
    myReadFile.close();


    // teste dos metodos criados
    grafo->imprimir();
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

    return 0;
}
