/*Для шифрования на квадрате находим букву текста и вставляем в шифровку нижнюю от 
её в том же столбце. Если буква в нижней строке, то берем верхнюю из того же столбца.*/

#include <iostream>
#include <cstdio>
#include <iostream>
using namespace std;

const char POLYBIUS[6][6] = {
    { 'A', 'B', 'C' , 'D', 'E'},
    { 'F', 'G', 'H' , 'I', 'K'},
    { 'L', 'M', 'N' , 'O', 'P'},
    { 'Q', 'R', 'S' , 'T', 'U'},
    { 'V', 'W', 'X' , 'Y', 'Z'}
};

char encrypt(const char c) {

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            if (POLYBIUS[i][j] == c)
                return POLYBIUS[(i + 1) % 5][j];
}

char decrypt(const char c) {

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            if (POLYBIUS[i][j] == c)
                return POLYBIUS[(i + 4) % 5][j];
}

int main() {
    setlocale(LC_ALL, "Russian");
    char c[256];
    cout << "Введите слово:"<<endl;
    gets_s(c);
    cout << endl;

    cout << "Шифрование:" << endl;
    for (int i = 0; c[i] != '\0'; ++i)
        cout << encrypt(c[i]);
    cout << std::endl;

    cout << "Дешифрование:" << endl;
    for (int i = 0; c[i] != '\0'; ++i)
        cout << decrypt(encrypt(c[i]));
    cout << endl;
    
    return 0;
}