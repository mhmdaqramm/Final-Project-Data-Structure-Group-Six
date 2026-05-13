#include <iostream>
#include <string>
#include <cctype>
using namespace std;

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
        cout<<"— "<<t->aktivitas<<endl;
        t=t->next;
    }
}

string kapital(string s) {
    for(int i=0;i<s.length();i++) {
        s[i]=toupper(s[i]);
    }
    return s;
}

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
