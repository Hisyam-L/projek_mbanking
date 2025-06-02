#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <conio.h>
using namespace std;

struct Data {
    int NIK;
    int jumlah_saldo;
    int jumlah_pinjaman;
};

struct riwayat_pembayaran {
    int NIK;
    int jumlah_pembayaran;
    int counter;
};

struct Akun {
    string nama;
    string sandi;
    string alamat;
    string pekerjaan;
    string no_telp;
    int NIK;
    string saldo;
    string pinjaman;
};

struct Login {
    string namaLogin;
    string sandiLogin;
    int NIKLogin;
};

int jml_user = 0;
int jml_rek = 100;
int pembayaran_counter = 0;

Data rekening[200] = {
    {1, 500000, 200000}, {2, 150000, 50000}, {3, 300000, 100000}, {4, 700000, 300000},
    {5, 250000, 100000}, {6, 450000, 200000}, {7, 100000, 50000}, {8, 350000, 150000},
    {9, 600000, 250000}, {10, 200000, 100000}, {11, 800000, 350000}, {12, 300000, 150000},
    {13, 400000, 200000}, {14, 150000, 75000}, {15, 500000, 250000}, {16, 350000, 150000},
    {17, 600000, 300000}, {18, 250000, 125000}, {19, 450000, 225000}, {20, 550000, 275000},
    {21, 100000, 50000}, {22, 300000, 150000}, {23, 700000, 350000}, {24, 400000, 200000},
    {25, 600000, 300000}, {26, 200000, 100000}, {27, 450000, 225000}, {28, 150000, 75000},
    {29, 500000, 250000}, {30, 350000, 175000}, {31, 600000, 300000}, {32, 200000, 100000},
    {33, 550000, 275000}, {34, 150000, 75000}, {35, 450000, 225000}, {36, 300000, 150000},
    {37, 700000, 350000}, {38, 400000, 200000}, {39, 250000, 125000}, {40, 500000, 250000},
    {41, 100000, 50000}, {42, 300000, 150000}, {43, 700000, 350000}, {44, 400000, 200000},
    {45, 600000, 300000}, {46, 200000, 100000}, {47, 550000, 275000}, {48, 250000, 125000},
    {49, 450000, 225000}, {50, 150000, 75000}, {51, 500000, 250000}, {52, 350000, 175000},
    {53, 600000, 300000}, {54, 200000, 100000}, {55, 550000, 275000}, {56, 150000, 75000},
    {57, 450000, 225000}, {58, 300000, 150000}, {59, 700000, 350000}, {60, 400000, 200000},
    {61, 250000, 125000}, {62, 500000, 250000}, {63, 100000, 50000}, {64, 300000, 150000},
    {65, 700000, 350000}, {66, 400000, 200000}, {67, 600000, 300000}, {68, 200000, 100000},
    {69, 550000, 275000}, {70, 250000, 125000}, {71, 450000, 225000}, {72, 150000, 75000},
    {73, 500000, 250000}, {74, 350000, 175000}, {75, 600000, 300000}, {76, 200000, 100000},
    {77, 550000, 275000}, {78, 150000, 75000}, {79, 450000, 225000}, {80, 300000, 150000},
    {81, 700000, 350000}, {82, 400000, 200000}, {83, 250000, 125000}, {84, 500000, 250000},
    {85, 100000, 50000}, {86, 300000, 150000}, {87, 700000, 350000}, {88, 400000, 200000},
    {89, 600000, 300000}, {90, 200000, 100000}, {91, 550000, 275000}, {92, 250000, 125000},
    {93, 450000, 225000}, {94, 150000, 75000}, {95, 500000, 250000}, {96, 350000, 175000},
    {97, 600000, 300000}, {98, 200000, 100000}, {99, 550000, 275000}, {100, 150000, 75000}
};

riwayat_pembayaran pembayaran[200];
Akun akun[200];

void simpanRekeningKeFile() {
    ofstream file("rekening.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file rekening.txt untuk menulis.\n";
        return;
    }
    for (int i = 0; i < jml_rek; i++) {
        file << rekening[i].NIK << "," << rekening[i].jumlah_saldo << "," << rekening[i].jumlah_pinjaman << endl;
    }
    file.close();
}

void loadRekeningDariFile() {
    ifstream file("rekening.txt");
    if (!file.is_open()) {
        return;
    }
    string line;
    int idx = 0;
    while (getline(file, line) && idx < 200) {
        stringstream ss(line);
        string item;
        Data temp;
        getline(ss, item, ','); temp.NIK = stoi(item);
        getline(ss, item, ','); temp.jumlah_saldo = stoi(item);
        getline(ss, item, ','); temp.jumlah_pinjaman = stoi(item);
        rekening[idx] = temp;
        idx++;
    }
    jml_rek = idx;
    file.close();
}

int cariTempatSaldo(int NIK, int index) {
    if (index >= jml_rek) {
        return -1;
    }
    if (rekening[index].NIK == NIK) {
        return index;
    }
    return cariTempatSaldo(NIK, index + 1);
}

void caridata(int NIK, int pilih) {
    ifstream file("akun.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file akun.txt\n";
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        Akun a;
        getline(ss, token, ','); a.NIK = stoi(token);
        getline(ss, a.alamat, ',');
        getline(ss, a.nama, ',');
        getline(ss, a.no_telp, ',');
        getline(ss, a.pekerjaan, ',');
        getline(ss, a.sandi, ',');
        if (a.NIK == NIK) {
            if (pilih == 1) {
                cout << "Nama      : " << a.nama << endl;
                cout << "Alamat    : " << a.alamat << endl;
                cout << "No Telp   : " << a.no_telp << endl;
                cout << "Pekerjaan : " << a.pekerjaan << endl;
                cout << "NIK       : " << a.NIK << endl;
            } else if (pilih == 2) {
                cout << a.nama << endl;
            }
            file.close();
            return;
        }
    }
    cout << "Data dengan NIK " << NIK << " tidak ditemukan.\n";
    file.close();
}

void tampilkanSaldoPinjaman(int NIK) {
    Data* ptr = nullptr;
    for (int i = 0; i < jml_rek; i++) {
        if (rekening[i].NIK == NIK) {
            ptr = &rekening[i];
            break;
        }
    }
    if (ptr != nullptr) {
        cout << "Jumlah Saldo   : " << ptr->jumlah_saldo << endl;
        cout << "Jumlah Pinjaman: " << ptr->jumlah_pinjaman << endl;
    } else {
        cout << "NIK tidak ditemukan di data rekening.\n";
    }
}

void pembayaranPinjaman(int NIK) {
    int index = 0;
    int idx = cariTempatSaldo(NIK, index);
    if (idx == -1) {
        cout << "NIK tidak ditemukan di data rekening.\n";
        return;
    }
    int bayar;
    cout << "Jumlah Pinjaman Saat Ini : " << rekening[idx].jumlah_pinjaman << endl;
    cout << "Saldo Anda Saat Ini      : " << rekening[idx].jumlah_saldo << endl;
    cout << "Masukkan jumlah pembayaran pinjaman: ";
    cin >> bayar;
    if (bayar <= 0) {
        cout << "Jumlah pembayaran tidak valid.\n";
        return;
    }
    if (bayar > rekening[idx].jumlah_saldo) {
        cout << "Saldo anda tidak cukup untuk melakukan pembayaran.\n";
        return;
    }
    if (bayar > rekening[idx].jumlah_pinjaman) {
        cout << "Jumlah bayar melebihi pinjaman. Transaksi dibatalkan.\n";
        return;
    }
    rekening[idx].jumlah_pinjaman -= bayar;
    rekening[idx].jumlah_saldo -= bayar;
    pembayaran[pembayaran_counter].NIK = NIK;
    pembayaran[pembayaran_counter].jumlah_pembayaran = bayar;
    pembayaran[pembayaran_counter].counter = pembayaran_counter + 1;
    pembayaran_counter++;
    cout << "Pembayaran berhasil.\n";
    cout << "Sisa Pinjaman : " << rekening[idx].jumlah_pinjaman << endl;
    cout << "Sisa Saldo    : " << rekening[idx].jumlah_saldo << endl;
    simpanRekeningKeFile();
}

void bubbleSortPembayaranAsc() {
    for (int i = 0; i < pembayaran_counter - 1; i++) {
        for (int j = 0; j < pembayaran_counter - 1 - i; j++) {
            if (pembayaran[j].jumlah_pembayaran > pembayaran[j + 1].jumlah_pembayaran) {
                riwayat_pembayaran temp = pembayaran[j];
                pembayaran[j] = pembayaran[j + 1];
                pembayaran[j + 1] = temp;
            }
        }
    }
}

void bubbleSortPembayaranDesc() {
    for (int i = 0; i < pembayaran_counter - 1; i++) {
        for (int j = 0; j < pembayaran_counter - 1 - i; j++) {
            if (pembayaran[j].jumlah_pembayaran < pembayaran[j + 1].jumlah_pembayaran) {
                riwayat_pembayaran temp = pembayaran[j];
                pembayaran[j] = pembayaran[j + 1];
                pembayaran[j + 1] = temp;
            }
        }
    }
}

void pilihanmember(int NIK) {
    bool ulang = true;
    while (ulang) {
        system("cls");
        int pilihan;
        cout << "Menu:\n";
        cout << "1. Lihat saldo\n";
        cout << "2. Pembayaran pinjaman\n";
        cout << "3. Transfer saldo\n";
        cout << "4. Riwayat pembayaran\n";
        cout << "5. Jumlah pinjaman\n";
        cout << "6. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            system("cls");
            cout << "Saldo anda:\n";
            tampilkanSaldoPinjaman(NIK);
            cout << "Tekan Enter untuk melanjutkan...\n";
            cin.get();
            break;
        case 2:
            system("cls");
            pembayaranPinjaman(NIK);
            cout << "Tekan Enter untuk melanjutkan...\n";
            cin.get();
            break;
        case 3: {
            system("cls");
            int index = 0;
            int tujuanNIK, jumlahTransfer;
            cout << "Masukkan NIK penerima transfer: ";
            cin >> tujuanNIK;
            cin.ignore();
            int idxTujuan = cariTempatSaldo(tujuanNIK, index);
            if (idxTujuan == -1) {
                cout << "NIK penerima tidak ditemukan.\n";
                cout << "Tekan Enter untuk melanjutkan...\n";
                cin.get();
                break;
            }
            cout << "Masukkan jumlah transfer: ";
            cin >> jumlahTransfer;
            cin.ignore();
            if (jumlahTransfer <= 0) {
                cout << "Jumlah transfer tidak valid.\n";
                cout << "Tekan Enter untuk melanjutkan...\n";
                cin.get();
                break;
            }
            int idxPengirim = cariTempatSaldo(NIK, index);
            if (jumlahTransfer > rekening[idxPengirim].jumlah_saldo) {
                cout << "Saldo anda tidak cukup untuk transfer.\n";
                cout << "Tekan Enter untuk melanjutkan...\n";
                cin.get();
                break;
            }
            rekening[idxPengirim].jumlah_saldo -= jumlahTransfer;
            rekening[idxTujuan].jumlah_saldo += jumlahTransfer;
            cout << "Transfer berhasil.\n";
            simpanRekeningKeFile();
            cout << "Tekan Enter untuk melanjutkan...\n";
            cin.get();
            break;
        }
        case 4:
            system("cls");
            if (pembayaran_counter == 0) {
                cout << "Belum ada riwayat pembayaran.\n";
            } else {
                cout << "Pilih urutan riwayat pembayaran:\n";
                cout << "1. Ascending\n";
                cout << "2. Descending\n";
                cout << "Pilih: ";
                int urutan;
                cin >> urutan;
                cin.ignore();
                if (urutan == 1) {
                    bubbleSortPembayaranAsc();
                } else if (urutan == 2) {
                    bubbleSortPembayaranDesc();
                }
                bool found = false;
                for (int i = 0; i < pembayaran_counter; i++) {
                    if (pembayaran[i].NIK == NIK) {
                        cout << i + 1 << ". Jumlah pembayaran: " << pembayaran[i].jumlah_pembayaran << endl;
                        found = true;
                    }
                }
                if (!found) {
                    cout << "Belum ada riwayat pembayaran untuk akun ini.\n";
                }
            }
            cout << "Tekan Enter untuk melanjutkan...\n";
            cin.get();
            break;
        case 5:
            system("cls");
            cout << "Jumlah pinjaman anda:\n";
            tampilkanSaldoPinjaman(NIK);
            cout << "Tekan Enter untuk melanjutkan...\n";
            cin.get();
            break;
        case 6:
            ulang = false;
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            cout << "Tekan Enter untuk mencoba lagi...\n";
            cin.get();
            break;
        }
    }
}

void login() {
    bool ulang = true;
    while (ulang) {
        system("cls");
        ifstream file("akun.txt");
        if (!file.is_open()) {
            cout << "File akun.txt tidak ditemukan atau gagal dibuka.\n";
            getch();
            return;
        }
        Login userlogin;
        cout << "Masukkan NIK : ";
        cin >> userlogin.NIKLogin;
        cin.ignore();
        cout << "Masukkan nama : ";
        getline(cin, userlogin.namaLogin);
        cout << "Masukkan sandi : ";
        getline(cin, userlogin.sandiLogin);
        bool akun_ditemukan = false;
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Akun a;
            string token;
            getline(ss, token, ','); a.NIK = stoi(token);
            getline(ss, a.alamat, ',');
            getline(ss, a.nama, ',');
            getline(ss, a.no_telp, ',');
            getline(ss, a.pekerjaan, ',');
            getline(ss, a.sandi, ',');
            if (userlogin.NIKLogin == a.NIK &&
                userlogin.namaLogin == a.nama &&
                userlogin.sandiLogin == a.sandi) {
                akun_ditemukan = true;
                cout << "Selamat datang " << a.nama << "!" << endl << endl;
                cin.get();
                pilihanmember(a.NIK);
                break;
            }
        }
        file.close();
        if (!akun_ditemukan) {
            cout << "Sandi atau nama akun anda salah\n";
            cout << "Apakah ingin mengulangi lagi ?\n1. Iya\n2. Tidak\nMasukan pilihan anda : ";
            int pil;
            cin >> pil;
            cin.ignore();
            ulang = (pil == 1);
        } else {
            ulang = false;
        }
    }
}

void simpanAkunKeFile(const Akun& a) {
    ofstream file("akun.txt", ios::app);
    if (!file.is_open()) {
        cout << "Gagal membuka file akun.txt untuk menulis.\n";
        return;
    }
    file << a.NIK << "," << a.alamat << "," << a.nama << "," << a.no_telp << "," << a.pekerjaan << "," << a.sandi << "," << a.saldo << "," << a.pinjaman << endl;
    file.close();
}

void daftar() {
    bool ulang = true;
    while (ulang) {
        Akun dummyakun;
        system("cls");
        cout << "Masukkan NIK : ";
        cin >> dummyakun.NIK;
        cin.ignore();
        bool exists = false;
        for (int i = 0; i < jml_rek; i++) {
            if (rekening[i].NIK == dummyakun.NIK) {
                exists = true;
                dummyakun.saldo = to_string(rekening[i].jumlah_saldo);
                dummyakun.pinjaman = to_string(rekening[i].jumlah_pinjaman);
                break;
            }
        }
        if (!exists) {
            cout << "Data Rekening Belum Terdaftar, pendaftaran akun tidak dapat dilakukan.\n";
            cout << "Tekan Enter untuk melanjutkan...\n";
            cin.get();
            return;
        }
        ifstream akunFile("akun.txt");
        bool akun_exists = false;
        if (akunFile.is_open()) {
            string line;
            while (getline(akunFile, line)) {
                stringstream ss(line);
                string token;
                int fileNIK;
                getline(ss, token, ',');
                fileNIK = stoi(token);
                if (fileNIK == dummyakun.NIK) {
                    akun_exists = true;
                    break;
                }
            }
            akunFile.close();
        }
        if (akun_exists) {
            cout << "Akun dengan NIK tersebut sudah terdaftar.\n";
            cout << "Tekan Enter untuk melanjutkan...\n";
            cin.get();
            return;
        }
        cout << "Data Rekening Terdaftar, silahkan buat akun baru\n";
        cout << "Masukkan nama : "; getline(cin, dummyakun.nama);
        cout << "Masukkan sandi : "; getline(cin, dummyakun.sandi);
        cout << "Masukkan alamat : "; getline(cin, dummyakun.alamat);
        cout << "Masukkan pekerjaan : "; getline(cin, dummyakun.pekerjaan);
        cout << "Masukkan nomor telepon : "; getline(cin, dummyakun.no_telp);
        system("cls");
        cout << "Konfirmasi data:\n";
        cout << "Nama         : " << dummyakun.nama << endl;
        cout << "Sandi        : " << dummyakun.sandi << endl;
        cout << "Alamat       : " << dummyakun.alamat << endl;
        cout << "Pekerjaan    : " << dummyakun.pekerjaan << endl;
        cout << "No. Telepon  : " << dummyakun.no_telp << endl;
        cout << "NIK          : " << dummyakun.NIK << endl;
        cout << "Saldo        : " << dummyakun.saldo << endl;
        cout << "Pinjaman     : " << dummyakun.pinjaman << endl;
        cout << "\nApakah data sudah benar? (1. Ya / 2. Tidak): ";
        int pil;
        cin >> pil;
        cin.ignore();
        if (pil == 1) {
            akun[jml_user] = dummyakun;
            jml_user++;
            simpanAkunKeFile(dummyakun);
            cout << "Pendaftaran akun berhasil.\n";
            cout << "Tekan Enter untuk melanjutkan...\n";
            cin.get();
            ulang = false;
        }
    }
}

int main() {
    loadRekeningDariFile();
    bool ulang = true;
    while (ulang) {
        int pil;
        system("cls");
        cout << "Selamat datang di bank CIHUY\n";
        cout << "1. Daftar\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pil;
        cin.ignore();
        switch (pil) {
            case 1:
                daftar();
                break;
            case 2:
                login();
                break;
            case 3:
                ulang = false;
                break;
            default:
                cout << "Pilihan tidak valid.\nTekan Enter untuk mencoba lagi...\n";
                cin.get();
                break;
        }
    }
    return 0;
}

