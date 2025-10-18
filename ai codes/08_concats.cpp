// 08_concats.cpp
// Amac: Iki stringi birlestiren `concats` fonksiyonunu ogretmek
// Aciklama: Bu dosyada farkli yontemlerle string birlestirme (operator+, append, move semantics) gosterilir

#include <iostream>
#include <string>
#include <cstring> // strlen icin

using std::cout;
using std::endl;
using std::string;

// Pointer ile string birlestirme (std::string uzerinden)
// Not: result.resize ile kapasite ayarlanir ve &result[0] ile yazilabilir bellek alinir
string concats_ptr_string(const string& a, const string& b) {
    string result;
    result.resize(a.size() + b.size());
    char* dest = &result[0];
    const char* p = a.c_str();
    while (*p) { *dest++ = *p++; }
    p = b.c_str();
    while (*p) { *dest++ = *p++; }
    // null-terminator eklemeye gerek yok; std::string boyutu ile yonetilir
    return result;
}

// Pointer ile C-stili dizelerden (const char*) birlestirme; yeni std::string dondurur
string concats_cstr(const char* a, const char* b) {
    size_t la = std::strlen(a);
    size_t lb = std::strlen(b);
    char* buf = new char[la + lb + 1];
    char* dest = buf;
    const char* p = a;
    while (*p) { *dest++ = *p++; }
    p = b;
    while (*p) { *dest++ = *p++; }
    *dest = '\0';
    string out(buf);
    delete[] buf;
    return out;
}

// Basit ve genel kullanim icin tek fonksiyon: iki stringi birlestirir
string concats(const string& a, const string& b) {
    return a + b;
}

// concats: iki std::string alir ve yeni bir std::string dondurur
// 1) Basit versiyon: kopyalama (kucuk stringlerde uygun)
string concats_copy(const string& a, const string& b) {
    return a + b; // operator+ ile birlestirme
}

// 2) append ile (daha az kopyalama yapma egiliminde)
string concats_append(const string& a, const string& b) {
    string result = a;
    result.append(b);
    return result;
}

// 3) move semantics kullanarak (tasima): performans icin buyuk stringlerde faydali
string concats_move(string a, string b) {
    a.append(b);
    return std::move(a); // dondurmeden once tasima
}

int main() {
    cout << "=== STRING CONCAT ORNEKLERI ===" << endl;

    string s1 = "Merhaba ";
    string s2 = "Dunya!";

    // -1) concats_ptr_string (std::string + pointer)
    string rp = concats_ptr_string(s1, s2);
    cout << "concats_ptr_string: " << rp << endl;

    // -0) concats_cstr (C-stili pointerlarla)
    string rc = concats_cstr(s1.c_str(), s2.c_str());
    cout << "concats_cstr: " << rc << endl;

    // 0) concats (en basit kullanim)
    string r0 = concats(s1, s2);
    cout << "concats: " << r0 << endl;

    // 1) concats_copy
    string r1 = concats_copy(s1, s2);
    cout << "concats_copy: " << r1 << endl;

    // 2) concats_append
    string r2 = concats_append(s1, s2);
    cout << "concats_append: " << r2 << endl;

    // 3) concats_move
    string r3 = concats_move(s1, s2);
    cout << "concats_move: " << r3 << endl;

    // 4) dogrudan operator+
    cout << "operator+ kullanimi: " << (s1 + s2) << endl;

    // 5) std::string::reserve ile performans iyilestirme
    string big1 = "Bu bir uzun metin parcasidir. ";
    string big2 = "Eklenen daha uzun bir metin parcasi.";
    string reserved;
    reserved.reserve(big1.size() + big2.size()); // onceden yeterli kapasite ayir
    reserved += big1;
    reserved += big2;
    cout << "reserve + +=: " << reserved << endl;

    return 0;
}
