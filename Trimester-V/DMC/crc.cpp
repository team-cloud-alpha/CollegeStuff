#include <iostream>
#include <string>

using namespace std;

string xorfun(string encoded, string crc) {
    for(int i = 0; i <= encoded.length() - crc.length();) {
        for(int j = 0; j < crc.length(); j++) {
            encoded[i+j] = (encoded[i+j] == crc[j] ? '0' : '1'); 
        }
        for(; i < encoded.length() && encoded[i] != '1'; i++) {}
    }
    return encoded;
}

bool zero(string encoded) {
    for(int i = 0; i < encoded.length(); i++) {
        if(encoded[i] == '1')
            return false;
    }
    return true;
}

int main() {
    string data, generator, encoded = "";
    cout << "Enter data for sender's side: ";
    cin >> data;
    cout << "Enter generator: ";
    cin >> generator;

    encoded += data;
    for(int i = 0; i < generator.length()-1; i++) {
        encoded += '0';
    }
    encoded = xorfun(encoded, generator);
    cout << "Data sent from sender side is: " << data + encoded.substr(encoded.length() - generator.length() + 1) << "\n";

    cout << "Enter data received on receiver's side: ";
    cin >> data;
    encoded = xorfun(data, generator);
    cout << (zero(encoded) ? "No error in communication" : "Error received") << "\n";
}