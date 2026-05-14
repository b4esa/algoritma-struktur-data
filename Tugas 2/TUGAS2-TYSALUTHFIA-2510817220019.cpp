#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[1];

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void hapusTargetH();
void hapusTargetHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

int main ()
{
    menu:
    cout<<"Double Linked List Non Circular (DLLNC)"<<endl;
    cout<<"======================================="<<endl;
    cout<<"Silahkan pilih program DLLNC yang ingin dijalankan!"<<endl;
    cout<<"1. DLLNC dengan head"<<endl;
    cout<<"2. DLLNC dengan head dan tail"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"Pilihan : ";
    cin>>menu;
    system("cls");
    if(menu==1){
        do {
            cout<<"Double Linked List Circular (DLLNC) (Head)"<<endl;
            cout<<"=========================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Hapus Berdasarkan Target"<<endl;
            cout<<"7. Reset"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil){
                case 1:
                    tambahDepanH();
                    break;
                case 2:
                    tambahBelakangH();
                    break;
                case 3:
                    tampilkanH();
                    break;
                case 4:
                    hapusDepanH();
                    break;
                case 5:
                    hapusBelakangH();
                    break;
                case 6:
                    hapusTargetH();
                    break;
                case 7:
                    clearH();
                    break;
                default:
                    system("cls");
                    goto menu;
            }

            cout<<"\nPress any key to continue"<<endl;
            getch();
            system("cls");

        } while(pil<8);
    } else if(menu==2){
        do {
            cout<<"Double Linked List Circular (DLLNC) (Head dan Tail)"<<endl;
            cout<<"==================================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Hapus Berdasarkan Target"<<endl;
            cout<<"7. Reset"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil){
                case 1:
                    tambahDepanHT();
                    break;
                case 2:
                    tambahBelakangHT();
                    break;
                case 3:
                    tampilkanHT();
                    break;
                case 4:
                    hapusDepanHT();
                    break;
                case 5:
                    hapusBelakangHT();
                    break;
                case 6:
                    hapusTargetHT();
                    break;
                case 7:
                    clearHT();
                    break;
                default:
                    system("cls");
                    goto menu;
            }

            cout<<"\nPress any key to continue"<<endl;
            getch();
            system("cls");

        } while (pil<8);
    } else {
        cout<<"\nTERIMA KASIH"<<endl;
        cout<<"Program was made by Tysa Luthfia (2510817220019)."<<endl;
    }
}

void initH(){
    head = NULL;
}

void initHT(){
    head = NULL;
    tail = NULL;
}

int isEmptyH(){
    if(head == NULL) return 1;
    else return 0;
}

int isEmptyHT(){
    if(tail == NULL) return 1;
    else return 0;
}

void tambahDepanH() {
    cout<<"Masukkan data (pisahkan dengan spasi) : ";
    string input, word;
    getline(cin >> ws, input);
    stringstream ss(input);
    vector<string> words;
    
    while(ss >> word) {
        words.push_back(word);
    }

    // Insert mundur agar urutan data tetap sesuai input meski ditambahkan di depan
    for (int i = words.size() - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = words[i];
        baru->next = NULL;
        baru->prev = NULL;

        if(isEmptyH() == 1) {
            head = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }
    cout << "Data berhasil dimasukkan di bagian depan" << endl;
}

void tambahDepanHT() {
    cout<<"Masukkan data (pisahkan dengan spasi) : ";
    string input, word;
    getline(cin >> ws, input);
    stringstream ss(input);
    vector<string> words;
    
    while(ss >> word) {
        words.push_back(word);
    }

    for (int i = words.size() - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = words[i];
        baru->next = NULL;
        baru->prev = NULL;

        if(isEmptyHT() == 1) {
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }
    cout << "Data berhasil dimasukkan di bagian depan." << endl;
}

void tambahBelakangH() {
    cout<<"Masukkan data (pisahkan dengan spasi) : ";
    string input, word;
    getline(cin >> ws, input);
    stringstream ss(input);
    
    while(ss >> word) {
        TNode *baru = new TNode;
        baru->data = word; 
        baru->next = NULL;
        baru->prev = NULL;
        
        if(isEmptyH() == 1) {
            head = baru; // Diperbaiki dari "head == baru"
        } else {
            TNode *bantu = head;
            while(bantu->next != NULL) {
                bantu = bantu->next;
            }
            bantu->next = baru;
            baru->prev = bantu;
        }
    }
    cout << "Data berhasil dimasukan di bagian belakang." << endl;
}

void tambahBelakangHT(){
    cout<<"Masukkan data (pisahkan dengan spasi) : ";
    string input, word;
    getline(cin >> ws, input);
    stringstream ss(input);
    
    while(ss >> word) {
        TNode *baru = new TNode;
        baru->data = word;
        baru->next = NULL;
        baru->prev = NULL;
        
        if(isEmptyHT() == 1) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }
    cout << "Data berhasil dimasukkan di bagian belakang." << endl;
}

void tampilkanH() {
    TNode *bantu;
    bantu = head;
    if(isEmptyH() == 0) {
        while(bantu != NULL) {
            cout<<bantu->data<<' '; 
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada linked list";
}

void tampilkanHT() {
    TNode *bantu;
    bantu = head;
    if(isEmptyHT() == 0) {
        while(bantu != NULL) { 
            cout<<bantu->data<<' '; 
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada linked list";
}

void hapusDepanH() {
    TNode *hapus;
    string data;
    if(isEmptyH() == 0) {
        hapus = head;
        data = hapus->data;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initH();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada linked list";
}

void hapusDepanHT() {
    TNode *hapus;
    string data;
    if(isEmptyHT() == 0) {
        hapus = head;
        data = hapus->data;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initHT();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada linked list";
}

void hapusBelakangH() {
    if(isEmptyH() == 1) {
        cout<<"Tidak terdapat data pada Linked List";
        return;
    }
    int n;
    cout << "Masukkan N (hapus node ke-N dari belakang): ";
    cin >> n;
    if (n <= 0) n = 1;

    TNode *bantu = head;
    while(bantu->next != NULL) {
        bantu = bantu->next;
    }
    
    TNode *temp_tail = bantu;
    // Sistem mundur ke belakang
    for(int i = 1; i < n; i++) {
        bantu = bantu->prev;
        if(bantu == NULL) {
            bantu = temp_tail; // Wrap around jika n lebih besar dari jumlah elemen
        }
    }

    string data = bantu->data;
    if(bantu == head && bantu->next == NULL) {
        initH();
    } else if (bantu == head) {
        head = head->next;
        head->prev = NULL;
    } else if (bantu->next == NULL) {
        bantu->prev->next = NULL;
    } else {
        bantu->prev->next = bantu->next;
        bantu->next->prev = bantu->prev;
    }
    
    delete bantu;
    cout<<"Data \""<<data<<"\" (node ke-"<<n<<" dari belakang) telah berhasil dihapus.";
}

void hapusBelakangHT() {
    if(isEmptyHT() == 1) {
        cout<<"Tidak terdapat data pada Linked List";
        return;
    }
    int n;
    cout << "Masukkan N (hapus node ke-N dari belakang): ";
    cin >> n;
    if (n <= 0) n = 1;

    TNode *bantu = tail;
    for(int i = 1; i < n; i++) {
        bantu = bantu->prev;
        if(bantu == NULL) {
            bantu = tail; // Wrap around ke belakang lagi
        }
    }

    string data = bantu->data;
    if(bantu == head && bantu == tail) {
        initHT();
    } else if (bantu == head) {
        head = head->next;
        head->prev = NULL;
    } else if (bantu == tail) {
        tail = tail->prev;
        tail->next = NULL;
    } else {
        bantu->prev->next = bantu->next;
        bantu->next->prev = bantu->prev;
    }
    
    delete bantu;
    cout<<"Data \""<<data<<"\" (node ke-"<<n<<" dari belakang) telah berhasil dihapus.";
}

// Fungsi Baru: Hapus Target
void hapusTargetH() {
    if(isEmptyH() == 1) {
        cout << "Tidak terdapat data pada linked list";
        return;
    }
    string target;
    cout << "Masukkan data target yang ingin dihapus: ";
    cin >> target;
    
    TNode *bantu = head;
    bool found = false;
    
    while(bantu != NULL) {
        if(bantu->data == target) {
            found = true;
            TNode *hapus = bantu;
            bantu = bantu->next; // Pindah pointer sebelum dihapus
            
            if(hapus == head) {
                head = head->next;
                if(head != NULL) head->prev = NULL;
            } else if(hapus->next == NULL) {
                hapus->prev->next = NULL;
            } else {
                hapus->prev->next = hapus->next;
                hapus->next->prev = hapus->prev;
            }
            delete hapus;
        } else {
            bantu = bantu->next;
        }
    }
    
    if(found) cout << "Semua data \"" << target << "\" berhasil dihapus.";
    else cout << "Data \"" << target << "\" tidak ditemukan.";
}

void hapusTargetHT() {
    if(isEmptyHT() == 1) {
        cout << "Tidak terdapat data pada linked list";
        return;
    }
    string target;
    cout << "Masukkan data target yang ingin dihapus: ";
    cin >> target;
    
    TNode *bantu = head;
    bool found = false;
    
    while(bantu != NULL) {
        if(bantu->data == target) {
            found = true;
            TNode *hapus = bantu;
            bantu = bantu->next; 
            
            if(hapus == head && hapus == tail) {
                initHT();
            } else if(hapus == head) {
                head = head->next;
                head->prev = NULL;
            } else if(hapus == tail) {
                tail = tail->prev;
                tail->next = NULL;
            } else {
                hapus->prev->next = hapus->next;
                hapus->next->prev = hapus->prev;
            }
            delete hapus;
        } else {
            bantu = bantu->next;
        }
    }
    
    if(found) cout << "Semua data \"" << target << "\" berhasil dihapus.";
    else cout << "Data \"" << target << "\" tidak ditemukan.";
}

void clearH() {
    if(isEmptyH() == 1) {
        cout << "Linked List sudah kosong.";
        return;
    }
    int urutan = 1;
    bool turnFront = true; // true = depan, false = belakang
    
    while(head != NULL) {
        if(turnFront) {
            TNode *hapus = head;
            cout << "Penghapusan ke-" << urutan << " (Dari Depan): " << hapus->data << endl;
            head = head->next;
            if(head != NULL) head->prev = NULL;
            delete hapus;
        } else {
            TNode *hapus = head;
            while(hapus->next != NULL) hapus = hapus->next; // cari tail
            cout << "Penghapusan ke-" << urutan << " (Dari Belakang): " << hapus->data << endl;
            if(hapus == head) {
                head = NULL;
            } else {
                hapus->prev->next = NULL;
            }
            delete hapus;
        }
        turnFront = !turnFront;
        urutan++;
    }
    cout<<"Seluruh data pada Linked List telah dibersihkan";
}

void clearHT() {
    if(isEmptyHT() == 1) {
        cout << "Linked List sudah kosong.";
        return;
    }
    int urutan = 1;
    bool turnFront = true;
    
    while(head != NULL) {
        if(turnFront) {
            TNode *hapus = head;
            cout << "Penghapusan ke-" << urutan << " (Dari Depan): " << hapus->data << endl;
            if(head == tail) initHT();
            else {
                head = head->next;
                head->prev = NULL;
            }
            delete hapus;
        } else {
            TNode *hapus = tail;
            cout << "Penghapusan ke-" << urutan << " (Dari Belakang): " << hapus->data << endl;
            if(head == tail) initHT();
            else {
                tail = tail->prev;
                tail->next = NULL;
            }
            delete hapus;
        }
        turnFront = !turnFront;
        urutan++;
    }
    cout<<"Seluruh data pada Linked List telah dibersihkan";
}