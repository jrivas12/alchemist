#include <iostream>

using namespace std;

int main ()
{
	int number, remainder;
	cout << "Please Enter an Integer: ";
	cin  >> number;
	remainder = number % 2;
	if (remainder == 0) {
		cout << number << ", The Number is Even.";
	}else
	{
		cout << number << ", The Number is Odd.";
	}
	
	return 0;
}