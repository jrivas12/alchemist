#include <iostream>
#include <string>

int main() {
  int primary_color_1;
  std::cout << "Select one of the three primary colors: " << std::endl;
  std::cout << "1. Red" << std::endl;
  std::cout << "2. Blue" << std::endl;
  std::cout << "3. Yellow" << std::endl;
  std::cin >> primary_color_1;

  int primary_color_2;
  std::cout << "Select another primary color: " << std::endl;
  std::cout << "1. Red" << std::endl;
  std::cout << "2. Blue" << std::endl;
  std::cout << "3. Yellow" << std::endl;
  std::cin >> primary_color_2;

  std::string result_color;
  if (primary_color_1 == 1 && primary_color_2 == 2) {
    result_color = "Purple";
  } else if (primary_color_1 == 2 && primary_color_2 == 3) {
    result_color = "Green";
  } else if (primary_color_1 == 1 && primary_color_2 == 3) {
    result_color = "Orange";
  } else {
    result_color = "Invalid combination";
  }

  std::cout << "Your color is " << result_color << "." << std::endl;

  return 0;
}
