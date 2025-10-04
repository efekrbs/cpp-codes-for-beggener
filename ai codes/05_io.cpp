// 05_io.cpp
// Amaç: Kullanıcıdan veri almak ve ekrana yazmak

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int main() {
    string isim;
    int yas;

    cout << "Adını gir: ";
    getline(cin, isim); // boşluklu isimler için getline kullanıyoruz

    cout << "Yaşını gir: ";
    cin >> yas; // sayı okuma

    cout << "Merhaba, " << isim << "! " << yas << " yaşındasın." << endl;

    return 0;
}
