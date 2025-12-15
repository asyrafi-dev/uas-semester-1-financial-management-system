# SISTEM MANAJEMEN KEUANGAN USAHA ONLINE

## Deskripsi Program

Program ini digunakan untuk mencatat dan mengelola keuangan usaha online sederhana menggunakan bahasa C++.

---

## Fitur Program

| No | Menu | Fungsi |
|----|------|--------|
| 1 | Tambah Pemasukan | Mencatat uang masuk |
| 2 | Tambah Pengeluaran | Mencatat uang keluar |
| 3 | Lihat Riwayat Pemasukan | Melihat daftar pemasukan |
| 4 | Lihat Riwayat Pengeluaran | Melihat daftar pengeluaran |
| 5 | Laporan Keuangan | Melihat laporan lengkap |
| 6 | Saldo & Status | Melihat saldo dan status keuangan |
| 7 | Reset Data | Menghapus semua data |
| 0 | Keluar | Keluar dari program |

---

## ALGORITMA PROGRAM

### Algoritma Program Utama

```
MULAI
    Set counter pemasukan = 0
    Set counter pengeluaran = 0
    
    ULANGI
        Tampilkan menu
        Input pilihan
        
        JIKA pilihan = 1 MAKA
            Jalankan Tambah Pemasukan
        JIKA pilihan = 2 MAKA
            Jalankan Tambah Pengeluaran
        JIKA pilihan = 3 MAKA
            Tampilkan Riwayat Pemasukan
        JIKA pilihan = 4 MAKA
            Tampilkan Riwayat Pengeluaran
        JIKA pilihan = 5 MAKA
            Tampilkan Laporan Lengkap
        JIKA pilihan = 6 MAKA
            Tampilkan Saldo & Status
        JIKA pilihan = 7 MAKA
            Reset Semua Data
        JIKA pilihan = 0 MAKA
            Keluar Program
            
    SAMPAI pilihan = 0
SELESAI
```

### Algoritma Tambah Pemasukan

```
MULAI
    Input keterangan
    Input jumlah
    
    JIKA jumlah > 0 MAKA
        Simpan ke array
        Tambah counter
        Tampilkan "Berhasil"
    LAIN
        Tampilkan "Error"
SELESAI
```

### Algoritma Tambah Pengeluaran

```
MULAI
    Input keterangan
    Input jumlah
    
    JIKA jumlah > 0 MAKA
        Simpan ke array
        Tambah counter
        Tampilkan "Berhasil"
    LAIN
        Tampilkan "Error"
SELESAI
```

### Algoritma Hitung Saldo

```
MULAI
    Hitung total pemasukan
    Hitung total pengeluaran
    Saldo = total pemasukan - total pengeluaran
    
    JIKA saldo > 0 MAKA
        Status = "UNTUNG"
    JIKA saldo < 0 MAKA
        Status = "RUGI"
    JIKA saldo = 0 MAKA
        Status = "IMPAS"
        
    Tampilkan saldo dan status
SELESAI
```

---

## FLOWCHART PROGRAM

### Keterangan Simbol

| Simbol | Nama | Fungsi |
|--------|------|--------|
| Oval | Terminator | Mulai / Selesai |
| Persegi Panjang | Process | Proses data |
| Belah Ketupat | Decision | Kondisi Ya/Tidak |
| Jajar Genjang | Input/Output | Input dan Output |
| Panah | Flow Line | Arah alur |

---

### Flowchart Program Utama

```
    ┌───────────┐
    │   MULAI   │
    └─────┬─────┘
          │
          ▼
    ┌───────────┐
    │Inisialisasi│
    │variabel = 0│
    └─────┬─────┘
          │
          ▼
    ┌───────────┐
    │ Tampilkan │
    │   Menu    │
    └─────┬─────┘
          │
          ▼
   ╱─────────────╲
  ╱ Input Pilihan ╲
  ╲               ╱
   ╲─────┬───────╱
         │
         ▼
    ◇───────────◇
   ╱Pilihan = 0?╲
  ◇             ◇
   Ya         Tidak
    │           │
    ▼           ▼
┌─────────┐ ┌─────────┐
│Tampilkan│ │Jalankan │
│"Terima  │ │ Fungsi  │
│ Kasih"  │ │ Sesuai  │
└────┬────┘ │ Pilihan │
     │      └────┬────┘
     ▼           │
┌─────────┐      │
│ SELESAI │      │
└─────────┘      │
                 │
    └────────────┘
    (Kembali ke Tampilkan Menu)
```

---

### Flowchart Tambah Pemasukan / Pengeluaran

```
    ┌───────────┐
    │   MULAI   │
    └─────┬─────┘
          │
          ▼
   ╱─────────────╲
  ╱    Input      ╲
  ╲  Keterangan   ╱
   ╲─────┬───────╱
         │
         ▼
   ╱─────────────╲
  ╱    Input      ╲
  ╲    Jumlah     ╱
   ╲─────┬───────╱
         │
         ▼
    ◇───────────◇
   ╱Jumlah > 0? ╲
  ◇             ◇
   Ya         Tidak
    │           │
    ▼           ▼
┌─────────┐ ┌─────────┐
│ Simpan  │ │Tampilkan│
│  Data   │ │ "Error" │
└────┬────┘ └────┬────┘
     │           │
     ▼           │
┌─────────┐      │
│Tampilkan│      │
│"Berhasil│      │
└────┬────┘      │
     │           │
     └─────┬─────┘
           │
           ▼
    ┌───────────┐
    │  SELESAI  │
    └───────────┘
```

---

### Flowchart Hitung Saldo & Status

```
    ┌───────────┐
    │   MULAI   │
    └─────┬─────┘
          │
          ▼
    ┌───────────┐
    │  Hitung   │
    │  Total    │
    │ Pemasukan │
    └─────┬─────┘
          │
          ▼
    ┌───────────┐
    │  Hitung   │
    │  Total    │
    │Pengeluaran│
    └─────┬─────┘
          │
          ▼
    ┌───────────┐
    │  Saldo =  │
    │ Pemasukan │
    │     -     │
    │Pengeluaran│
    └─────┬─────┘
          │
          ▼
    ◇───────────◇
   ╱ Saldo > 0? ╲
  ◇             ◇
   Ya         Tidak
    │           │
    ▼           ▼
┌─────────┐ ◇───────────◇
│ Status= │╱ Saldo < 0? ╲
│"UNTUNG" ◇             ◇
└────┬────┘ Ya        Tidak
     │       │          │
     │       ▼          ▼
     │  ┌─────────┐┌─────────┐
     │  │ Status= ││ Status= │
     │  │ "RUGI"  ││ "IMPAS" │
     │  └────┬────┘└────┬────┘
     │       │          │
     └───────┴────┬─────┘
                  │
                  ▼
          ╱─────────────╲
         ╱   Tampilkan   ╲
         ╲Saldo & Status ╱
          ╲─────┬───────╱
                │
                ▼
         ┌───────────┐
         │  SELESAI  │
         └───────────┘
```

---

## Rumus Perhitungan

| Perhitungan | Rumus |
|-------------|-------|
| Total Pemasukan | Jumlahkan semua pemasukan |
| Total Pengeluaran | Jumlahkan semua pengeluaran |
| Saldo | Total Pemasukan - Total Pengeluaran |

---

## Status Keuangan

| Kondisi | Status |
|---------|--------|
| Saldo > 0 | UNTUNG |
| Saldo < 0 | RUGI |
| Saldo = 0 | IMPAS |

---

## Cara Menjalankan Program

### Kompilasi
```bash
g++ -o main main.cpp
```

### Jalankan
```bash
./main
```

---

## Informasi

**Nama:** Muhammad Asyrafi Hidayatullah  
**Mata Kuliah:** Algoritma dan Pemrograman  
**Semester:** 1  
**Tahun:** 2025

---

## Catatan

Program ini dibuat oleh **Muhammad Asyrafi Hidayatullah** dengan menggunakan **AI sebagai alat bantu**.

---

*Dibuat menggunakan C++*
