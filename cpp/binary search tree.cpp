#include <iostream>
#include <string>
using namespace std;

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
    cout<<r->id<<" — "<<r->nama<<endl;
    inorder(r->kanan);
}
queue<pair<string,string>> antrean;
