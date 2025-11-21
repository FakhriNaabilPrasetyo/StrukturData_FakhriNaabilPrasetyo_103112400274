#include <iostream>
using namespace std;

// Struktur Node pada Double Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Pointer awal dan akhir list
Node* head = NULL;
Node* tail = NULL;

// Fungsi Insert Akhir
void insertEnd(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = NULL;
    baru->prev = NULL;

    if (head == NULL) { 
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

// Fungsi Delete Terakhir
void deleteLast() {
    if (tail == NULL) {
        return;
    }

    Node* hapus = tail;

    if (head == tail) { 
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    delete hapus;
}

// View Depan
void viewDepan() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Reverse List
void reverseList() {
    Node* sekarang = head;
    Node* sementara = NULL;

    while (sekarang != NULL) {
        sementara = sekarang->prev;
        sekarang->prev = sekarang->next;
        sekarang->next = sementara;
        sekarang = sekarang->prev;
    }

    if (sementara != NULL) {
        head = sementara->prev;
    }
}

// Reverse dan View
void reverseAndView() {
    reverseList();
    cout << "List setelah di-reverse: ";
    viewDepan();
}

// Program Utama 
int main() {
    int menu, nilai;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit\n";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertEnd(nilai);
                break;
            case 2:
                deleteLast();
                break;
            case 3:
                viewDepan();
                break;
            case 4:
                reverseAndView();
                break;
            case 0:
                break;
            default:
                cout << "Pilihan tidak ada!\n";
        }

    } while (menu != 0);

    return 0;
}
