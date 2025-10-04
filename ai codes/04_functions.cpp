// 04_functions.cpp
// Amaç: Fonksiyon tanımlama ve çağırma

#include <iostream>

using std::cout;
using std::endl;

// Fonksiyon bildirimi: iki tam sayı alır ve toplamını döndürür
int topla(int a, int b) {
    return a + b;
}

int main() {
    int x = 5;
    int y = 7;

    int sonuc = topla(x, y); // fonksiyon çağrısı
    cout << x << " + " << y << " = " << sonuc << endl;

    return 0;
}
