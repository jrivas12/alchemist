#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>
#include "ArrayStats.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "records_sorter.h"
#include "ListNode.h"
#include "Node.h"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"

using namespace std;

Node::Node(string desc) : description(desc), gem(false), sword(false), chest(false), cave(false), north(nullptr), south(nullptr), east(nullptr), west(nullptr) {}

// Forward declarations for program_option1 + ... + program_option(n)
void program_option1();
void program_option2();
void program_option3();
void program_option4();
void program_option5();
void program_option6();
// Forward delcarations for programs_option1:
void generatePassword(char* array, int size);
void randomizeDoubles(double* array, int size);

void print_with_pause(string text, int pause_time = 1500);
string to_lower(string str);
void explore_forest(Node* current_location, bool& found_gem, bool& found_sword, bool& found_chest, bool& found_cave);

// Define MainMenu class
class MainMenu {
private:
    std::map<std::string, std::pair<std::string, void(*)()>> topics;

public:
    MainMenu() {
        topics = {
            {"1", {"\033[94mProgram1\033[0m", &program_option1}},
            {"2", {"\033[95mProgram2\033[0m", &program_option2}},
            {"3", {"\033[96mProgram3\033[0m", &program_option3}},
            {"4", {"\033[93mProgram4\033[0m", &program_option4}},
            {"5", {"\033[92mProgram5\033[0m", &program_option5}},
            {"6", {"\033[90mProgram6\033[0m", &program_option6}},
            // Add other topics here...
        };
    }

    void display() {
        std::cout << "\033[96m    Main Menu   \033[0m" << std::endl;
        for (const auto& topic : topics) {
            std::cout << topic.first << ". " << topic.second.first << std::endl;
        }
        std::cout << "0. \033[91mExit\033[0m" << std::endl;
    }

    void selectTopic(const std::string& choice) {
        if (topics.find(choice) != topics.end()) {
            topics[choice].second();
        } else {
            std::cout << "Invalid choice!" << std::endl;
        }
    }
};


void sequence(int n, int steps) {
    if (n == 1 || steps >= n) {
        cout << "n              = " << GREEN << n << RESET << endl;
        cout << "Number of steps = " << YELLOW << steps << RESET << endl;
        return;
    }
    cout << "n              = " << GREEN << n << RESET << endl;
    if (n % 2 == 0) {
        cout << "n * 3 + 1      = " << YELLOW << n * 3 + 1 << RESET << endl;
        sequence(n / 2, steps + 1);
    } else {
        cout << "n / 2          = " << YELLOW << n / 2 << RESET << endl;
        sequence(3 * n + 1, steps + 1);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << "\033[1;36m" << setw(4) << num << "\033[0m";
    }
    cout << endl;
}

vector<int>::iterator findMinIndex(vector<int>::iterator start, vector<int>::iterator end) {
    return min_element(start, end);
}

void selectionSortRecursive(vector<int>& arr, vector<int>::iterator start, vector<int>::iterator end) {
    if (start == end) {
        return;
    }
    auto minIndex = findMinIndex(start, end);
    if (minIndex != start) {
        iter_swap(minIndex, start);
    }
    selectionSortRecursive(arr, start + 1, end);
}


// Define generatePassword function
void generatePassword(char* array, int size);
// Define randomizeDoubles function
void randomizeDoubles(double* array, int size);

int main() {
    // Instantiate menu object
    MainMenu menu;
    std::string choice;

    // "do-while loop", guarntees to execution while true
    do {
        menu.display();
        std::cout << "\033[98m\nEnter your choice: \033[0m";
        std::cin >> choice;

        if (choice == "0") {
            break;
        }

        menu.selectTopic(choice);
    } while (true);

    return 0;
}
// Define program_option1 function
void program_option1() {
    try {
        int size;
        cout << "Enter the size of the arrays: ";
        cin >> size;

        ArrayStats<int> intArray(size, 10);
        intArray.randomizeValues();
        cout << "\033[1;32mMax value in intArray: \033[0m" << intArray.findMax() << endl;
        cout << "\033[1;33mMin value in intArray: \033[0m" << intArray.findMin() << endl;

        ArrayStats<double> doubleArray(size, 10.5);
        randomizeDoubles(doubleArray.getArray(), size);
        cout << "\033[1;34mMax value in doubleArray: \033[0m" << doubleArray.findMax() << endl;
        cout << "\033[1;35mMin value in doubleArray: \033[0m" << doubleArray.findMin() << endl;

        ArrayStats<char> charArray(8, ' '); // Password-like string of up to 8 characters
        generatePassword(charArray.getArray(), 8);
        cout << "\033[1;36mPassword-like string in charArray: \033[0m";
        for (int i = 0; i < 8; ++i) {
            cout << charArray.getArray()[i];
        }
        cout << endl;
    } catch (const invalid_argument& e) {
        cerr << "\033[1;38mError: \033[0m" << e.what() << endl;
    }
}
// Define program_option2 function ->
void program_option2() {
    // Implemented program_option2 logic
    int input_value;

    cout << "Enter the starting point: " << GREEN << RESET << endl;
    cin >> input_value;

    sequence(input_value, 0);
}
// Define program_option3 function ->
void program_option3() {
    // Implemented program_option3 logic
    srand(time(nullptr));

    const int SIZE = 20;
    const int MAX_RANDOM_VALUE = 100;
    vector<int> arr(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % MAX_RANDOM_VALUE;
    }

    cout << "\nUnsorted array:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    sort(arr.begin(), arr.end());

    cout << "\nSorted array:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}
// Define program_option3 function ->
void program_option4() {
    // Implement program_option4 logic here
    vector<Student> students;
    int option;

    do {
        cout << "|---------------------------------------|" << endl;
        cout << "|         Student Records Sorter        |" << endl;
        cout << "|---------------------------------------|" << endl;
        cout << "|Option | Description                   |" << endl;
        cout << "|-------|-------------------------------|" << endl;
        cout << "| 1     | Load student records          |" << endl;
        cout << "| 2     | View data                     |" << endl;
        cout << "| 3     | MergeSort data                |" << endl;
        cout << "| 4     | QuickSort data                |" << endl;
        cout << "| 5     | Exit                          |" << endl;
        cout << "|---------------------------------------|" << endl;
        cout << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << endl;

        switch (option) {
            case 1:
                cout << "Loading Student Data...";
                loadStudentRecords(students);
                break;
            case 2:
                viewData(students);
                break;
            case 3:
                mergeSortData(students);
                viewData(students);
                break;
            case 4:
                quickSortData(students, 0, students.size() - 1);
                viewData(students);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
        cout << endl;
    } while (option != 5);
}

void program_option5() {
    ifstream inFile;
    inFile.open("Grades.txt");
    ListNode *head= NULL;
    double value;

    for (int x=0; x<10; x++)
    {
        inFile >> value;
        head = new ListNode(value, head);
    }

    ListNode *ptr1;
    double temp;

    for (int x=0; x<10; x++)
    {
        ptr1=head;
        for (int y=0; y<10-1-x; y++)
        {
            if (ptr1->value > ptr1->next->value)
            {
                temp = ptr1->value;
                ptr1->value = ptr1->next->value;
                ptr1->next->value = temp;
            }
            ptr1=ptr1->next;
        }
    }

    ListNode *ptr = head;
    for (int x=0; x<10; x++)
    {
        cout << ptr->value << endl;
        ptr = ptr->next;
    }
}
// Define program_option6 function ->
void program_option6() {
    // Implemented program_option6 logic
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
}

// Define generatePassword function for program_option1 ->
void generatePassword(char* array, int size) {
    const char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        array[i] = charset[rand() % (sizeof(charset) - 1)]; // Exclude null terminator
    }
}

// Define randomizeDoubles function (program_option1) 
void randomizeDoubles(double* array, int size) {
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        array[i] = (rand() % 10000) / 100.0; // Random doubles between 0.00 and 99.99
    }
}
