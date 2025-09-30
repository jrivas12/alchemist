#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
  // Open the txt file.
  ifstream file("search.txt");

  // Check if the file opened successfully.
  if (!file) {
    cout << "Error opening file." << endl;
    return 1;
  }

  // Create a vector to store the words in the file.
  vector<string> words;

  // Read the words from the file.
  string word;
  while (file >> word) {
    words.push_back(word);
  }

  // Prompt the user for a word to find.
  cout << "Enter a word to find: ";
  string searchWord;
  cin >> searchWord;

  // Count the number of occurrences of the search word.
  int count = 0;
  for (string word : words) {
    if (word == searchWord) {
      count++;
    }
  }

  // Calculate the percentage of the search word in the file.
  double percentage = (double)count / words.size() * 100;

  // Print the statistics.
  cout << searchWord << " appears " << count << " times in the file. This is " << percentage << "% of the total words." << endl;

  // Close the file.
  file.close();

  return 0;
}

