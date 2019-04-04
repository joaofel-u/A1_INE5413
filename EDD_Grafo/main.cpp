#include<iostream>
#include<fstream>
#include<string>

#include "include/SimpleGraph.h";

using namespace std;

int main(int argc, char** argv) {

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

  GrafoSimples* grafo = new GrafoSimples(arquivo);
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
      //cout << "vertice: " << vertice << " - rotulo: " << rotulo << "\n";
      grafo.inserirVertice(vertice, rotulo);
    }

    myReadFile >> output; //descarta string *edges
    //cout << "\n------------------------\n" << output << "\n------------------------\n";

    while (!myReadFile.eof()) {
      int verticeOrigem, verticeDestino;
      float peso;
      myReadFile >> verticeOrigem >> verticeDestino >> peso;
      //cout << "verticeOrigem: " << verticeOrigem << " - verticeDestino: " << verticeDestino << " - peso: " << peso << "\n";
      grafo.inserirAresta(verticeOrigem, verticeDestino, peso);
    }

    std::cout << "Vertices" << grafo.qtdVertices() << '\n' << "Aresta" << grafo.qtdArestas() << '\n';

  }
  myReadFile.close();
  return 0;
}
