#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct studentInfo
{
    string studentName;
    double studentGrade;
    string studentMajor;
};

void averageGrade(studentInfo student[]);

int main ()
{
    cout << "Please enter the file you wish to open:" << endl;
    string fileName;
    cin >> fileName;

    ifstream infile;
    infile.open("grades.txt");

    if (!infile)
    {
        cout << "Error! Cannot find specified file!" << endl;

        return 1;
    }

    studentInfo array[11];
    int i;

    for (int i = 0; i < 11; i ++)
    {
        infile >> array[i].studentName >>  array[i].studentGrade >>array[i].studentMajor;
    }

    for (int i = 0; i < 11; i++)
    {
        cout << array[i].studentName << " ";
        cout << array[i].studentGrade << " ";
        cout << array[i].studentMajor << "\n ";
    }

    return 0;
}
void averageGrade(studentInfo[] student[], int i){
        double average;
        double total = 0;
        int j;
            for (j = 0; j < 5; j++){
                total = total + studentInfo.array[i];
                //student[i] << endl;
            }
            average = total / 5;
            cout << " average", average;
            if ( average > 90 && average <= 100)
                cout << " The average grade is: A\n";
            else if (average > 80 && average <= 90)
                cout << " The average grade is: B\n";
            else if (average > 70 && average <= 80)
                cout << " The average grade is: C\n";
            else if (average > 60 && average <= 70)
                cout << " The average grade is: D\n";
            else if (average < 60)
                cout <<" The average grade is: F\n";
}
