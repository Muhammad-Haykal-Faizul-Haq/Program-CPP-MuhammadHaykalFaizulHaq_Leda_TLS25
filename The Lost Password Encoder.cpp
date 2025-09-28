#include <iostream>
#include <string>
#include <limits>
using namespace std;
// Muhammad Haykal Faizul Haq
// Leda
// 25/560398/TK/63292
// The Lost Password Encoder
// Kode Mesin Misterius

char getFirstChar(const string& str) {
    if (str.empty()) {
        return '\0'; // Return null character jika string kosong
    }
    return str[0];
}

int main() {
    char Retry;
    do {
        string textInput = "";

        cout << "Selamat datang di Algoritma kode mesin misterius\nmasukan input anda: ";
        getline(cin, textInput); // Untuk membaca seluruh baris input

         // Cek jika string kosong
        if (textInput.empty()) {
            cout << "Input tidak boleh kosong! Silakan coba lagi.\n";
            continue;
        }

        char hurufAwal = textInput[0];
        int ASCIIHurufawal = (int)hurufAwal;

        string hapusHuruf = "aiueoAIUEO"; // String yang berisi huruf-huruf vokal

        for (int i = 0; i < textInput.length(); i++) {
            // Cek jika karakter saat ini adalah salah satu dari hapusHuruf
            if (hapusHuruf.find(textInput[i]) != string::npos) {
                textInput.erase(i, 1);
                i--; // Karena kita menghapus karakter, indeks perlu dikurangi
            }
        }
        cout << "Hasil Sementara: " << textInput << endl;
        
        string reversedInput = " "; //menyimpan teks yang dibalik
        for (int i=textInput.length() - 1; i >= 0; i--) {
            reversedInput += textInput[i];
        } 
        cout << "Hasil sementara dibalik: " << reversedInput << endl;
        cout << "Huruf awal: " << hurufAwal << endl;
        cout << "ASCII huruf awal: " << ASCIIHurufawal << endl;

        int panjangString = reversedInput.length();
        int tengah = (panjangString/2)+1;
        reversedInput.insert(tengah, to_string(ASCIIHurufawal));
        cout << "Hasil password" << reversedInput;

        cout << "\nCoba lagi? (Y/N)\n";
        cin >> Retry;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (Retry == 'Y' || Retry == 'y');

    cout << "\nTerima Kasih!\n";
    system("pause");
}
