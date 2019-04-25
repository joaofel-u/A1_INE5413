#include "include/SimpleGraph.h"
#include <queue>

using namespace std;


int main(int argc, char const *argv[]) {

	// Checagem do arquivo passado por parametro
    ifstream myReadFile;
    if (argc < 3) {
        cout << "Insira o nome do arquivo / vertice inicial\n";
        return 1;
    }


    // criacao do grafo e leitura do arquivo de entrada para populacao
    GrafoSimples* grafo = new GrafoSimples();

    if (!grafo->ler(argv[1])) {
        cout << "Arquivo inexistente\n";
        return 1;
    }


	// definicao do vertice de origem da busca
	int s = stoi(argv[2]);
    int num_vertices = grafo->qtdVertices();

	// verifica se o vertice passado por parametro existe dentro do grafo
	if (s > num_vertices || s == 0) {
		cout << "O vértice " << s << " não existe no grafo " << argv[1] << endl;
		return 1;
	}


	// BUSCA EM LARGURA (nao utiliza Av por nao precisar armazenar os antecessores)
    // Inicializacao
    bool* c = new bool[num_vertices+1];
    int* d = new int[num_vertices+1];

    for (int i = 0; i <= num_vertices; i++) {
        c[i] = false;
        d[i] = INFINITE_INT;
    }

    c[s] = true;
    d[s] = 0;

    queue<int> q = *new queue<int>();
    q.push(s);


    // Propagacao das visitas
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : grafo->vizinhos(u)) {
            if (!c[v]) {
                c[v] = true;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }


    // Saida
    int nivel = 0;
    bool control = true;
    while (control) {
        control = false;
        string out = to_string(nivel) + ": ";

        for (int i = 0; i <= num_vertices; i++) {
            if (d[i] == nivel) {
                control = true;
                out += to_string(i) + ",";
            }
        }

        if (control) {
            out.pop_back();
            cout << out << endl;
            nivel++;
        }
    }

    // na hora de imprimir lembrar de utilizar vertice+1


	return 0;
}
