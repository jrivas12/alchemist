#include <stdio.h>
#define STUDENTS 2
#define EXAMS 4

int min(const int grades[] [EXAMS], int pupils, int test);
int max(const int grades[] [EXAMS], int pupils, int test);
double average(const int setOfGrades [], int test);
void printArray(const int grades[][EXAMS], int pupils, int test);


int main (void){

int student;

const int studentGrades[STUDENTS][EXAMS]=
{{77, 68, 86, 73},
{96, 87, 89, 78},
{70, 90, 86, 81}};

printf("The array is:\n");
printArray(studentGrades, STUDENTS, EXAMS);

printf("\n\nLowest grade: %d\nHighest grade:%d\n",
min(studentGrades, STUDENTS, EXAMs),
max(studentGrades, STUDENTS, EXAMS));
    for(student = 0;student < STUDENTS; student++){
        printf("The average grade for student %d is %.2f\n"), 
        student, average(studentGrades[student], EXAMS));
    }
return 0;
}
int min(const int grades[][EXAMS], int pupils, int tests)
{
int i;
int j;
int lowGrade = 100;

for (i = 0; i < pupils; i++){
            
    for(j = 0; j < tests; j++){
            
        if( grades[i][j] < lowGrade ){
            lowGrade = grades[i][j];
            }
        }
    }
return lowGrade;
}
int min(const int grades[][EXAMS], int pupils, int tests)
{
int i;
int j;
int highGrade = 0;
for (i = 0; i < pupils; i++){
    for(j = 0; j < tests; j++){
        if(grades[i][j] > highGrade){
            highgrade = grades [i][j];
            }
        }
    }
return highGrade;
}     