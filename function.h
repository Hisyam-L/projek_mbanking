#include "data.cpp"
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




Akun akunarray[100];


bool check_daftar_akun_baru(int NIK){
    int left = 0;
    int size = sizeof(dataarray) / sizeof(dataarray[0]);
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (dataarray[mid].NIK == NIK) {
            return true; 
        }

        if (dataarray[mid].NIK < NIK) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return false;
}

int cariNIK(string username){
    for (int i = 0; i < 100; i++)
    {
        if (username == akunarray[i].nama)
        {
            cout<<akunarray[i].NIK<<endl;
            return akunarray[i].NIK;
        }
        else{
            return -1;
        }
        
    }
    
}

int cariTempatSaldo(int NIK){
    int left = 0;
    int size = sizeof(dataarray) / sizeof(dataarray[0]);
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (dataarray[mid].NIK == NIK) {
            return mid; 
        }

        if (dataarray[mid].NIK < NIK) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return -1;
}

void pilihanmember(string username) {
    bool kembalimenu = true; int userNIK = cariNIK(username);
    do {
        system("cls");
        int pilihan, banyakpembayaran;
        cout << "Pilihan anda sebagai member bank CIHUY\n"
             << "1. Lihat saldo\n"
             << "2. Pembayaran\n"
             << "3. Transfer\n"
             << "4. Mutasi saldo\n"
             << "5. Jumlah pinjaman\n"
             << "6. Kembali ke menu utama\n"
             << "7. Lihat Riwayat transaksi\n";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                system("cls");
                cout << "Berikut jumlah saldo anda: ";
                cout << "\nSaldo untuk member " << dataarray[cariTempatSaldo(cariNIK(username))].jumlah_saldo << " adalah ...\n";
                cin.get();
                break;

            case 2:
                cout << "Berapa yang ingin anda bayar: ";
                cin >> banyakpembayaran;

                if (banyakpembayaran > dataarray[cariTempatSaldo(cariNIK(username))].jumlah_saldo) {
                    cout << "\nSaldo anda kurang\nSaldo anda saat ini adalah " << dataarray[cariTempatSaldo(cariNIK(username))].jumlah_saldo;
                    cin.get();
                } else {
                    dataarray[cariTempatSaldo(cariNIK(username))].jumlah_saldo -= banyakpembayaran;
                    cout << "Jumlah saldo sisanya adalah: " << dataarray[cariTempatSaldo(cariNIK(username))].jumlah_saldo << endl;

                    pembayaran[jumlah_bayar].NIK = userNIK;
                    pembayaran[jumlah_bayar].jumlah_pembayaran = banyakpembayaran;
                    jumlah_bayar++;
                    system("pause");
                }
                break;

            case 3:
                cout << "Fitur transfer belum tersedia.\n";
                cin.get();
                break;

            case 4:
                cout << "Fitur mutasi saldo belum tersedia.\n";
                cin.get();
                break;

            case 5:
                system("cls");
                cout << "Berikut jumlah pinjaman anda: ";
                cout << "\nJumlah pinjaman: " << dataarray[cariTempatSaldo(cariNIK(username))].jumlah_pinjaman << " adalah ...\n";
                cin.get();
                break;

            case 6:
                kembalimenu = false;
                break;

            case 7:
                if (userNIK != -1) {
                    cout << "NIK: " << userNIK << endl;
                    cout << "Riwayat Pembayaran:\n";
                    for (int i = 0; i < 100; i++) {
                        if (pembayaran[i].NIK == userNIK) {
                            cout << "Jumlah: " << pembayaran[i].jumlah_pembayaran << endl;
                        }
                    }
                    system("pause");
                } else {
                    cout << "Akun tidak ditemukan.\n";
                    
                }
                cin.get();
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                cin.get();
                break;
        }
    } while (kembalimenu);
}