#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    connectNodeUndirected(G, 'A', 'B');
    connectNodeUndirected(G, 'A', 'C');
    connectNodeUndirected(G, 'B', 'D');
    connectNodeUndirected(G, 'B', 'E');
    connectNodeUndirected(G, 'C', 'F');
    connectNodeUndirected(G, 'C', 'G');
    connectNodeUndirected(G, 'D', 'H');
    connectNodeUndirected(G, 'E', 'H');
    connectNodeUndirected(G, 'F', 'H');
    connectNodeUndirected(G, 'G', 'H');

    resetVisited(G);
    cout << "Hasil BFS dari node A: ";
    printBFS(G, G.first);
    cout << endl;

    return 0;
}