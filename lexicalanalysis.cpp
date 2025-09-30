#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
 
  ifstream file("essay.txt");

  
  if (!file) {
    cout << "Error opening file." << endl;
    return 1;
  }

  
  vector<string> words;

  
  string  word;
  while (file >> word) {
    words.push_back(word);
  }

  bool complete = false;
  while (!complete) {

    cout << "Enter a word to find: ";
    string regex;
    cin  >> regex;

    int count = 0;
    for (string word : words) {
        if (word == regex) {
        count++;
        }
    }

    double percentage = (double)count / words.size() * 100;

    cout << regex << " appears " 
         << count << " times in the file. This is " 
         << percentage << "% of the total words." 
         << endl;

    cout << "Enter the next word: ";
    string adj_rex;
    cin  >> adj_rex;

    bool true_dex = false;
    for  (int i  = 0; i < words.size() - 1; i++) {
      if (words[i] == regex && words[i + 1] == adj_rex) {
         true_dex = true;
         break;
      }
    }

    if (true_dex) {
      cout << "The words '"   << regex << "' and '" << adj_rex
           << "' appear together " << count << " times in the file. This is " 
           << percentage << "% of the total words." << endl;
    }

   // Prompt the user if they are done.
    cout << "Are you done? (y/n) ";
    char answer;
    cin >> answer;

    // If the user says yes, set the done flag to true.
    if (answer == 'y') {
      complete = true;
    }
  }

  // Close the file.
  file.close();

  return 0;
}
