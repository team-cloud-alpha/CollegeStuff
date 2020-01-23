#include <iostream>

using namespace std;

void get_data_word(bool dw[]) {
    cout << "Enter dataword:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Enter a" << 3-i << ": ";
        cin >> dw[i];
    }
}
//a3 a2 a1 a0 r2 r1 r0
void calc_redundant(bool dw[]) {
    dw[6] = dw[1] ^ dw[2] ^ dw[3]; // r0 = a2+a1+a0
    dw[5] = dw[0] ^ dw[1] ^ dw[2]; // r1 = a3+a2+a1
    dw[4] = dw[2] ^ dw[3] ^ dw[0]; // r2 = a1+a0+a3
}

void print_code_word(bool dw[]) {
    for (int i = 0; i < 7; i++) {
        cout << dw[i];
    }
    cout << "\n";
}

void get_code_word(bool cw[]) {
    cout << "Enter recieved codeword:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Enter a" << 3-i << ": ";
        cin >> cw[i];
    }
    for (int i = 4; i < 7; i++) {
        cout << "Enter r" << 6-i << ": ";
        cin >> cw[i];
    }
}
//b3 b2 b1 b0 q2 q1 q0
void calc_syndrome(bool cw[], bool syn[]) {
    syn[2] = cw[1] ^ cw[2] ^ cw[3] ^ cw[6];//s0 = b2 + b1 + b0 + q0
    syn[1] = cw[0] ^ cw[1] ^ cw[2] ^ cw[5];//s1 = b3 + b2 + b1 + q1
    syn[0] = cw[2] ^ cw[3] ^ cw[0] ^ cw[4];//s2 = b1 + b0 + b3 + q2
}

bool check_syndrome(bool cw[], bool syn[]) {
    if(!syn[0] && !syn[1] && !syn[2])       //000
        return true;
    else if(!syn[0] && !syn[1] && syn[2])   //001
        cw[6] = !cw[6];
    else if(!syn[0] && syn[1] && !syn[2])   //010
        cw[5] = !cw[5];
    else if(!syn[0] && syn[1] && syn[2])    //011
        cw[0] = !cw[0];
    else if(syn[0] && !syn[1] && !syn[2])   //100
        cw[4] = !cw[4];
    else if(syn[0] && !syn[1] && syn[2])    //101
        cw[3] = !cw[3];
    else if(syn[0] && syn[1] && !syn[2])    //110
        cw[1] = !cw[1];
    else                                    //111
        cw[2] = !cw[2];
    return false;
}

int main() {
    bool dw[7], cw[7], syn[3];
    get_data_word(dw);
    calc_redundant(dw);
    cout << "Generated codeword: ";
    print_code_word(dw);
    
    get_code_word(cw);
    calc_syndrome(cw, syn);
    bool check = check_syndrome(cw, syn);
    if(check) {
        cout << "Entered codeword is correct\n";
    }
    else {
        cout << "Entered codeword is incorrect\n";
        cout << "Corrected codeword: ";
        print_code_word(cw);
    }
}