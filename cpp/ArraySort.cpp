#include <iostream>
using namespace std;

//Struct utama
struct Barang {
  string id;
  string nama;
  int stok;
  string rak;
};

const int MAX = 500;
Barang barang[MAX];
int n = 0;

//Array
//bikinka fungsi ini supaya bisa di testing
void initData() {
  //data dummy
  n = 0;
  barang[n++] = {"A1", "Tumbler", 20, "A"};
  barang[n++] = {"A2", "Hair Dryer", 10, "A"};
  barang[n++] = {"B1", "Ganci", 30, "B"};
  barang[n++] = {"B2", "Tasbih Digital", 15, "B"};
  barang[n++] = {"C1", "CCTV", 5, "C"};
  barang[n++] = {"C2", "Senter", 25, "C"};
  barang[n++] = {"D1", "Battery Realme", 12, "D"};
  barang[n++] = {"D2", "Battery OPPO", 10, "D"};
  barang[n++] = {"E1", "Battery Samsung", 8, "E"};
  barang[n++] = {"E2", "Battery iPhone", 6, "E"};
  barang[n++] = {"E3", "Kipas Portable", 20, "E"};
  barang[n++] = {"F1", "Stylus", 18, "F"};
  barang[n++] = {"F2", "Kran Air", 7, "F"};
  barang[n++] = {"G1", "Ampere Meter", 4, "G"};
  barang[n++] = {"G2", "Router", 9, "G"};
  barang[n++] = {"H1", "LCD", 3, "H"};
  barang[n++] = {"H2", "Cup Press", 2, "H"};
  barang[n++] = {"I1", "Mouse", 25, "I"};
  barang[n++] = {"I2", "Keyboard", 15, "I"};
  barang[n++] = {"J1", "Kabel Charger", 40, "J"};
  barang[n++] = {"J2", "Kepala Charger", 35, "J"};
  barang[n++] = {"K1", "Case Xiaomi", 22, "K"};
  barang[n++] = {"K2", "Case iPhone", 18, "K"};
  barang[n++] = {"K3", "Case Samsung", 20, "K"};
}

//tambah fitru ini supaya auto bikin id saat penginputan data
string generateID(string) {
  int maxNum = 0;
    for(int i=0;i<n;i++) {
        if(barang[i].rak==rak) {
            string numStr="";
            for(int j=rak.length();j<barang[i].id.length();j++) {
                if(isdigit(barang[i].id[j])) numStr+=barang[i].id[j];
            }
            if(!numStr.empty()) {
                int num=stoi(numStr);
                if(num>maxNum) maxNum=num;
            }
        }
    }
    return rak+to_string(maxNum+1);
}

//fungsi tambah data
void tambahData() {
    if(n>=MAX) {
        cout<<"Kapasitas penyimpanan data sudah penuh\n";
        return;
    }

    Barang b;
    string inputRak;

    cout<<"Masukkan abjad rak (A-K): ";
    cin>>inputRak;
    if(inputRak=="0") return;

    b.rak=kapital(inputRak);

    if(b.rak < "A" || b.rak > "K") {
        cout<<"Rak tidak valid\n";
        return;
    }

    b.id=generateID(b.rak);
    cout<<"ID dibuat: "<<b.id<<endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<"Nama: ";
    getline(cin,b.nama);
    if(b.nama=="0") return;
    if(b.nama.empty()) {
        cout<<"Nama produk tidak boleh kosong\n";
        return;
    }

    cout<<"Stok: ";
    if (!(cin>>b.stok)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Input stok tidak valid\n";
        return;
    }

    if(b.stok < 0) {
        cout<<"Stok tidak boleh negatif\n";
        return;
    }

    barang[n++] = b;
    cout<<"Data ditambahkan\n";
}

//Fungsi hapus data
void hapusData(int idx) {
    for(int i=idx;i<n-1;i++) {
        barang[i] = barang[i+1];
    }
    n--;
}

//Fungsi tampil data
void tampilData() {
    cout<<left<<setw(8)<<"ID"<<setw(10)<<"Stok"<<setw(8)<<"Rak"<<"Nama Barang\n";
    cout<<"—————————————————————————————————————\n";
    for(int i=0;i<n;i++) {
        cout<<left<<setw(8)<<barang[i].id
            <<setw(10)<<barang[i].stok
            <<setw(8)<<barang[i].rak
            <<barang[i].nama<<endl;
    }
}
