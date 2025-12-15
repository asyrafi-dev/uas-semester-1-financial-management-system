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

### 🔶 Keterangan Simbol Flowchart

| Simbol | Nama | Keterangan |
|--------|------|------------|
| ⬭ (Oval) | **Terminator** | Simbol untuk permulaan (START) atau akhir (STOP) dari program |
| ▭ (Persegi Panjang) | **Process** | Simbol untuk proses/pengolahan data yang dilakukan oleh komputer |
| ◇ (Belah Ketupat) | **Decision** | Simbol untuk pengambilan keputusan berdasarkan kondisi (Ya/Tidak) |
| ▱ (Jajar Genjang) | **Input/Output** | Simbol untuk proses input dan output data |
| → (Panah) | **Flow Direction** | Simbol penghubung alur antar simbol |

---

### 🔶 Flowchart Program Utama

```
                    ┌─────────────────┐
                    │     MULAI       │
                    │   (Terminator)  │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────┐
                    │   Inisialisasi  │
                    │    Variabel     │
                    │    (Process)    │
                    └────────┬────────┘
                             │
            ┌────────────────┴────────────────┐
            │                                 │
            ▼                                 │
   ┌─────────────────┐                        │
   │  Bersihkan      │                        │
   │  Layar          │                        │
   │  (Process)      │                        │
   └────────┬────────┘                        │
            │                                 │
            ▼                                 │
   ┌─────────────────┐                        │
   │ Tampilkan       │                        │
   │ Header & Menu   │                        │
   │ (Process)       │                        │
   └────────┬────────┘                        │
            │                                 │
            ▼                                 │
   ┌─────────────────┐                        │
   │  Input          │                        │
   │  Pilihan        │                        │
   │  (Input/Output) │                        │
   └────────┬────────┘                        │
            │                                 │
            ▼                                 │
   ┌─────────────────┐                        │
   │   Pilihan?      │                        │
   │   (Decision)    │                        │
   └────────┬────────┘                        │
            │                                 │
    ┌───┬───┼───┬───┬───┬───┬───┬───┐        │
    │   │   │   │   │   │   │   │   │        │
    ▼   ▼   ▼   ▼   ▼   ▼   ▼   ▼   ▼        │
   [1] [2] [3] [4] [5] [6] [7] [0] [X]       │
    │   │   │   │   │   │   │   │   │        │
    ▼   ▼   ▼   ▼   ▼   ▼   ▼   │   ▼        │
  ┌───┬───┬───┬───┬───┬───┬───┐│ ┌───┐       │
  │   │   │   │   │   │   │   ││ │Err│       │
  │ T │ T │ L │ L │ L │ L │ R │└►│or │       │
  │ a │ a │ i │ i │ i │ i │ e │  │   │       │
  │ m │ m │ h │ h │ h │ h │ s │  └─┬─┘       │
  │ b │ b │ a │ a │ a │ a │ e │    │         │
  │ a │ a │ t │ t │ t │ t │ t │    │         │
  │ h │ h │   │   │   │   │   │    │         │
  │   │   │ P │ P │ L │ S │ D │    │         │
  │ P │ P │ e │ e │ a │ a │ a │    │         │
  │ e │ e │ m │ n │ p │ l │ t │    │         │
  │ m │ n │ a │ g │ o │ d │ a │    │         │
  │ a │ g │ s │ e │ r │ o │   │    │         │
  │ s │ e │ u │ l │ a │   │   │    │         │
  │ u │ l │ k │ u │ n │   │   │    │         │
  │ k │ u │ a │ a │   │   │   │    │         │
  │ a │ a │ n │ r │   │   │   │    │         │
  │ n │ r │   │ a │   │   │   │    │         │
  │   │ a │   │ n │   │   │   │    │         │
  │   │ n │   │   │   │   │   │    │         │
  └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘    │         │
    │   │   │   │   │   │   │      │         │
    └───┴───┴───┴───┴───┴───┴──────┴─────────┤
                                             │
            ┌────────────────────────────────┘
            │
            ▼
   ┌─────────────────┐      ┌─────────────────┐
   │ Pilihan = 0 ?   │  Ya  │  Tampilkan      │
   │   (Decision)    ├─────►│  Pesan Keluar   │
   └────────┬────────┘      │  (Process)      │
            │ Tidak         └────────┬────────┘
            │                        │
            │                        ▼
            │               ┌─────────────────┐
            │               │    SELESAI      │
            │               │   (Terminator)  │
            │               └─────────────────┘
            │
            └──────────► (Kembali ke Bersihkan Layar)
```

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
| **Total Pemasukan** | $\sum_{i=0}^{n-1} \text{jumlahPemasukan}[i]$ |
| **Total Pengeluaran** | $\sum_{i=0}^{n-1} \text{jumlahPengeluaran}[i]$ |
| **Saldo** | $\text{Saldo} = \text{Total Pemasukan} - \text{Total Pengeluaran}$ |
| **Margin Keuntungan** | $\text{Margin} = \frac{\text{Saldo}}{\text{Total Pemasukan}} \times 100\%$ |
| **Rata-rata Pemasukan** | $\bar{x}_{masuk} = \frac{\text{Total Pemasukan}}{n_{masuk}}$ |
| **Rata-rata Pengeluaran** | $\bar{x}_{keluar} = \frac{\text{Total Pengeluaran}}{n_{keluar}}$ |

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

**Mata Kuliah:** Algoritma dan Pemrograman  
**Semester:** 1  
**Tahun:** 2024/2025

---

## 📜 Lisensi

Program ini dibuat untuk keperluan tugas UAS Algoritma Semester 1.

---

*Dibuat dengan ❤️ menggunakan C++*
