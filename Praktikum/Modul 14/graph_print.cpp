#include "graph.h"
#include <queue>

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void printDFS(Graph G, adrNode N) {
    if (N == NULL) return;

    N->visited = true;
    cout << N->info << " ";

    // Telusuri semua edge
    adrEdge E = N->firstEdge;
    while (E != NULL) {
        if (!E->node->visited) {
            printDFS(G, E->node);
        }
        E = E->next;
    }
}

void resetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = false;
        P = P->next;
    }
}

void printBFS(Graph G, adrNode start) {
    if (start == NULL) return;

    queue<adrNode> Q;

    start->visited = true;
    Q.push(start);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();

        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (!E->node->visited) {
                E->node->visited = true;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}