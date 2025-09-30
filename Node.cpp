//Node.cpp
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <algorithm>
#include "Node.h"
using namespace std;

void print_with_pause(string text, int pause_time = 1500){
    cout << text << endl;
    this_thread::sleep_for(chrono::milliseconds(pause_time));
}

string to_lower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void explore_forest(Node* current_location, bool& found_gem, bool& found_sword, bool& found_chest, bool& found_cave) {
    print_with_pause(current_location->description);

    if (current_location->gem && !found_gem) {
        found_gem = true;
        print_with_pause("\033[94m💎 You stumbled upon a glittering gem hidden among the ferns!\033[0m");
    }
    if (current_location->sword && !found_sword) {
        found_sword = true;
        print_with_pause("\033[92m🗡️ A gleaming sword, adorned with ancient runes, catches your eye!\033[0m");
    }
    if (current_location->chest && !found_chest) {
        found_chest = true;
        print_with_pause("\033[93m🎉 You discover a mysterious treasure chest half-buried beneath a magical oak tree!\033[0m");
    }
    if (current_location->cave && !found_cave) {
        found_cave = true;
        print_with_pause("\033[95m⛰️️ A hidden underwater cave beckons you with its iridescent glow!\033[0m");
    }

    if (found_gem && found_sword && found_chest && found_cave) {
        print_with_pause("\033[1m\033[91m🌈 Congratulations! You've found all the magical treasures and completed your quest!\033[0m");
        return;
    }

    string direction;
    cout << "\033[93m🔍 Which path will you explore next? (north/south/east/west): \033[0m";
    cin >> direction;

    direction = to_lower(direction);

    if (direction == "north" && current_location->north != nullptr) {
        explore_forest(current_location->north, found_gem, found_sword, found_chest, found_cave);
    } else if (direction == "south" && current_location->south != nullptr) {
        explore_forest(current_location->south, found_gem, found_sword, found_chest, found_cave);
    } else if (direction == "east" && current_location->east != nullptr) {
        explore_forest(current_location->east, found_gem, found_sword, found_chest, found_cave);
    } else if (direction == "west" && current_location->west != nullptr) {
        explore_forest(current_location->west, found_gem, found_sword, found_chest, found_cave);
    } else {
        print_with_pause("\033[91m🪄 You encountered a magical barrier, preventing further exploration in that direction. Perhaps there's another path to discover...\033[0m");
        explore_forest(current_location, found_gem, found_sword, found_chest, found_cave);
    }
}

