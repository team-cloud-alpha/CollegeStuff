#include <iostream>

int main() {
    int frames, window, i = 1;
    
    std::cout << "Enter number of frames to send: ";
    std::cin >> frames;
    std::cout << "Enter window size: ";
    std::cin >> window;
    
    while(i <= frames) {
        for(int j = i; j < i + window && j <= frames; j++) {
            std::cout << "Sending frame " << j << "\n";
        }

        char ans;
        std::cout << "Did you receive the window? ";
        std::cin >> ans;
    
        if(ans == 'Y' || ans == 'y') {
            i += window;
        }
    }
    
    return 0;
}