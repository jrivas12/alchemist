#include <iostream>
using namespace std;

int main ()
{
        //5.11 (Find the Smallest Value) Write a program that finds the smallest of several integers. Assume that the first value read specifies the number of values to input from the user.

        int count    = 0;
        int smallest = 99999;
        int number   = 0;
        int numValues;

        cout << "How many numbers will you be entering? ";
        cin  >> numValues;

        while(count < numValues){
                cout << "Enter number: ";
                cin  >> number;
                if (number < smallest)
                        smallest = number;
                count = count + 1;
        }

        cout << "The smallest value is " << smallest << "." << endl;


        return 0;
}
