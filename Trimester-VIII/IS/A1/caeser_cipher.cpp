#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>

using namespace std;

void validateOperation(string op) {
    if (!(op == "encrypt()" || op == "decrypt()" || op == "exit()"))
        throw invalid_argument("Invalid Operation!");
}

void validateText(string text) {
    regex expr("[a-z]*");
    if (!regex_match(text, expr))
        throw invalid_argument("Text must contain only lower-cased alphabets.");
}

void validateShift(int shift) {
    regex expr("1*[0-9]|2[0-5]");
    if (!regex_match(to_string(shift), expr))
        throw invalid_argument("Shift is not within the specified range (0-25).");
}

char encryptCipher(char ch, int shift) {
    int i = (int(ch) - 96 + shift) % 26;
    return (i != 0) ? (i + 96) : 122;
}

char decryptCipher(char ch, int shift) {
    int i = int(ch) - 96 - shift; 
    return (i > 0) ? (i + 96) : (122 - i);
}

void encryptText(string text, int shift) {
    cout << "Encrypted Cipher: ";
    for(int i : text)
        cout << encryptCipher(i, shift);
}

void decryptText(string text, int shift) {
    cout << "Decrypted Cipher: ";
    for(int i : text)
        cout << decryptCipher(i, shift);
}

int main() {
    cout << "Welcome to Caesar Cipher!\n"
        "A classical cryptographer based on shift technique used by Julius Caesar.\n"
        "The application provides a REPL interface supporting encrypt(), decrypt() and exit() functions.\n\n";

    while (true) {
        int shift;
        string text, op;

        while (true) {
            try {
                cout << ">>> ";
                cin >> op;
                validateOperation(op);
                break;
            }
            catch (invalid_argument& e) {
                cerr << e.what() << '\n';
            }
        }

        if (op == "exit()") {
            cout << "Bye!\n";
            break;
        }

        while (true) {
            try {
                cout << "Enter Text: ";
                cin >> text;
                validateText(text);
                break;
            }
            catch (invalid_argument& e) {
                cerr << e.what() << '\n';
            }
        }

        while (true) {
            try {
                cout << "Enter Shift: ";
                cin >> shift;
                validateShift(shift);
                break;
            }
            catch (invalid_argument& e) {
                cerr << e.what() << '\n';
            }
        }

        if (op == "encrypt()") encryptText(text, shift);
        else decryptText(text, shift);
        cout << '\n';
    }
    return 0;
}