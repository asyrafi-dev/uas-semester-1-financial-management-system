/*
 * ============================================================================
 *                SISTEM MANAJEMEN KEUANGAN USAHA ONLINE
 * ============================================================================
 * Program ini dibuat untuk membantu pelaku usaha online dalam mencatat
 * dan mengelola keuangan usaha mereka secara sederhana.
 * 
 * FITUR UTAMA:
 * - Pencatatan pemasukan (uang masuk dari penjualan)
 * - Pencatatan pengeluaran (biaya operasional, modal, dll)
 * - Laporan keuangan lengkap
 * - Analisis status keuangan (untung/rugi)
 * ============================================================================
 */

#include <iostream>   // Library untuk input/output (cin, cout)
#include <iomanip>    // Library untuk format tampilan (setw, setprecision)
#include <string>     // Library untuk tipe data string
using namespace std;  // Agar tidak perlu menulis std:: setiap kali

// ============================================================================
//                         KONSTANTA PROGRAM
// ============================================================================
// Konstanta adalah nilai tetap yang tidak berubah selama program berjalan

const int MAX_TRANSAKSI = 100;  // Batas maksimal transaksi yang bisa disimpan
const string GARIS_PANJANG = "================================================";
const string GARIS_PENDEK  = "------------------------------------------------";

// ============================================================================
//                         VARIABEL GLOBAL
// ============================================================================
// Variabel global dapat diakses dari semua fungsi dalam program
// Menggunakan ARRAY untuk menyimpan banyak data transaksi

// --- Data Pemasukan ---
string keteranganPemasukan[MAX_TRANSAKSI];  // Array untuk menyimpan keterangan pemasukan
double jumlahPemasukan[MAX_TRANSAKSI];       // Array untuk menyimpan nominal pemasukan
int totalTransaksiPemasukan = 0;             // Counter jumlah transaksi pemasukan

// --- Data Pengeluaran ---
string keteranganPengeluaran[MAX_TRANSAKSI]; // Array untuk menyimpan keterangan pengeluaran
double jumlahPengeluaran[MAX_TRANSAKSI];     // Array untuk menyimpan nominal pengeluaran
int totalTransaksiPengeluaran = 0;           // Counter jumlah transaksi pengeluaran

// ============================================================================
//                         FUNGSI-FUNGSI UTILITAS
// ============================================================================

/*
 * Fungsi: clearScreen()
 * Tujuan: Membersihkan layar console agar tampilan lebih rapi
 * Cara kerja: Menggunakan preprocessor directive untuk mendeteksi OS
 */
void clearScreen() {
    #ifdef _WIN32           // Jika sistem operasi Windows
        system("cls");      // Gunakan perintah "cls"
    #else                   // Jika sistem operasi lain (Linux/Mac)
        system("clear");    // Gunakan perintah "clear"
    #endif
}

/*
 * Fungsi: pauseProgram()
 * Tujuan: Menghentikan program sementara sampai user menekan ENTER
 * Berguna agar user bisa membaca output sebelum layar dibersihkan
 */
void pauseProgram() {
    cout << "\n" << GARIS_PENDEK << endl;
    cout << "Tekan ENTER untuk melanjutkan...";
    cin.ignore();  // Mengabaikan karakter newline yang tersisa di buffer
    cin.get();     // Menunggu user menekan ENTER
}

/*
 * Fungsi: tampilkanHeader()
 * Tujuan: Menampilkan judul/header program
 */
void tampilkanHeader() {
    cout << "\n" << GARIS_PANJANG << endl;
    cout << "|     SISTEM MANAJEMEN KEUANGAN USAHA ONLINE     |" << endl;
    cout << GARIS_PANJANG << endl;
}

/*
 * Fungsi: tampilkanMenu()
 * Tujuan: Menampilkan daftar menu pilihan kepada user
 */
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

// ============================================================================
//                    FUNGSI FORMAT RUPIAH (STRING MANIPULATION)
// ============================================================================
/*
 * Fungsi: formatRupiah(double nilai)
 * Tujuan: Mengubah angka menjadi format mata uang Rupiah
 * Contoh: 1500000 -> "Rp 1.500.000,00"
 * 
 * KONSEP PENTING:
 * - Konversi tipe data (casting)
 * - Manipulasi string
 * - Perulangan (loop) untuk menambah titik pemisah ribuan
 */
string formatRupiah(double nilai) {
    string hasil = "Rp ";
    
    // Ambil nilai absolut (positif) untuk diformat
    double nilaiAbs = (nilai < 0) ? -nilai : nilai;
    
    // Pisahkan bagian bulat dan desimal
    long long nilaiInt = static_cast<long long>(nilaiAbs);  // Bagian bulat
    int desimal = static_cast<int>((nilaiAbs - nilaiInt) * 100);  // 2 digit desimal
    
    // Konversi angka ke string dan tambahkan titik pemisah ribuan
    string angka = to_string(nilaiInt);
    string formatted = "";
    int count = 0;
    
    // Loop dari belakang untuk menambah titik setiap 3 digit
    for (int i = angka.length() - 1; i >= 0; i--) {
        if (count > 0 && count % 3 == 0) {
            formatted = "." + formatted;  // Tambah titik pemisah
        }
        formatted = angka[i] + formatted;
        count++;
    }
    
    // Tambahkan tanda minus jika nilai negatif
    if (nilai < 0) {
        hasil = "-" + hasil;
    }
    
    // Gabungkan semua: "Rp " + angka + "," + desimal
    hasil += formatted + "," + (desimal < 10 ? "0" : "") + to_string(desimal);
    return hasil;
}

// ============================================================================
//                    FUNGSI PERHITUNGAN (MENGGUNAKAN LOOP)
// ============================================================================
/*
 * Fungsi: hitungTotalPemasukan()
 * Tujuan: Menjumlahkan semua nilai dalam array jumlahPemasukan
 * Konsep: Perulangan FOR untuk mengakses setiap elemen array
 */
double hitungTotalPemasukan() {
    double total = 0;  // Inisialisasi total = 0
    
    // Loop dari index 0 sampai totalTransaksiPemasukan-1
    for (int i = 0; i < totalTransaksiPemasukan; i++) {
        total += jumlahPemasukan[i];  // Tambahkan setiap elemen ke total
    }
    
    return total;  // Kembalikan hasil penjumlahan
}

/*
 * Fungsi: hitungTotalPengeluaran()
 * Tujuan: Menjumlahkan semua nilai dalam array jumlahPengeluaran
 */
double hitungTotalPengeluaran() {
    double total = 0;
    
    for (int i = 0; i < totalTransaksiPengeluaran; i++) {
        total += jumlahPengeluaran[i];
    }
    
    return total;
}

// ============================================================================
//                    FUNGSI INPUT DATA (ARRAY & VALIDASI)
// ============================================================================
/*
 * Fungsi: tambahPemasukan()
 * Tujuan: Menerima input pemasukan baru dari user dan menyimpan ke array
 * 
 * KONSEP PENTING:
 * - Validasi input (cek apakah array penuh, cek nilai > 0)
 * - Menyimpan data ke array menggunakan index
 * - Increment counter setelah data disimpan
 */
void tambahPemasukan() {
    clearScreen();
    tampilkanHeader();
    
    cout << "\n" << GARIS_PENDEK << endl;
    cout << "|           TAMBAH PEMASUKAN                     |" << endl;
    cout << GARIS_PENDEK << endl;
    
    // VALIDASI 1: Cek apakah array sudah penuh
    if (totalTransaksiPemasukan >= MAX_TRANSAKSI) {
        cout << "\n[!] PERINGATAN: Data pemasukan sudah penuh!" << endl;
        cout << "    Maksimal " << MAX_TRANSAKSI << " transaksi." << endl;
        pauseProgram();
        return;  // Keluar dari fungsi jika array penuh
    }
    
    // Deklarasi variabel untuk menampung input
    string keterangan;
    double jumlah;
    
    // Input keterangan (menggunakan getline untuk bisa input dengan spasi)
    cout << "\nMasukkan keterangan pemasukan: ";
    cin.ignore();  // Bersihkan buffer input
    getline(cin, keterangan);  // Baca satu baris penuh
    
    // Input jumlah nominal
    cout << "Masukkan jumlah pemasukan    : Rp ";
    cin >> jumlah;
    
    // VALIDASI 2: Cek apakah jumlah valid (lebih dari 0)
    if (jumlah <= 0) {
        cout << "\n[X] ERROR: Jumlah harus lebih dari 0!" << endl;
        pauseProgram();
        return;
    }
    
    // SIMPAN DATA KE ARRAY
    // Index yang digunakan adalah nilai totalTransaksiPemasukan saat ini
    keteranganPemasukan[totalTransaksiPemasukan] = keterangan;
    jumlahPemasukan[totalTransaksiPemasukan] = jumlah;
    
    // INCREMENT COUNTER (penting! agar data berikutnya disimpan di index selanjutnya)
    totalTransaksiPemasukan++;
    
    // Tampilkan konfirmasi
    cout << "\n" << GARIS_PENDEK << endl;
    cout << "[V] BERHASIL!" << endl;
    cout << GARIS_PENDEK << endl;
    cout << "Pemasukan berhasil ditambahkan!" << endl;
    cout << "Keterangan : " << keterangan << endl;
    cout << "Jumlah     : " << formatRupiah(jumlah) << endl;
    cout << "Total Pemasukan Saat Ini: " << formatRupiah(hitungTotalPemasukan()) << endl;
    
    pauseProgram();
}

/*
 * Fungsi: tambahPengeluaran()
 * Tujuan: Menerima input pengeluaran baru dari user dan menyimpan ke array
 * Logika sama dengan tambahPemasukan()
 */
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
    
    // Simpan ke array pengeluaran
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


// ============================================================================
//                    FUNGSI MENAMPILKAN DATA (LOOP & FORMAT)
// ============================================================================
/*
 * Fungsi: lihatRiwayatPemasukan()
 * Tujuan: Menampilkan semua data pemasukan dalam bentuk tabel
 * 
 * KONSEP PENTING:
 * - Perulangan FOR untuk menampilkan semua elemen array
 * - setw() untuk mengatur lebar kolom (format tabel)
 * - left/right untuk alignment (rata kiri/kanan)
 */
void lihatRiwayatPemasukan() {
    clearScreen();
    tampilkanHeader();
    
    cout << "\n" << GARIS_PANJANG << endl;
    cout << "|           RIWAYAT PEMASUKAN                    |" << endl;
    cout << GARIS_PANJANG << endl;
    
    // Cek apakah ada data
    if (totalTransaksiPemasukan == 0) {
        cout << "\n[i] Belum ada data pemasukan." << endl;
        cout << "    Silakan tambah pemasukan terlebih dahulu." << endl;
    } else {
        // Tampilkan header tabel
        cout << "\n";
        cout << left << setw(5) << "No"           // Kolom nomor, lebar 5, rata kiri
            << setw(30) << "Keterangan"           // Kolom keterangan, lebar 30
            << right << setw(20) << "Jumlah" << endl;  // Kolom jumlah, lebar 20, rata kanan
        cout << GARIS_PENDEK << endl;
        
        // LOOP untuk menampilkan setiap transaksi
        for (int i = 0; i < totalTransaksiPemasukan; i++) {
            cout << left << setw(5) << (i + 1)    // Nomor urut (index + 1)
                << setw(30) << keteranganPemasukan[i].substr(0, 28)  // Potong max 28 karakter
                << right << setw(20) << formatRupiah(jumlahPemasukan[i]) << endl;
        }
        
        // Tampilkan total
        cout << GARIS_PENDEK << endl;
        cout << left << setw(35) << "TOTAL PEMASUKAN" 
            << right << setw(20) << formatRupiah(hitungTotalPemasukan()) << endl;
        cout << "Jumlah Transaksi: " << totalTransaksiPemasukan << " transaksi" << endl;
    }
    
    pauseProgram();
}

/*
 * Fungsi: lihatRiwayatPengeluaran()
 * Tujuan: Menampilkan semua data pengeluaran dalam bentuk tabel
 */
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

// ============================================================================
//                    FUNGSI LAPORAN LENGKAP
// ============================================================================
/*
 * Fungsi: lihatLaporanLengkap()
 * Tujuan: Menampilkan laporan keuangan lengkap (pemasukan + pengeluaran + ringkasan)
 */
void lihatLaporanLengkap() {
    clearScreen();
    tampilkanHeader();
    
    // Hitung total-total yang diperlukan
    double totalMasuk = hitungTotalPemasukan();
    double totalKeluar = hitungTotalPengeluaran();
    double saldo = totalMasuk - totalKeluar;  // Saldo = Pemasukan - Pengeluaran
    
    cout << "\n" << GARIS_PANJANG << endl;
    cout << "|        LAPORAN KEUANGAN LENGKAP                |" << endl;
    cout << GARIS_PANJANG << endl;
    
    // --- Bagian Pemasukan ---
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
    
    // --- Bagian Pengeluaran ---
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
    
    // --- Ringkasan Total ---
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

// ============================================================================
//                    FUNGSI ANALISIS STATUS KEUANGAN
// ============================================================================
/*
 * Fungsi: lihatSaldoDanStatus()
 * Tujuan: Menampilkan analisis status keuangan (untung/rugi/impas)
 * 
 * KONSEP PENTING:
 * - Percabangan IF-ELSE IF-ELSE untuk menentukan status
 * - Perhitungan persentase margin keuntungan
 * - Rata-rata transaksi
 */
void lihatSaldoDanStatus() {
    clearScreen();
    tampilkanHeader();
    
    // Hitung semua nilai yang diperlukan
    double totalMasuk = hitungTotalPemasukan();
    double totalKeluar = hitungTotalPengeluaran();
    double saldo = totalMasuk - totalKeluar;
    
    // Hitung persentase margin (jika ada pemasukan)
    // Rumus: (Saldo / Total Pemasukan) x 100%
    double persentase = (totalMasuk > 0) ? ((saldo / totalMasuk) * 100) : 0;
    
    cout << "\n" << GARIS_PANJANG << endl;
    cout << "|          SALDO & STATUS KEUANGAN               |" << endl;
    cout << GARIS_PANJANG << endl;
    
    // --- Ringkasan Keuangan ---
    cout << "\n>>> RINGKASAN KEUANGAN <<<" << endl;
    cout << GARIS_PENDEK << endl;
    cout << left << setw(30) << "Total Pemasukan" << ": " << formatRupiah(totalMasuk) << endl;
    cout << left << setw(30) << "Total Pengeluaran" << ": " << formatRupiah(totalKeluar) << endl;
    cout << GARIS_PENDEK << endl;
    cout << left << setw(30) << "SALDO AKHIR" << ": " << formatRupiah(saldo) << endl;
    
    // --- Statistik ---
    cout << "\n>>> STATISTIK <<<" << endl;
    cout << GARIS_PENDEK << endl;
    cout << left << setw(30) << "Jumlah Transaksi Masuk" << ": " << totalTransaksiPemasukan << " transaksi" << endl;
    cout << left << setw(30) << "Jumlah Transaksi Keluar" << ": " << totalTransaksiPengeluaran << " transaksi" << endl;
    cout << left << setw(30) << "Total Semua Transaksi" << ": " << (totalTransaksiPemasukan + totalTransaksiPengeluaran) << " transaksi" << endl;
    
    // Hitung dan tampilkan rata-rata (jika ada transaksi)
    if (totalTransaksiPemasukan > 0) {
        double rataRataMasuk = totalMasuk / totalTransaksiPemasukan;
        cout << left << setw(30) << "Rata-rata Pemasukan" << ": " << formatRupiah(rataRataMasuk) << endl;
    }
    
    if (totalTransaksiPengeluaran > 0) {
        double rataRataKeluar = totalKeluar / totalTransaksiPengeluaran;
        cout << left << setw(30) << "Rata-rata Pengeluaran" << ": " << formatRupiah(rataRataKeluar) << endl;
    }
    
    // --- Status Keuangan (PERCABANGAN IF-ELSE) ---
    cout << "\n>>> STATUS KEUANGAN <<<" << endl;
    cout << GARIS_PENDEK << endl;
    
    // PERCABANGAN untuk menentukan status keuangan
    if (totalMasuk == 0 && totalKeluar == 0) {
        // Kondisi 1: Belum ada transaksi sama sekali
        cout << "[i] STATUS: BELUM ADA TRANSAKSI" << endl;
        cout << "    Silakan mulai mencatat keuangan Anda." << endl;
    } 
    else if (saldo > 0) {
        // Kondisi 2: Saldo positif = UNTUNG
        cout << "[+] STATUS: UNTUNG / SURPLUS" << endl;
        cout << "    Selamat! Keuangan Anda dalam kondisi POSITIF." << endl;
        cout << "    Keuntungan: " << formatRupiah(saldo) << endl;
        if (totalMasuk > 0) {
            cout << fixed << setprecision(2);  // Format 2 angka di belakang koma
            cout << "    Margin Keuntungan: " << persentase << "%" << endl;
        }
    } 
    else if (saldo < 0) {
        // Kondisi 3: Saldo negatif = RUGI
        cout << "[-] STATUS: RUGI / DEFISIT" << endl;
        cout << "    Perhatian! Keuangan Anda dalam kondisi NEGATIF." << endl;
        cout << "    Kerugian: " << formatRupiah(-saldo) << endl;  // -saldo agar tampil positif
        cout << "    Saran: Kurangi pengeluaran atau tingkatkan pemasukan." << endl;
    } 
    else {
        // Kondisi 4: Saldo = 0 = IMPAS
        cout << "[=] STATUS: IMPAS / BREAK EVEN" << endl;
        cout << "    Pemasukan dan pengeluaran Anda seimbang." << endl;
        cout << "    Tidak ada keuntungan atau kerugian." << endl;
    }
    
    cout << GARIS_PANJANG << endl;
    
    pauseProgram();
}

// ============================================================================
//                         FUNGSI UTAMA (MAIN)
// ============================================================================
/*
 * Fungsi: main()
 * Ini adalah fungsi utama yang pertama kali dijalankan saat program dimulai
 * 
 * KONSEP PENTING:
 * - DO-WHILE loop: Menu akan terus ditampilkan sampai user memilih keluar (0)
 * - SWITCH-CASE: Untuk menangani pilihan menu user
 */
int main() {
    int pilihan;  // Variabel untuk menyimpan pilihan menu user
    
    // DO-WHILE: Jalankan minimal 1 kali, ulangi selama pilihan != 0
    do {
        clearScreen();
        tampilkanHeader();
        tampilkanMenu();
        
        // Input pilihan dari user
        cout << "\nMasukkan pilihan Anda [0-6]: ";
        cin >> pilihan;
        
        // SWITCH-CASE: Eksekusi fungsi sesuai pilihan
        switch (pilihan) {
            case 1:
                tambahPemasukan();      // Panggil fungsi tambah pemasukan
                break;
            case 2:
                tambahPengeluaran();    // Panggil fungsi tambah pengeluaran
                break;
            case 3:
                lihatRiwayatPemasukan();    // Panggil fungsi lihat riwayat pemasukan
                break;
            case 4:
                lihatRiwayatPengeluaran();  // Panggil fungsi lihat riwayat pengeluaran
                break;
            case 5:
                lihatLaporanLengkap();      // Panggil fungsi laporan lengkap
                break;
            case 6:
                lihatSaldoDanStatus();      // Panggil fungsi status keuangan
                break;
            case 0:
                // Tampilkan pesan keluar
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
                // Jika pilihan tidak valid (bukan 0-6)
                cout << "\n[X] ERROR: Pilihan tidak valid!" << endl;
                cout << "    Silakan pilih menu 0-6." << endl;
                pauseProgram();
        }
        
    } while (pilihan != 0);  // Ulangi selama pilihan bukan 0
    
    return 0;  // Program selesai dengan sukses
}
