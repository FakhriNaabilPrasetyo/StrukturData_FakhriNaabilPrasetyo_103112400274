#include <iostream>
using namespace std;

int hitungTotal(int *stok, int jumlah) {
    int total = 0;
    for (int i = 0; i < jumlah; i++) {
        total += *(stok + i);
    }
    return total;
}

int cariStokTerkecil(int *stok, int jumlah) {
    int indeksMin = 0;
    for (int i = 1; i < jumlah; i++) {
        if (*(stok + i) < *(stok + indeksMin)) {
            indeksMin = i;
        }
    }
    return indeksMin;
}

void tampilkanStok(int *stok, int jumlah) {
    cout << "[ ";
    for (int i = 0; i < jumlah; i++) {
        cout << *(stok + i);
        if (i < jumlah - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

int main() {
    int stokBuku[] = {12, 8, 25, 5, 18};
    int jumlahBuku = sizeof(stokBuku) / sizeof(stokBuku[0]);

    cout << "Stok Buku Awal:" << endl;
    tampilkanStok(stokBuku, jumlahBuku);

    int total = hitungTotal(stokBuku, jumlahBuku);
    cout << "Total semua stok buku: " << total << endl << endl;

    int indeksMin = cariStokTerkecil(stokBuku, jumlahBuku);
    *(stokBuku + indeksMin) += 10;

    cout << "Stok Buku Setelah Penambahan Bonus:" << endl;
    tampilkanStok(stokBuku, jumlahBuku);

    return 0;
}