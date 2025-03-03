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

void pilihanmember(string username)
{
    system("cls");
    int pilihan;
    string namamembercheck;
    cout << "Pilihan anda sebagai member bank CIHUY\n1. Lihat saldo\n2. Pembayaran\n3. Transfer\n4. Mutasi saldo\n5. Jumlah pinjaman\n6. Kembali ke menu utama\n";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        system("cls");
            cout << "Berikut jumlah saldo anda: ";
            cout << "\nSaldo untuk member " << dataarray[cariTempatSaldo(cariNIK(username))].jumlah_saldo << " adalah ...\n";
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
    system("cls");
            cout << "Berikut jumlah pinjaman anda : ";
            cout << "\nJumlah pinjaman : " << dataarray[cariTempatSaldo(cariNIK(username))].jumlah_pinjaman << " adalah ...\n";
        break;

    case 6:
        cout << "Berikut jumlah saldo anda: ";
        break;
        
    default:
        cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        break;
    }
}

