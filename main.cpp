#include "function.h"
int jml_user = 0;

int main(){

    bool ulang = true,pilihan= true, loginulang = true;
    int x, y, z;
    
    do
    {
        int pil ;
        system("cls");
        cout << "Selamat datang di bank CIHUY";
        cout << "\n1. Daftar Akun Baru";
        cout << "\n2. Login Akun";
        cout << "\n3. Keluar";
        cout << "\n\nPilih menu : ";
        cin >> pil;
        cin.ignore();

        switch (pil)
        {
        case 1 : do
        {
            int NIK;
            system("cls");
            cout << "Masukkan NIK           : ";
            cin >> NIK;
            
            bool check = check_daftar_akun_baru(NIK);
            
            cin.ignore();
            
            if (check == true)
            {
                    cout << "Masukkan nama          : ";
                    getline(cin, akunarray[jml_user].nama);
                    cout << "Masukkan sandi         : ";
                    getline(cin, akunarray[jml_user].sandi);
                    cout << "Masukkan alamat        : ";
                    getline(cin, akunarray[jml_user].alamat);
                    cout << "Masukkan pekerjaan     : ";
                    getline(cin, akunarray[jml_user].pekerjaan);
                    cout << "Masukkan nomor telepon : ";
                    getline(cin, akunarray[jml_user].no_telp);
                    
                    cin.ignore(); 
                
                    system("cls");
                    cout << "\nNama         : " << akunarray[jml_user].nama ;
                    cout << "\nSandi        : " << akunarray[jml_user].sandi ;
                    cout << "\nAlamat       : " << akunarray[jml_user].alamat ;
                    cout << "\nPekerjaan    : " << akunarray[jml_user].pekerjaan ;
                    cout << "\nNomor Telepon: " << akunarray[jml_user].no_telp;
                    cout << "\nNIK          : " << akunarray[jml_user].NIK <<endl;
                    cin.get();
                    do
                    {
                        cout << "Apakah Data Anda Sudah Benar\n1). Benar\n2). Salah\n"; cin >> x;
                        if(x == 1){
                            jml_user++;
                            pilihan = false;
                        }
                        else if(x == 2){
                            pilihan = true;
                        }
                    } while (x != 1 && x != 2);
            }
            else{
            cout << "Data NIK tidak ada \n";
            int keluar1 = 1;
                do
                {
                    cout << "Apakah anda ingin keluar  tidak (1) / ya (2)\n";cin >> keluar1;
                        if (keluar1 == 1)
                        {
                            pilihan = true;
                            keluar1 = 1;

                        }
                        else if (keluar1 == 2)
                        {
                            keluar1 = 1;
                            pilihan = false;
                        }
                        else{
                            cout << "Pilihan tidak ada\n";
                            cin.get();
                        }
                        
                        
            
                } while (keluar1 == 0);
            
            }
        } while (pilihan == true);
        
            break;
        case 2 :
        do
        {
            system("cls");
            bool akun_ditemukan = false;
            if (jml_user == 0)
            {
                cout << "Anda belum memiliki akun, buat terlebih dahulu";
                cin.get();
                loginulang = false;
                break;

            }
            
            Login userlogin;
            int pilihanlogin;
            system("cls");
            cout << "Masukkan nama          : ";
            getline(cin, userlogin.namaLogin);
            cout << "Masukkan sandi         : ";
            getline(cin, userlogin.sandiLogin);

            system("cls");
            for (int i = 0; i < jml_user; i++)
            {
                if (userlogin.namaLogin == akunarray[i].nama && userlogin.sandiLogin == akunarray[i].sandi)
                {
                    akun_ditemukan = true;
                    cout << "Selamat datang " << akunarray[i].nama << endl;
                    cin.get();

                    pilihanmember(akunarray[i].nama);
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
         
        break;


        case 3:
        ulang = false;
            break;
        }


    } while (ulang == true);

    
}
