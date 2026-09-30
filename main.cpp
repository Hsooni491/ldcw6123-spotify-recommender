// Spotify Music Recommendation System
// LDCW6123 Group Project - Part 2 (C++)
// Inspired by Spotify's personalised recommendations (Discover Weekly).
// Part 1 link: Spotify's free tier was the low-end foothold in Christensen's
// disruptive innovation model, and personalisation was how it moved upmarket.

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>

using TrackMap = std::map<std::string, std::map<std::string, std::vector<std::string>>>;
TrackMap getTracks()
{
    return {
        {"Pop / Upbeat", {{"Blinding Lights", {"The Weeknd", "Fast, synth-driven pop"}}, {"Levitating", {"Dua Lipa", "Bright, danceable disco-pop"}}, {"Shake It Off", {"Taylor Swift", "Cheerful, catchy pop"}}}},
        {"Hip-Hop / Energy", {{"Lose Yourself", {"Eminem", "Intense, motivating rap"}}, {"HUMBLE.", {"Kendrick Lamar", "Hard-hitting beat with sharp lyrics"}}, {"SICKO MODE", {"Travis Scott", "High-energy trap with beat switches"}}}},
        {"Lo-Fi / Study", {{"Snowman", {"WYS", "Soft, calm beats for focus"}}, {"Aruarian Dance", {"Nujabes", "Mellow jazz-hop for studying"}}, {"Affection", {"Jinsang", "Relaxed lo-fi for long study sessions"}}}},
        {"Rock / Classic", {{"Bohemian Rhapsody", {"Queen", "Epic, dramatic classic rock"}}, {"Sweet Child O' Mine", {"Guns N' Roses", "Famous guitar riff and hard rock energy"}}, {"Hotel California", {"Eagles", "Smooth, timeless guitar-driven rock"}}}}};
}

int readNumber(const std::string &errorMessage)
{
    int number;
    while (!(std::cin >> number))
    {
        if (std::cin.eof())
        {
            std::cout << "\nInput closed. Goodbye!\n";
            std::exit(0);
        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << errorMessage;
    }
    std::cin.ignore(10000, '\n'); // discard anything typed after the number
    return number;
}

int chooseTier()
{
    std::cout << "\nWelcome to Spotify!\n";
    std::cout << "1. Free (with ads)\n";
    std::cout << "2. Premium (no ads)\n";
    std::cout << "Choose your plan: ";
    int tier = readNumber("Invalid input. Enter 1 or 2: ");
    while (tier < 1 || tier > 2)
    {
        tier = readNumber("Please enter 1 or 2: ");
    }
    return tier;
}

int displayMessage()
{
    int choice = 0;
    std::cout << "\n===== SPOTIFY MUSIC RECOMMENDATION ====\n";
    std::cout << "Choose your preferred mood/genre:\n";
    std::cout << "1. Pop / Upbeat\n";
    std::cout << "2. Hip-Hop / Energy\n";
    std::cout << "3. Lo-Fi / Study\n";
    std::cout << "4. Rock / Classic\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter choice: ";
    choice = readNumber("Invalid input. Enter a number 1-5: ");
    return choice;
}

void logic(int choice)
{
    TrackMap tracks = getTracks();
    // define the genres in a vector for easy access
    const std::vector<std::string> genres = {
        "Pop / Upbeat",
        "Hip-Hop / Energy",
        "Lo-Fi / Study",
        "Rock / Classic"};

    // handle user choice
    if (choice == 5)
    {
        std::cout << "Goodbye!\n";
        return;
    }

    // validate user choice
    if (choice < 1 || choice > 4)
    {
        std::cout << "Invalid choice. Please select 1-5.\n";
        return;
    }

    // get the selected genre
    std::string genre = genres[choice - 1];
    std::cout << "\nRecommended tracks for " << genre << ":\n";

    std::vector<std::string> titles;
    int number = 1;

    for (const auto &track : tracks[genre])
    {
        std::cout << number << ". " << track.first
                  << " by " << track.second[0] << "\n";
        titles.push_back(track.first);
        number++;
    }

    std::cout << "Choose a song: ";
    int pick;
    pick = readNumber("Invalid input. Enter a song number: ");

    if (pick < 1 || pick > (int)titles.size())
    {
        std::cout << "Invalid song choice.\n";
        return;
    }

    std::string title = titles[pick - 1];
    std::cout << "\nTrack: " << title << "\n";
    std::cout << "Artist: " << tracks[genre][title][0] << "\n";
    std::cout << "Description: " << tracks[genre][title][1] << "\n";
}

// main function to run the program
int main()
{
    int userChoice = 0;

    while (userChoice != 5)
    {
        userChoice = displayMessage();
        logic(userChoice);
    }

    return 0;
}