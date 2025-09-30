//program2

#include <iostream>

//using namespace std;

int main()
{
   int number1{0};
   int number2{0};
   int sum{0};
   
   std::cout << "Enter the first interger: ";
   std::cin >> number1;
   
   std::cout<< "Enter second interger: ";
   std::cin >> number2;
   
   sum = number1 + number2;
   
   std::cout << "Sum is " << sum << std::endl;
   
   // return 0;
}