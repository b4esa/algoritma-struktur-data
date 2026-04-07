#include <iostream>
#include <conio.h>
#include <cstdlib>
#define n 10
using namespace std;

void INSERT();
void DELETE();
void CETAKLAYAR();
void Inisialisasi();
void RESET();
int PIL,F,R;
char PILIHAN [1], HURUF;
char Q[n];

int main()
{
    Inisialisasi(); 
    do 
    {
        cout << "QUEUE" << endl;
        cout << "============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. QUIT" << endl;
        cout << "PILIHAN : "; cin >> PILIHAN;
        PIL = atoi(PILIHAN); 
        switch (PIL)
        {
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            default:
                cout << "TERIMA KASIH" << endl;
                break;
        }
        cout << "Press any key to continue" << endl;
        getch();
        system("cls");
    } while (PIL < 4);

}

void Inisialisasi() {
    F = -1;
    R = -1;
}

void INSERT() {
    if (R == n - 1) {
        cout << "Queue Penuh!" << endl;
    } else {
        if (F == -1) 
        F = 0;
        cout << "Masukkan Data: ";
        cin >> HURUF;
        R++;
        Q[R] = HURUF;
        cout << "Data " << HURUF << " ditambahkan ke queue." << endl;
    }
}

void DELETE() {
    if (F == -1 || F > R) {
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Data yang Terhapus: " << Q[F] << endl;
        F++;
    }
}

void CETAKLAYAR() {
    if (F == -1 || F > R) {
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Isi Queue yaitu: ";
        for (int i = F; i <= R; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}