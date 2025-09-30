//jrivas_lab7.cpp
#include <iostream>
#include <string>
#include <thread>
#include <algorithm>
#include "Node.h"
using namespace std;

Node::Node(string desc) : description(desc), gem(false), sword(false), chest(false), cave(false), north(nullptr), south(nullptr), east(nullptr), west(nullptr) {}

void print_with_pause(string text, int pause_time = 1500);

string to_lower(string str);

void explore_forest(Node* current_location, bool& found_gem, bool& found_sword, bool& found_chest, bool& found_cave);

int main() {
    
    Node* start = new Node("\033[96m🌲 Welcome to the Enchanted Forest! As you step into the forest, you feel a gentle breeze carrying whispers of ancient magic.\033[0m");
    Node* heart_of_forest = new Node("\033[96m🌳 You've reached the heart of the Enchanted Forest. Majestic trees tower above, their branches swaying in harmony with the forest's melody.\033[0m");
    Node* fork_in_path = new Node("\033[96m🌅 At a fork in the path, you sense two distinct energies calling to you – one vibrant and lively, the other tranquil and mysterious.\033[0m");
    Node* meadow = new Node("\033[96m🌼 Entering a sun-kissed meadow, you're greeted by a chorus of singing birds and dancing flowers. Nature's symphony fills your heart with joy.\033[0m");
    Node* hidden_cave = new Node("\033[96m🏞️ Concealed behind a waterfall, you find a hidden cave. The air is thick with magic, and you can't help but feel a sense of wonder.\033[0m");
    Node* crystal_cavern = new Node("\033[96m️⛰️Venturing into the cave, you discover a breathtaking crystal cavern, its walls adorned with precious gems that twinkle like stars.\033[0m");
    Node* glade = new Node("\033[96m🌺 You stumble upon a tranquil glade, bathed in soft sunlight. Colorful flowers bloom all around, emitting a sweet fragrance.\033[0m");
    Node* ancient_ruins = new Node("\033[96m🏰 You come across ancient ruins, remnants of a once-glorious civilization. Whispers of forgotten tales linger in the air.\033[0m");
    Node* mystical_pool = new Node("\033[96m🌊 A mystical pool shimmers in the sunlight, its waters reflecting the secrets of the forest.\033[0m");
    Node* whispering_trees = new Node("\033[96m🌳 The whispering trees beckon you closer, their ancient voices carrying hints of hidden knowledge.\033[0m");
    Node* enchanted_meadow = new Node("\033[96m🍄 Walking into an enchanted meadow, you find yourself surrounded by magical mushrooms of all shapes and sizes.\033[0m");
    Node* shimmering_falls = new Node("\033[96m💧 A cascading waterfall shimmers in the distance, its mesmerizing beauty drawing you closer.\033[0m");
    Node* ethereal_clearing = new Node("\033[96m✨ You step into an ethereal clearing, bathed in the soft glow of faerie lights. Time seems to stand still in this magical place.\033[0m");
    Node* ancient_grove = new Node("\033[96m🌳 You wander into an ancient grove, where ancient spirits linger among the ancient trees.\033[0m");
    Node* forgotten_path = new Node("\033[96m🌿 You stumble upon a forgotten path, overgrown with moss and ivy. It seems to lead to an unknown destination.\033[0m");
    Node* twilight_glade = new Node("\033[96m🌄 You discover a tranquil glade bathed in twilight hues, the sky painted with shades of orange and purple.\033[0m");
    Node* luminous_lake = new Node("\033[96m🌅 A luminous lake stretches before you, its waters reflecting the colors of the setting sun.\033[0m");
    Node* ancient_altar = new Node("\033[96m⛩️ You stumble upon an ancient altar, carved with mysterious symbols. The air around it hums with ancient power.\033[0m");
    Node* hidden_clearing = new Node("\033[96m🍃 A hidden clearing appears before you, surrounded by towering trees. It seems untouched by time.\033[0m");

    crystal_cavern->gem = true;
    hidden_cave->sword = true;
    fork_in_path->chest = true;
    meadow->cave = true;

    start->north = heart_of_forest;
    heart_of_forest->south = start;
    heart_of_forest->north = fork_in_path;
    fork_in_path->south = heart_of_forest;
    fork_in_path->east = meadow;
    fork_in_path->west = hidden_cave;
    meadow->west = fork_in_path;
    hidden_cave->east = fork_in_path;
    hidden_cave->north = crystal_cavern;
    crystal_cavern->south = hidden_cave;

    start->east = ancient_ruins;
    start->west = mystical_pool;
    ancient_ruins->west = start;
    mystical_pool->east = start;

    heart_of_forest->east = whispering_trees;
    heart_of_forest->west = enchanted_meadow;
    whispering_trees->west = heart_of_forest;
    enchanted_meadow->east = heart_of_forest;

    fork_in_path->east = shimmering_falls;
    fork_in_path->west = ethereal_clearing;
    shimmering_falls->west = fork_in_path;
    ethereal_clearing->east = fork_in_path;

    hidden_cave->south = ancient_grove;
    hidden_cave->east = forgotten_path;
    ancient_grove->north = hidden_cave;
    forgotten_path->west = hidden_cave;

    meadow->north = twilight_glade;
    meadow->south = luminous_lake;
    twilight_glade->south = meadow;
    luminous_lake->north = meadow;

    crystal_cavern->east = ancient_altar;
    crystal_cavern->west = hidden_clearing;
    ancient_altar->west = crystal_cavern;
    hidden_clearing->east = crystal_cavern;

    print_with_pause("\033[96mWelcome to the Enchanted Forest!\033[0m");

    string user_name;
    cout << "\033[93mWhat's your name, brave adventurer? \033[0m";
    cin >> user_name;

    print_with_pause("\n\033[1m\033[92mGreetings, " + user_name + "! Prepare to embark on a magical journey!\033[0m");

    bool found_gem = false;
    bool found_sword = false;
    bool found_chest = false;
    bool found_cave = false;

    explore_forest(start, found_gem, found_sword, found_chest, found_cave);

    delete start;
    delete heart_of_forest;
    delete fork_in_path;
    delete meadow;
    delete hidden_cave;
    delete crystal_cavern;
    delete glade;
    delete ancient_ruins;
    delete mystical_pool;
    delete whispering_trees;
    delete enchanted_meadow;
    delete shimmering_falls;
    delete ethereal_clearing;
    delete ancient_grove;
    delete forgotten_path;
    delete twilight_glade;
    delete luminous_lake;
    delete ancient_altar;
    delete hidden_clearing;

    print_with_pause("\n\033[96mThank you for exploring the Enchanted Forest. Come back soon!\033[0m");

    return 0;
}