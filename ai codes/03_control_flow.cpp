// 03_control_flow.cpp
// Amaç: if-else, for ve while döngüsü örnekleri

#include <iostream>

using std::cout;
using std::endl;

int main() {
    int sayi = 7;

    // if-else örneği
    if (sayi % 2 == 0) {
        cout << sayi << " çifttir\n";
    } else {
        cout << sayi << " tektir\n";
    }

    // for döngüsü: 0'dan 4'e kadar sayıları yazdır
    for (int i = 0; i < 5; ++i) {
        cout << "for i = " << i << endl;
    }

    // while döngüsü: sayaç azalıyor
    int count = 3;
    while (count > 0) {
        cout << "kalan: " << count << endl;
        --count;
    }

    return 0;
}
