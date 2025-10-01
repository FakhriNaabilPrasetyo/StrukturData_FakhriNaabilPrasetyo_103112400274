#include <iostream>
#include <string>
using namespace std;

string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    if (n == 0) cout << "nol";
    else if (n == 100) cout << "seratus";
    else if (n < 10) cout << satuan[n];
    else if (n < 20) cout << belasan[n - 10];
    else {
        cout << puluhan[n / 10];
        if (n % 10 != 0) cout << " " << satuan[n % 10];
    }

    return 0;
}
