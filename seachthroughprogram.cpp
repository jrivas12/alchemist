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

  // Create a map to store the word counts.
  map<string, int> wordCounts;

  // Count the number of occurrences of each word.
  for (string word : words) {
    wordCounts[word]++;
  }

  // Calculate the percentage of each word.
  for (auto& pair : wordCounts) {
    pair.second /= words.size();
  }

  // Print the word counts and percentages.
  for (auto& pair : wordCounts) {
    cout << pair.first << " " << pair.second * 100 << "%" << endl;
  }

  // Close the file.
  file.close();

  return 0;
}



