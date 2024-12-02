
# Sistem Booking Hotel 

## Deskripsi
Sistem Booking Hotel adalah sebuah program berbasis C++ yang memungkinkan pengguna untuk melakukan reservasi hotel secara virtual. Aplikasi ini memiliki berbagai fitur seperti pemilihan tipe kamar, kasur, nomor kamar, durasi menginap, hingga pembayaran. Selain itu, terdapat fitur sorting nomor kamar dan konversi umur menjadi teks untuk memberikan pengalaman pengguna yang lebih baik.

## Fitur
1. **Booking Hotel**
   - Pilihan tipe kamar: Standard Room, Twin Room, Family Room, Presidential Suite.
   - Pilihan tipe kasur: Single bed, Double bed, Twin bed, King bed.
   - Pemilihan nomor kamar (dengan fitur sorting).
   - Durasi menginap berdasarkan tanggal check-in dan check-out.
   - Verifikasi umur pengguna sebelum booking.

2. **History Booking**
   - Melihat informasi detail dari pemesanan sebelumnya.

3. **Fasilitas Hotel**
   - Menampilkan fasilitas hotel yang tersedia.

4. **Promo Menarik**
   - Memberikan informasi terkait promo hotel.

5. **Pembayaran**
   - Sistem pembayaran dengan kalkulasi otomatis berdasarkan tipe kamar dan durasi menginap.

6. **Cetak File Booking**
   - Menyimpan detail pemesanan dalam file untuk kebutuhan dokumentasi.

## Struktur Program
- **Variabel Global:** Menyimpan informasi umum seperti tipe kamar, harga, nomor kamar, dll.
- **Fungsi dan Prosedur:** Dibagi berdasarkan fitur untuk modularitas kode.
- **Rekursif:** Digunakan untuk mengonversi umur menjadi teks.
- **Sorting:** Algoritma Insertion Sort diterapkan pada daftar nomor kamar.
- **Struct:** Digunakan untuk menyimpan data identitas pelanggan.

## Cara Menggunakan
1. Clone repositori ini.
2. Buka file `main.cpp` di editor C++ favorit Anda.
3. Kompilasi program menggunakan compiler seperti `g++`.
   ```bash
   g++ main.cpp -o SistemBookingHotel
   ```
4. Jalankan file eksekusi yang dihasilkan.
   ```bash
   ./SistemBookingHotel
   ```

## Prasyarat
- Compiler C++ (contoh: GCC, MinGW).
- Terminal atau command prompt untuk menjalankan program.

## Teknologi yang Digunakan
- **Bahasa Pemrograman:** C++
- **Library:** 
  - `<iostream>`: Untuk input/output.
  - `<conio.h>`: Untuk manipulasi input konsol.
  - `<fstream>`: Untuk membaca/menulis file.

## Penulis
Proyek ini dikembangkan oleh [Nama Anda].

## Lisensi
Proyek ini dilisensikan di bawah [MIT License](LICENSE).
