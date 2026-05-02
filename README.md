# Final Project Struktur Data - Kelompok 6
# Sistem Manajemen & Pencarian Lokasi pada Toko Elektronik BINTANG
 
---
 
## 1. Pembuka
 
Puji syukur kehadirat Tuhan Yang Maha Esa karena atas rahmat dan karunia-Nya, proyek akhir ini dapat diselesaikan dengan baik. Proyek dengan sistem "Sistem Manajemen & Pencarian Lokasi pada Toko Elektronik BINTANG" ini disusun sebagai bentuk pemenuhan tugas akhir praktikum Struktur Data yang dibimbing oleh dosen kami, Pak Kurnia Prima Putra, S.Kom., M.T.
 
Dalam proses pengerjaannya, proyek ini menjadi sarana untuk menerapkan secara langsung konsep-konsep struktur data yang telah dipelajari selama perkuliahan semester dua. Beberapa struktur data yang sebelumnya hanya dipahami secara teori seperti array, graph, linked list, serta binary search tree, pada proyek ini dicoba untuk diimplementasikan ke dalam satu sistem yang saling terhubung.
 
Pengembangan sistem dilakukan secara bertahap, dimulai dari perancangan fitur, pembagian tugas, hingga proses integrasi program. Pada tahap integrasi, setiap bagian yang telah dikerjakan secara terpisah perlu disesuaikan kembali agar dapat berjalan dalam satu alur program yang utuh. Hal ini menjadi salah satu bagian yang cukup menantang, karena setiap struktur data memiliki cara kerja yang berbeda.
 
Adapun sistem yang kami buat berbasis pada Terminal/Command Line Interface (CLI) dan berfokus pada pengelolaan data barang, pencarian produk, serta pemetaan lokasi rak dalam toko. Penggunaan CLI ketimbang GUI dilakukan agar program tetap ringan dan dapat dijalankan pada berbagai perangkat tanpa membutuhkan spesifikasi tinggi.
 
Selain itu, kami juga menyadari bahwa proyek ini masih memiliki banyak kekurangan, baik dari segi fitur maupun dari segi pengembangan sistemnya. Oleh karena itu, kritik dan saran sangat diharapkan untuk perbaikan ke proyek ini kedepannya.
 
---
 
## 2. Anggota Kelompok
 
| Nama | NIM | Kontribusi |
|------|-----|------------|
| Muh. Akram Marzuki | 250210501051 | `README.md`, `main.cpp`, `graph.cpp` |
| Muh. Aidil Al Qadri Az | 250210501035 | `array.cpp`, `sorting.cpp` |
| Nur Syalsabila Oktavia R | 250210500024 | `linkedlist.cpp`, `search.cpp` |
| Ade Irmawati | 250210500017 | `bst.cpp` |
 
---
 
## 3. Latar Belakang
 
Pada toko elektronik terutama yang memiliki banyak jenis barang, proses pencarian produk sering kali menjadi kurang efisien. Hal ini disebabkan oleh banyaknya variasi barang serta penempatan rak yang cukup sempit (kompleks). Ketika jumlah barang terus bertambah, pencarian secara manual menjadi semakin sulit dan memakan waktu.
 
Kondisi tersebut dapat ditemukan pada pusat penjualan elektronik di kawasan Jl. Pengayoman, Makassar, terutama pada toko seperti Toko Bintang Elektronik. Dengan banyaknya jenis produk yang tersedia, penataan barang biasanya disusun berdasarkan kategori tertentu, namun tetap membutuhkan pemahaman terhadap letak rak agar proses pencarian dapat dilakukan dengan cepat.
 
Selain itu, pengelolaan data barang dan pelanggan juga menjadi hal yang penting. Tanpa sistem yang terstruktur, pencatatan data inventaris dapat menjadi tidak rapi, dan riwayat aktivitas pengguna tidak dapat ditelusuri dengan baik. Hal ini dapat berdampak pada efisiensi kerja, terutama ketika jumlah data semakin banyak.
 
Berdasarkan permasalahan tersebut, diperlukan suatu sistem yang dapat membantu dalam pengelolaan data sekaligus mempermudah proses pencarian barang. Dalam proyek ini, pendekatan yang digunakan adalah dengan memanfaatkan beberapa struktur data yang memiliki fungsi sebagai berikut:
 
- **Graph** untuk merepresentasikan hubungan antar rak
- **Array** untuk menyimpan data barang
- **Linked List** untuk riwayat aktivitas
- **Binary Search Tree (BST)** untuk data pelanggan VIP

Dengan menggabungkan beberapa struktur data tersebut, sistem yang dibangun diharapkan dapat membantu menyederhanakan proses yang sebelumnya dilakukan secara manual menjadi lebih terstruktur dan efisien.
 
---
 
## 4. Rancangan Sistem
 
Sistem dirancang dalam bentuk menu berbasis CLI sebagai berikut:
 
```
>. Toko Elektronik BINTANG
 
==== MENU ====
1. Mengecek rak
2. Tambahkan data
3. Tampilkan data
4. Urutkan ID
5. Urutkan stok
6. Cari ID
7. Cari produk
8. Riwayat
9. Tambahkan VIP
10. Tampilkan VIP
==============
```
 
Setiap menu dirancang untuk mewakili fungsi tertentu dalam sistem, yaitu:
- **Mengecek rak (Graph)**
Fitur ini digunakan untuk melihat hubungan antar rak dalam toko. Dengan menggunakan graph, setiap rak direpresentasikan sebagai node dan hubungan antar rak sebagai edge, sehingga memudahkan dalam memahami struktur lokasi barang.
- **Tambahkan data (Array)**
Digunakan untuk menambahkan data barang ke dalam sistem, seperti ID, nama produk, dan jumlah stok. Data ini akan disimpan dalam struktur array.
- **Tampilkan data (Array)**
Menampilkan seluruh data barang yang telah tersimpan, sehingga pengguna dapat melihat daftar inventaris yang tersedia.
- **Urutkan ID (Merge Sort)**
Mengurutkan data berdasarkan ID menggunakan algoritma merge sort. Pengurutan ini diperlukan agar proses pencarian dengan binary search dapat dilakukan.
- **Urutkan stok (Insertion Sort)**
Mengurutkan data berdasarkan jumlah stok menggunakan insertion sort, sehingga dapat diketahui barang dengan stok rendah atau tinggi.
- **Cari ID (Binary Search)**
Digunakan untuk mencari data barang berdasarkan ID dengan lebih cepat setelah data dalam keadaan terurut.
- **Cari produk (Linear Search)**
Digunakan untuk mencari barang berdasarkan nama produk, terutama ketika data belum diurutkan berdasarkan nama.
- **Riwayat (Linked List)**
Menyimpan histori aktivitas pengguna, seperti pencarian yang dilakukan. Struktur linked list digunakan karena fleksibel dalam penambahan data.
- **Tambahkan VIP (BST)**
Digunakan untuk menambahkan data pelanggan VIP ke dalam sistem dengan struktur binary search tree.
- **Tampilkan VIP (BST)**
Menampilkan data pelanggan VIP secara terurut berdasarkan aturan BST.
Secara keseluruhan, setiap fitur dirancang agar saling terhubung dan mendukung proses pengelolaan data dalam sistem.
 
---
 
## 5. Penutup
 
Berdasarkan hasil pengembangan yang telah dilakukan, dapat dilihat bahwa penerapan struktur data dalam sebuah sistem dapat membantu dalam pengelolaan data secara lebih teratur dan efisien. Setiap struktur data yang digunakan memiliki fungsi masing-masing dan berperan dalam mendukung fitur yang ada.
 
Proses pengerjaan proyek ini juga memberikan pemahaman yang lebih jelas mengenai bagaimana konsep struktur data diterapkan dalam bentuk program. Tidak hanya memahami cara kerja masing-masing struktur, tetapi juga bagaimana menggabungkannya dalam satu sistem yang berjalan secara utuh.
 
Meskipun sistem yang dibuat masih tergolong sederhana, namun sudah mencakup beberapa fungsi dasar yang dibutuhkan dalam pengelolaan toko elektronik. Oleh karena itu, sistem ini masih dapat dikembangkan lebih lanjut, baik dari segi fitur maupun tampilan.
 
Terakhir, diharapkan untuk ke depannya segala pihak dapat mengembangkan lebih lanjut proyek ini dengan menambahkan fitur yang lebih kompleks serta meningkatkan efisiensi program secara keseluruhan.
