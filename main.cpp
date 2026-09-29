#include <iostream>
#include <map>
#include <vector>
#include <string>



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

int logic(int choice){
map<string, map<string, vector<string>>> tracks = {
    {"Pop / Upbeat", {
        {"Blinding Lights", {"The Weeknd", "Fast, synth-driven pop"}},
        {"Levitating", {"Dua Lipa", "Bright, danceable disco-pop"}},
        {"Shake It Off", {"Taylor Swift", "Cheerful, catchy pop"}}
    }},
    {"Hip-Hop / Energy", {
        {"Lose Yourself", {"Eminem", "Intense, motivating rap"}},
        {"HUMBLE.", {"Kendrick Lamar", "Hard-hitting beat with sharp lyrics"}},
        {"SICKO MODE", {"Travis Scott", "High-energy trap with beat switches"}}
    }},
    {"Lo-Fi / Study", {
        {"Snowman", {"WYS", "Soft, calm beats for focus"}},
        {"Aruarian Dance", {"Nujabes", "Mellow jazz-hop for studying"}},
        {"Affection", {"Jinsang", "Relaxed lo-fi for long study sessions"}}
    }},
    {"Rock / Classic", {
        {"Bohemian Rhapsody", {"Queen", "Epic, dramatic classic rock"}},
        {"Sweet Child O' Mine", {"Guns N' Roses", "Famous guitar riff and hard rock energy"}},
        {"Hotel California", {"Eagles", "Smooth, timeless guitar-driven rock"}}
    }}
};
int main(){
    int userChoice = displayMessage();
    return 0;
}