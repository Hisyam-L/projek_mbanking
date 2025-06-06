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
    int jenisTransaksi;
};

struct user
{
    string nama, email, password;
    int pin, UserId, noRekening;
    double balance;
    mutasi riwayatTransaksi[100]; 
    int mutasi_count = 0;
};

char ulang;
user user1[max];
int pengguna = 0;
int lastUserID = user1[pengguna - 1].UserId;
int lastNoRek = user1[pengguna - 1].noRekening;

double balance[max];

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
void saveTransaksi();
void loadTransaksi();


int main()
{
    loadUsers();
    loadTransaksi();
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

        // anggep kalo ini dari dia bukak rekening di bank terus diarahkan buat bikin mbanking sekalian :)
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
    bool ketemu = false;
    int milih;
    bool bener = false;
    do
    {
        system("cls");
        cout << "+===========================+" << endl;
        cout << "|         MENU UTAMA!       |" << endl;
        cout << "+===========================+" << endl;
        cout << "| 1. Data Rekening          |" << endl;
        cout << "| 2. Transaksi Tanpa Kartu  |" << endl;
        cout << "| 3. Transfer               |" << endl;
        cout << "| 4. Riwayat Transaksi      |" << endl;
        cout << "| 5. Arsip Transaksi        |" << endl;
        cout << "| 6. Keluar                 |" << endl;
        cout << "+===========================+" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan)
        {
        case 1:
            dataUser(UserID);
            ketemu = false;
            break;
            
        case 2:
            do {
                system("cls");
                cout << "+=======================+" << endl;
                cout << "|        Cardless       |" << endl;
                cout << "+=======================+" << endl;
                cout << "|1. Setor Tunai         |" << endl;
                cout << "|2. Tarik Tunai         |" << endl; 
                cout << "+=======================+" << endl;
                cout << "Pilihan Anda (1/2) : ";
                cin >> milih;

                if (milih == 1) {
                    setor(UserID);
                    bener = true;
                } else if (milih == 2) {
                    tarik(UserID);
                    bener = true;
                } else {
                    cout << "Pilihan Anda Tidak Valid";
                    getch();
                    bener = false; 
                }
            } while (bener == false);

            ketemu = false;
            break;

            
        case 3:
            transfer(UserID);
            ketemu = false;
            break;
            
        case 4:
            riwayat(UserID);
            ketemu = false;
            break;
        case 5:
            data_transaksi(UserID);
            break;
        case 6:
            menu();
            ketemu = true;
            break;
        default:
            cout << "Pilihan tidak valid!";
            getch();
            menuUtama(UserID);
        }
    } while (ketemu == false);
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
    saveUsers();
    saveTransaksi();
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
    saveUsers();
    saveTransaksi();
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
        
        
        if (transferPilihan == 1)
        {
            if (rekTujuan == user1[UserID - 1].noRekening)
            {
                cout << "Tidak bisa transfer ke rekening sendiri!" << endl;
                benar = false;
                getch();
            }
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

    if (jumlahTransfer < 10000)
    {
        cout << "Minimum transfer adalah Rp10.000" << endl;
        getch();
        return;
    }

    double totalDikurangi = jumlahTransfer;
    int biayaAdmin = (transferPilihan == 2) ? 5000 : 0;
    totalDikurangi += biayaAdmin;

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

    user1[UserID - 1].balance -= jumlahTransfer; 

    if (transferPilihan == 1 && indexTujuan != -1)
    {
        user1[indexTujuan].balance += jumlahTransfer;

        int idxPenerima = user1[indexTujuan].mutasi_count;
        user1[indexTujuan].riwayatTransaksi[idxPenerima] = {
            (int)jumlahTransfer, 
            user1[UserID - 1].noRekening,
            "Transfer masuk",
            3 
        };
        user1[indexTujuan].mutasi_count++;
    }

    int idxPengirim = user1[UserID - 1].mutasi_count;
    string keteranganTransfer = (transferPilihan == 1) ? "Transfer keluar" : "Transfer ke bank lain";

    user1[UserID - 1].riwayatTransaksi[idxPengirim] = {
        -(int)jumlahTransfer, 
        rekTujuan,
        keteranganTransfer,
        3 
    };
    user1[UserID - 1].mutasi_count++;

    if (biayaAdmin > 0)
    {
        user1[UserID - 1].balance -= biayaAdmin;

        int idxBiayaAdmin = user1[UserID - 1].mutasi_count;
        user1[UserID - 1].riwayatTransaksi[idxBiayaAdmin] = {
            -biayaAdmin,
            0, 
            "Biaya admin transfer",
            4 
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

    saveUsers();
    saveTransaksi();
}

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

                if (nominal >= 0)
                    tandaNominal = "+";
                else
                    tandaNominal = "-";

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

    bool found = false;
    bool passed = false;

    while (getline(riwayat, line))
    {
        if (line.find("User ID           : " + to_string(UserID)) != string::npos)
        {
            found = true;
        }

        if (found && (line.find("Nasabah ke-") != string::npos) &&
            line.find("Nasabah ke-" + to_string(UserID)) == string::npos)
        {
            passed = true;
        }

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

void saveTransaksi() {
    ofstream file("transaksi.txt");

    for (int i = 0; i < pengguna; i++) {
        if (user1[i].mutasi_count == 0) continue;
        file << "UserID:" << user1[i].UserId << endl;

        for (int j = 0; j < user1[i].mutasi_count; j++) {
            file << j + 1 << '|'
                 << user1[i].riwayatTransaksi[j].keterangan << '|'
                 << user1[i].riwayatTransaksi[j].rekTujuan << '|'
                 << user1[i].riwayatTransaksi[j].nominal << endl;
        }
    }

    file.close();
}

void loadTransaksi() {
    ifstream file("transaksi.txt");
    string line;
    int currentUser = -1;

    while (getline(file, line)) {
        if (line.rfind("UserID:", 0) == 0) {
            int id = stoi(line.substr(7));
            for (int i = 0; i < pengguna; i++) {
                if (user1[i].UserId == id) {
                    currentUser = i;
                    user1[i].mutasi_count = 0;
                    break;
                }
            }
        } else if (currentUser != -1) {
            stringstream ss(line);
            string no, ket, rekStr, nomStr;
            getline(ss, no, '|');
            getline(ss, ket, '|');
            getline(ss, rekStr, '|');
            getline(ss, nomStr, '|');

            int idx = user1[currentUser].mutasi_count++;
            user1[currentUser].riwayatTransaksi[idx].keterangan = ket;
            user1[currentUser].riwayatTransaksi[idx].rekTujuan = stoi(rekStr);
            user1[currentUser].riwayatTransaksi[idx].nominal = stoi(nomStr);
            user1[currentUser].riwayatTransaksi[idx].jenisTransaksi =
                ket == "Setor tunai" ? 1 :
                ket == "Tarik tunai" ? 2 :
                ket == "Biaya admin transfer ke bank lain" ? 4 : 3;
        }
    }

    file.close();
}
