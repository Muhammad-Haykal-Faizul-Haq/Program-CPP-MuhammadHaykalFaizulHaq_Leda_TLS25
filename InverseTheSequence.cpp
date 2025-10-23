#include <iostream>
using namespace std;
// Muhammad Haykal Faizul Haq
// Leda
// Inverse The Sequence

int balikDigit(int m){
    int balik = 0;
    int temp = abs(m);
    while(temp>0){
        int digit = temp % 10;
        balik = balik * 10 + digit;
        temp = temp/10;
    }
    if (m < 0) {
        return -balik;
    }
    return balik;
}

int main (){
    char Retry;
    do {
        int n;
        cout << "Selamat datang di algoritma inverse the sequence\nMasukan panjang array anda: ";
        cin >> n; //n adalah panjang input array
        int isiArray[n];
        int isiArrayModifikasi[n]; // Array setelah modifikasi (hanya indeks genap yang dibalik)
        cout << "Masukkan isi array\n";
        for (int i=0; i<n; i++){
            cin >> isiArray[i];
            // Jika indeks genap (i % 2 == 0), maka balik digitnya
            if (i % 2 == 0) {
                isiArrayModifikasi[i] = balikDigit(isiArray[i]);
            } else {
                // Untuk indeks ganjil, biarkan asli
                isiArrayModifikasi[i] = isiArray[i];
            }
        }

        cout << "Array awal anda: ";
        for (int i = 0; i < n; i++) {
            cout << isiArray[i] << " ";
        }
        cout << endl;

        cout << "Array dengan digit indeks genap terbalik: ";
        int sumDigitTerbalik = 0;
        for (int i = 0; i < n; i++) {
            cout << isiArrayModifikasi[i] << " ";
            sumDigitTerbalik += isiArrayModifikasi[i];
        }
        cout << endl;
        cout << "Jumlah array dengan digit terbalik: " << sumDigitTerbalik << endl;

        cout << "\nCoba lagi? (Y/N)\n";
        cin >> Retry;

    } while (Retry == 'Y' || Retry == 'y');

    return 0;

}
