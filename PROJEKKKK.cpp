#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct Akun {
    string nama;
    string sandi;
    string alamat;
    string pekerjaan;
    string no_telp;
    int nik;
};

struct Data {
    int nik;
    int jumlah_saldo;
    int jumlah_pinjaman;
    int no_rek;
    string mutasi[100];
    int mutasi_count = 0;
};

Akun akunArray[100];
Data dataArray[100] = {
    {1, 500000, 200000, 110}, {2, 150000, 50000, 111}, {3, 300000, 100000, 112}, {4, 700000, 300000, 113},
    {5, 250000, 100000, 114}, {6, 450000, 200000, 115}, {7, 100000, 50000, 116}, {8, 350000, 150000, 117},
    {9, 600000, 250000, 118}, {10, 200000, 100000, 119}, {11, 800000, 350000, 120}, {12, 300000, 150000, 121},
    {13, 400000, 200000, 122}, {14, 150000, 75000, 123}, {15, 500000, 250000, 124}, {16, 350000, 150000, 125},
    {17, 600000, 300000, 126}, {18, 250000, 125000, 127}, {19, 450000, 225000, 128}, {20, 550000, 275000, 129},
    {21, 100000, 50000, 130}, {22, 300000, 150000, 131}, {23, 700000, 350000, 132}, {24, 400000, 200000, 133},
    {25, 600000, 300000, 134}, {26, 200000, 100000, 135}, {27, 450000, 225000, 136}, {28, 150000, 75000, 137},
    {29, 500000, 250000, 138}, {30, 350000, 175000, 139}, {31, 600000, 300000, 140}, {32, 200000, 100000, 141},
    {33, 550000, 275000, 142}, {34, 150000, 75000, 143}, {35, 450000, 225000, 144}, {36, 300000, 150000, 145},
    {37, 700000, 350000, 146}, {38, 400000, 200000, 147}, {39, 250000, 125000, 148}, {40, 500000, 250000, 149},
    {41, 100000, 50000, 150}, {42, 300000, 150000, 151}, {43, 700000, 350000, 152}, {44, 400000, 200000, 153},
    {45, 600000, 300000, 154}, {46, 200000, 100000, 155}, {47, 550000, 275000, 156}, {48, 250000, 125000, 157},
    {49, 450000, 225000, 158}, {50, 150000, 75000, 159}, {51, 500000, 250000, 160}, {52, 350000, 175000, 161},
    {53, 600000, 300000, 162}, {54, 200000, 100000, 163}, {55, 550000, 275000, 164}, {56, 150000, 75000, 165},
    {57, 450000, 225000, 166}, {58, 300000, 150000, 167}, {59, 700000, 350000, 168}, {60, 400000, 200000, 169},
    {61, 250000, 125000, 170}, {62, 500000, 250000, 171}, {63, 100000, 50000, 172}, {64, 300000, 150000, 173},
    {65, 700000, 350000, 174}, {66, 400000, 200000, 175}, {67, 600000, 300000, 176}, {68, 200000, 100000, 177},
    {69, 550000, 275000, 178}, {70, 250000, 125000, 179}, {71, 450000, 225000, 180}, {72, 150000, 75000, 181},
    {73, 500000, 250000, 182}, {74, 350000, 175000, 183}, {75, 600000, 300000, 184}, {76, 200000, 100000, 185},
    {77, 550000, 275000, 186}, {78, 150000, 75000, 187}, {79, 450000, 225000, 188}, {80, 300000, 150000, 189},
    {81, 700000, 350000, 190}, {82, 400000, 200000, 191}, {83, 250000, 125000, 192}, {84, 500000, 250000, 193},
    {85, 100000, 50000, 194}, {86, 300000, 150000, 195}, {87, 700000, 350000, 196}, {88, 400000, 200000, 197},
    {89, 600000, 300000, 198}, {90, 200000, 100000, 199}, {91, 550000, 275000, 200}, {92, 250000, 125000, 201},
    {93, 450000, 225000, 202}, {94, 150000, 75000, 203}, {95, 500000, 250000, 204}, {96, 350000, 175000, 205},
    {97, 600000, 300000, 206}, {98, 200000, 100000, 207}, {99, 550000, 275000, 208}, {100, 150000, 75000, 209}
};

int cariNik(string username) {
    for (int i = 0; i < 100; i++) {
        if (username == akunArray[i].nama) {
            return akunArray[i].nik;
        }
    }
    return -1;
}

int cariTempatSaldo(int nik) {
    for (int i = 0; i < 100; i++) {
        if (dataArray[i].nik == nik) {
            return i;
        }
    }
    return -1;
}

void tampilkanMutasi(string mutasi[], int index) {
    if (index < 0) return;
    tampilkanMutasi(mutasi, index - 1);
    cout << mutasi[index] << endl;
}

void pilihanMember(string username) {
    int pilihan;
    bool kembaliKeMenuMember = true;

    while (kembaliKeMenuMember) {
        system("cls");
        cout << username << endl;
        cout << "Pilihan anda sebagai member bank CIHUY\n";
        cout << "1. Lihat saldo\n2. Pembayaran\n3. Transfer\n4. Mutasi saldo\n5. Jumlah pinjaman\n6. Kembali ke menu utama\n";
        cin >> pilihan;

        int indeks = cariTempatSaldo(cariNik(username));
        if (indeks == -1) {
            cout << "Akun tidak ditemukan.\n";
            system("pause");
            return;
        }

        // Deklarasi variabel di luar switch-case
        int bayar, transferPilihan, rekTujuan, jumlahTransfer, indexTujuan;

        switch (pilihan) {
        case 1:
            system("cls");
            cout << "Saldo Anda: " << dataArray[indeks].no_rek << endl;
            cout << "Saldo Anda: " << dataArray[indeks].jumlah_saldo << endl;
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "Masukkan jumlah pembayaran: ";
            cin >> bayar;
            if (bayar > dataArray[indeks].jumlah_saldo) {
                cout << "Saldo tidak mencukupi.\n";
            } else {
                dataArray[indeks].jumlah_saldo -= bayar;
                dataArray[indeks].mutasi[dataArray[indeks].mutasi_count++] = "Pembayaran: -" + to_string(bayar);
                cout << "Pembayaran berhasil! Sisa saldo: " << dataArray[indeks].jumlah_saldo << endl;
            }
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "Pilih jenis transfer:\n";
            cout << "1. Transfer ke bank yang sama\n";
            cout << "2. Transfer ke bank lain\n";
            cin >> transferPilihan;

            cout << "Masukkan nomor rekening tujuan: ";
            cin >> rekTujuan;
            cout << "Masukkan jumlah transfer: ";
            cin >> jumlahTransfer;

            indexTujuan = -1;
            for (int i = 0; i < 100; i++) {
                if (dataArray[i].no_rek == rekTujuan) {
                    indexTujuan = i;
                    break;
                }
            }

            if (indexTujuan == -1) {
                cout << "Rekening tujuan tidak ditemukan.\n";
            } else if (jumlahTransfer > dataArray[indeks].jumlah_saldo) {
                cout << "Saldo tidak mencukupi untuk transfer.\n";
            } else {
                dataArray[indeks].jumlah_saldo -= jumlahTransfer;
                dataArray[indexTujuan].jumlah_saldo += jumlahTransfer;
                dataArray[indeks].mutasi[dataArray[indeks].mutasi_count++] = "Transfer ke " + to_string(rekTujuan) + ": -" + to_string(jumlahTransfer);
                dataArray[indexTujuan].mutasi[dataArray[indexTujuan].mutasi_count++] = "Transfer dari " + to_string(dataArray[indeks].no_rek) + ": +" + to_string(jumlahTransfer);
                cout << "Transfer berhasil! Sisa saldo Anda: " << dataArray[indeks].jumlah_saldo << endl;

                if (transferPilihan == 2) {
                    cout << "Karena transfer ke bank lain, biaya admin dikenakan.\n";
                    int biayaAdmin = 5000;
                    if (dataArray[indeks].jumlah_saldo >= biayaAdmin) {
                        dataArray[indeks].jumlah_saldo -= biayaAdmin;
                        dataArray[indeks].mutasi[dataArray[indeks].mutasi_count++] = "Biaya admin: -" + to_string(biayaAdmin);
                        cout << "Biaya admin sebesar " << biayaAdmin << " telah dipotong dari saldo Anda.\n";
                    } else {
                        cout << "Saldo tidak mencukupi untuk membayar biaya admin.\n";
                    }
                }
            }
            system("pause");
            break;

        case 4:
            system("cls");
            cout << "Mutasi saldo:\n";
            tampilkanMutasi(dataArray[indeks].mutasi, dataArray[indeks].mutasi_count - 1);
            system("pause");
            break;

        case 5:
            system("cls");
            cout << "Jumlah pinjaman Anda: " << dataArray[indeks].jumlah_pinjaman << endl;
            getch();
            break;

        case 6:
            kembaliKeMenuMember = false; // Keluar dari loop dan kembali ke menu utama
            break;

        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            system("pause");
            break;
        }
    }
}

int jml_user = 0;

// Fungsi untuk mengecek apakah NIK sudah terdaftar
bool checkDaftarAkunBaru(int NIK) {
    for (int i = 0; i < jml_user; i++) {
        if (akunArray[i].nik == NIK) {
            return true; // NIK sudah terdaftar
        }
    }
    return false; // NIK belum terdaftar
}

// Fungsi untuk pendaftaran akun baru
void daftarAkunBaru() {
    int NIK;
    system("cls");
    cout << "Masukkan NIK           : ";
    cin >> NIK;
    cin.ignore();

    if (checkDaftarAkunBaru(NIK)) {
        cout << "NIK sudah terdaftar. Silakan gunakan NIK lain.\n";
        cin.get();
        return;
    }

    cout << "Masukkan nama          : ";
    getline(cin, akunArray[jml_user].nama);
    cout << "Masukkan sandi         : ";
    getline(cin, akunArray[jml_user].sandi);
    cout << "Masukkan alamat        : ";
    getline(cin, akunArray[jml_user].alamat);
    cout << "Masukkan pekerjaan     : ";
    getline(cin, akunArray[jml_user].pekerjaan);
    cout << "Masukkan nomor telepon : ";
    getline(cin, akunArray[jml_user].no_telp);
    akunArray[jml_user].nik = NIK;

    system("cls");
    cout << "\nNama         : " << akunArray[jml_user].nama;
    cout << "\nSandi        : " << akunArray[jml_user].sandi;
    cout << "\nAlamat       : " << akunArray[jml_user].alamat;
    cout << "\nPekerjaan    : " << akunArray[jml_user].pekerjaan;
    cout << "\nNomor Telepon: " << akunArray[jml_user].no_telp;
    cout << "\nNIK          : " << NIK << endl;

    int konfirmasi;
    do {
        cout << "Apakah Data Anda Sudah Benar?\n1). Benar\n2). Salah\n";
        cin >> konfirmasi;
        if (konfirmasi == 1) {
            jml_user++;
            cout << "Akun berhasil didaftarkan!\n";
            cin.get();
        } else if (konfirmasi == 2) {
            cout << "Silakan ulangi pendaftaran.\n";
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (konfirmasi != 1 && konfirmasi != 2);
}

// Fungsi untuk login
void loginAkun() {
    system("cls");
    if (jml_user == 0) {
        cout << "Anda belum memiliki akun, buat terlebih dahulu.\n";
        cin.get();
        return;
    }

    string namaLogin, sandiLogin;
    cout << "Masukkan nama          : ";
    getline(cin, namaLogin);
    cout << "Masukkan sandi         : ";
    getline(cin, sandiLogin);

    bool akunDitemukan = false;
    for (int i = 0; i < jml_user; i++) {
        if (namaLogin == akunArray[i].nama && sandiLogin == akunArray[i].sandi) {
            akunDitemukan = true;
            cout << "Selamat datang, " << akunArray[i].nama << "!\n";
            cin.get();
            // Panggil fungsi menu member setelah login berhasil
            pilihanMember(akunArray[i].nama);
            break;
        }
    }

    if (!akunDitemukan) {
        cout << "Nama atau sandi salah. Silakan coba lagi.\n";
        cin.get();
    }
}

int main() {
    bool ulang = true;
    while (ulang) {
        system("cls");
        cout << "Selamat datang di bank CIHUY\n";
        cout << "1. Daftar Akun Baru\n";
        cout << "2. Login Akun\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        int pilihan;
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                daftarAkunBaru();
                break;
            case 2:
                loginAkun();
                break;
            case 3:
                ulang = false;
                cout << "Terima kasih telah menggunakan layanan kami.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                cin.get();
                break;
        }
    }
    return 0;
}