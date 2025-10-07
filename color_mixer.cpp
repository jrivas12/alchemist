#include <iostream>
#include <string>
using namespace std;

int main() {
  int primary_color_1;
  cout << "Select one of the three primary colors: " << endl;
  cout << "1. Red" << endl;
  cout << "2. Blue" << endl;
  cout << "3. Yellow" << endl; 
  	
  cin >> primary_color_1;

  int primary_color_2;
  cout << "Select another primary color: " << endl;
  cout << "1. Red" << endl;
  cout << "2. Blue" << endl;
  cout << "3. Yellow" << endl;
  cin >> primary_color_2;

  string result_color;
  if (primary_color_1 == 1 && primary_color_2 == 2) {
    result_color = "Purple";
  } else if (primary_color_1 == 2 && primary_color_2 == 3) {
    result_color = "Green";
  } else if (primary_color_1 == 1 && primary_color_2 == 3) {
    result_color = "Orange";
  } else {
    result_color = "Invalid combination";
  }

  cout << "Your color is " << result_color << "." << endl;

  return 0;
}
