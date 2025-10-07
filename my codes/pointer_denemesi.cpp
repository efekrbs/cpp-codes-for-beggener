#include <iostream>

using namespace std;

int main(){

    int sayi = 54;
    cout << "sayi değişkeninin değeri: " << sayi << endl;
    cout << "sayi değişkeninin adresi: " << &sayi << endl;
    cout << endl;

    // Güvenli pointer kullanımı:
    int* ptr = &sayi ;  // sayi'nin adresini ptr'ye ata
    cout << "ptr'nin işaret ettiği değer: " << *ptr << endl;
    
    // Belirli bir adresi okuma (TEHLİKELİ!):
    int* specificPtr = (int*)0x00ff00;  // Type casting ile adres atama
    cout << "0x61ff08 adresindeki değer: " << *specificPtr << endl;


    return 0;
}

