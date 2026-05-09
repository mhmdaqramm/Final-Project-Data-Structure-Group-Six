#include <iostream>
#include <queue>
#include <string>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include <limits>
using namespace std;

const int MAX = 500;
const int V = 12;

string kapital(string s) {
    for(int i=0;i<s.length();i++) {
        s[i]=toupper(s[i]);
    }
    return s;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    cout << "\nTekan ENTER untuk kembali...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// ================= ARRAY =================
struct Barang {
    string id;
    string nama;
    int stok;
    string rak;
};

Barang barang[MAX];
int n = 0;

string generateID(string rak) {
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

// ================= LINKED LIST =================
struct NodeLL {
    string aktivitas;
    NodeLL* next;
};

NodeLL* head=NULL;

void tambahRiwayat(string act) {
    NodeLL* baru=new NodeLL{act,NULL};
    if(!head) head=baru;
    else {
        NodeLL* t=head;
        while(t->next) t=t->next;
        t->next=baru;
    }
}

void tampilRiwayat() {
    if(!head) {
        cout<<"Tidak ada riwayat aktivitas\n";
        return;
    }
    NodeLL* t=head;
    while(t) {
        cout<<"\u2014 "<<t->aktivitas<<endl;
        t=t->next;
    }
}

// ================= BINARY SEARCH TREE =================
struct NodeBST {
    string id;
    string nama;
    NodeBST* kiri;
    NodeBST* kanan;
};

NodeBST* root = NULL;

NodeBST* insertBST(NodeBST* r,string id,string nama) {
    if(!r) return new NodeBST{id,nama,NULL,NULL};
    if(id<r->id) r->kiri=insertBST(r->kiri,id,nama);
    else r->kanan=insertBST(r->kanan,id,nama);
    return r;
}

void inorder(NodeBST* r) {
    if(!r) return;
    inorder(r->kiri);
    cout<<r->id<<" \u2014 "<<r->nama<<endl;
    inorder(r->kanan);
}

// ================= QUEUE =================
queue<pair<string,string>> antrean;

// ================= GRAPH (ADJACENCY MATRIX) =================
string rakNode[V]={"PINTU","A","B","C","D","E","F","G","H","I","J","K"};

int graph[V][V]={
 {0,1,0,0,0,0,0,0,0,0,0,1},
 {1,0,1,0,0,0,0,0,0,0,0,1},
 {0,1,0,1,0,0,0,0,0,0,0,0},
 {0,0,1,0,1,0,0,0,0,1,0,0},
 {0,0,0,1,0,1,0,0,0,1,1,0},
 {0,0,0,0,1,0,1,0,0,0,1,0},
 {0,0,0,0,0,1,0,1,0,1,0,0},
 {0,0,0,0,0,0,1,0,1,1,0,0},
 {0,0,0,0,0,0,0,1,0,1,0,0},
 {0,0,0,1,1,0,1,1,1,0,0,0},
 {0,0,0,0,1,1,0,0,0,0,0,0},
 {1,1,0,0,0,0,0,0,0,0,0,0}
};

int getRakIdx(string r) {
    for(int i=0;i<V;i++) {
        if(rakNode[i]==r) return i;
    }
    return -1;
}

// ================= BFS =================
void bfsCariJalur(int start,int target) {
    bool visited[V]={false};
    int parent[V];
    for(int i=0;i<V;i++) parent[i]=-1;

    queue<int> q;
    visited[start]=true;
    q.push(start);

    while(!q.empty()) {
        int u=q.front(); q.pop();
        for(int v=0;v<V;v++) {
            if(graph[u][v] && !visited[v]) {
                visited[v]=true;
                parent[v]=u;
                q.push(v);
            }
        }
    }

    if(!visited[target]) {
        cout<<"Tidak ada rute\n";
        return;
    }

    cout<<"Rute: ";

    int path[V], idx=0;
    for(int v=target; v!=-1; v=parent[v])
        path[idx++]=v;

    for(int i=idx-1;i>=0;i--) {
        cout<<rakNode[path[i]];
        if(i>0) cout<<" --> ";
    }
    cout<<endl;
}

void initData() {
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

void tampilData() {
    cout<<left<<setw(8)<<"ID"<<setw(10)<<"Stok"<<setw(8)<<"Rak"<<"Nama Barang\n";
    cout<<"\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\u2014\n";
    for(int i=0;i<n;i++) {
        cout<<left<<setw(8)<<barang[i].id
            <<setw(10)<<barang[i].stok
            <<setw(8)<<barang[i].rak
            <<barang[i].nama<<endl;
    }
}

void cekRak(string r) {
    bool ada=false;
    cout<<"Isi rak "<<r<<":\n";
    for(int i=0;i<n;i++) {
        if(barang[i].rak==r) {
            cout<<"- "<<barang[i].nama<<" ("<<barang[i].stok<<")\n";
            ada=true;
        }
    }
    if(!ada) cout<<"Rak kosong\n";
}

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

void hapusData(int idx) {
    for(int i=idx;i<n-1;i++) {
        barang[i] = barang[i+1];
    }
    n--;
}

// ================= INSERTION SORT =================
void insertionSort() {
    for(int i=1;i<n;i++) {
        Barang key=barang[i];
        int j=i-1;
        while(j>=0 && barang[j].stok>key.stok) {
            barang[j+1]=barang[j];
            j--;
        }
        barang[j+1]=key;
    }
}

// ================= MERGE SORT =================
void merge(Barang arr[], int l, int m, int r) {
    int n1=m-l+1,n2=r-m;
    Barang L[250],R[250];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int j=0;j<n2;j++) R[j]=arr[m+1+j];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2) {
        if(L[i].id<=R[j].id) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(int l,int r) {
    if(l<r) {
        int m=(l+r)/2;
        mergeSort(l,m);
        mergeSort(m+1,r);
        merge(barang,l,m,r);
    }
}

// ================= BINARY SEARCH =================
int binarySearch(string x) {
    int l=0,r=n-1;
    while(l<=r) {
        int mid=(l+r)/2;
        if(barang[mid].id==x) return mid;
        if(barang[mid].id<x) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

// ================= LINEAR SEARCH =================
void linearSearch(string nama) {
    bool ada=false;
    for(int i=0;i<n;i++) {
        if(kapital(barang[i].nama)==kapital(nama)) {
            cout<<"Ditemukan ID "<<barang[i].id<<" di rak "<<barang[i].rak<<endl;
            ada=true;
        }
    }
    if(!ada) cout<<"Tidak ditemukan\n";
}

// ===================== MAIN =====================
int main() {
    int pilih;
    string inputStr;
    initData();

    do {
        clearScreen();

        cout<<"===================================\n";
        cout<<"Toko Elektronik & Aksesoris BINTANG\n";
        cout<<"===================================\n";
        cout<<"1.  Mengecek isi rak\n";
        cout<<"2.  Mengecek rute rak\n";
        cout<<"3.  Tambahkan produk\n";
        cout<<"4.  Hilangkan produk\n";
        cout<<"5.  Tampilkan produk\n";
        cout<<"6.  Urutkan ID produk\n";
        cout<<"7.  Urutkan stok produk\n";
        cout<<"8.  Cari ID produk\n";
        cout<<"9.  Cari nama produk\n";
        cout<<"10. Riwayat aktivitas\n";
        cout<<"11. Tambahkan antrean servis\n";
        cout<<"12. Panggil antrean servis\n";
        cout<<"13. Tampilkan antrean servis\n";
        cout<<"0.  Keluar\n\n";
        cout<<"Pilihan >> ";

        if (!(cin>>pilih)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pilih = -1;
        }

        cout<<endl;

        switch(pilih) {
            case 1: {
                cout<<"Pilih rak (A-K): ";
                cin>>inputStr;
                if(inputStr=="0") break;

                inputStr = kapital(inputStr);
                if(inputStr < "A" || inputStr > "K") {
                    cout<<"Rak tidak ditemukan\n";
                } else {
                    cekRak(inputStr);
                }
                tambahRiwayat("Mengecek isi rak");
                pauseScreen();
                break;
            }

            case 2: {
                cout<<"Pilih rak tujuan (A-K): ";
                cin>>inputStr;
                if(inputStr=="0") break;

                inputStr = kapital(inputStr);
                int idx=getRakIdx(inputStr);
                if(idx<=0) cout<<"Rak tidak ditemukan\n";
                else bfsCariJalur(0,idx);

                tambahRiwayat("Mengecek rute rak");
                pauseScreen();
                break;
            }

            case 3:
                tambahData();
                tambahRiwayat("Tambahkan produk");
                pauseScreen();
                break;

            case 4: {
                if(n == 0) {
                    cout<<"Data produk masih kosong\n";
                    pauseScreen();
                    break;
                }

                cout<<"Masukkan ID yang ingin dihapus: ";
                cin>>inputStr;
                if(inputStr=="0") break;

                mergeSort(0,n-1);
                int idx=binarySearch(kapital(inputStr));
                if(idx==-1) cout<<"Barang tidak ditemukan\n";
                else {
                    hapusData(idx);
                    cout<<"Barang berhasil dihapus\n";
                }
                tambahRiwayat("Hilangkan produk");
                pauseScreen();
                break;
            }

            case 5:
                if(n == 0) {
                    cout<<"Data produk masih kosong\n";
                } else {
                    tampilData();
                }
                tambahRiwayat("Tampilkan produk");
                pauseScreen();
                break;

            case 6:
                if(n == 0) {
                    cout<<"Data produk masih kosong\n";
                } else {
                    mergeSort(0,n-1);
                    cout<<"Data berhasil diurutkan berdasarkan 'ID'\n";
                }
                tambahRiwayat("Urutkan ID produk");
                pauseScreen();
                break;

            case 7:
                if(n == 0) {
                    cout<<"Data produk masih kosong\n";
                } else {
                    insertionSort();
                    cout<<"Data berhasil diurutkan berdasarkan 'stok'\n";
                }
                tambahRiwayat("Urutkan stok produk");
                pauseScreen();
                break;

            case 8: {
                if(n == 0) {
                    cout<<"Data produk masih kosong\n";
                    pauseScreen();
                    break;
                }

                cout<<"Masukkan ID yang ingin dicari: ";
                cin>>inputStr;
                if(inputStr=="0") break;

                mergeSort(0,n-1);
                int idx=binarySearch(kapital(inputStr));
                if(idx!=-1) {
                    cout<<"Berhasil menemukan ID dengan data:\n";
                    cout<<"Nama Barang : "<<barang[idx].nama<<endl;
                    cout<<"Stok        : "<<barang[idx].stok<<endl;
                    cout<<"Rak         : "<<barang[idx].rak<<endl;
                } else cout<<"ID tidak ditemukan\n";
                tambahRiwayat("Cari ID produk");
                pauseScreen();
                break;
            }

            case 9: {
                if(n == 0) {
                    cout<<"Data produk masih kosong\n";
                    pauseScreen();
                    break;
                }

                cout<<"Masukkan nama barang yang ingin dicari: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,inputStr);
                if(inputStr=="0" || inputStr.empty()) break;

                linearSearch(inputStr);
                tambahRiwayat("Cari nama produk");
                pauseScreen();
                break;
            }

            case 10:
                tampilRiwayat();
                pauseScreen();
                break;

            case 11: {
                string namaBaru;
                cout<<"ID Antrean: ";
                cin>>inputStr;
                if(inputStr=="0") break;
                inputStr=kapital(inputStr);

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Nama Pelanggan: ";
                getline(cin,namaBaru);
                if(namaBaru=="0" || namaBaru.empty()) break;

                antrean.push({inputStr,namaBaru});
                root=insertBST(root,inputStr,namaBaru);

                cout<<"Antrean ditambahkan\n";
                tambahRiwayat("Tambahkan antrean servis");
                pauseScreen();
                break;
            }

            case 12:
                if(!antrean.empty()) {
                    auto p=antrean.front();
                    antrean.pop();
                    cout<<"Memanggil ID: "<<p.first<<"\u2014"<<p.second<<endl;
                } else cout<<"Antrean servis saat ini kosong\n";
                tambahRiwayat("Panggil antrean servis");
                pauseScreen();
                break;

            case 13: {
                if(antrean.empty()) cout<<"Antrean servis saat ini kosong\n";
                else {
                    queue<pair<string,string>> temp=antrean;
                    while(!temp.empty()) {
                        cout<<temp.front().first<<"\u2014"<<temp.front().second<<endl;
                        temp.pop();
                    }
                }
                tambahRiwayat("Tampilkan antrean servis");
                pauseScreen();
                break;
            }

            case 0:
                cout<<"Keluar...\n";
                exit(0);
                break;

            default:
                cout<<"Pilihan tidak valid\n";
                pauseScreen();
        }

    } while(pilih!=0);

    return 0;
}
