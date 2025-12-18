#include "graph.h"

adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while (P !=NULL){
        if (P -> info == X) return P;
        P = P -> next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = NULL;

        if (pStart->firstEdge == NULL) {
            pStart->firstEdge = newEdge;
        } else {
            adrEdge E = pStart->firstEdge;
            while (E->next != NULL) {
                E = E->next;
            }
            E->next = newEdge;
        }
    }
}

void connectNodeUndirected(Graph &G, infoGraph A, infoGraph B) {
    connectNode(G, A, B);
    connectNode(G, B, A);
}