#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <fstream>
#define max 200
using namespace std;

struct mutasi
{
    int nominal;
    int rekTujuan;
    string keterangan;
    int jenisTransaksi; // 1 = setor, 2 = tarik, 3 = transfer
};

struct user
{
    string nama, email, password;
    int pin, UserId, noRekening;
    double balance;
    mutasi riwayatTransaksi[100]; // array mutasi untuk setiap user
    int mutasi_count = 0;
};

// int pengguna = 0, lastUserID = 0, lastNoRek = 123240000;
char ulang;
user user1[max] = {
    {"User1", "user1@mail.com", "pass1234", 1234, 123240001, 1, 500000, {}, 0},
    {"User2", "user2@mail.com", "pass1234", 2346, 123240002, 2, 150000, {}, 0},
    {"User3", "user3@mail.com", "pass1234", 3458, 123240003, 3, 300000, {}, 0},
    {"User4", "user4@mail.com", "pass1234", 4567, 123240004, 4, 700000, {}, 0},
    {"User5", "user5@mail.com", "pass1234", 5679, 123240005, 5, 250000, {}, 0},
    {"User6", "user6@mail.com", "pass1234", 6791, 123240006, 6, 450000, {}, 0},
    {"User7", "user7@mail.com", "pass1234", 7890, 123240007, 7, 100000, {}, 0},
    {"User8", "user8@mail.com", "pass1234", 8902, 123240008, 8, 350000, {}, 0},
    {"User9", "user9@mail.com", "pass1234", 9014, 123240009, 9, 600000, {}, 0},
    {"User10", "user10@mail.com", "pass1234", 1122, 123240010, 10, 200000, {}, 0},
    {"User11", "user11@mail.com", "pass1234", 1235, 123240011, 11, 800000, {}, 0},
    {"User12", "user12@mail.com", "pass1234", 2347, 123240012, 12, 300000, {}, 0},
    {"User13", "user13@mail.com", "pass1234", 3456, 123240013, 13, 400000, {}, 0},
    {"User14", "user14@mail.com", "pass1234", 4568, 123240014, 14, 150000, {}, 0},
    {"User15", "user15@mail.com", "pass1234", 5680, 123240015, 15, 500000, {}, 0},
    {"User16", "user16@mail.com", "pass1234", 6789, 123240016, 16, 350000, {}, 0},
    {"User17", "user17@mail.com", "pass1234", 7891, 123240017, 17, 600000, {}, 0},
    {"User18", "user18@mail.com", "pass1234", 8903, 123240018, 18, 250000, {}, 0},
    {"User19", "user19@mail.com", "pass1234", 9012, 123240019, 19, 450000, {}, 0},
    {"User20", "user20@mail.com", "pass1234", 1123, 123240020, 20, 550000, {}, 0},
    {"User21", "user21@mail.com", "pass1234", 1236, 123240021, 21, 100000, {}, 0},
    {"User22", "user22@mail.com", "pass1234", 2345, 123240022, 22, 300000, {}, 0},
    {"User23", "user23@mail.com", "pass1234", 3457, 123240023, 23, 700000, {}, 0},
    {"User24", "user24@mail.com", "pass1234", 4569, 123240024, 24, 400000, {}, 0},
    {"User25", "user25@mail.com", "pass1234", 5678, 123240025, 25, 600000, {}, 0},
    {"User26", "user26@mail.com", "pass1234", 6790, 123240026, 26, 200000, {}, 0},
    {"User27", "user27@mail.com", "pass1234", 7892, 123240027, 27, 450000, {}, 0},
    {"User28", "user28@mail.com", "pass1234", 8901, 123240028, 28, 150000, {}, 0},
    {"User29", "user29@mail.com", "pass1234", 9013, 123240029, 29, 500000, {}, 0},
    {"User30", "user30@mail.com", "pass1234", 1124, 123240030, 30, 350000, {}, 0},
    {"User31", "user31@mail.com", "pass1234", 1234, 123240031, 31, 600000, {}, 0},
    {"User32", "user32@mail.com", "pass1234", 2346, 123240032, 32, 200000, {}, 0},
    {"User33", "user33@mail.com", "pass1234", 3458, 123240033, 33, 550000, {}, 0},
    {"User34", "user34@mail.com", "pass1234", 4567, 123240034, 34, 150000, {}, 0},
    {"User35", "user35@mail.com", "pass1234", 5679, 123240035, 35, 450000, {}, 0},
    {"User36", "user36@mail.com", "pass1234", 6791, 123240036, 36, 300000, {}, 0},
    {"User37", "user37@mail.com", "pass1234", 7890, 123240037, 37, 700000, {}, 0},
    {"User38", "user38@mail.com", "pass1234", 8902, 123240038, 38, 400000, {}, 0},
    {"User39", "user39@mail.com", "pass1234", 9014, 123240039, 39, 250000, {}, 0},
    {"User40", "user40@mail.com", "pass1234", 1122, 123240040, 40, 500000, {}, 0},
    {"User41", "user41@mail.com", "pass1234", 1235, 123240041, 41, 100000, {}, 0},
    {"User42", "user42@mail.com", "pass1234", 2347, 123240042, 42, 300000, {}, 0},
    {"User43", "user43@mail.com", "pass1234", 3456, 123240043, 43, 700000, {}, 0},
    {"User44", "user44@mail.com", "pass1234", 4568, 123240044, 44, 400000, {}, 0},
    {"User45", "user45@mail.com", "pass1234", 5680, 123240045, 45, 600000, {}, 0},
    {"User46", "user46@mail.com", "pass1234", 6789, 123240046, 46, 200000, {}, 0},
    {"User47", "user47@mail.com", "pass1234", 7891, 123240047, 47, 550000, {}, 0},
    {"User48", "user48@mail.com", "pass1234", 8903, 123240048, 48, 250000, {}, 0},
    {"User49", "user49@mail.com", "pass1234", 9012, 123240049, 49, 450000, {}, 0},
    {"User50", "user50@mail.com", "pass1234", 1123, 123240050, 50, 150000, {}, 0},
    {"User51", "user51@mail.com", "pass1234", 1236, 123240051, 51, 500000, {}, 0},
    {"User52", "user52@mail.com", "pass1234", 2345, 123240052, 52, 350000, {}, 0},
    {"User53", "user53@mail.com", "pass1234", 3457, 123240053, 53, 600000, {}, 0},
    {"User54", "user54@mail.com", "pass1234", 4569, 123240054, 54, 200000, {}, 0},
    {"User55", "user55@mail.com", "pass1234", 5678, 123240055, 55, 550000, {}, 0},
    {"User56", "user56@mail.com", "pass1234", 6790, 123240056, 56, 150000, {}, 0},
    {"User57", "user57@mail.com", "pass1234", 7892, 123240057, 57, 450000, {}, 0},
    {"User58", "user58@mail.com", "pass1234", 8901, 123240058, 58, 300000, {}, 0},
    {"User59", "user59@mail.com", "pass1234", 9013, 123240059, 59, 700000, {}, 0},
    {"User60", "user60@mail.com", "pass1234", 1124, 123240060, 60, 400000, {}, 0},
    {"User61", "user61@mail.com", "pass1234", 1234, 123240061, 61, 250000, {}, 0},
    {"User62", "user62@mail.com", "pass1234", 2346, 123240062, 62, 500000, {}, 0},
    {"User63", "user63@mail.com", "pass1234", 3458, 123240063, 63, 100000, {}, 0},
    {"User64", "user64@mail.com", "pass1234", 4567, 123240064, 64, 300000, {}, 0},
    {"User65", "user65@mail.com", "pass1234", 5679, 123240065, 65, 700000, {}, 0},
    {"User66", "user66@mail.com", "pass1234", 6791, 123240066, 66, 400000, {}, 0},
    {"User67", "user67@mail.com", "pass1234", 7890, 123240067, 67, 600000, {}, 0},
    {"User68", "user68@mail.com", "pass1234", 8902, 123240068, 68, 200000, {}, 0},
    {"User69", "user69@mail.com", "pass1234", 9014, 123240069, 69, 550000, {}, 0},
    {"User70", "user70@mail.com", "pass1234", 1122, 123240070, 70, 250000, {}, 0},
    {"User71", "user71@mail.com", "pass1234", 1235, 123240071, 71, 450000, {}, 0},
    {"User72", "user72@mail.com", "pass1234", 2347, 123240072, 72, 150000, {}, 0},
    {"User73", "user73@mail.com", "pass1234", 3456, 123240073, 73, 500000, {}, 0},
    {"User74", "user74@mail.com", "pass1234", 4568, 123240074, 74, 350000, {}, 0},
    {"User75", "user75@mail.com", "pass1234", 5680, 123240075, 75, 600000, {}, 0},
    {"User76", "user76@mail.com", "pass1234", 6789, 123240076, 76, 200000, {}, 0},
    {"User77", "user77@mail.com", "pass1234", 7891, 123240077, 77, 550000, {}, 0},
    {"User78", "user78@mail.com", "pass1234", 8903, 123240078, 78, 150000, {}, 0},
    {"User79", "user79@mail.com", "pass1234", 9012, 123240079, 79, 450000, {}, 0},
    {"User80", "user80@mail.com", "pass1234", 1123, 123240080, 80, 300000, {}, 0},
    {"User81", "user81@mail.com", "pass1234", 1236, 123240081, 81, 700000, {}, 0},
    {"User82", "user82@mail.com", "pass1234", 2345, 123240082, 82, 400000, {}, 0},
    {"User83", "user83@mail.com", "pass1234", 3457, 123240083, 83, 250000, {}, 0},
    {"User84", "user84@mail.com", "pass1234", 4569, 123240084, 84, 500000, {}, 0},
    {"User85", "user85@mail.com", "pass1234", 5678, 123240085, 85, 100000, {}, 0},
    {"User86", "user86@mail.com", "pass1234", 6790, 123240086, 86, 300000, {}, 0},
    {"User87", "user87@mail.com", "pass1234", 7892, 123240087, 87, 700000, {}, 0},
    {"User88", "user88@mail.com", "pass1234", 8901, 123240088, 88, 400000, {}, 0},
    {"User89", "user89@mail.com", "pass1234", 9013, 123240089, 89, 600000, {}, 0},
    {"User90", "user90@mail.com", "pass1234", 1124, 123240090, 90, 200000, {}, 0},
    {"User91", "user91@mail.com", "pass1234", 1234, 123240091, 91, 550000, {}, 0},
    {"User92", "user92@mail.com", "pass1234", 2346, 123240092, 92, 250000, {}, 0},
    {"User93", "user93@mail.com", "pass1234", 3458, 123240093, 93, 450000, {}, 0},
    {"User94", "user94@mail.com", "pass1234", 4567, 123240094, 94, 150000, {}, 0},
    {"User95", "user95@mail.com", "pass1234", 5679, 123240095, 95, 500000, {}, 0},
    {"User96", "user96@mail.com", "pass1234", 6791, 123240096, 96, 350000, {}, 0},
    {"User97", "user97@mail.com", "pass1234", 7890, 123240097, 97, 600000, {}, 0},
    {"User98", "user98@mail.com", "pass1234", 8902, 123240098, 98, 200000, {}, 0},
    {"User99", "user99@mail.com", "pass1234", 9014, 123240099, 99, 550000, {}, 0},
    {"User100", "user100@mail.com", "pass1234", 1122, 123240100, 100, 150000, {}, 0},
};

int pengguna = 100;
int lastUserID = user1[pengguna - 1].UserId;
int lastNoRek = user1[pengguna - 1].noRekening;

double balance[max]; // ganti nama variabel

struct bank
{
    string namaBank;
    int kodeBank;
};

void menu();
void daftar();
void login(int kesempatan);
void inputPin();
void menuUtama(int UserID);
void setor(int UserID);
void tarik(int UserID);
void cariDataUser(int userID);
void dataUser(int UserID);
void transfer(int UserID);
void riwayat(int UserID);
void simpan_transaksi();
void data_transaksi(int UserID);
void loadUsers();
void saveUsers();


int main()
{
    loadUsers();
    menu();
}

void menu()
{
    int pilihan;
    do
    {
        system("cls");
        cout << "+=======================+" << endl;
        cout << "|    Selamat Datang!    | " << endl;
        cout << "+=======================+" << endl;
        cout << "| 1. Daftar             |" << endl;
        cout << "| 2. Login              |" << endl;
        cout << "| 3. Keluar             |" << endl;
        cout << "+=======================+" << endl;
        cout << "Pilih menu nomor : ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan)
        {
        case 1:
            daftar();
            break;
        case 2:
            login(3);
            break;
        case 3:
            cout << "Terima Kasih Telah Menggunakan Program ini";
            exit(0);
            break;
        default:
            cout << "Pilihan tidak valid!";
            getch();
            menu();
        }
    } while (pilihan < 4);
}

void login(int kesempatan)
{
    system("cls");
    if (pengguna > 0)
    {
        string username;
        int pin;

        if (kesempatan == 0)
        {
            cout << "Kesempatan anda habis. Silahkan menghubungi call center!";
            getch();
            exit(0);
        }
        else
        {
            cout << "+=======================+" << endl;
            cout << "|         Login         | " << endl;
            cout << "+=======================+" << endl;
            cout << "Nama   : ";
            getline(cin, username);
            cout << "Pin    : ";
            cin >> pin;
            cin.ignore();
            cout << "+=======================+" << endl;

            bool valid = false;
            for (int i = 0; i < pengguna; i++)
            {
                if (username == user1[i].nama && pin == user1[i].pin)
                {
                    valid = true;
                    cout << "Selamat datang " << user1[i].nama << endl;
                    getch();
                    menuUtama(user1[i].UserId);
                    break;
                }
            }
            if (!valid)
            {
                if (kesempatan != 1)
                {
                    cout << "\nUsername atau Pin tidak ditemukan!!\nKesempatan anda tersisa " << kesempatan - 1 << " kali percobaan!";
                    getch();
                }
                login(kesempatan - 1);
            }
        }
    }
    else
    {
        cout << "!!! Tidak ada pengguna terdaftar. Silakan daftar terlebih dahulu !!!" << endl;
        getch();
        daftar();
    }
}

void daftar()
{
    char pilihan;
    do
    {
        system("cls");
        if (pengguna >= max)
        {
            cout << "Jumlah pengguna maksimum telah tercapai." << endl;
            getch();
            return;
        }

        lastUserID++;
        user1[pengguna].UserId = lastUserID;

        lastNoRek++;
        user1[pengguna].noRekening = lastNoRek;

        cout << "+===========================+" << endl;
        cout << "| Input Data Nasabah ke - " << pengguna + 1 << " | " << endl;
        cout << "+===========================+" << endl;
        cout << "User ID                : " << user1[pengguna].UserId << endl;
        cout << "Nomor Rekening         : " << user1[pengguna].noRekening << endl;
        cout << "Masukkan nama anda     : ";
        getline(cin, user1[pengguna].nama);
        cout << "Masukkan email anda    : ";
        cin >> user1[pengguna].email;
        cin.ignore();
        cout << "Masukkan password anda : ";
        getline(cin, user1[pengguna].password);
        inputPin();

        // Set saldo awal ke 50.000
        user1[pengguna].balance = 50000;
        balance[pengguna] = 50000;

        cout << "============================" << endl;
        pengguna++;
        saveUsers();

        cout << "Apakah anda ingin mendaftar lagi? (y/n): ";
        cin >> pilihan;
        cin.ignore();
    } while (pilihan == 'y' && pengguna < max);
}

void inputPin()
{
    cout << "Masukkan pin anda      : ";
    cin >> user1[pengguna].pin;
    cin.ignore();

    if (user1[pengguna].pin < 1000 || user1[pengguna].pin > 9999)
    {
        cout << "PIN harus 4 digit! Silahkan coba lagi" << endl;
        return inputPin();
    }
}

void menuUtama(int UserID)
{
    int pilihan;
    bool nabil = false;
    do
    {
        system("cls");
        cout << "+=======================+" << endl;
        cout << "|      MENU UTAMA!      |" << endl;
        cout << "+=======================+" << endl;
        cout << "| 1. Setor Tunai        |" << endl;
        cout << "| 2. Tarik Tunai        |" << endl;
        cout << "| 3. Transfer           |" << endl;
        cout << "| 4. Riwayat Transaksi  |" << endl;
        cout << "| 5. Tampilkan Data     |" << endl;
        cout << "| 6. Arsip Transaksi    |" << endl;
        cout << "| 7. Keluar             |" << endl;
        cout << "+=======================+" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan)
        {
        case 1:
            setor(UserID);
            nabil = false;
            break;
        case 2:
            tarik(UserID);
            nabil = false;
            break;
        case 3:
            transfer(UserID);
            nabil = false;
            break;
        case 4:
            riwayat(UserID);
            nabil = false;
            break;
        case 5:
            dataUser(UserID);
            nabil = false;
            break;
        case 6:
            data_transaksi(UserID);
            break;
        case 7:
            menu();
            nabil = true;
            break;
        default:
            cout << "Pilihan tidak valid!";
            getch();
            menuUtama(UserID);
        }
    } while (nabil == false);
}

void setor(int UserID)
{
    int jumlah;
    cout << "Rekening Tujuan : " << user1[UserID - 1].noRekening << endl;
    cout << "Masukan jumlah setor tunai : Rp.";
    cin >> jumlah;
    if (jumlah > 0)
    {
        balance[UserID - 1] += jumlah;
        user1[UserID - 1].balance = balance[UserID - 1];

        // Simpan riwayat transaksi
        int index = user1[UserID - 1].mutasi_count;
        user1[UserID - 1].riwayatTransaksi[index].jenisTransaksi = 1; // 1 untuk setor
        user1[UserID - 1].riwayatTransaksi[index].nominal = jumlah;
        user1[UserID - 1].riwayatTransaksi[index].rekTujuan = user1[UserID - 1].noRekening;
        user1[UserID - 1].riwayatTransaksi[index].keterangan = "Setor tunai";
        user1[UserID - 1].mutasi_count++;

        cout << "Setor tunai berhasil. " << endl
             << endl;
    }
    else
    {
        cout << "Jumlah setor harus lebih dari 0. Silahkan coba lagi." << endl
             << endl;
        setor(UserID);
    }
    getch();
    simpan_transaksi();
}

void tarik(int UserID)
{
    int jumlah;
    user *u = &user1[UserID - 1];     // Pointer ke user
    double *b = &balance[UserID - 1]; // Pointer ke balance

    cout << "Masukan jumlah tarik tunai : Rp";
    cin >> jumlah;

    if (jumlah <= u->balance)
    {
        *b -= jumlah;
        u->balance = *b;

        // Simpan riwayat transaksi
        int index = u->mutasi_count;
        u->riwayatTransaksi[index].jenisTransaksi = 2; // 2 untuk tarik
        u->riwayatTransaksi[index].nominal = jumlah;
        u->riwayatTransaksi[index].rekTujuan = u->noRekening;
        u->riwayatTransaksi[index].keterangan = "Tarik tunai";
        u->mutasi_count++;

        cout << "Tarik tunai berhasil. " << endl
             << endl;
    }
    else
    {
        cout << "Saldo tidak mencukupi. " << endl
             << endl;
        getch();
        menuUtama(UserID);
    }

    getch();
    simpan_transaksi();
}

void cariDataUser(int userID)
{
    bool found = false;
    int awal, tengah, akhir;

    awal = 0;
    akhir = pengguna - 1;

    while ((!found) && (awal <= akhir))
    {
        tengah = (awal + akhir) / 2;
        if (userID == user1[tengah].UserId)
        {
            found = true;
        }
        else
        {
            if (userID < user1[tengah].UserId)
            {
                akhir = tengah - 1;
            }
            else
            {
                awal = tengah + 1;
            }
        }
    }

    if (found)
    {
        cout << "Nomor Rekening     : " << user1[tengah].noRekening << endl;
        cout << "Nama               : " << user1[tengah].nama << endl;
        cout << "Email              : " << user1[tengah].email << endl;
        cout << "Password           : " << user1[tengah].password << endl;
        cout << "Pin                : " << user1[tengah].pin << endl;
        cout << fixed << setprecision(2) << "Saldo              : Rp. " << user1[tengah].balance << endl;
        cout << "Jumlah Transaksi   : " << user1[tengah].mutasi_count << endl;
    }
    else
    {
        cout << "Data user tidak ditemukan!";
    }
}

void dataUser(int UserID)
{
    system("cls");
    if (pengguna > 0)
    {
        cout << "+=======================+" << endl;
        cout << "|       Data User       | " << endl;
        cout << "+=======================+" << endl;
        cariDataUser(UserID);
        getch();
        menuUtama(UserID);
    }
    else
    {
        cout << "!!! Tidak ada pengguna terdaftar. Silakan daftar terlebih dahulu !!!" << endl;
        getch();
        daftar();
    }
}

void transfer(int UserID)
{
    bool benar
     = true;
    system("cls");
    int transferPilihan, rekTujuan, indexTujuan = -1;
    double jumlahTransfer;

    cout << "+===========================+" << endl;
    cout << "|         TRANSFER          |" << endl;
    cout << "+===========================+" << endl;
    cout << "Pilih jenis transfer:\n";
    cout << "1. Transfer ke bank yang sama\n";
    cout << "2. Transfer ke bank lain\n";
    cout << "Pilihan : ";
    cin >> transferPilihan;

    // Validasi pilihan transfer
    if (transferPilihan != 1 && transferPilihan != 2)
    {
        cout << "Pilihan tidak valid!" << endl;
        getch();
        return;
    }

    do
    {
        cout << "Masukkan nomor rekening tujuan: ";
        cin >> rekTujuan;
        
        // Cek transfer ke rekening sendiri
        
        // Cari rekening tujuan hanya jika transfer ke bank yang sama
        if (transferPilihan == 1)
        {
            if (rekTujuan == user1[UserID - 1].noRekening)
            {
                cout << "Tidak bisa transfer ke rekening sendiri!" << endl;
                benar = false;
                getch();
                // return;
            }
            // Jika transfer ke bank yang sama, validasi rekening tujuan
            for (int i = 0; i < pengguna; i++)
            {
                if (user1[i].noRekening == rekTujuan)
                {
                    indexTujuan = i;
                    break;
                }
            }
            
            if (indexTujuan == -1)
            {
                cout << "Rekening tujuan tidak ditemukan." << endl;
                getch();
                return;
            }
        }
    } while (benar == false);

    cout << "Masukkan jumlah transfer: Rp.";
    cin >> jumlahTransfer;

    // Validasi jumlah transfer
    if (jumlahTransfer < 10000)
    {
        cout << "Minimum transfer adalah Rp10.000" << endl;
        getch();
        return;
    }

    // Hitung total yang akan dikurangi (termasuk biaya admin jika transfer antar bank)
    double totalDikurangi = jumlahTransfer;
    int biayaAdmin = (transferPilihan == 2) ? 5000 : 0;
    totalDikurangi += biayaAdmin;

    // Cek saldo mencukupi
    if (totalDikurangi > user1[UserID - 1].balance)
    {
        cout << "Saldo tidak mencukupi." << endl;
        if (biayaAdmin > 0)
        {
            cout << "Dibutuhkan: Rp" << jumlahTransfer << " + biaya admin Rp" << biayaAdmin
                 << " = Rp" << totalDikurangi << endl;
        }
        getch();
        return;
    }

    // Lakukan transfer
    user1[UserID - 1].balance -= jumlahTransfer; // Kurangi saldo pengirim

    // Tambah saldo penerima hanya jika transfer ke bank yang sama dan rekening tujuan valid
    if (transferPilihan == 1 && indexTujuan != -1)
    {
        user1[indexTujuan].balance += jumlahTransfer;

        // Catat riwayat transaksi untuk PENERIMA
        int idxPenerima = user1[indexTujuan].mutasi_count;
        user1[indexTujuan].riwayatTransaksi[idxPenerima] = {
            (int)jumlahTransfer, // nominal positif (pemasukan)
            user1[UserID - 1].noRekening,
            "Transfer masuk",
            3 // jenis: transfer
        };
        user1[indexTujuan].mutasi_count++;
    }

    // Catat riwayat transaksi untuk PENGIRIM
    int idxPengirim = user1[UserID - 1].mutasi_count;
    string keteranganTransfer = (transferPilihan == 1) ? "Transfer keluar" : "Transfer ke bank lain";

    user1[UserID - 1].riwayatTransaksi[idxPengirim] = {
        -(int)jumlahTransfer, // nominal negatif (pengeluaran)
        rekTujuan,
        keteranganTransfer,
        3 // jenis: transfer
    };
    user1[UserID - 1].mutasi_count++;

    // Jika ada biaya admin, catat sebagai transaksi terpisah
    if (biayaAdmin > 0)
    {
        user1[UserID - 1].balance -= biayaAdmin;

        int idxBiayaAdmin = user1[UserID - 1].mutasi_count;
        user1[UserID - 1].riwayatTransaksi[idxBiayaAdmin] = {
            -biayaAdmin,
            0, // tidak ada rekening tujuan
            "Biaya admin transfer",
            4 // JENIS BARU: admin fee
        };
        user1[UserID - 1].mutasi_count++;

        cout << "Biaya admin Rp" << biayaAdmin << " telah dipotong." << endl;
    }

    cout << "Transfer berhasil!" << endl;
    if (transferPilihan == 2)
    {
        cout << "Transfer ke bank lain ke rekening " << rekTujuan << " sebesar Rp" << jumlahTransfer << endl;
    }
    cout << "Sisa saldo Anda: Rp" << user1[UserID - 1].balance << endl;

    simpan_transaksi();
    getch();
}

// Fungsi sorting untuk riwayat transaksi
void sortTransaksi(mutasi arr[], int n, bool ascending)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            bool swap;
            if (ascending)
                swap = abs(arr[j].nominal) > abs(arr[j + 1].nominal);
            else
                swap = abs(arr[j].nominal) < abs(arr[j + 1].nominal);

            if (swap)
            {
                mutasi temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void riwayat(int UserID)
{
    int pilihan;
    bool ulang = true;

    int userIndex = UserID - 1;
    int count = user1[userIndex].mutasi_count;
    mutasi tempRiwayat[100];

    // Salin riwayat
    for (int i = 0; i < count; i++)
    {
        tempRiwayat[i] = user1[userIndex].riwayatTransaksi[i];
    }

    do
    {
        system("cls");
        if (count == 0)
        {
            cout << "Tidak ada riwayat transaksi." << endl;
        }

        if (count != 0)
        {
            cout << "+===========================+" << endl;
            cout << "|       Riwayat Transaksi   |" << endl;
            cout << "+===========================+" << endl;
            cout << "Urutkan menurut?" << endl;
            cout << "[1] Terbesar" << endl;
            cout << "[2] Terkecil" << endl;
            cout << "Pilihan Anda : ";
            cin >> pilihan;
            system("cls");

            cout << "+===========================+" << endl;
            cout << "|       Riwayat Transaksi   |" << endl;
            cout << "+===========================+" << endl;
            sortTransaksi(tempRiwayat, count, pilihan == 2);

            for (int i = 0; i < count; i++)
            {
                string jenis = "";
                string tandaNominal = "";
                int nominal = tempRiwayat[i].nominal;

                // Penentuan jenis
                if (tempRiwayat[i].jenisTransaksi == 1) // Setor
                {
                    jenis = "Setor tunai";
                }
                else if (tempRiwayat[i].jenisTransaksi == 2) // Tarik
                {
                    jenis = "Tarik tunai";
                }
                else if (tempRiwayat[i].jenisTransaksi == 3) // Transfer
                {
                    jenis = tempRiwayat[i].keterangan;
                }
                else if (tempRiwayat[i].jenisTransaksi == 4) // Biaya admin
                {
                    jenis = "Biaya admin transfer ke bank lain";
                }

                // Tentukan tanda berdasarkan nilai nominal (positif atau negatif)
                if (nominal >= 0)
                    tandaNominal = "+";
                else
                    tandaNominal = "-";

                // Tampilkan informasi rekening untuk transfer (jika sesuai)
                cout << (i + 1) << ". " << jenis;

                if (tempRiwayat[i].rekTujuan != 0 && tempRiwayat[i].jenisTransaksi == 3)
                {
                    if (jenis == "Transfer keluar")
                        cout << " ke " << tempRiwayat[i].rekTujuan;
                    else
                        cout << " dari " << tempRiwayat[i].rekTujuan;
                }

                if (tempRiwayat[i].jenisTransaksi == 1 && tempRiwayat[i].rekTujuan != 0 &&
                    tempRiwayat[i].rekTujuan != user1[userIndex].noRekening)
                {
                    // Tampilkan info rekening setor jika bukan setor ke sendiri
                    cout << " ";
                    if (tempRiwayat[i].nominal < 0)
                        cout << "ke " << tempRiwayat[i].rekTujuan;
                    else
                        cout << "dari " << tempRiwayat[i].rekTujuan;
                }

                cout << ": " << tandaNominal << "Rp. " << abs(nominal) << endl;
            }
        }

        cout << "+===========================+" << endl;
        ulang = false;
        getch();

    } while (ulang);
}

void simpan_transaksi()
{
    ofstream transaksi;
    transaksi.open("data.txt", ios::out);
    for (int i = 0; i < pengguna; i++)
    {
        transaksi << "Nasabah ke-" << i + 1 << endl;
        transaksi << "User ID           : " << user1[i].UserId << endl;
        transaksi << "Nama Nasabah      : " << user1[i].nama << endl;
        transaksi << "Rekening Nasabah  : " << user1[i].noRekening << endl;
        transaksi << "Saldo             : Rp. " << fixed << setprecision(2) << user1[i].balance << endl;
        transaksi << "Jumlah Transaksi  : " << user1[i].mutasi_count << endl;
        if (user1[i].mutasi_count > 0)
        {
            transaksi << "Riwayat Transaksi :" << endl;
            for (int j = 0; j < user1[i].mutasi_count; j++)
            {
                string jenis;
                string tandaNominal;

                if (user1[i].riwayatTransaksi[j].jenisTransaksi == 1) // Setor
                {
                    jenis = "Setor tunai";
                }
                else if (user1[i].riwayatTransaksi[j].jenisTransaksi == 2) // Tarik
                {
                    jenis = "Tarik tunai";
                }
                else if (user1[i].riwayatTransaksi[j].jenisTransaksi == 3) // Transfer
                {
                    jenis = user1[i].riwayatTransaksi[j].keterangan;
                }
                else if (user1[i].riwayatTransaksi[j].jenisTransaksi == 4) // Biaya admin
                {
                    jenis = "Biaya admin transfer ke bank lain";
                }

                if (user1[i].riwayatTransaksi[j].nominal >= 0)
                    tandaNominal = "+";
                else
                    tandaNominal = "-";

                transaksi << "  " << j + 1 << ". " << jenis << " " << tandaNominal << "Rp" << abs(user1[i].riwayatTransaksi[j].nominal) << endl;
            }
        }
        transaksi << "----------------------------------" << endl
                  << endl;
    }
    transaksi.close();
}

// Perbaikan fungsi data_transaksi() untuk menampilkan hanya data nasabah yang login
void data_transaksi(int UserID)
{
    ifstream riwayat;
    string line;
    system("cls");
    riwayat.open("data.txt");
    cout << "=================================================" << endl;
    cout << "                 RIWAYAT TRANSAKSI               " << endl;
    cout << "=================================================" << endl
         << endl;

    // Variabel untuk menandai apakah sudah menemukan data user yang login
    bool found = false;
    // Variabel untuk menandai apakah sudah melewati data user yang login
    bool passed = false;

    while (getline(riwayat, line))
    {
        // Cek apakah line berisi User ID yang sedang login
        if (line.find("User ID           : " + to_string(UserID)) != string::npos)
        {
            found = true;
        }

        // Cek apakah sudah melewati data user yang login
        // (ketika menemukan header nasabah berikutnya atau akhir file)
        if (found && (line.find("Nasabah ke-") != string::npos) &&
            line.find("Nasabah ke-" + to_string(UserID)) == string::npos)
        {
            passed = true;
        }

        // Tampilkan hanya data user yang login
        if (found && !passed)
        {
            cout << line << endl;
        }
    }

    riwayat.close();
    cout << "\nTekan apa saja untuk melanjutkan...";
    getch();
}

void loadUsers() {
    ifstream file("users.txt");
    string line;
    pengguna = 0;

    while (getline(file, line) && pengguna < max) {
        stringstream ss(line);
        string token;
        getline(ss, user1[pengguna].nama, '|');
        getline(ss, user1[pengguna].email, '|');
        getline(ss, user1[pengguna].password, '|');

        getline(ss, token, '|');
        user1[pengguna].pin = stoi(token);
        getline(ss, token, '|');
        user1[pengguna].UserId = stoi(token);
        getline(ss, token, '|');
        user1[pengguna].noRekening = stoi(token);
        getline(ss, token, '|');
        user1[pengguna].balance = stod(token);

        user1[pengguna].mutasi_count = 0;
        pengguna++;
    }

    if (pengguna > 0) {
        lastUserID = user1[pengguna - 1].UserId;
        lastNoRek = user1[pengguna - 1].noRekening;
    }

    file.close();
}

void saveUsers() {
    ofstream file("users.txt");

    for (int i = 0; i < pengguna; i++) {
        file << user1[i].nama << '|'
             << user1[i].email << '|'
             << user1[i].password << '|'
             << user1[i].pin << '|'
             << user1[i].UserId << '|'
             << user1[i].noRekening << '|'
             << user1[i].balance << endl;
    }

    file.close();
}
