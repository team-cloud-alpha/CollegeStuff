#include <iostream>

int main() {
    int frames, window, i = 1;
    bool ack[frames];
    
    for(int j = 0; j < frames; j++) {
        ack[j] = 0;
    }

    std::cout << "Enter number of frames to send: ";
    std::cin >> frames;
    std::cout << "Enter window size: ";
    std::cin >> window;
    
    while(i <= frames) {
        int counter = 0;
        
        for(int j = 0; (counter < window) && (j < frames); j++) {
            if(!ack[j]) {
                std::cout << "Sending frame " << j+1 << "\n";
                counter++;
            }
        }

        counter = 0;

        for(int j = 0; (counter < window) && (j < frames); j++) {
            if(!ack[j]) {
                char ans;
                
                std::cout << "Did you receive frame " << j+1 << "? ";
                std::cin >> ans;
                
                if(ans == 'Y' || ans == 'y') {
                    ack[j] = 1;
                    i++;
                }
                counter++;
            }
        }
    }

    return 0;
}