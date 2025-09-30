#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "Tortoise.h"
#include "Hare.h"

using namespace std;

void tick(Tortoise* turtlePtr, Hare* rabbitPtr);
void displayOutput(int turtleSquare, int rabbitSquare);

int main() {
        cout <<
        "\033[0;37m             //\\\n"
        "\033[0;37m           /     \\\n"
        "\033[0;33m           / \\     \\\n"
        "\033[0;33m        / ___      \\\n"
        "\033[0;33m        /     _      \\\n"
        "\033[0;33m       / ____         \\\n"
        "\033[0;33m     // /  /     ___   \\   \\\n"
        "\033[1;32m    //   \033[0;31mT  O  R  T  O  I  S  E\033[1;35m   A  N  D\n"
        "\033[1;32m  // /     \033[0;31mT  H  E   H  A  R  E\033[1;31m   R  A  C  E\n"
        "\033[1;32m//                         \\    \\  \033[0m" << endl;
cout << "\n" << endl;
cout << "BANG !!!\n",
cout << "AND THEY'RE OFF !!!!!\n" << endl;
    Tortoise turtle;
    Hare rabbit;

    Tortoise* turtlePtr = &turtle;
    Hare* rabbitPtr = &rabbit;

    while (!(turtlePtr->victor() || rabbitPtr->victor())) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        displayOutput(turtlePtr->square, rabbitPtr->square);
        tick(turtlePtr, rabbitPtr);
    }

    if (turtlePtr->victor() && rabbitPtr->victor())
        cout << "It's a tie.\n";
    else if (turtlePtr->victor())
        turtlePtr->win();
    else
        rabbitPtr->win();

    return 0;
}

void tick(Tortoise* turtlePtr, Hare* rabbitPtr) {
    srand(time(0));

    int random = rand() % 11;

    if (random < 5)
        turtlePtr->move();
    else if (random < 7)
        turtlePtr->move();
    else
        turtlePtr->move();

    if (random >= 2 && random < 4)
        rabbitPtr->move();
    else if (random < 5)
        rabbitPtr->move();
    else if (random < 8)
        rabbitPtr->move();
    else if (random < 10)
        rabbitPtr->move();

    displayOutput(turtlePtr->square, rabbitPtr->square);
}

void displayOutput(int turtleSquare, int rabbitSquare) {
    system("clear");  
    cout <<
        "\033[0;37m             //\\\n"
        "\033[0;37m           /     \\\n"
        "\033[0;33m           / \\     \\\n"
        "\033[0;33m        / ___      \\\n"
        "\033[0;33m        /     _      \\\n"
        "\033[0;33m       / ____         \\\n"
        "\033[0;33m     // /  /     ___   \\   \\\n"
        "\033[1;32m    //   \033[0;31mT  O  R  T  O  I  S  E\033[1;35m   A  N  D\n"
        "\033[1;32m  // /     \033[0;31mT  H  E   H  A  R  E\033[1;31m   R  A  C  E\n"
        "\033[1;32m//                         \\    \\  \033[0m" << endl;
    const int trackWidth = 50;
    const int mountainHeight = 10;

    int turtlePosition = (turtleSquare * trackWidth) / 70;
    int rabbitPosition = (rabbitSquare * trackWidth) / 70;

    cout << "\x1B[31mTORTOISE\x1B[0m vs. \x1B[32mHARE\x1B[0m" << endl;

    for (int i = mountainHeight; i > 0; i--) {
        cout << "|";
        for (int j = 0; j < trackWidth; j++) {
            if (i == mountainHeight)
                cout << "_"; // Draw the track
            else {
                if (j == turtlePosition && i == 1)
                    cout << "\x1B[31mT\x1B[0m"; // Tortoise (red T)
                else if (j == rabbitPosition && i == 1)
                    cout << "\x1B[32mH\x1B[0m"; // Hare (green H)
                else
                    cout << " ";
            }
        }
        cout << "|" << endl;
    }

    if (turtleSquare == rabbitSquare)
        cout << "OUCH !!!" << endl;

    cout << "T = Tortoise, H = Hare" << endl;
}


