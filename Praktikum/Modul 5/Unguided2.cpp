#include <iostream>
using namespace std;
#define Nil NULL

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) { if (P != Nil) { delete P; P = Nil; } }

void insertFirst(List &L, address P) {
    P->next = L.first;
    P->prev = Nil;
    if (L.first != Nil) L.first->prev = P;
    else L.last = P;
    L.first = P;
}

void printInfo(List &L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    P = L.first; L.first = L.first->next;
    if (L.first != Nil) L.first->prev = Nil;
    else L.last = Nil;
    P->next = Nil;
    P->prev = Nil;
}

void deleteLast(List &L, address &P) {
    P = L.last; L.last = L.last->prev;
    if (L.last != Nil) L.last->next = Nil;
    else L.first = Nil;
    P->prev = Nil;
    P->next = Nil;
}

void deleteAfter(List &L, address &P, address R) {
    P = R->next;
    R->next = P->next;
    if (P->next != Nil) P->next->prev = R;
    else L.last = R;
    P->prev = Nil;
    P->next = Nil;
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

bool deleteByValue(List &L, infotype x) {
    address P = findElm(L, x);
    if (P == Nil) {
        return false;
    }
    address Pdel;
    if (P == L.first) {
        deleteFirst(L, Pdel);
    } else if (P == L.last) {
        deleteLast(L, Pdel);
    } else {
        address R = P->prev;
        deleteAfter(L, Pdel, R);
    }
    dealokasi(Pdel);
    return true;
}

int deleteAll(List &L) {
    int count = 0;
    address Pdel;
    while (L.first != Nil) {
        deleteFirst(L, Pdel);
        dealokasi(Pdel);
        count++;
    }
    return count;
}

int main() {
    List L;
    L.first = Nil;
    L.last = Nil;
    insertFirst(L, alokasi(1));
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(3));
    insertFirst(L, alokasi(2));
    cout << "TASK 1: DELETE OPERATIONS" << endl;
    cout << "List awal: ";
    printInfo(L);
    if (deleteByValue(L, 2)) {
        cout << "Nilai 2 berhasil dihapus" << endl;
    } else {
        cout << "Nilai 2 tidak ditemukan" << endl;
    }
    cout << "Setelah deleteByValue(2): ";
    printInfo(L);
    if (deleteByValue(L, 5)) {
        cout << "Nilai 5 berhasil dihapus" << endl;
    } else {
        cout << "Nilai 5 tidak ditemukan" << endl;
    }
    cout << "List tetap: ";
    printInfo(L);
    insertFirst(L, alokasi(4));
    insertFirst(L, alokasi(5));
    cout << "List setelah tambah data: ";
    printInfo(L);
    int count = deleteAll(L);
    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;
    return 0;
}