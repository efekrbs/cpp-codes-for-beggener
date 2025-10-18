#include <iostream>
#include <bits/stdc++.h>


int main(){
    
    int dizi[] = {1, 2, 3, 4, 5};
    // Dizi uzunluğu
    int uzunluk = static_cast<int>(sizeof(dizi) / sizeof(dizi[0]));

    std::cout << uzunluk << std::endl;
    return 0;

}