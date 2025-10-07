#include <iostream> 
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

const int MAX_CLASSES = 25;
const int NUM_GRADES = 5;

struct Class {
    string subject;
    double grades[NUM_GRADES];
};

void calculateAndWriteAverages(ifstream& grade_input, ofstream& grade_output, Class  classes[], int num_classes);


int main() {
    
    ifstream grade_input("grades.txt");
    ofstream grade_output("averages.txt");
    
    if (!grade_input.is_open() || !grade_output.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }
    
    Class classes[MAX_CLASSES];
    int num_classes = 0;
    string inFileLine;
    while (getline(grade_input, inFileLine)) {
        if (num_classes >= MAX_CLASSES) {
            cerr << "Too many classes in input file." << endl;
            return 1;
        }
        stringstream inGradeFile(inFileLine);
        inGradeFile >> classes[num_classes].subject;
        for (int i = 0; i < NUM_GRADES; i++) {
            inGradeFile >> classes[num_classes].grades[i];
        }
        num_classes++;
    }
    
    cout << "Welcome to your Grade Calculator\n";
    cout << "1. New Entry\n";
    cout << "2. Highest Course Average\n";
    cout << "3. Lowest Course Average\n";
    cout << "4. Calculate your Average\n";
    cout << "5. Exit\n";
    
    int choice;
    do {
        cout << "\nChoose an option: ";
        cin >> choice;
        
        switch (choice) {
                case 1: {
                    string new_subject;
                    cout << "Enter the name of the new subject: ";
                    cin >> new_subject;
                
                    double new_grades[NUM_GRADES];
                    cout << "Enter the grades for the new subject: ";
                    for (int i = 0; i < NUM_GRADES; i++) {
                        cin >> new_grades[i];
                    }
                    if (num_classes >= MAX_CLASSES) {
                        cerr << "Cannot add new class: maximum number of classes reached." << endl;
                        break;
                    }
                    Class& new_class = classes[num_classes];
                    new_class.subject = new_subject;
                    for (int i = 0; i < NUM_GRADES; i++){
                        new_class.grades[i] = new_grades[i];
                    }
             //       calculateAndWriteAverages(ifstream& grade_input, ofstream& grade_output, Class  classes[], int num_classes);
                    break;
                }
                case 2: {
            // Find the class with the highest average grade
                    int max_sort = -1;
                    double max_avg_grade = -1.0;
                    for (int i = 0; i < num_classes; i++) {
                        double sum = 0.0;
                    for (int j = 0; j < NUM_GRADES; j++) {
                        sum += classes[i].grades[j];
                    }
                    double avg_grade = sum / NUM_GRADES;
                    if (avg_grade > max_avg_grade) {
                        max_sort = i;
                        max_avg_grade = avg_grade;
                        }
                    }
    
                    // Output the class with the highest average grade
                    if (max_sort == -1) {
                    cout << "No classes found." << endl;
                    } else {
                    cout << "Class with highest average grade: " << classes[max_sort].subject << endl;
                    }
                    break;
                }
                case 3: {
           
                    int min_sort = -1;
                    double min_avg_grade = 101.0;
                    for (int i = 0; i < num_classes; i++) {
                        double sum = 0.0;
                        for (int j = 0; j < NUM_GRADES; j++) {
                            sum += classes[i].grades[j];
                        }
                        double avg_grade = sum / NUM_GRADES;
                        if (avg_grade < min_avg_grade) {
                            min_sort = i;
                            min_avg_grade = avg_grade;
                        }
                    }
                    if (min_sort == -1) {
                        cout << "No classes found." << endl;
                    } else {
                        cout << "Class with lowest average grade: " << classes[min_sort].subject << endl;
                    }
                    break;
                }
                case 4: {

                    if (num_classes == 0) {
                        cerr << "No classes to calculate average." << endl;
                        break;
                    }
                
                    double sum = 0.0;
                    int num_grades = num_classes * NUM_GRADES;
                    for (int i = 0; i < num_classes; i++) {
                        for (int j = 0; j < NUM_GRADES; j++) {
                            sum += classes[i].grades[j];
                        }
                    }
                
                    double overall_avg = sum / num_grades;
                
                    for (int i = 0; i < num_classes; i++) {
                        Class& vector = classes[i];
                        double sum = 0.0;
                        for (int j = 0; j < NUM_GRADES; j++) {
                            sum += vector.grades[j];
                        }
                        double avg_grade = sum / NUM_GRADES;
                        cout << vector.subject << ": "
                             << fixed
                             << setprecision(2)
                             << avg_grade
                             << endl;
                    }
                
                    cout << "Overall average: " << fixed << setprecision(2) << overall_avg << endl;
                    break;
                }

                    case 5:
                        cout << "Goodbye!" << endl;
                        break;
                    //}
                    default:
                        cout << "Fatal error! Please choose a correct option!" << endl;
                        break;
                }
        } while (choice != 5);

    grade_input.close();
    grade_output.close();

    return 0;
}
void calculateAndWriteAverages(ifstream& grade_input, ofstream& grade_output, Class  classes[], int num_classes){
        for(int i = 0; i < num_classes; i++){
                Class& vector = classes[i];
                double sum = 0.0;
                for(int j = 0; j < NUM_GRADES; j++) {
                        sum += vector.grades[j];
                }
                double avg_grade = sum / NUM_GRADES;
                grade_output << vector.subject << ": "
                             << fixed
                             << setprecision(2)
                             << avg_grade
                             << endl;
         }
}



