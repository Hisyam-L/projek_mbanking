#include "function.h"

int main(){
    void sortingrekening();
    bool ulang = true;
    
    do
    {
        int pil ;
        system("cls");
        cout << jml_user << endl;
        cout << "Selamat datang di bank CIHUY";
        cout << "\n1. Daftar";
        cout << "\n2. Login";
        cout << "\n3. Keluar";
        cout << "\n\nPilih menu : ";
        cin >> pil;

        switch (pil)
        {
        case 1 :
        daftar();
        break;
        
        case 2 :
        login();        
        break;


        case 3:
        ulang = false;
            break;
        }


    } while (ulang == true);

    
}
