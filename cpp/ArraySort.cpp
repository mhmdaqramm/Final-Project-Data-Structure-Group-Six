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
//NOTE : tolong di cek coba, struct ini sudah sesuai blum?

