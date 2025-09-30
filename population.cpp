#include <iostream>
#include <iomanip>
#include "population.h"
using namespace std;


#define RESET       "\033[0m"
#define RED         "\033[31m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define PURPLE      "\033[35m"
#define LIME_GREEN  "\033[92m"

int main() {
    int population, births, deaths;
    cout << "POPULATION STATISTICS\n";
    cout << YELLOW << "\nEnter total population: " << RESET << endl;
    cin >> population;

    cout << BLUE << "Enter yearly births: " << RESET << endl;
    cin >> births;

    cout << RED << "Enter annual number of deaths: " << RESET << endl;
    cin >> deaths;

    Population pop(population, births, deaths);

    cout << PURPLE << "|      Birth rate: |" << setw(18) << "      Death rate:|" << RESET << endl;
    cout << LIME_GREEN << "|" << setw(17) << fixed << setprecision(2) << pop.getBirthRate() << "%" << "|"  << setw(17) << setprecision(2) << pop.getDeathRate() << "%" << "|" << RESET << endl;
    cout << LIME_GREEN << "|__________________|"  << "__________________|" << RESET << endl;

    return 0;
}