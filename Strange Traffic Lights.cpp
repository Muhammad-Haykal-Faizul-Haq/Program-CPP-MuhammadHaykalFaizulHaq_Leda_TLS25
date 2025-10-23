#include <iostream>
using namespace std;
// Muhammad Haykal Faizul Haq
// Leda
// Strange Traffic Lights

int main(){
    int t; //waktu input
    do {
        cout << "\nMasukan waktu input: . . . (masukan 0 untuk berhenti)\n t=" ;
        cin >> t;

        int tmod = t % 103;
        int tmodmin = tmod-24;

        if (tmodmin > 0 && tmodmin <= 20){
            cout << "\033[32m" << "Lampu hijau" << "\033[0m" << endl;
        } else if (tmodmin > 20 && tmodmin <= 24){
            cout << "\033[33m" << "Lampu kuning" << "\033[0m" << endl;
        } else {
            cout << "\033[31m" << "Lampu merah" << "\033[0m" << endl;
        }

        int t;

    } while (t != 0);

    cout << "Terima Kasih";

}
