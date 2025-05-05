#include "data.cpp"

void sortingrekening() { //pakai shell sort hehehe
    int n = 200; // 200 ni ukuran tampungan buat array rekening ygy
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Data temp = rekening[i];
            int j;
            for (j = i; j >= gap && rekening[j - gap].NIK > temp.NIK; j -= gap) {
                rekening[j] = rekening[j - gap];
            }
            rekening[j] = temp;
        }
    }
}


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
    int size = sizeof(rekening) / sizeof(rekening[0]);
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (rekening[mid].NIK == NIK) {
            return true; 
        }

        if (rekening[mid].NIK < NIK) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return false;
}



int cariNIK(string username) {
    for (int i = 0; i < 100; i++) {
        if (username == akun[i].nama) {
            cout << akun[i].NIK << endl;
            return akun[i].NIK;
        }
    }
    return -1; 
}

int cariTempatSaldo(int NIK){
    int left = 0;
    int size = sizeof(rekening) / sizeof(rekening[0]);
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (rekening[mid].NIK == NIK) {
            return mid; 
        }

        if (rekening[mid].NIK < NIK) {
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
            cout << "\nSaldo dengan nama " << username << " adalah :" << rekening[letak_akun].jumlah_saldo;
            cout << "\nTekan Enter untuk melanjutkan...\n";
            cin.ignore();
            cin.get();
            break;

            case 2:
            cout << "Berapa yang ingin anda bayar: ";
            cin >> banyakpembayaran;
            
            if (banyakpembayaran > rekening[letak_akun].jumlah_saldo) {
                    cout << "\nSaldo anda kurang\nSaldo anda saat ini adalah " << rekening[letak_akun].jumlah_saldo;
                    cin.ignore();
                    cin.get();
                } else {
                    rekening[cariTempatSaldo(cariNIK(username))].jumlah_saldo -= banyakpembayaran;
                    cout << "Jumlah saldo sisanya adalah: " << rekening[letak_akun].jumlah_saldo << endl;
                    
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
                cout << "Berikut jumlah pinjaman anda : "<< rekening[letak_akun].jumlah_pinjaman ;
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
   
    int jml_user = 0;

    void login(){
        bool loginulang = true;
            do
            {
                system("cls");
                bool akun_ditemukan = false;
                if (jml_user == 0)
                {
                    cout << "Anda belum memiliki akun, silahkan buat terlebih dahulu";
                    getch();
                    loginulang = false;
                    break;
        
                }
                
                Login userlogin;
                int pilihanlogin;
                system("cls");
        
                cin.ignore();
                
                cout << "Masukkan nama          : ";
                getline(cin, userlogin.namaLogin);
                cout << "Masukkan sandi         : ";
                getline(cin, userlogin.sandiLogin);
        
                system("cls");
                for (int i = 0; i < jml_user; i++)
                {
                    if (userlogin.namaLogin == akun[i].nama && userlogin.sandiLogin == akun[i].sandi)
                    {
                        akun_ditemukan = true;
                        cout << "Selamat datang " << akun[i].nama << endl;
                        cin.get();
                        
                        pilihanmember(akun[i].nama);
                        loginulang = false;
                        
        
                    }
                    
                }
                if (akun_ditemukan == false)
                {
                    system("cls");
                        cout <<"Sandi atau nama akun anda salah";
                        cout<<"\nApakah ingin mengulangi lagi ?\n1. Iya\n2. Tidak\nMasukan pilihan anda : ";
                        cin>>pilihanlogin;
                        cin.ignore();
                        if (pilihanlogin == 1)
                        {
                            loginulang = true;
                        }
                        else if (pilihanlogin == 2)
                        {
                            loginulang = false;
                        }
                        else{
                            cout<<"Pilihan tidak ada";
                        }
                        
                }
                
                
            } while (loginulang == true );
                
        }

void daftar(){
        bool pilihan= true;
        int x, y, z;

        do
    {
        int NIK;
        Akun dummyakun;
        system("cls");
        cout << "Masukkan NIK           : ";
        cin >> dummyakun.NIK;
        cin.ignore();
        
        bool check = check_daftar_akun_baru(dummyakun.NIK);
        
        
        if (check == false)
        {
            cout << "Data Rekening Belum Terdaftar\nsilahkan buat akun\n";
            
            cout << "Masukkan nama          : ";
            getline(cin, dummyakun.nama);
            cout << "Masukkan sandi         : ";
            getline(cin, dummyakun.sandi);
            cout << "Masukkan alamat        : ";
            getline(cin, dummyakun.alamat);
            cout << "Masukkan pekerjaan     : ";
            getline(cin, dummyakun.pekerjaan);
            cout << "Masukkan nomor telepon : ";
            getline(cin, dummyakun.no_telp);
            
            cin.ignore(); 
        
            system("cls");
            cout << "\nNama         : " << dummyakun.nama ;
            cout << "\nSandi        : " << dummyakun.sandi ;
            cout << "\nAlamat       : " << dummyakun.alamat ;
            cout << "\nPekerjaan    : " << dummyakun.pekerjaan ;
            cout << "\nNomor Telepon: " << dummyakun.no_telp;
            cout << "\nNIK          : " << dummyakun.NIK <<endl;
            cin.get();
            do
            {
                cout << "Apakah Data Anda Sudah Benar\n1). Benar\n2). Salah\n"; cin >> x;
                if(x == 1){
                    akun[jml_user] = dummyakun;
                    rekening[99+jml_user].NIK = dummyakun.NIK;
                    rekening[99+jml_user].jumlah_saldo = 50000;
                    rekening[99+jml_user].jumlah_pinjaman = 0;
                    jml_user++;
                    cout << "Pendaftaran Berhasil, Saldo Akun Baru Rp 50.000,00 Telah Ditambahkan";
                    getch();
                    pilihan = false;
                }
                else if(x == 2){
                    pilihan = true;
                }
            } while (x != 1 && x != 2);
        
        }
        else {
            cout << "Data Rekening Sudah Terdaftar\nsilahkan buat akun\n";
            cout << "Masukkan nama          : ";
                getline(cin, dummyakun.nama);
                cout << "Masukkan sandi         : ";
                getline(cin, dummyakun.sandi);
                cout << "Masukkan alamat        : ";
                getline(cin, dummyakun.alamat);
                cout << "Masukkan pekerjaan     : ";
                getline(cin, dummyakun.pekerjaan);
                cout << "Masukkan nomor telepon : ";
                getline(cin, dummyakun.no_telp);
                
                cin.ignore(); 
            
                system("cls");
                cout << "\nNama         : " << dummyakun.nama ;
                cout << "\nSandi        : " << dummyakun.sandi ;
                cout << "\nAlamat       : " << dummyakun.alamat ;
                cout << "\nPekerjaan    : " << dummyakun.pekerjaan ;
                cout << "\nNomor Telepon: " << dummyakun.no_telp;
                cout << "\nNIK          : " << dummyakun.NIK <<endl;
                cin.get();
                do
                {
                    cout << "Apakah Data Anda Sudah Benar\n1). Benar\n2). Salah\n"; cin >> x;
                    if(x == 1){
                        akun[jml_user] = dummyakun;
                        jml_user++;
                        pilihan = false;
                    }
                    else if(x == 2){
                        pilihan = true;
                    }
                } while (x != 1 && x != 2);
            }
        } while (pilihan == true);
    }
        

    