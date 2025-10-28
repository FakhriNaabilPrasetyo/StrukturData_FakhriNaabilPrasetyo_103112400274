#include <iostream>
#define NIL NULL

using namespace std;

typedef int DataType;
typedef struct Node *Pointer;

struct Node {
    DataType data;
    Pointer next;
    Pointer prev;
};

struct DoubleList {
    Pointer head;
    Pointer tail;
};

// --- Fungsi Alokasi dan Dealokasi ---
Pointer createNode(DataType val) {
    Pointer node = new Node;
    node->data = val;
    node->next = NIL;
    node->prev = NIL;
    return node;
}

void freeNode(Pointer &node) {
    delete node;
    node = NIL;
}

// --- Fungsi Dasar Insert ---
void insertAtFront(DoubleList &L, Pointer node) {
    node->next = L.head;
    node->prev = NIL;
    if (L.head != NIL)
        L.head->prev = node;
    else
        L.tail = node;
    L.head = node;
}

void insertAtEnd(DoubleList &L, Pointer node) {
    node->prev = L.tail;
    node->next = NIL;
    if (L.tail != NIL)
        L.tail->next = node;
    else
        L.head = node;
    L.tail = node;
}

void insertAfterNode(DoubleList &L, Pointer node, Pointer prec) {
    node->next = prec->next;
    node->prev = prec;
    if (prec->next != NIL)
        prec->next->prev = node;
    else
        L.tail = node;
    prec->next = node;
}

// --- Fungsi Traversal ---
void displayForward(DoubleList L) {
    Pointer p = L.head;
    while (p != NIL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void displayBackward(DoubleList L) {
    Pointer p = L.tail;
    while (p != NIL) {
        cout << p->data << " ";
        p = p->prev;
    }
    cout << endl;
}

// --- Fungsi Delete Dasar ---
void removeFront(DoubleList &L, Pointer &node) {
    node = L.head;
    if (node != NIL) {
        L.head = node->next;
        if (L.head != NIL)
            L.head->prev = NIL;
        else
            L.tail = NIL;
        node->next = NIL;
        node->prev = NIL;
    }
}

void removeBack(DoubleList &L, Pointer &node) {
    node = L.tail;
    if (node != NIL) {
        L.tail = node->prev;
        if (L.tail != NIL)
            L.tail->next = NIL;
        else
            L.head = NIL;
        node->next = NIL;
        node->prev = NIL;
    }
}

// --- Fungsi Smart Insert ---
void smartInsert(DoubleList &L, DataType val) {
    Pointer node = createNode(val);

    if (L.head == NIL) {
        insertAtFront(L, node);
        cout << "Smart Insert: List kosong, insert " << val << " di first" << endl;
        return;
    }

    if (val < L.head->data) {
        insertAtFront(L, node);
        cout << "Smart Insert: " << val << " < first, insert di first" << endl;
        return;
    }

    if (val % 2 == 0) {
        insertAtEnd(L, node);
        cout << "Smart Insert: " << val << " genap, insert di last" << endl;
        return;
    }

    if (val > L.tail->data) {
        insertAtEnd(L, node);
        cout << "Smart Insert: " << val << " ganjil, lebih besar dari last, insert di last" << endl;
        return;
    }

    Pointer q = L.head;
    while (q->next != NIL && !(q->data == 5 && q->next->data == 7)) {
        q = q->next;
    }

    if (q->next != NIL) {
        insertAfterNode(L, node, q);
        cout << "Smart Insert: " << val << " di antara 5 dan 7" << endl;
    } else {
        insertAtEnd(L, node);
        cout << "Smart Insert: kondisi lain, insert di last" << endl;
    }
}

// --- Fungsi Conditional Delete (hapus semua ganjil) ---
int conditionalDelete(DoubleList &L) {
    int count = 0;
    Pointer p = L.head;
    while (p != NIL) {
        Pointer nextP = p->next;
        if (p->data % 2 != 0) {
            if (p == L.head)
                removeFront(L, p);
            else if (p == L.tail)
                removeBack(L, p);
            else {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            freeNode(p);
            count++;
        }
        p = nextP;
    }
    return count;
}

// --- Fungsi Delete by Value ---
void deleteByValue(DoubleList &L, DataType val) {
    Pointer p = L.head;
    while (p != NIL && p->data != val) {
        p = p->next;
    }

    if (p == NIL) {
        cout << "Nilai " << val << " tidak ditemukan" << endl;
        return;
    }

    if (p == L.head)
        removeFront(L, p);
    else if (p == L.tail)
        removeBack(L, p);
    else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    cout << "Nilai " << val << " berhasil dihapus" << endl;
    freeNode(p);
}

// --- Fungsi Delete Semua Data ---
void deleteAll(DoubleList &L) {
    Pointer p;
    int count = 0;
    while (L.head != NIL) {
        removeFront(L, p);
        freeNode(p);
        count++;
    }
    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;
}

// --- MAIN PROGRAM ---
int main() {
    DoubleList L;
    L.head = NIL;
    L.tail = NIL;

    cout << "ADVANCED OPERATIONS" << endl;
    cout << "SMART INSERT DEMO" << endl;

    smartInsert(L, 5);
    smartInsert(L, 3);
    smartInsert(L, 8);
    smartInsert(L, 6);
    smartInsert(L, 4);
    smartInsert(L, 7);

    cout << "\nHasil Smart Insert:" << endl;
    cout << "Forward: ";
    displayForward(L);
    cout << "Backward: ";
    displayBackward(L);

    cout << "\nCONDITIONAL DELETE" << endl;
    cout << "Sebelum Conditional Delete: ";
    displayForward(L);
    int deleted = conditionalDelete(L);
    cout << "Conditional Delete: " << deleted << " elemen ganjil dihapus" << endl;
    cout << "Setelah Conditional Delete: ";
    displayForward(L);

    cout << "\nDELETE BY VALUE DEMO" << endl;
    deleteByValue(L, 6);
    deleteByValue(L, 10);
    cout << "List akhir: ";
    displayForward(L);

    cout << "\nDELETE ALL DEMO" << endl;
    deleteAll(L);

    return 0;
}
