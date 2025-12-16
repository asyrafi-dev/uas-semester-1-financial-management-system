# 📊 SISTEM MANAJEMEN KEUANGAN USAHA ONLINE

## 📝 Deskripsi Program

Program **Sistem Manajemen Keuangan Usaha Online** adalah aplikasi berbasis konsol yang digunakan untuk mencatat dan mengelola keuangan usaha online secara sederhana. Program ini dibuat menggunakan bahasa pemrograman **C++**.

---

## ✨ Fitur Program

| No | Fitur | Keterangan |
|----|-------|------------|
| 1 | Tambah Pemasukan | Mencatat pemasukan dengan keterangan dan jumlah |
| 2 | Tambah Pengeluaran | Mencatat pengeluaran dengan keterangan dan jumlah |
| 3 | Lihat Riwayat Pemasukan | Menampilkan daftar semua pemasukan |
| 4 | Lihat Riwayat Pengeluaran | Menampilkan daftar semua pengeluaran |
| 5 | Laporan Keuangan Lengkap | Menampilkan laporan pemasukan & pengeluaran |
| 6 | Saldo & Status Keuangan | Menampilkan saldo dan analisis keuangan |
| 7 | Reset Semua Data | Menghapus semua data transaksi |
| 0 | Keluar Program | Mengakhiri program |

---

## 📐 ALGORITMA PROGRAM

### 🔷 Algoritma Utama (Main Program)

```
ALGORITMA Sistem_Manajemen_Keuangan_Usaha_Online

DEKLARASI:
    KONSTANTA:
        MAX_TRANSAKSI = 100
    
    VARIABEL:
        keteranganPemasukan : array [1..100] of string
        jumlahPemasukan : array [1..100] of real
        totalTransaksiPemasukan : integer
        
        keteranganPengeluaran : array [1..100] of string
        jumlahPengeluaran : array [1..100] of real
        totalTransaksiPengeluaran : integer
        
        pilihan : integer

ALGORITMA:
    1. MULAI
    2. Inisialisasi semua variabel dengan nilai awal 0
    3. ULANGI
        3.1. Bersihkan layar
        3.2. Tampilkan header program
        3.3. Tampilkan menu utama
        3.4. Input pilihan dari pengguna
        3.5. JIKA pilihan = 1 MAKA
                Panggil prosedur tambahPemasukan()
             LAIN JIKA pilihan = 2 MAKA
                Panggil prosedur tambahPengeluaran()
             LAIN JIKA pilihan = 3 MAKA
                Panggil prosedur lihatRiwayatPemasukan()
             LAIN JIKA pilihan = 4 MAKA
                Panggil prosedur lihatRiwayatPengeluaran()
             LAIN JIKA pilihan = 5 MAKA
                Panggil prosedur lihatLaporanLengkap()
             LAIN JIKA pilihan = 6 MAKA
                Panggil prosedur lihatSaldoDanStatus()
             LAIN JIKA pilihan = 7 MAKA
                Panggil prosedur resetData()
             LAIN JIKA pilihan = 0 MAKA
                Tampilkan pesan "Terima Kasih"
             LAIN
                Tampilkan pesan "Pilihan tidak valid"
             AKHIR JIKA
    4. SAMPAI pilihan = 0
    5. SELESAI
```

---

### 🔷 Algoritma Tambah Pemasukan

```
ALGORITMA tambahPemasukan

DEKLARASI:
    keterangan : string
    jumlah : real

ALGORITMA:
    1. MULAI
    2. Bersihkan layar
    3. Tampilkan header "TAMBAH PEMASUKAN"
    4. JIKA totalTransaksiPemasukan >= MAX_TRANSAKSI MAKA
        4.1. Tampilkan "Data pemasukan sudah penuh!"
        4.2. KEMBALI
       AKHIR JIKA
    5. Input keterangan pemasukan
    6. Input jumlah pemasukan
    7. JIKA jumlah <= 0 MAKA
        7.1. Tampilkan "Jumlah harus lebih dari 0!"
        7.2. KEMBALI
       AKHIR JIKA
    8. Simpan keterangan ke array keteranganPemasukan[totalTransaksiPemasukan]
    9. Simpan jumlah ke array jumlahPemasukan[totalTransaksiPemasukan]
    10. Tambah totalTransaksiPemasukan dengan 1
    11. Tampilkan "Pemasukan berhasil ditambahkan!"
    12. Tampilkan total pemasukan saat ini
    13. SELESAI
```

---

### 🔷 Algoritma Tambah Pengeluaran

```
ALGORITMA tambahPengeluaran

DEKLARASI:
    keterangan : string
    jumlah : real

ALGORITMA:
    1. MULAI
    2. Bersihkan layar
    3. Tampilkan header "TAMBAH PENGELUARAN"
    4. JIKA totalTransaksiPengeluaran >= MAX_TRANSAKSI MAKA
        4.1. Tampilkan "Data pengeluaran sudah penuh!"
        4.2. KEMBALI
       AKHIR JIKA
    5. Input keterangan pengeluaran
    6. Input jumlah pengeluaran
    7. JIKA jumlah <= 0 MAKA
        7.1. Tampilkan "Jumlah harus lebih dari 0!"
        7.2. KEMBALI
       AKHIR JIKA
    8. Simpan keterangan ke array keteranganPengeluaran[totalTransaksiPengeluaran]
    9. Simpan jumlah ke array jumlahPengeluaran[totalTransaksiPengeluaran]
    10. Tambah totalTransaksiPengeluaran dengan 1
    11. Tampilkan "Pengeluaran berhasil ditambahkan!"
    12. Tampilkan total pengeluaran saat ini
    13. SELESAI
```

---

### 🔷 Algoritma Hitung Total Pemasukan

```
ALGORITMA hitungTotalPemasukan

DEKLARASI:
    total : real
    i : integer

ALGORITMA:
    1. MULAI
    2. Set total = 0
    3. UNTUK i = 0 SAMPAI totalTransaksiPemasukan - 1 LAKUKAN
        3.1. total = total + jumlahPemasukan[i]
       AKHIR UNTUK
    4. KEMBALIKAN nilai total
    5. SELESAI
```

---

### 🔷 Algoritma Hitung Total Pengeluaran

```
ALGORITMA hitungTotalPengeluaran

DEKLARASI:
    total : real
    i : integer

ALGORITMA:
    1. MULAI
    2. Set total = 0
    3. UNTUK i = 0 SAMPAI totalTransaksiPengeluaran - 1 LAKUKAN
        3.1. total = total + jumlahPengeluaran[i]
       AKHIR UNTUK
    4. KEMBALIKAN nilai total
    5. SELESAI
```

---

### 🔷 Algoritma Lihat Saldo & Status Keuangan

```
ALGORITMA lihatSaldoDanStatus

DEKLARASI:
    totalMasuk : real
    totalKeluar : real
    saldo : real
    persentase : real

ALGORITMA:
    1. MULAI
    2. Bersihkan layar
    3. Tampilkan header "SALDO & STATUS KEUANGAN"
    4. totalMasuk = hitungTotalPemasukan()
    5. totalKeluar = hitungTotalPengeluaran()
    6. saldo = totalMasuk - totalKeluar
    7. JIKA totalMasuk > 0 MAKA
        7.1. persentase = (saldo / totalMasuk) × 100
       LAIN
        7.2. persentase = 0
       AKHIR JIKA
    8. Tampilkan ringkasan keuangan
    9. JIKA totalMasuk = 0 DAN totalKeluar = 0 MAKA
        9.1. Tampilkan "STATUS: BELUM ADA TRANSAKSI"
       LAIN JIKA saldo > 0 MAKA
        9.2. Tampilkan "STATUS: UNTUNG / SURPLUS"
       LAIN JIKA saldo < 0 MAKA
        9.3. Tampilkan "STATUS: RUGI / DEFISIT"
       LAIN
        9.4. Tampilkan "STATUS: IMPAS / BREAK EVEN"
       AKHIR JIKA
    10. SELESAI
```

---

### 🔷 Algoritma Reset Data

```
ALGORITMA resetData

DEKLARASI:
    konfirmasi : char
    i : integer

ALGORITMA:
    1. MULAI
    2. Bersihkan layar
    3. Tampilkan header "RESET SEMUA DATA"
    4. Tampilkan peringatan dan data yang akan dihapus
    5. Input konfirmasi (y/n)
    6. JIKA konfirmasi = 'y' ATAU konfirmasi = 'Y' MAKA
        6.1. Set totalTransaksiPemasukan = 0
        6.2. Set totalTransaksiPengeluaran = 0
        6.3. UNTUK i = 0 SAMPAI MAX_TRANSAKSI - 1 LAKUKAN
            6.3.1. keteranganPemasukan[i] = ""
            6.3.2. jumlahPemasukan[i] = 0
            6.3.3. keteranganPengeluaran[i] = ""
            6.3.4. jumlahPengeluaran[i] = 0
             AKHIR UNTUK
        6.4. Tampilkan "Semua data telah direset"
       LAIN
        6.5. Tampilkan "Data tidak jadi dihapus"
       AKHIR JIKA
    7. SELESAI
```

---

## 📊 FLOWCHART PROGRAM

### 🔶 Definisi Flowchart

**Flowchart** (Diagram Alir) adalah representasi grafis dari langkah-langkah dan urutan prosedur dalam suatu program atau proses. Flowchart menggambarkan alur logika program secara visual sehingga lebih mudah dipahami.

#### 📌 Pengertian Flowchart

Flowchart adalah diagram yang menunjukkan urutan langkah-langkah dalam menyelesaikan suatu masalah atau proses menggunakan simbol-simbol standar yang dihubungkan dengan garis alir (flow lines). Flowchart membantu programmer dalam:

1. **Memahami Alur Program** - Visualisasi langkah-langkah program dari awal hingga akhir
2. **Menganalisis Masalah** - Mengidentifikasi titik-titik keputusan dan percabangan
3. **Dokumentasi Program** - Menyediakan dokumentasi visual yang mudah dipahami
4. **Komunikasi** - Memudahkan komunikasi antar programmer atau dengan pengguna
5. **Debugging** - Membantu menemukan kesalahan logika dalam program

#### 📌 Jenis-Jenis Flowchart

| Jenis | Keterangan |
|-------|------------|
| **System Flowchart** | Menggambarkan alur kerja sistem secara keseluruhan |
| **Program Flowchart** | Menggambarkan alur logika program secara detail |
| **Document Flowchart** | Menggambarkan alur dokumen dalam suatu sistem |
| **Process Flowchart** | Menggambarkan langkah-langkah proses secara berurutan |

#### 📌 Aturan Pembuatan Flowchart

1. Flowchart harus dimulai dari **atas ke bawah** atau **kiri ke kanan**
2. Setiap flowchart harus memiliki **satu titik awal (START)** dan **satu atau lebih titik akhir (END)**
3. Arah alur harus jelas dengan menggunakan **garis panah**
4. Gunakan **simbol standar** yang sesuai dengan fungsinya
5. Hindari **perpotongan garis** alir sebisa mungkin
6. Setiap simbol harus memiliki **keterangan yang jelas dan singkat**
7. Gunakan **connector** jika flowchart terlalu panjang atau kompleks

---

### 🔶 Keterangan Simbol Flowchart

| Simbol | Nama | Keterangan | Fungsi |
|--------|------|------------|--------|
| ⬭ (Oval) | **Terminator** | Simbol berbentuk oval/elips | Menandakan permulaan (START) atau akhir (STOP/END) dari program |
| ▭ (Persegi Panjang) | **Process** | Simbol berbentuk persegi panjang | Menyatakan proses/pengolahan data yang dilakukan oleh komputer, seperti perhitungan, assignment, atau operasi |
| ◇ (Belah Ketupat) | **Decision** | Simbol berbentuk belah ketupat/diamond | Menyatakan pengambilan keputusan berdasarkan kondisi tertentu, memiliki dua atau lebih cabang (Ya/Tidak atau True/False) |
| ▱ (Jajar Genjang) | **Input/Output** | Simbol berbentuk jajar genjang | Menyatakan proses input (menerima data dari pengguna) atau output (menampilkan hasil ke layar) |
| → (Panah) | **Flow Direction** | Garis dengan anak panah | Menunjukkan arah alur program dan menghubungkan antar simbol |
| ○ (Lingkaran Kecil) | **Connector** | Simbol berbentuk lingkaran kecil | Menghubungkan bagian flowchart yang terputus dalam satu halaman |
| ⬠ (Pentagon) | **Off-page Connector** | Simbol berbentuk pentagon | Menghubungkan flowchart yang berlanjut ke halaman berbeda |
| ▭▭ (Predefined Process) | **Subroutine/Procedure** | Persegi panjang dengan garis vertikal di sisi | Memanggil subprogram atau prosedur yang sudah didefinisikan |

---

### 🔶 Flowchart Program Utama

```
                    ┌─────────────────┐
                    │     MULAI       │
                    │   (Terminator)  │
                    └────────┬────────┘
                             │
                             ▼
        ┌─────────────────────────────────────┐
        │         INISIALISASI VARIABEL       │
        │              (Process)              │
        │                                     │
        │  • totalTransaksiPemasukan = 0      │
        │  • totalTransaksiPengeluaran = 0    │
        │  • Array keteranganPemasukan = []   │
        │  • Array jumlahPemasukan = []       │
        │  • Array keteranganPengeluaran = [] │
        │  • Array jumlahPengeluaran = []     │
        └────────────────┬────────────────────┘
                         │
            ┌────────────┴────────────────┐
            │                             │
            ▼                             │
   ┌─────────────────┐                    │
   │  Bersihkan      │                    │
   │  Layar          │                    │
   │  (Process)      │                    │
   └────────┬────────┘                    │
            │                             │
            ▼                             │
   ┌─────────────────┐                    │
   │ Tampilkan       │                    │
   │ Header & Menu   │                    │
   │ (Process)       │                    │
   └────────┬────────┘                    │
            │                             │
            ▼                             │
   ┌─────────────────┐                    │
   │  Input          │                    │
   │  Pilihan        │                    │
   │  (Input/Output) │                    │
   └────────┬────────┘                    │
            │                             │
            ▼                             │
   ┌─────────────────┐                    │
   │   Pilihan?      │                    │
   │   (Decision)    │                    │
   └────────┬────────┘                    │
            │                             │
    ┌───────┴───────┐                     │
    │               │                     │
    ▼               ▼                     │
┌───────┐       ┌───────┐                 │
│1,2,3, │       │   0   │                 │
│4,5,6,7│       └───┬───┘                 │
└───┬───┘           │                     │
    │               ▼                     │
    ▼       ┌─────────────────┐           │
┌────────┐  │  Tampilkan      │           │
│Jalankan│  │  "Terima Kasih" │           │
│ Fungsi │  │  (Process)      │           │
│ Sesuai │  └────────┬────────┘           │
│Pilihan │           │                    │
│(Process│           ▼                    │
└───┬────┘  ┌─────────────────┐           │
    │       │    SELESAI      │           │
    │       │   (Terminator)  │           │
    │       └─────────────────┘           │
    │                                     │
    └─────────────────────────────────────┘
              (Kembali ke Bersihkan Layar)
```

**Penjelasan Inisialisasi Variabel:**
- `totalTransaksiPemasukan = 0` → Menyimpan jumlah transaksi pemasukan (awalnya 0)
- `totalTransaksiPengeluaran = 0` → Menyimpan jumlah transaksi pengeluaran (awalnya 0)
- `Array keteranganPemasukan` → Array kosong untuk menyimpan keterangan pemasukan
- `Array jumlahPemasukan` → Array kosong untuk menyimpan nilai pemasukan
- `Array keteranganPengeluaran` → Array kosong untuk menyimpan keterangan pengeluaran
- `Array jumlahPengeluaran` → Array kosong untuk menyimpan nilai pengeluaran

---

### 🔶 Flowchart Tambah Pemasukan

```
                    ┌─────────────────┐
                    │     MULAI       │
                    │   (Terminator)  │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │  Bersihkan      │
                    │  Layar          │
                    │  (Process)      │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ Tampilkan       │
                    │ Header Tambah   │
                    │ Pemasukan       │
                    │ (Process)       │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ totalTransaksi  │     ┌─────────────────┐
                    │ Pemasukan >=    │ Ya  │ Tampilkan       │
                    │ MAX_TRANSAKSI ? ├────►│ "Data Penuh"    │
                    │   (Decision)    │     │ (Process)       │
                    └────────┬────────┘     └────────┬────────┘
                             │ Tidak                 │
                             ▼                       │
                    ┌─────────────────┐              │
                    │ Input           │              │
                    │ Keterangan      │              │
                    │ (Input/Output)  │              │
                    └────────┬────────┘              │
                             │                       │
                             ▼                       │
                    ┌─────────────────┐              │
                    │ Input           │              │
                    │ Jumlah          │              │
                    │ (Input/Output)  │              │
                    └────────┬────────┘              │
                             │                       │
                             ▼                       │
                    ┌─────────────────┐              │
                    │ Jumlah <= 0 ?   │ Ya  ┌───────┴───────┐
                    │   (Decision)    ├────►│ Tampilkan     │
                    └────────┬────────┘     │ "Error"       │
                             │ Tidak        │ (Process)     │
                             ▼              └───────┬───────┘
                    ┌─────────────────┐             │
                    │ Simpan          │             │
                    │ Keterangan &    │             │
                    │ Jumlah ke Array │             │
                    │ (Process)       │             │
                    └────────┬────────┘             │
                             │                      │
                             ▼                      │
                    ┌─────────────────┐             │
                    │ totalTransaksi  │             │
                    │ Pemasukan++     │             │
                    │ (Process)       │             │
                    └────────┬────────┘             │
                             │                      │
                             ▼                      │
                    ┌─────────────────┐             │
                    │ Tampilkan       │             │
                    │ "Berhasil"      │             │
                    │ (Output)        │             │
                    └────────┬────────┘             │
                             │                      │
                             ├──────────────────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │    SELESAI      │
                    │   (Terminator)  │
                    └─────────────────┘
```

---

### 🔶 Flowchart Tambah Pengeluaran

```
                    ┌─────────────────┐
                    │     MULAI       │
                    │   (Terminator)  │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │  Bersihkan      │
                    │  Layar          │
                    │  (Process)      │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ Tampilkan       │
                    │ Header Tambah   │
                    │ Pengeluaran     │
                    │ (Process)       │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ totalTransaksi  │     ┌─────────────────┐
                    │ Pengeluaran >=  │ Ya  │ Tampilkan       │
                    │ MAX_TRANSAKSI ? ├────►│ "Data Penuh"    │
                    │   (Decision)    │     │ (Process)       │
                    └────────┬────────┘     └────────┬────────┘
                             │ Tidak                 │
                             ▼                       │
                    ┌─────────────────┐              │
                    │ Input           │              │
                    │ Keterangan      │              │
                    │ (Input/Output)  │              │
                    └────────┬────────┘              │
                             │                       │
                             ▼                       │
                    ┌─────────────────┐              │
                    │ Input           │              │
                    │ Jumlah          │              │
                    │ (Input/Output)  │              │
                    └────────┬────────┘              │
                             │                       │
                             ▼                       │
                    ┌─────────────────┐              │
                    │ Jumlah <= 0 ?   │ Ya  ┌───────┴───────┐
                    │   (Decision)    ├────►│ Tampilkan     │
                    └────────┬────────┘     │ "Error"       │
                             │ Tidak        │ (Process)     │
                             ▼              └───────┬───────┘
                    ┌─────────────────┐             │
                    │ Simpan          │             │
                    │ Keterangan &    │             │
                    │ Jumlah ke Array │             │
                    │ (Process)       │             │
                    └────────┬────────┘             │
                             │                      │
                             ▼                      │
                    ┌─────────────────┐             │
                    │ totalTransaksi  │             │
                    │ Pengeluaran++   │             │
                    │ (Process)       │             │
                    └────────┬────────┘             │
                             │                      │
                             ▼                      │
                    ┌─────────────────┐             │
                    │ Tampilkan       │             │
                    │ "Berhasil"      │             │
                    │ (Output)        │             │
                    └────────┬────────┘             │
                             │                      │
                             ├──────────────────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │    SELESAI      │
                    │   (Terminator)  │
                    └─────────────────┘
```

---

### 🔶 Flowchart Hitung Saldo & Status Keuangan

```
                    ┌─────────────────┐
                    │     MULAI       │
                    │   (Terminator)  │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ totalMasuk =    │
                    │ hitungTotal     │
                    │ Pemasukan()     │
                    │ (Process)       │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ totalKeluar =   │
                    │ hitungTotal     │
                    │ Pengeluaran()   │
                    │ (Process)       │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ saldo =         │
                    │ totalMasuk -    │
                    │ totalKeluar     │
                    │ (Process)       │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ totalMasuk = 0  │     ┌─────────────────┐
                    │ DAN             │ Ya  │ Tampilkan       │
                    │ totalKeluar = 0?├────►│ "BELUM ADA      │
                    │   (Decision)    │     │  TRANSAKSI"     │
                    └────────┬────────┘     │ (Output)        │
                             │ Tidak        └────────┬────────┘
                             ▼                       │
                    ┌─────────────────┐              │
                    │ saldo > 0 ?     │     ┌───────┴───────┐
                    │   (Decision)    │ Ya  │ Tampilkan     │
                    └────────┬────────┼────►│ "UNTUNG /     │
                             │ Tidak  │     │  SURPLUS"     │
                             ▼        │     │ (Output)      │
                    ┌─────────────────┐     └───────┬───────┘
                    │ saldo < 0 ?     │             │
                    │   (Decision)    │ Ya  ┌───────┴───────┐
                    └────────┬────────┼────►│ Tampilkan     │
                             │ Tidak  │     │ "RUGI /       │
                             ▼        │     │  DEFISIT"     │
                    ┌─────────────────┐     │ (Output)      │
                    │ Tampilkan       │     └───────┬───────┘
                    │ "IMPAS /        │             │
                    │  BREAK EVEN"    │             │
                    │ (Output)        │             │
                    └────────┬────────┘             │
                             │                      │
                             ├──────────────────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │    SELESAI      │
                    │   (Terminator)  │
                    └─────────────────┘
```

---

### 🔶 Flowchart Reset Data

```
                    ┌─────────────────┐
                    │     MULAI       │
                    │   (Terminator)  │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ Tampilkan       │
                    │ Peringatan &    │
                    │ Data yg Dihapus │
                    │ (Output)        │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ Input           │
                    │ Konfirmasi      │
                    │ (y/n)           │
                    │ (Input/Output)  │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │ konfirmasi =    │     ┌─────────────────┐
                    │ 'y' atau 'Y' ?  │ Ya  │ Reset semua     │
                    │   (Decision)    ├────►│ variabel ke 0   │
                    └────────┬────────┘     │ (Process)       │
                             │ Tidak        └────────┬────────┘
                             │                       │
                             ▼                       ▼
                    ┌─────────────────┐     ┌─────────────────┐
                    │ Tampilkan       │     │ Tampilkan       │
                    │ "Dibatalkan"    │     │ "Data Berhasil  │
                    │ (Output)        │     │  Direset"       │
                    └────────┬────────┘     │ (Output)        │
                             │              └────────┬────────┘
                             │                       │
                             ├───────────────────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │    SELESAI      │
                    │   (Terminator)  │
                    └─────────────────┘
```

---

## 🛠️ Cara Menjalankan Program

### Kompilasi Program
```bash
g++ -o main main.cpp
```

### Menjalankan Program
```bash
./main
```

---

## 📋 Struktur Data yang Digunakan

| Variabel | Tipe Data | Keterangan |
|----------|-----------|------------|
| `keteranganPemasukan[]` | Array of String | Menyimpan keterangan setiap pemasukan |
| `jumlahPemasukan[]` | Array of Double | Menyimpan jumlah setiap pemasukan |
| `totalTransaksiPemasukan` | Integer | Counter jumlah transaksi pemasukan |
| `keteranganPengeluaran[]` | Array of String | Menyimpan keterangan setiap pengeluaran |
| `jumlahPengeluaran[]` | Array of Double | Menyimpan jumlah setiap pengeluaran |
| `totalTransaksiPengeluaran` | Integer | Counter jumlah transaksi pengeluaran |

---

## 📌 Rumus Perhitungan

| Perhitungan | Rumus |
|-------------|-------|
| **Total Pemasukan** | Σ jumlahPemasukan[i], dimana i = 0 sampai n-1 |
| **Total Pengeluaran** | Σ jumlahPengeluaran[i], dimana i = 0 sampai n-1 |
| **Saldo** | Saldo = Total Pemasukan - Total Pengeluaran |
| **Margin Keuntungan** | Margin = (Saldo / Total Pemasukan) × 100% |
| **Rata-rata Pemasukan** | Rata-rata Pemasukan = Total Pemasukan / Jumlah Transaksi Pemasukan |
| **Rata-rata Pengeluaran** | Rata-rata Pengeluaran = Total Pengeluaran / Jumlah Transaksi Pengeluaran |

---

## 📊 Status Keuangan

| Kondisi | Status | Keterangan |
|---------|--------|------------|
| `saldo > 0` | **UNTUNG / SURPLUS** | Pemasukan lebih besar dari pengeluaran |
| `saldo < 0` | **RUGI / DEFISIT** | Pengeluaran lebih besar dari pemasukan |
| `saldo = 0` | **IMPAS / BREAK EVEN** | Pemasukan sama dengan pengeluaran |
| Tidak ada transaksi | **BELUM ADA TRANSAKSI** | Belum ada data yang diinput |

---

## 👤 Informasi

**Nama:** Muhammad Asyrafi Hidayatullah  
**Mata Kuliah:** Algoritma dan Pemrograman  
**Semester:** 1  
**Tahun:** 2025

---

## 📝 Catatan Pengembangan

Program ini dikembangkan oleh **Muhammad Asyrafi Hidayatullah** dengan menggunakan **AI sebagai alat bantu** dalam proses pembuatan dokumentasi dan optimalisasi kode.

---

## 📜 Lisensi

Program ini dibuat untuk keperluan tugas UAS Algoritma Semester 1.

---

*Dibuat dengan ❤️ menggunakan C++*
