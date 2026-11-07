#include <iostream>
#include <string>
using namespace std;

// تشفير قيصر: إزاحة كل حرف إنجليزي بمقدار المفتاح
string encrypt(const string& text, int key) {
    string result = text;
    key = ((key % 26) + 26) % 26;
    for (char& c : result) {
        if (isupper(c))
            c = 'A' + (c - 'A' + key) % 26;
        else if (islower(c))
            c = 'a' + (c - 'a' + key) % 26;
    }
    return result;
}

// فك التشفير: نفس العملية بإزاحة معاكسة
string decrypt(const string& text, int key) {
    return encrypt(text, 26 - (((key % 26) + 26) % 26));
}

int main() {
    string message;
    int key;

    cout << "ادخل الرسالة (بالانجليزية): ";
    getline(cin, message);
    cout << "ادخل المفتاح (رقم): ";
    cin >> key;

    string encrypted = encrypt(message, key);
    string decrypted = decrypt(encrypted, key);

    cout << "\nالرسالة المشفرة: " << encrypted << endl;
    cout << "الرسالة بعد فك التشفير: " << decrypted << endl;

    return 0;
}
