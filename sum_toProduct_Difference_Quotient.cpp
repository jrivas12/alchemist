#include <iostream>

using namespace std;

using std::cout;
using std::endl;
using std::cin;

int main()
{
    int num1, num2;
    
    cout<< "Enter tow integers: " << endl;
    cin >> num1 >>num2;
    
    cout<< "THe Sum is " << num1 + num2
        << "\nTHe product is " << num1 * num2
        << "\nThe difference is " << num1 - num2
        << "\nThe quotient is " << num1 / num2 << endl;

    return 0;
}
