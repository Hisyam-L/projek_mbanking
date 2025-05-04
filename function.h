#include "data.cpp"

void sortPembayaran(riwayat_pembayaran pembayaran[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (pembayaran[j].jumlah_pembayaran < pembayaran[j + 1].jumlah_pembayaran) {
                swap(pembayaran[j], pembayaran[j+1]);
            }
        }
    }
}

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



int cariNIK(string username) {
    for (int i = 0; i < 100; i++) {
        if (username == akunarray[i].nama) {
            cout << akunarray[i].NIK << endl;
            return akunarray[i].NIK;
        }
    }
    return -1; 
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
    bool kembalimenu = true; 
    int userNIK = cariNIK(username);
    int letak_akun = cariTempatSaldo(userNIK);

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
             << "7. Lihat Riwayat transaksi\n"
             << "Masukan pilihan anda : ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                system("cls");
                cout << "Berikut jumlah saldo anda: ";
                cout << "\nSaldo dengan nama " << username << " adalah :" << dataarray[letak_akun].jumlah_saldo;
                cout << "\nTekan Enter untuk melanjutkan...\n";
                cin.ignore();
                cin.get();
                break;

            case 2:
                cout << "Berapa yang ingin anda bayar: ";
                cin >> banyakpembayaran;

                if (banyakpembayaran > dataarray[letak_akun].jumlah_saldo) {
                    cout << "\nSaldo anda kurang\nSaldo anda saat ini adalah " << dataarray[letak_akun].jumlah_saldo;
                    cin.ignore();
                    cin.get();
                } else {
                    dataarray[cariTempatSaldo(cariNIK(username))].jumlah_saldo -= banyakpembayaran;
                    cout << "Jumlah saldo sisanya adalah: " << dataarray[letak_akun].jumlah_saldo << endl;

                    pembayaran[jumlah_bayar].NIK = userNIK;
                    pembayaran[jumlah_bayar].jumlah_pembayaran = banyakpembayaran;
                    jumlah_bayar++;
                    cout << "\nTekan Enter untuk melanjutkan...\n";
                    cin.ignore();
                    cin.get();
                }
                break;

            case 3:
                cout << "Fitur transfer belum tersedia.\n";
                cout << "\nTekan Enter untuk melanjutkan...\n";
                cin.ignore();
                cin.get();
                break;

            case 4:
                cout << "Fitur mutasi saldo belum tersedia.\n";
                cout << "\nTekan Enter untuk melanjutkan...\n";
                cin.ignore();
                cin.get();
                break;

            case 5:
                system("cls");
                cout << "NIK                          : " << userNIK << endl;
                cout << "Berikut jumlah pinjaman anda : "<< dataarray[letak_akun].jumlah_pinjaman ;
                cout << "\nTekan Enter untuk melanjutkan...\n";
                cin.ignore();
                cin.get();
                break;

            case 6:
                kembalimenu = false;
                break;

            case 7:
                system("cls");
                sortPembayaran(pembayaran,100);
                if (userNIK != -1) {
                    cout << "NIK               : " << userNIK << endl;
                    cout << "Riwayat Pembayaran:\n";
                    for (int i = 0; i < 100; i++) {
                        if (pembayaran[i].NIK == userNIK) {
                            cout << "Jumlah: " << pembayaran[i].jumlah_pembayaran << endl;
                        }
                    }


                } else {
                    cout << "Akun tidak ditemukan.\n";
                    
                }
                cout << "\nTekan Enter untuk melanjutkan...\n";
                cin.ignore();
                cin.get();

                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                cout << "\nTekan Enter untuk melanjutkan...\n";
                cin.ignore();
                cin.get();
                break;
        }
    } while (kembalimenu);
}