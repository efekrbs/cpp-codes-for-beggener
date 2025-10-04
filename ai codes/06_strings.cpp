// 06_strings.cpp
// Amaç: C++'ta string (metin) kullanımı ve temel işlemler
// Açıklama: string tanımlama, birleştirme, uzunluk bulma ve karakterlere erişim örnekleri

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
    // String tanımlama
    string ad = "Ahmet";
    string soyad = "Yılmaz";

    // String birleştirme (concatenation)
    string tamIsim = ad + " " + soyad;
    cout << "Tam isim: " << tamIsim << endl;

    // Uzunluk bulma
    cout << "İsmin uzunluğu: " << tamIsim.length() << endl;

    // Karakterlere erişim
    cout << "İlk harf: " << tamIsim[0] << endl;
    cout << "Son harf: " << tamIsim[tamIsim.length() - 1] << endl;

    // String üzerinde döngü
    cout << "Harfler: ";
    for (char c : tamIsim) {
        cout << c << ' ';
    }
    cout << endl;

    return 0;
}
