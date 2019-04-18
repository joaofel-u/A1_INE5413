#include "../include/SimpleGraph.h"

GrafoSimples::GrafoSimples()
{
    adjs = *(new vector< unordered_map<int, float> >());
    rotulos = *(new vector<string>());
    qtdArestas_ = 0;
}

GrafoSimples::~GrafoSimples()
{
    // dtor
}

int GrafoSimples::readFile(string fileName)
{
    ifstream myReadFile;
    myReadFile.open(fileName);
    if (myReadFile.fail()) {
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
            myReadFile >> vertice;
            getline(myReadFile, rotulo);
            inserirVertice(rotulo);
        }

        myReadFile >> output; //descarta string *edges

        while (true) {
            int verticeOrigem, verticeDestino;
            float peso;
            myReadFile >> verticeOrigem >> verticeDestino >> peso;
            if (myReadFile.eof())
              break;
            inserirAresta(verticeOrigem, verticeDestino, peso);
        }
    }
    myReadFile.close();
    return 0;
}

int GrafoSimples::inserirVertice(string rotulo)
{
    adjs.push_back( unordered_map<int, float>() );
    rotulos.push_back( rotulo );

    return adjs.size()-1;
}

void GrafoSimples::inserirAresta(int u, int v, float peso)
{
    adjs[u-1].emplace(v, peso);
    adjs[v-1].emplace(u, peso);
    qtdArestas_ ++;
}

int GrafoSimples::qtdVertices()
{
    return adjs.size();
}

int GrafoSimples::qtdArestas()
{
    return qtdArestas_;
}

int GrafoSimples::grau(int v)
{
    return adjs[v-1].size();
}

string GrafoSimples::rotulo(int v)
{
    return rotulos[v-1];
}

vector<int> GrafoSimples::vizinhos(int v)
{
    int tam = adjs[v-1].size();
    vector<int> vizinhos = *(new vector<int>());

    for (auto it : adjs[v-1])
        vizinhos.push_back(it.first);

    return vizinhos;
}

bool GrafoSimples::haAresta(int u, int v)
{
    return adjs[u-1].find(v) != adjs[u-1].end();
}

float GrafoSimples::peso(int u, int v)
{
    auto it = adjs[u-1].find(v);
    if (it == adjs[u-1].end())
        return numeric_limits<float>::max();  // infinito
    else
        return adjs[u-1][v];

}

void GrafoSimples::imprimir()
{
    for (size_t i = 0; i < rotulos.size(); i++) {
        cout << i+1 <<": " << rotulos[i] << "\n";
    }
    for(int v = 0; v < adjs.size(); v++) {
        cout << v+1 << ": ";
        for (auto pr: adjs[v])
            cout << "(" << pr.first << ", " << pr.second << "), ";

        cout << "\n";
    }
}
