echo "Compiling files..."

cd EDD_Grafo

g++ -c src/SimpleGraph.cpp -std=c++17

if [ -f "./SimpleGraph.o" ]; then
	g++ -o ../runMain.o main.cpp SimpleGraph.o -std=c++17
	g++ -o ../runBFS.o ex2_buscas.cpp SimpleGraph.o -std=c++17
	g++ -o ../runDIJK.o ex4_dijkstra.cpp SimpleGraph.o -std=c++17
	g++ -o ../runFW.o ex5_floyd-warshall.cpp SimpleGraph.o -std=c++17
	g++ -o ../runHH.o ex3_hierholzer.cpp SimpleGraph.o -std=c++17

	rm SimpleGraph.o
else
	echo "Compilation failed!"
fi
