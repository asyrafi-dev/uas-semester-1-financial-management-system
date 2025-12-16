/*
 * ============================================
 * SISTEM MANAJEMEN KEUANGAN USAHA ONLINE
 * ============================================
 * Program ini digunakan untuk mencatat dan
 * mengelola keuangan usaha online sederhana.
 * 
 * Fitur:
 * - Input pemasukan dengan keterangan
 * - Input pengeluaran dengan keterangan
 * - Lihat laporan keuangan lengkap
 * - Hitung saldo dan status keuangan
 * ============================================
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ==================== KONSTANTA ====================
const int MAX_TRANSAKSI = 100;
const string GARIS_PANJANG = "================================================";
const string GARIS_PENDEK  = "------------------------------------------------";

// ==================== VARIABEL GLOBAL ====================
// Data Pemasukan
string keteranganPemasukan[MAX_TRANSAKSI];
double jumlahPemasukan[MAX_TRANSAKSI];
int totalTransaksiPemasukan = 0;

// Data Pengeluaran
string keteranganPengeluaran[MAX_TRANSAKSI];
double jumlahPengeluaran[MAX_TRANSAKSI];
int totalTransaksiPengeluaran = 0;

// ==================== FUNGSI-FUNGSI ====================

// Fungsi untuk membersihkan layar
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Fungsi untuk jeda (tekan enter untuk lanjut)
void pauseProgram() {
    cout << "\n" << GARIS_PENDEK << endl;
    cout << "Tekan ENTER untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

// Fungsi untuk menampilkan header program
void tampilkanHeader() {
    cout << "\n" << GARIS_PANJANG << endl;
    cout << "|     SISTEM MANAJEMEN KEUANGAN USAHA ONLINE     |" << endl;
    cout << GARIS_PANJANG << endl;
}

// Fungsi untuk menampilkan menu utama
void tampilkanMenu() {
    cout << "\n" << GARIS_PENDEK << endl;
    cout << "|              MENU UTAMA                        |" << endl;
    cout << GARIS_PENDEK << endl;
    cout << "| [1] Tambah Pemasukan                           |" << endl;
    cout << "| [2] Tambah Pengeluaran                         |" << endl;
    cout << "| [3] Lihat Riwayat Pemasukan                    |" << endl;
    cout << "| [4] Lihat Riwayat Pengeluaran                  |" << endl;
    cout << "| [5] Lihat Laporan Keuangan Lengkap             |" << endl;
    cout << "| [6] Lihat Saldo & Status Keuangan              |" << endl;
    cout << "| [0] Keluar dari Program                        |" << endl;
    cout << GARIS_PENDEK << endl;
}

// Fungsi untuk format angka ke format Rupiah
string formatRupiah(double nilai) {
    string hasil = "Rp ";
    
    // Ambil nilai absolut untuk format
    double nilaiAbs = (nilai < 0) ? -nilai : nilai;
    
    // Konversi ke string dengan 2 desimal
    long long nilaiInt = static_cast<long long>(nilaiAbs);
    int desimal = static_cast<int>((nilaiAbs - nilaiInt) * 100);
    
    // Format dengan pemisah ribuan
    string angka = to_string(nilaiInt);
    string formatted = "";
    int count = 0;
    
    for (int i = angka.length() - 1; i >= 0; i--) {
        if (count > 0 && count % 3 == 0) {
            formatted = "." + formatted;
        }
        formatted = angka[i] + formatted;
        count++;
    }
    
    if (nilai < 0) {
        hasil = "-" + hasil;
    }
    
    hasil += formatted + "," + (desimal < 10 ? "0" : "") + to_string(desimal);
    return hasil;
}

// Fungsi untuk menghitung total pemasukan
double hitungTotalPemasukan() {
    double total = 0;
    for (int i = 0; i < totalTransaksiPemasukan; i++) {
        total += jumlahPemasukan[i];
    }
    return total;
}

// Fungsi untuk menghitung total pengeluaran
double hitungTotalPengeluaran() {
    double total = 0;
    for (int i = 0; i < totalTransaksiPengeluaran; i++) {
        total += jumlahPengeluaran[i];
    }
    return total;
}

// Fungsi untuk menambah pemasukan
void tambahPemasukan() {
    clearScreen();
    tampilkanHeader();
    
    cout << "\n" << GARIS_PENDEK << endl;
    cout << "|           TAMBAH PEMASUKAN                     |" << endl;
    cout << GARIS_PENDEK << endl;
    
    if (totalTransaksiPemasukan >= MAX_TRANSAKSI) {
        cout << "\n[!] PERINGATAN: Data pemasukan sudah penuh!" << endl;
        cout << "    Maksimal " << MAX_TRANSAKSI << " transaksi." << endl;
        pauseProgram();
        return;
    }
    
    string keterangan;
    double jumlah;
    
    cout << "\nMasukkan keterangan pemasukan: ";
    cin.ignore();
    getline(cin, keterangan);
    
    cout << "Masukkan jumlah pemasukan    : Rp ";
    cin >> jumlah;
    
    if (jumlah <= 0) {
        cout << "\n[X] ERROR: Jumlah harus lebih dari 0!" << endl;
        pauseProgram();
        return;
    }
    
    // Simpan data
    keteranganPemasukan[totalTransaksiPemasukan] = keterangan;
    jumlahPemasukan[totalTransaksiPemasukan] = jumlah;
    totalTransaksiPemasukan++;
    
    cout << "\n" << GARIS_PENDEK << endl;
    cout << "[V] BERHASIL!" << endl;
    cout << GARIS_PENDEK << endl;
    cout << "Pemasukan berhasil ditambahkan!" << endl;
    cout << "Keterangan : " << keterangan << endl;
    cout << "Jumlah     : " << formatRupiah(jumlah) << endl;
    cout << "Total Pemasukan Saat Ini: " << formatRupiah(hitungTotalPemasukan()) << endl;
    
    pauseProgram();
}

// Fungsi untuk menambah pengeluaran
void tambahPengeluaran() {
    clearScreen();
    tampilkanHeader();
    
    cout << "\n" << GARIS_PENDEK << endl;
    cout << "|          TAMBAH PENGELUARAN                    |" << endl;
    cout << GARIS_PENDEK << endl;
    
    if (totalTransaksiPengeluaran >= MAX_TRANSAKSI) {
        cout << "\n[!] PERINGATAN: Data pengeluaran sudah penuh!" << endl;
        cout << "    Maksimal " << MAX_TRANSAKSI << " transaksi." << endl;
        pauseProgram();
        return;
    }
    
    string keterangan;
    double jumlah;
    
    cout << "\nMasukkan keterangan pengeluaran: ";
    cin.ignore();
    getline(cin, keterangan);
    
    cout << "Masukkan jumlah pengeluaran    : Rp ";
    cin >> jumlah;
    
    if (jumlah <= 0) {
        cout << "\n[X] ERROR: Jumlah harus lebih dari 0!" << endl;
        pauseProgram();
        return;
    }
    
    // Simpan data
    keteranganPengeluaran[totalTransaksiPengeluaran] = keterangan;
    jumlahPengeluaran[totalTransaksiPengeluaran] = jumlah;
    totalTransaksiPengeluaran++;
    
    cout << "\n" << GARIS_PENDEK << endl;
    cout << "[V] BERHASIL!" << endl;
    cout << GARIS_PENDEK << endl;
    cout << "Pengeluaran berhasil ditambahkan!" << endl;
    cout << "Keterangan : " << keterangan << endl;
    cout << "Jumlah     : " << formatRupiah(jumlah) << endl;
    cout << "Total Pengeluaran Saat Ini: " << formatRupiah(hitungTotalPengeluaran()) << endl;
    
    pauseProgram();
}

// Fungsi untuk menampilkan riwayat pemasukan
void lihatRiwayatPemasukan() {
    clearScreen();
    tampilkanHeader();
    
    cout << "\n" << GARIS_PANJANG << endl;
    cout << "|           RIWAYAT PEMASUKAN                    |" << endl;
    cout << GARIS_PANJANG << endl;
    
    if (totalTransaksiPemasukan == 0) {
        cout << "\n[i] Belum ada data pemasukan." << endl;
        cout << "    Silakan tambah pemasukan terlebih dahulu." << endl;
    } else {
        cout << "\n";
        cout << left << setw(5) << "No" 
            << setw(30) << "Keterangan" 
            << right << setw(20) << "Jumlah" << endl;
        cout << GARIS_PENDEK << endl;
        
        for (int i = 0; i < totalTransaksiPemasukan; i++) {
            cout << left << setw(5) << (i + 1) 
                << setw(30) << keteranganPemasukan[i].substr(0, 28) 
                << right << setw(20) << formatRupiah(jumlahPemasukan[i]) << endl;
        }
        
        cout << GARIS_PENDEK << endl;
        cout << left << setw(35) << "TOTAL PEMASUKAN" 
            << right << setw(20) << formatRupiah(hitungTotalPemasukan()) << endl;
        cout << "Jumlah Transaksi: " << totalTransaksiPemasukan << " transaksi" << endl;
    }
    
    pauseProgram();
}

// Fungsi untuk menampilkan riwayat pengeluaran
void lihatRiwayatPengeluaran() {
    clearScreen();
    tampilkanHeader();
    
    cout << "\n" << GARIS_PANJANG << endl;
    cout << "|          RIWAYAT PENGELUARAN                   |" << endl;
    cout << GARIS_PANJANG << endl;
    
    if (totalTransaksiPengeluaran == 0) {
        cout << "\n[i] Belum ada data pengeluaran." << endl;
        cout << "    Silakan tambah pengeluaran terlebih dahulu." << endl;
    } else {
        cout << "\n";
        cout << left << setw(5) << "No" 
            << setw(30) << "Keterangan" 
            << right << setw(20) << "Jumlah" << endl;
        cout << GARIS_PENDEK << endl;
        
        for (int i = 0; i < totalTransaksiPengeluaran; i++) {
            cout << left << setw(5) << (i + 1) 
                << setw(30) << keteranganPengeluaran[i].substr(0, 28) 
                << right << setw(20) << formatRupiah(jumlahPengeluaran[i]) << endl;
        }
        
        cout << GARIS_PENDEK << endl;
        cout << left << setw(35) << "TOTAL PENGELUARAN" 
            << right << setw(20) << formatRupiah(hitungTotalPengeluaran()) << endl;
        cout << "Jumlah Transaksi: " << totalTransaksiPengeluaran << " transaksi" << endl;
    }
    
    pauseProgram();
}

// Fungsi untuk menampilkan laporan keuangan lengkap
void lihatLaporanLengkap() {
    clearScreen();
    tampilkanHeader();
    
    double totalMasuk = hitungTotalPemasukan();
    double totalKeluar = hitungTotalPengeluaran();
    double saldo = totalMasuk - totalKeluar;
    
    cout << "\n" << GARIS_PANJANG << endl;
    cout << "|        LAPORAN KEUANGAN LENGKAP                |" << endl;
    cout << GARIS_PANJANG << endl;
    
    // Ringkasan Pemasukan
    cout << "\n>>> PEMASUKAN <<<" << endl;
    cout << GARIS_PENDEK << endl;
    if (totalTransaksiPemasukan == 0) {
        cout << "[i] Belum ada transaksi pemasukan" << endl;
    } else {
        cout << left << setw(5) << "No" 
            << setw(30) << "Keterangan" 
            << right << setw(20) << "Jumlah" << endl;
        cout << GARIS_PENDEK << endl;
        for (int i = 0; i < totalTransaksiPemasukan; i++) {
            cout << left << setw(5) << (i + 1) 
                << setw(30) << keteranganPemasukan[i].substr(0, 28) 
                << right << setw(20) << formatRupiah(jumlahPemasukan[i]) << endl;
        }
    }
    cout << GARIS_PENDEK << endl;
    cout << left << setw(35) << "SUBTOTAL PEMASUKAN" 
        << right << setw(20) << formatRupiah(totalMasuk) << endl;
    
    // Ringkasan Pengeluaran
    cout << "\n>>> PENGELUARAN <<<" << endl;
    cout << GARIS_PENDEK << endl;
    if (totalTransaksiPengeluaran == 0) {
        cout << "[i] Belum ada transaksi pengeluaran" << endl;
    } else {
        cout << left << setw(5) << "No" 
            << setw(30) << "Keterangan" 
            << right << setw(20) << "Jumlah" << endl;
        cout << GARIS_PENDEK << endl;
        for (int i = 0; i < totalTransaksiPengeluaran; i++) {
            cout << left << setw(5) << (i + 1) 
                << setw(30) << keteranganPengeluaran[i].substr(0, 28) 
                << right << setw(20) << formatRupiah(jumlahPengeluaran[i]) << endl;
        }
    }
    cout << GARIS_PENDEK << endl;
    cout << left << setw(35) << "SUBTOTAL PENGELUARAN" 
        << right << setw(20) << formatRupiah(totalKeluar) << endl;
    
    // Ringkasan Total
    cout << "\n" << GARIS_PANJANG << endl;
    cout << "|              RINGKASAN                         |" << endl;
    cout << GARIS_PANJANG << endl;
    cout << left << setw(35) << "Total Pemasukan" 
        << right << setw(20) << formatRupiah(totalMasuk) << endl;
    cout << left << setw(35) << "Total Pengeluaran" 
        << right << setw(20) << formatRupiah(totalKeluar) << endl;
    cout << GARIS_PENDEK << endl;
    cout << left << setw(35) << "SALDO/KEUNTUNGAN BERSIH" 
        << right << setw(20) << formatRupiah(saldo) << endl;
    cout << GARIS_PANJANG << endl;
    
    pauseProgram();
}

// Fungsi untuk menampilkan saldo dan status keuangan
void lihatSaldoDanStatus() {
    clearScreen();
    tampilkanHeader();
    
    double totalMasuk = hitungTotalPemasukan();
    double totalKeluar = hitungTotalPengeluaran();
    double saldo = totalMasuk - totalKeluar;
    double persentase = (totalMasuk > 0) ? ((saldo / totalMasuk) * 100) : 0;
    
    cout << "\n" << GARIS_PANJANG << endl;
    cout << "|          SALDO & STATUS KEUANGAN               |" << endl;
    cout << GARIS_PANJANG << endl;
    
    cout << "\n>>> RINGKASAN KEUANGAN <<<" << endl;
    cout << GARIS_PENDEK << endl;
    cout << left << setw(30) << "Total Pemasukan" << ": " << formatRupiah(totalMasuk) << endl;
    cout << left << setw(30) << "Total Pengeluaran" << ": " << formatRupiah(totalKeluar) << endl;
    cout << GARIS_PENDEK << endl;
    cout << left << setw(30) << "SALDO AKHIR" << ": " << formatRupiah(saldo) << endl;
    
    cout << "\n>>> STATISTIK <<<" << endl;
    cout << GARIS_PENDEK << endl;
    cout << left << setw(30) << "Jumlah Transaksi Masuk" << ": " << totalTransaksiPemasukan << " transaksi" << endl;
    cout << left << setw(30) << "Jumlah Transaksi Keluar" << ": " << totalTransaksiPengeluaran << " transaksi" << endl;
    cout << left << setw(30) << "Total Semua Transaksi" << ": " << (totalTransaksiPemasukan + totalTransaksiPengeluaran) << " transaksi" << endl;
    
    if (totalTransaksiPemasukan > 0) {
        double rataRataMasuk = totalMasuk / totalTransaksiPemasukan;
        cout << left << setw(30) << "Rata-rata Pemasukan" << ": " << formatRupiah(rataRataMasuk) << endl;
    }
    
    if (totalTransaksiPengeluaran > 0) {
        double rataRataKeluar = totalKeluar / totalTransaksiPengeluaran;
        cout << left << setw(30) << "Rata-rata Pengeluaran" << ": " << formatRupiah(rataRataKeluar) << endl;
    }
    
    cout << "\n>>> STATUS KEUANGAN <<<" << endl;
    cout << GARIS_PENDEK << endl;
    
    if (totalMasuk == 0 && totalKeluar == 0) {
        cout << "[i] STATUS: BELUM ADA TRANSAKSI" << endl;
        cout << "    Silakan mulai mencatat keuangan Anda." << endl;
    } else if (saldo > 0) {
        cout << "[+] STATUS: UNTUNG / SURPLUS" << endl;
        cout << "    Selamat! Keuangan Anda dalam kondisi POSITIF." << endl;
        cout << "    Keuntungan: " << formatRupiah(saldo) << endl;
        if (totalMasuk > 0) {
            cout << fixed << setprecision(2);
            cout << "    Margin Keuntungan: " << persentase << "%" << endl;
        }
    } else if (saldo < 0) {
        cout << "[-] STATUS: RUGI / DEFISIT" << endl;
        cout << "    Perhatian! Keuangan Anda dalam kondisi NEGATIF." << endl;
        cout << "    Kerugian: " << formatRupiah(-saldo) << endl;
        cout << "    Saran: Kurangi pengeluaran atau tingkatkan pemasukan." << endl;
    } else {
        cout << "[=] STATUS: IMPAS / BREAK EVEN" << endl;
        cout << "    Pemasukan dan pengeluaran Anda seimbang." << endl;
        cout << "    Tidak ada keuntungan atau kerugian." << endl;
    }
    
    cout << GARIS_PANJANG << endl;
    
    pauseProgram();
}

// ==================== FUNGSI UTAMA ====================
int main() {
    int pilihan;
    
    do {
        clearScreen();
        tampilkanHeader();
        tampilkanMenu();
        
        cout << "\nMasukkan pilihan Anda [0-6]: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tambahPemasukan();
                break;
            case 2:
                tambahPengeluaran();
                break;
            case 3:
                lihatRiwayatPemasukan();
                break;
            case 4:
                lihatRiwayatPengeluaran();
                break;
            case 5:
                lihatLaporanLengkap();
                break;
            case 6:
                lihatSaldoDanStatus();
                break;
            case 0:
                clearScreen();
                tampilkanHeader();
                cout << "\n" << GARIS_PENDEK << endl;
                cout << "|         TERIMA KASIH                           |" << endl;
                cout << GARIS_PENDEK << endl;
                cout << "\nTerima kasih telah menggunakan" << endl;
                cout << "Sistem Manajemen Keuangan Usaha Online!" << endl;
                cout << "\nSampai jumpa kembali!" << endl;
                cout << "\n" << GARIS_PANJANG << endl;
                break;
            default:
                cout << "\n[X] ERROR: Pilihan tidak valid!" << endl;
                cout << "    Silakan pilih menu 0-6." << endl;
                pauseProgram();
        }
        
    } while (pilihan != 0);
    
    return 0;
}
