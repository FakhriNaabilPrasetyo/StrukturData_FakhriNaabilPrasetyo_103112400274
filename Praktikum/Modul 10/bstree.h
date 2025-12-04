#ifndef BSTREE_H
#include <iostream>

using namespace std;

typedef int infotype;
typedef struct Node*address;

struct Node {
    infotype info;
    address left;
    address right;
};

// Fungsi Alokasi / Pembuatan Node Baru
address newNode(infotype x);

// Fungsi Insert Node ke BST
address insertNode(address root, infotype x);

// Prosedur Traversal InOrder (Left-Root-Right)
void inOrder(address root);

#endif