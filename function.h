#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Akun
{
    string nama;
    string sandi;
    string alamat;
    string pekerjaan;
    string no_telp;
    int NIK;
};

struct Login
{
    string namaLogin;
    string sandiLogin;
};

struct Data
{
    string nama;
    int jumlah_saldo;
    int jumlah_pinjaman;
};

Akun akunarray[1000];
Data dataarray[1000];

void pilihanmember()
{
    system("cls");
    int pilihan;
    string namamembercheck;
    cout << "Pilihan anda sebagai member bank CIHUY\n1. Lihat saldo\n2. Pembayaran\n3. Transfer\n4. Mutasi saldo\n5. Kembali ke menu utama\n";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        system("cls");
        cout << "Berikut jumlah saldo anda: ";
        getline(cin, namamembercheck);
        cout << "Saldo untuk member " << namamembercheck << " adalah ...\n";
        break;

    case 2:
        cout << "Berikut jumlah saldo anda: ";
        break;

    case 3:
        cout << "Berikut jumlah saldo anda: ";
        break;

    case 4:
        cout << "Berikut jumlah saldo anda: ";
        break;

    case 5:
        cout << "Berikut jumlah saldo anda: ";
        break;

    default:
        cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        break;
    }
}
