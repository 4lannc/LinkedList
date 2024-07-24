#include <iostream>

using namespace std;

struct PlaylistLagu
{
    string judul, pengarang;
    int flot;

    PlaylistLagu *next;
};

PlaylistLagu *kepala, *buntut, *ini, *nodeBaru, *hapus;

void ngisiLinkedlist (string judul, string pengarang, int flot) {
    kepala = new PlaylistLagu();
    kepala->judul = judul;
    kepala->pengarang = pengarang;
    kepala->flot = flot;
    kepala->next = NULL;
    buntut = kepala;    
}

void tambahAwal (string judul, string pengarang, int flot) {
    nodeBaru = new PlaylistLagu();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->flot = flot;
    nodeBaru->next = kepala;
    kepala = nodeBaru;
}

void tambahahir (string judul, string pengarang, int flot) {
    nodeBaru = new PlaylistLagu();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->flot = flot;
    nodeBaru->next = NULL;
    buntut->next = nodeBaru;
    buntut = nodeBaru;
}
// Tambah tengah single list

void tambahtengah (string judul, string pengarang, int flot,int posisi) {
    nodeBaru = new PlaylistLagu();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->flot = flot;
    
    //transversing
    ini = kepala;
    int nomer = 1;
    while(nomer < posisi - 1){
        ini = ini->next;
        nomer++;
    }
    nodeBaru->next = ini->next;
    ini->next = nodeBaru;
}

void ubahAwal(string judul, string pengarang, int flot){
    kepala->judul = judul;
    kepala->pengarang = pengarang;
    kepala->flot = flot;
}


void ubahLast(string judul, string pengarang, int flot){
    buntut->judul = judul;
    buntut->pengarang = pengarang;
    buntut->flot = flot;
}

void hapusAwal () {
    hapus = kepala;
    kepala = kepala->next;
    delete hapus;
}

void hapusLast () {
    hapus = buntut;
    ini = kepala;
    while (ini->next != buntut)
    {
        ini = ini->next;
    }
    buntut = ini;
    buntut->next = NULL;
    delete hapus;  
}

void cetakLinkedlist(){
    ini = kepala;
    while (ini != NULL)
    {
        cout << "Judul Lagu : " << ini->judul << endl;
        cout << "Artis Lagu : " << ini->pengarang << endl;
        cout << "Durasi Lagu : " << ini->flot << endl;
        cout << endl;
    ini = ini->next;
    }
    
}

int main () {
 ngisiLinkedlist("Malam", "Ayu Kiswara", 04.00);
 tambahAwal("Mancing", "Dike Sabrina", 05.22);
 tambahahir("turu", "Dyo Haw", 06.22);
//  tambahtengah();

 hapusAwal();

 hapusLast();


 ubahAwal("Mengejar Badai", "Ayu Cantika", 05.21);
 ubahLast("Bahtera Cinta", "Cantika Devinca", 03.45);
 cetakLinkedlist();

 return 0;
}