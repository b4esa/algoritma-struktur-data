#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define n 10
using namespace std;

void INSERT();
void DELETE();
void CETAKLAYAR();
void Inisialisasi();
void RESET();
int PIL, F, R, ITEM;
char HURUF;
char Q[n];

int main(){
    Inisialisasi();
    do
    {
        cout << "QUEUE" << endl;
        cout << "=============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. QUIT" << endl;
        cout << "PILIHAN : "; cin >> PIL;

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

        cout << "\npress any key to continue" << endl;
        getch();
        system("cls");

    } while (PIL < 4);
    
}

void INSERT()
{
    cout << "\n\nINSERT" << endl;
    cout << "=============" << endl;
    cout << "MASUKKAN HURUF : "; cin >> HURUF;
    if(ITEM != n){
        if(R == n-1) R = -1;
        Q[++R] = HURUF;
        ITEM++;
    }else{
        cout << "Queue Penuh\n";
    }

}

void DELETE()
{
    if(F == n-1){
        cout << "Item " << Q[F] << " Dihapus\n";
        Q[F] = '0';
        F = 0;
        ITEM--;
    }else if(ITEM != 0){
        cout << "Item " << Q[F] << " Dihapus\n";
        Q[F++] = '0';
        ITEM--;
    }else{
        cout << "Queue Kosong";
    }
}

void CETAKLAYAR()
{
    if(ITEM == 0){cout << "Queue Kosong\n"; return;}
    cout << "\nCETAK QUEUE : ";
    int d = F, i = 0;
    while (i < ITEM)
    {
        if(d > n-1){
            d = 0;
        }
        cout << Q[d++] << " ";
        i++;
    }
    
}

void Inisialisasi()
{
    F = 0;
    R = -1;

    cout << "Queue telah diinisialisasi\n";
}

void RESET()
{
    F = 0;
    R = -1;
    ITEM = 0;

    cout << "Queue telah direset";
}