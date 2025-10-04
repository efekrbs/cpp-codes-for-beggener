// 07_pointers.cpp
// Amaç: C++'ta pointer (işaretçi) kavramını detaylı örneklerle öğrenmek
// Açıklama: Pointer nedir, nasıl tanımlanır, nasıl kullanılır, örnek senaryolar

#include <iostream>

using std::cout;
using std::endl;

int main() {
    cout << "=== POINTER'LARA GİRİŞ ===" << endl;
    
    // 1. Basit değişken ve adresi
    int sayi = 42;
    cout << "sayi değişkeninin değeri: " << sayi << endl;
    cout << "sayi değişkeninin adresi: " << &sayi << endl;
    cout << endl;

    // 2. Pointer tanımlama ve ilk atama
    int* ptr = &sayi; // ptr, sayi değişkeninin adresini tutuyor
    cout << "=== POINTER TANIMLAMA ===" << endl;
    cout << "ptr'nin tuttuğu adres: " << ptr << endl;
    cout << "ptr'nin işaret ettiği değer: " << *ptr << endl; // * operatörü ile değeri alıyoruz
    cout << "ptr'nin kendi adresi: " << &ptr << endl;
    cout << endl;

    // 3. Pointer ile değişken değerini değiştirme
    cout << "=== POINTER İLE DEĞİŞİM ===" << endl;
    cout << "Önce sayi: " << sayi << endl;
    *ptr = 100; // pointer üzerinden sayi değişkeninin değerini değiştiriyoruz
    cout << "Sonra sayi: " << sayi << endl;
    cout << "ptr ile erişilen değer: " << *ptr << endl;
    cout << endl;

    // 4. Farklı veri tipleri ile pointerlar
    cout << "=== FARKLI TİPLERDE POINTERLAR ===" << endl;
    double ondalik = 3.14;
    double* doublePtr = &ondalik;
    
    char harf = 'A';
    char* charPtr = &harf;
    
    cout << "double değer: " << *doublePtr << ", adresi: " << doublePtr << endl;
    cout << "char değer: " << *charPtr << ", adresi: " << (void*)charPtr << endl;
    cout << endl;

    // 5. Array (dizi) ve pointerlar
    cout << "=== DİZİLER VE POINTERLAR ===" << endl;
    int dizi[5] = {10, 20, 30, 40, 50};
    int* diziPtr = dizi; // Dizi adı aslında ilk elemanın adresi
    
    cout << "Dizi elemanları (normal erişim):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "dizi[" << i << "] = " << dizi[i] << endl;
    }
    
    cout << "\nDizi elemanları (pointer erişimi):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "*(diziPtr + " << i << ") = " << *(diziPtr + i) << endl;
    }
    cout << endl;

    // 6. Pointer aritmetiği
    cout << "=== POINTER ARİTMETİĞİ ===" << endl;
    int* p = dizi;
    cout << "İlk eleman (p): " << *p << endl;
    p++; // Sonraki elemana geç
    cout << "İkinci eleman (p++): " << *p << endl;
    p += 2; // 2 eleman daha ilerle
    cout << "Dördüncü eleman (p+2): " << *p << endl;
    cout << endl;

    // 7. Null pointer kontrolü
    cout << "=== NULL POINTER KONTROLÜ ===" << endl;
    int* nullPtr = nullptr; // Modern C++'ta nullptr kullanılır
    
    if (nullPtr == nullptr) {
        cout << "nullPtr hiçbir şeyi işaret etmiyor (güvenli)" << endl;
    }
    
    // Tehlikeli! Null pointer'ı kullanmaya çalışmayın
    // cout << *nullPtr; // Bu program çökmesine neden olur!
    cout << endl;

    // 8. Pointer to pointer (çift pointer)
    cout << "=== POINTER TO POINTER ===" << endl;
    int deger = 999;
    int* tek_ptr = &deger;
    int** cift_ptr = &tek_ptr; // tek_ptr'nin adresini tutuyor
    
    cout << "deger: " << deger << endl;
    cout << "*tek_ptr: " << *tek_ptr << endl;
    cout << "**cift_ptr: " << **cift_ptr << endl;
    cout << "Hepsi aynı değer!" << endl;
    cout << endl;

    // 9. Fonksiyon parametresi olarak pointer
    cout << "=== FONKSİYON ÖRNEĞİ ===" << endl;
    
    // Lambda fonksiyon (basit örnek)
    auto degerDegistir = [](int* p, int yeniDeger) {
        *p = yeniDeger;
    };
    
    int test = 123;
    cout << "test başlangıç değeri: " << test << endl;
    degerDegistir(&test, 456);
    cout << "test fonksiyon sonrası: " << test << endl;
    cout << endl;

    // 10. Dinamik bellek (heap) - basit örnek
    cout << "=== DİNAMİK BELLEK (HEAP) ===" << endl;
    int* dinamikPtr = new int(777); // Heap'te int oluştur
    cout << "Heap'teki değer: " << *dinamikPtr << endl;
    cout << "Heap adresi: " << dinamikPtr << endl;
    
    delete dinamikPtr; // Belleği serbest bırak (önemli!)
    dinamikPtr = nullptr; // Güvenlik için
    cout << "Bellek serbest bırakıldı." << endl;
    cout << endl;

    // 11. Const pointerlar
    cout << "=== CONST POINTERLAR ===" << endl;
    int x = 100, y = 200;
    
    const int* ptr1 = &x; // Değer değiştirilemez, pointer değiştirilebilir
    // *ptr1 = 300; // HATA! Değer değiştirilemez
    ptr1 = &y; // OK! Pointer değiştirilebilir
    cout << "const int* örneği: " << *ptr1 << endl;
    
    int* const ptr2 = &x; // Pointer değiştirilemez, değer değiştirilebilir
    *ptr2 = 300; // OK! Değer değiştirilebilir
    // ptr2 = &y; // HATA! Pointer değiştirilemez
    cout << "int* const örneği: " << *ptr2 << endl;
    cout << endl;

    cout << "=== POINTER DERSİ BİTTİ ===" << endl;
    cout << "Önemli hatırlatmalar:" << endl;
    cout << "1. * operatörü: pointer'ın işaret ettiği değeri alır" << endl;
    cout << "2. & operatörü: değişkenin adresini alır" << endl;
    cout << "3. nullptr: güvenli null pointer" << endl;
    cout << "4. new/delete: dinamik bellek yönetimi" << endl;
    cout << "5. Pointer aritmetiği: +, -, ++, -- kullanılabilir" << endl;

    return 0;
}