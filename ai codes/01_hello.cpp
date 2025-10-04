// 01_hello.cpp
// Amaç: C++'ta en basit program — "Merhaba Dünya"
// Açıklama: Bu örnek, bir C++ programının temel yapısını ve nasıl derlenip çalıştırılacağını gösterir.

#include <iostream> // std::cout, std::endl tanımlarını içerir

// Kısaltma: Her seferinde "std::" yazmamak için sık kullanılan isimleri getiriyoruz.
using std::cout;
using std::endl;

// Her C++ programı main fonksiyonuyla başlar.
int main() {
    // cout: konsola yazdırmak için kullanılır. << operatörü ile string ve değişkenler eklenir.
    cout << "Merhaba Dünya!" << endl; // endl yeni satır ekler ve çıktıyı temizler

    // Program başarılı şekilde tamamlandığında 0 döndürür.
    return 0;
}
