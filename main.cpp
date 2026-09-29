#include <iostream>

int displayMessage(){
    int choice = 0;
    std::cout << "\n===== SPOTIFY MUSIC RECOMMENDATION ====\n";
    std::cout << "Choose your preferred mood/genre:\n";
    std::cout << "1. Pop / Upbeat\n";
    std::cout << "2. Hip-Hop / Energy\n";
    std::cout << "3. Lo-Fi / Study\n";
    std::cout << "4. Rock / Classic\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;
    return choice;
}


int main(){
    int userChoice = displayMessage();
    return 0;
}