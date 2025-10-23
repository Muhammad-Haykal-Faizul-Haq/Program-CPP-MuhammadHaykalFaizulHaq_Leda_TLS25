#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <limits>
using namespace std;
// Muhammad Haykal Faizul Haq
// Leda
// The Lost Password Decoder
// Kode Mesin Misterius

bool hasVowel(const string& text) {
    string vowels = "aeiouAEIOU";

    for (char c : text) {
        if (vowels.find(c) != string::npos) { 
            return true; //Bukan output mesin misterius
        }
    }
    return false; 
}

bool hasNumberInMiddle(const string& str) {
    if (str.empty()) {
        return false;
    }
    
    int length = str.length();
    int middle = length / 2;
    
    // Jika panjang ganjil, periksa satu karakter di tengah
    if (length % 2 == 1) {
        return isdigit(str[middle]);
    } 
    // Jika panjang genap, periksa dua karakter di tengah
    else {
        return isdigit(str[middle - 1]) || isdigit(str[middle]);
    }
}

string numberEraser(const string& str) {
    string result = str;
    for (int i = 0; i < result.length(); i++) {
        if (isdigit(result[i])) {
            result.erase(i, 1);
            i--; // Kurangi indeks karena karakter dihapus
        }
    }
    return result;
}

vector<string> generateWithVowels(const string& s) {
    string vowels = "aiueo";
    int n = s.length();
    
    // Hitung total kombinasi: 5^n
    int total = 1;
    for (int i = 0; i < n; i++) {
        total *= 5;
    }
    
    vector<string> results;
    
    // Generate semua kombinasi
    for (int i = 0; i < total; i++) {
        string word;
        int temp = i;
        
        // Untuk setiap huruf dalam input
        for (int j = 0; j < n; j++) {
            // Tambahkan huruf asli
            word += s[j];
            
            // Tambahkan vokal berdasarkan representasi base-5
            int vowel_index = temp % 5;
            temp /= 5;
            word += vowels[vowel_index];
        }
        results.push_back(word);
    }
    
    return results;
}


int main() {
    char Retry;
    do {
        string input;
        cout << "Masukan kode dari mesin misterius: ";
        getline(cin, input);

        if (hasVowel(input) || !hasNumberInMiddle(input)) {
        cout << "Bukan output dari mesin misterius" << endl;
        return 0;
        }

        string reversedInput = ""; //menyimpan teks yang dibalik
            for (int i=input.length() - 1; i >= 0; i--) {
                reversedInput += input[i];
            } 
        cout << "Hasil sementara dibalik: " << reversedInput << endl;

        string tanpaAngka = numberEraser(reversedInput);
        cout << "Hasil sementara angka dihapus: " << tanpaAngka << endl;

        vector<string> combinations = generateWithVowels(tanpaAngka);
        cout << "10 Contoh Kemungkinan Kata:" << endl;
        
        // Tampilkan hanya 10 baris (50 kata jika 5 per baris)
        int maxBaris = 10;
        int kataPerBaris = 5;
        int totalDitampilkan = maxBaris * kataPerBaris;
        
        for (int i = 0; i < min((int)combinations.size(), totalDitampilkan); i++) {
            cout << combinations[i] << " ";
            if ((i + 1) % kataPerBaris == 0) {
                cout << endl;
            }
        }
        
        if (combinations.size() > totalDitampilkan) {
            cout << "\n... dan " << (combinations.size() - totalDitampilkan) << " kemungkinan lainnya" << endl;
        }


        cout << "\nCoba lagi? (Y/N)\n";
        cin >> Retry;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (Retry == 'Y' || Retry == 'y');

    cout << "\nTerima Kasih!\n";
    system("pause");
    return 0;
}


