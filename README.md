# Final Project Struktur Data - Kelompok 6
# Sistem Manajemen & Pencarian Lokasi pada Toko Elektronik BINTANG
 
---
 
## 1. Pembuka
 
Puji syukur kehadirat Tuhan Yang Maha Esa karena atas rahmat dan karunia-Nya, proyek akhir ini dapat diselesaikan dengan baik. Proyek dengan judul "Sistem Manajemen & Pencarian Lokasi pada Toko Elektronik BINTANG" ini disusun sebagai bentuk pemenuhan tugas akhir praktikum Struktur Data yang dibimbing oleh dosen kami, Pak Kurnia Prima Putra, S.Kom., M.T.
 
Proyek ini menjadi sarana untuk menerapkan secara langsung konsep-konsep struktur data yang telah dipelajari selama perkuliahan semester dua. Beberapa struktur data yang sebelumnya hanya dipahami secara teori, seperti array, graph, linked list, queue, serta binary search tree, pada proyek ini dicoba untuk diimplementasikan ke dalam satu sistem yang saling terhubung.
 
Ide pengembangan sistem berawal dari pengamatan terhadap denah lantai dan susunan rak di kawasan toko elektronik Jl. Pengayoman, Makassar, khususnya Toko Bintang Elektronik. Denah rak dan hubungan antar area tersebut menjadi inspirasi dalam merancang representasi graf serta struktur data lain yang digunakan pada proyek ini.
 
Sistem yang kami buat berbasis Terminal/Command Line Interface (CLI) dan berfokus pada pengelolaan data produk, pencarian produk, pemetaan rute antar rak, serta manajemen antrean servis pelanggan. Penggunaan CLI dipilih agar program tetap ringan dan dapat dijalankan pada berbagai perangkat tanpa membutuhkan spesifikasi tinggi.
 
Kami menyadari bahwa proyek ini masih memiliki banyak kekurangan, baik dari segi fitur maupun dari segi pengembangan sistemnya. Oleh karena itu, kritik dan saran sangat diharapkan untuk perbaikan ke proyek ini ke depannya.
 
---
 
## 2. Anggota Kelompok
 
| Nama | NIM | Kontribusi |
|------|-----|------------|
| Muh. Akram Marzuki | 250210501051 | `README.md`, `main.cpp` (integrasi, graph, BFS, queue, BST) |
| Muh. Aidil Al Qadri Az | 250210501035 | Array (struktur data barang, tambah, hapus, tampil), Merge Sort, Insertion Sort |
| Nur Syalsabila Oktavia R | 250210500024 | Linked List (riwayat aktivitas), Binary Search, Linear Search |
| Ade Irmawati | 250210500017 | Binary Search Tree (antrean servis pelanggan) |
 
---
 
## 3. Latar Belakang
 
Proyek ini terinspirasi dari struktur fisik Toko Bintang Elektronik yang berlokasi di kawasan Jl. Pengayoman, Makassar. Denah lantai toko beserta susunan raknya yang terdiri dari beberapa area berlabel (A hingga K) menjadi landasan dalam merancang representasi graf pada sistem ini. Tata letak rak tersebut digunakan sebagai acuan dalam membangun adjacency matrix yang merepresentasikan konektivitas antar rak di dalam toko.
 
Dari inspirasi denah tersebut, sistem dikembangkan untuk meniru fungsi-fungsi dasar pengelolaan toko secara sederhana, mulai dari manajemen stok produk per rak, pencarian jalur antar rak, hingga antrean servis pelanggan. Setiap fitur dirancang untuk memetakan salah satu konsep struktur data yang dipelajari selama perkuliahan.
 
Dengan memanfaatkan berbagai struktur data, sistem yang dibangun bertujuan menunjukkan bagaimana konsep-konsep tersebut dapat diintegrasikan dalam satu program yang fungsional:
 
- **Graph (Adjacency Matrix)** untuk merepresentasikan koneksi antar rak berdasarkan denah toko
- **BFS (Breadth-First Search)** untuk mencari rute terpendek dari pintu masuk ke rak tujuan
- **Array** untuk menyimpan dan mengelola data produk
- **Linked List** untuk mencatat riwayat aktivitas pengguna
- **Queue** untuk sistem antrean servis pelanggan
- **Binary Search Tree (BST)** untuk menyimpan data pelanggan antrean secara terurut
- **Merge Sort** untuk mengurutkan produk berdasarkan ID
- **Insertion Sort** untuk mengurutkan produk berdasarkan jumlah stok
- **Binary Search** untuk pencarian produk berdasarkan ID
- **Linear Search** untuk pencarian produk berdasarkan nama

---
 
## 4. Rancangan Sistem
 
Sistem dirancang dalam bentuk menu berbasis CLI sebagai berikut:
 
```
===================================
Toko Elektronik & Aksesoris BINTANG
===================================
1.  Mengecek isi rak
2.  Mengecek rute rak
3.  Tambahkan produk
4.  Hilangkan produk
5.  Tampilkan produk
6.  Urutkan ID produk
7.  Urutkan stok produk
8.  Cari ID produk
9.  Cari nama produk
10. Riwayat aktivitas
11. Tambahkan antrean servis
12. Panggil antrean servis
13. Tampilkan antrean servis
0.  Keluar
```
 
Penjelasan tiap menu beserta struktur data yang digunakan:

- **Mengecek isi rak** — Menampilkan daftar produk yang tersimpan pada rak tertentu (A–K). Menggunakan **Array**.
- **Mengecek rute rak** — Mencari dan menampilkan rute terpendek dari pintu masuk ke rak yang dituju. Menggunakan **Graph (Adjacency Matrix)** + **BFS**.
- **Tambahkan produk** — Menambahkan data produk baru (ID otomatis, nama, stok, rak) ke dalam sistem. Menggunakan **Array**.
- **Hilangkan produk** — Menghapus data produk berdasarkan ID yang dimasukkan. Menggunakan **Array** + **Merge Sort** + **Binary Search**.
- **Tampilkan produk** — Menampilkan seluruh data produk yang tersimpan beserta ID, stok, rak, dan nama. Menggunakan **Array**.
- **Urutkan ID produk** — Mengurutkan data produk secara alfabetis berdasarkan ID. Menggunakan **Merge Sort**.
- **Urutkan stok produk** — Mengurutkan data produk berdasarkan jumlah stok dari yang terkecil. Menggunakan **Insertion Sort**.
- **Cari ID produk** — Mencari produk berdasarkan ID dan menampilkan detail data. Menggunakan **Binary Search** (diawali Merge Sort).
- **Cari nama produk** — Mencari produk berdasarkan nama, tidak case-sensitive. Menggunakan **Linear Search**.
- **Riwayat aktivitas** — Menampilkan histori seluruh aktivitas yang telah dilakukan selama sesi berjalan. Menggunakan **Linked List**.
- **Tambahkan antrean servis** — Menambahkan pelanggan ke dalam antrean servis berdasarkan ID dan nama. Menggunakan **Queue** + **BST** (data juga disimpan ke BST).
- **Panggil antrean servis** — Memanggil dan mengeluarkan pelanggan pertama dari antrean. Menggunakan **Queue**.
- **Tampilkan antrean servis** — Menampilkan seluruh pelanggan yang sedang berada dalam antrean tanpa menghapus data. Menggunakan **Queue**.

---

## 5. Denah Graf Rak

Toko memiliki 12 node yang terdiri dari satu pintu masuk dan 11 rak berlabel A–K. Konektivitas antar rak direpresentasikan sebagai adjacency matrix berikut:

```
Node : PINTU, A, B, C, D, E, F, G, H, I, J, K

Koneksi:
  PINTU ↔ A, K
  A     ↔ PINTU, B, K
  B     ↔ A, C
  C     ↔ B, D, I
  D     ↔ C, E, I, J
  E     ↔ D, F, J
  F     ↔ E, G, I
  G     ↔ F, H, I
  H     ↔ G, I
  I     ↔ C, D, F, G, H
  J     ↔ D, E
  K     ↔ PINTU, A
```

Pencarian rute dari pintu masuk ke rak tujuan dilakukan menggunakan algoritma BFS sehingga jalur yang ditemukan adalah jalur dengan jumlah langkah paling sedikit.

---
 
## 6. Penutup
 
Berdasarkan hasil pengembangan yang telah dilakukan, dapat dilihat bahwa penerapan berbagai struktur data dalam sebuah sistem dapat membantu pengelolaan data secara lebih teratur dan efisien. Setiap struktur data yang digunakan memiliki peran masing-masing dan saling melengkapi dalam mendukung fitur yang ada.
 
Proses pengerjaan proyek ini memberikan pemahaman yang lebih mendalam mengenai bagaimana konsep struktur data diterapkan dalam bentuk program nyata, mulai dari manajemen inventaris produk, penelusuran rute graf, hingga sistem antrean. Tidak hanya memahami cara kerja masing-masing struktur, tetapi juga bagaimana menggabungkannya dalam satu program yang berjalan secara utuh.
 
Meskipun sistem yang dibuat masih tergolong sederhana dan berbasis CLI, program ini telah mencakup sejumlah fungsi dasar yang relevan sebagai simulasi sistem manajemen toko. Oleh karena itu, sistem ini masih dapat dikembangkan lebih lanjut, misalnya dengan menambahkan antarmuka grafis, fitur persistensi data, atau pengembangan fitur graf yang lebih kompleks.
 
Terakhir, diharapkan proyek ini dapat menjadi referensi bagi yang ingin mengembangkan lebih lanjut sistem serupa dengan menambahkan fitur yang lebih kompleks serta meningkatkan efisiensi program secara keseluruhan.
