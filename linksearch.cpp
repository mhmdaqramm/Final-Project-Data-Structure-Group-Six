#include <iostream>
#inlcude <string>
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
