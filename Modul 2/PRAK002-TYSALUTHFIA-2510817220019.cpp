#include <iostream>
using std::cout;
using std::cin;

struct tumpuk{
    int atas = -1;
    int data[5];
};

tumpuk Tumpuk;
int max = 5;

int kosong(){
    if(Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}

int penuh(){
    if(Tumpuk.atas == max-1)
        return 1;
    else
        return 0;
}

void input(int data){
    if(kosong() == 1 || penuh() == 0){
        Tumpuk.data[++Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk ke Stack\n";
    }else
        cout << "Tumpukan Penuh\n";
}

void hapus(){
    if(kosong()==0){
        cout << "Data teratas sudah terambil\n";
        Tumpuk.atas--;
    }else 
        cout << " Data Kosong";
}

void tampil(){
    if(kosong()==0){
        for(int i = Tumpuk.atas; i >= 0; i--){
            cout << "Tumpukan Ke " << i  << " = " << Tumpuk.data[i] <<  '\n';
        }
    }else 
        cout << "Tumpukan Kosong\n";
}
void bersih(){
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !\n";
}

int main(){
    while(penuh() == 0){
        int in;
        cin >> in;
        input(in);
    }
    tampil();
    bersih();
}