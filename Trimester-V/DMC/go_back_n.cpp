#include<iostream>

using namespace std;

int main() {
    int frames, window, i = 1;
    cout << "Enter number of frames to send: ";
    cin >> frames;
    cout << "Enter window size: ";
    cin >> window;
    while(i <= frames) {
        int x = 0;
        for(int j = i; j < i + window && j <= frames; j++) {
            cout << "Sending frame " << j << "\n";
        }
        for(int j = i; j < i + window && j <= frames; j++) {
            string ans;
            cout << "Did you receive frame " << j << "? ";
            cin >> ans;
            if(ans == "Yes") 
                x++;
            else {
                cout << "Retransmitting window\n";
                break;
            }
        }
        i += x;
    }
}