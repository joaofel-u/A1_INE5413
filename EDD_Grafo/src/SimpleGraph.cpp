#include "../include/SimpleGraph.h"

GrafoSimples::GrafoSimples(string arquivo)
{
    rotulos = new vector<string>();
  qtdArestas_ = 0;
	// fazer a leitura do arquivo para construcao do grafo
}

GrafoSimples::~GrafoSimples()
{
    //dtor
}

int GrafoSimples::inserirVertice(string rotulo)
{
	adjs.push_back( unordered_map<int, int>() );
	rotulos.push_back( rotulo );
  // ver onde vai ser guardado o rotulo
  return adjs.size()-1;
}

void GrafoSimples::inserirAresta(int u, int v, int peso)  // VER
{
	adjs[u].insert(v, peso);
	adjs[v-1].insert(u, peso);
    // ver onde guardar o peso da aresta
	qtdArestas_ += 1;
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
	return "";  // IMPLEMENTAR
}

vector<int> GrafoSimples::vizinhos(int v)  // TESTAR
{
	int tam = adjs[v-1].size();
	vector<int>* vizinhos = new vector<int>();
    vizinhos->resize(tam);

	for (auto it = adjs[v-1].begin(); it != adjs[v-1].end(); ++it)
		vizinhos->push_back(*it);

	return *vizinhos;
}

bool GrafoSimples::haAresta(int u, int v)
{
	return adjs[u].find(v) != adjs[u].end();
}

float GrafoSimples::peso(int u, int v)  // implementar corretamente apos decidir armazenamento dos pesos
{
	if (adjs[u].find(v) != adjs[u].end())
		return 1;
	else {
		return numeric_limits<float>::max();  // infinito
    }
}

void GrafoSimples::imprimir()
{
	for(int v = 0; v < adjs.size(); v++) {
		cout << v << ": ";
		for (auto pr: adjs[v])
			cout << pr << ", ";

		cout << "\n";
	}
}
