#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>

const int MAX_CLASSES = 25;
const int NUM_GRADES = 5;

struct Class {
    std::string name;
    double grades[NUM_GRADES];
};

void calculateAndWriteAverages(std::ifstream& input_file, std::ofstream& output_file, Class classes[], int num_classes) {
    for (int i = 0; i < num_classes; i++) {
        Class& class_obj = classes[i];
        
        // Calculate the average grade for the class
        double sum = 0.0;
        for (int j = 0; j < NUM_GRADES; j++) {
            sum += class_obj.grades[j];
        }
        double avg_grade = sum / NUM_GRADES;
        
        output_file << class_obj.name << ": " << std::fixed << std::setprecision(2) << avg_grade << std::endl;
    }
}

int main() {
    
    std::ifstream input_file("grades.txt");
    std::ofstream output_file("averages.txt");
    
    if (!input_file.is_open() || !output_file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }
    
    Class classes[MAX_CLASSES];
    int num_classes = 0;
    std::string line;
    while (std::getline(input_file, line)) {
        if (num_classes >= MAX_CLASSES) {
            std::cerr << "Too many classes in input file." << std::endl;
            return 1;
        }
        std::stringstream ss(line);
        ss >> classes[num_classes].name;
        for (int i = 0; i < NUM_GRADES; i++) {
            ss >> classes[num_classes].grades[i];
        }
        num_classes++;
    }
    
    std::cout << "Welcome to your Grade Calculator\n";
    std::cout << "1. New Entry\n";
    std::cout << "2. Highest Grade in Course\n";
    std::cout << "3. Lowest Grade in Course\n";
    std::cout << "4. Calculate your Average\n";
    std::cout << "5. Exit\n";
    
    int option;
    do {
        std::cout << "\nChoose an option: ";
        std::cin >> option;
        
        switch (option) {
            case 1: {
                // Get the name of the new subject
                std::string new_subject;
                std::cout << "Enter the name of the new subject: ";
                std::cin >> new_subject;
                
                // Get the grades for the new subject
                double new_grades[NUM_GRADES];
                std::cout << "Enter the grades for the new subject: ";
                for (int i = 0; i < NUM_GRADES; i++) {
                    std::cin >> new_grades[i];
                }
                
                // Add the new subject and grades to the end of the classes array
                if (num_classes >= MAX_CLASSES) {
                    std::cerr << "Cannot add new class: maximum number of classes reached." << std::endl;
                    break;
                }
                Class& new_class = classes[num_classes];
                new_class.name = new_subject;
                for (int i = 0; i < NUM_GRADES; i++){
                    new_class.grades[i] = new_grades[i];
                }
                
                // Write the updated averages to the output file
                calculateAndWriteAverages(input_file, output_file, classes, num_classes);
                break;
            }
            
            case 2: {
            // Find the highest grade in the classes array
            double highest_grade = 0.0;
            std::string highest_grade_class;
            for (int i = 0; i < num_classes; i++) {
                Class& class_obj = classes[i];
                for (int j = 0; j < NUM_GRADES; j++) {
                    if (class_obj.grades[j] > highest_grade) {
                        highest_grade = class_obj.grades[j];
                        highest_grade_class = class_obj.name;
                    }
                }
            }
            
            // Write the highest grade and class to the output file
            output_file << "Highest grade: " << highest_grade << " in " << highest_grade_class << std::endl;
            break;
        }
        case 3: {
            // Find the lowest grade in the classes array
            double lowest_grade = 100.0;
            std::string lowest_grade_class;
            for (int i = 0; i < num_classes; i++) {
                Class& class_obj = classes[i];
                for (int j = 0; j < NUM_GRADES; j++) {
                    if (class_obj.grades[j] < lowest_grade) {
                        lowest_grade = class_obj.grades[j];
                        lowest_grade_class = class_obj.name;
                    }
                }
            }
            
            // Write the lowest grade and class to the output file
            output_file << "Lowest grade: " << lowest_grade << " in " << lowest_grade_class << std::endl;
            break;
        }
        case 4: {
     if (num_classes == 0) {
        std::cerr << "No classes to calculate average." << std::endl;
        break;
    }

    // Calculate the overall average for all classes
    double sum = 0.0;
    for (int i = 0; i < num_classes; i++) {
        for (int j = 0; j < NUM_GRADES; j++) {
            sum += classes[i].grades[j];
        }
    }
    double overall_avg = sum / (num_classes * NUM_GRADES);

    output_file << "Overall Average: " << std::fixed << std::setprecision(2) << overall_avg << std::endl;

    std::cout << "Average grades have been written to averages.txt" << std::endl;
    break;
}

        case 5:
            // Exit the program
            break;
        default:
            std::cout << "Invalid option. Please choose a valid option." << std::endl;
            break;
    }
} while (option != 5);

// Close the input and output files
input_file.close();
output_file.close();

return 0;
}
