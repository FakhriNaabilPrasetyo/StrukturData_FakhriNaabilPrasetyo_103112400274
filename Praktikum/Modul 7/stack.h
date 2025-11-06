#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl]; // Array untuk menyimpan elemen stack
    int top;
};

// Prototipe fungsi dasar
void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x); // Menambahkan elemen ke dalam stack
infotype pop(Stack &S); // Mengambil elemen teratas dari stack
void printInfo(Stack S);

// Fungsi Tambahan
void balikStack(Stack &S); // Membalik urutan elemen dalam stock
void pushAscending(Stack &S, int x);
void getInputStream(Stack &S);

#endif