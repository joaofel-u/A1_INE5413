echo "Compiling files..."

cd EDD_Grafo

g++ -c src/SimpleGraph.cpp -std=c++17

g++ -o ../runMain.o main.cpp SimpleGraph.o -std=c++17

g++ -o ../runBFS.o ex2_buscas.cpp SimpleGraph.o -std=c++17

g++ -o ../runFW.o ex5_floyd-warshall.cpp SimpleGraph.o -std=c++17

rm SimpleGraph.o

echo "Compilation completed!"
