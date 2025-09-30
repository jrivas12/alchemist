#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STUDENTS 100
#define STRING_LENGHT 255
#define TEST_SCORES 7
#define TRUE 1
#define FALSE 0



// METHOD 1 : REMOVING EXTRA WHITE SPACE
typedef struct {

    char name[STRING_LENGHT];
    char letterGrade;
    int scores[TEST_SCORES];

} STUDENT;

char *trimString(char *string)
{
    char *end = NULL;

    while (isspace(*string)) string++;

    if (*string == 0)
        return string;

    end = string + strlen(string) - 1;

    while (end > string && isspace(*end))
        end--;

    *(end + 1) = 0;

    return string;

}

// METHOD 2 : READ FROM INPUT FILE
int loadStudents(char *filename, STUDENT students[MAX_STUDENTS], int *numStudents)
{
    FILE *inFile = NULL;

    char *tokenizer = NULL;
    char line[STRING_LENGHT];
    char token[STRING_LENGHT];

    int i = 0;

    inFile = fopen(filename, "r");

    if (!inFile)
    {
        printf("FAIL! Cannot open %s\n", filename);
        return FALSE;

    }

    *numStudents = 0;

    while (fgets(line, STRING_LENGHT, inFile))
    {

        trimString(line);
        tokenizer = strtok(line,",");

        strcpy(token, tokenizer);
        strcpy(token, trimString(token));
        strcpy(students[*numStudents].name, token);

        for (i = 0; i < TEST_SCORES; i++)
        {
            tokenizer = strtok(NULL, ",");
            strcpy(token, tokenizer);
            strcpy(token, trimString(token));
            students[*numStudents].scores[i] = atoi(token);

        } 

        (*numStudents)++;

     } 

    return TRUE;

} 


// METHOD 3 : CALCULATING INDIVIDUAL STUDENT SCORE
double calculateGrade(int scores[TEST_SCORES])
{
    double weights[] = { 0.10, 0.10, 0.10, 0.10, 0.20, 0.15, 0.25 };
    double grade = 0;
    int i = 0;

    for (i = 0; i < TEST_SCORES; i++)
    grade += scores[i] * weights[i];

    return grade;

} 

   // METHOD 4 : CONVERTING FROM STUDENT TOTAL SCORE TO LETTER GRADE
char calculateLetterGrade(double grade)
{
//average = total / 3;
printf("average = %.1f", grade);
        if (grade > 90 && grade <= 100)
                printf("The average grade is: A");
        else if (grade > 80 && grade <= 90)
                printf("The average grade is: B");
        else if (grade > 70 && grade <= 80)
                printf("The average grade is: C");
        else if (grade > 60 && grade <= 70)
                printf("The average grade is: D");
        else if (grade < 60)
                printf("The average grade is: F");
    return grade;
}

// METHOD 5 : CALCULATING STUDENT GRADE
void calculateStudentGrades(STUDENT students[MAX_STUDENTS], int numStudents)
{
    int i = 0;

    for (i = 0; i < numStudents; i++)
        students[i].letterGrade = calculateLetterGrade(calculateGrade(students[i].scores));
}

// METHOD 6 : SORTING STUDENT NAME ALPHABETICALLY
void sortStudents(STUDENT students[MAX_STUDENTS], int numStudents)
{
    int i = 0;
    int j = 0;

    STUDENT temp;

    for (i = 0; i < numStudents - 1; i++)
    {
        for (j = i + 1; j < numStudents; j++)
        {
            if (strcmp(students[i].name, students[j].name) > 0)
            {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;

            } 
        }         
    }

}

// METHOD 7 : WRITING STUDENT LETTER GRADE TO OUTPUT FILE
int writeGrade(char *filename, char *inputFilename, STUDENT students[MAX_STUDENTS], int numStudents)

{
    FILE *outFile = NULL;
    int i = 0;

    outFile = fopen(filename, "w");

    if (!outFile)

    {
        printf("Error: failed to open %s\n", filename);
        return FALSE;

    } 

    fprintf(outFile, "Letter grade for %d students listed in file %s\n\n\n Here is the class average:\n\n", numStudents, inputFilename);

    for (i = 0; i < numStudents; i++)
        fprintf(outFile, "%s%c\n", strcat(students[i].name, ":"), students[i].letterGrade);

    fclose(outFile);
    return TRUE;

} 


// METHOD 8 : CALCULATING INDIVIDUAL TESTS AVERAGE
double calculateAverage(STUDENT students[MAX_STUDENTS], int numStudents, int scoreCategory)

{
    double sum = 0;
    int i = 0;

    for (i = 0; i < numStudents; i++)
        sum += students[i].scores[scoreCategory];

    return sum / numStudents;

}


// METHOD 9 : BUBBLE SORT AND EXTRACTING MINIMUM SCORE OF EACH TEST
int findMinimumScore(STUDENT students[MAX_STUDENTS], int numStudents, int scoreCategory)

{
    int min = -1;
    int i = 0;

    for (i = 0; i < numStudents; i++)
        if (min == -1 || students[i].scores[scoreCategory] < min)
            min = students[i].scores[scoreCategory];

    return min;

} 


// METHOD 10 : BUBBLE SORT AND EXTRACTING MAXIMUM SCORE OF EACH TEST
int findMaximumScore(STUDENT students[MAX_STUDENTS], int numStudents, int scoreCategory)
{
    int max = -1;
    int i = 0;

    for (i = 0; i < numStudents; i++)
        if (max == -1 || students[i].scores[scoreCategory] > max)
            max = students[i].scores[scoreCategory];

    return max;

}