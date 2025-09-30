#include <stdio.h>

typedef struct{
    char firstName[25];
    char lastName[25];
    double grades[5];
}students;

printData(students student[], int);
int loadData(students student[]);
void averageGrade(students student[], int i);

int main()
{
    students student[10];
    int numStudents = 0;
    numStudents = loadData(student);
    printData (student, numStudents);
    

    return 0;
}

printData(students student[], int numStudents)
{
    int i = 0;
    for(i = 0; i < numStudents; i++){
        printf("%s %s", student[i].firstName, student[i].lastName);
        averageGrade(student, i);
    }
}
int loadData(students student[])
{
    FILE *fh;
    int x = 0;
    
    if((fh = fopen("grades.txt", "r"))==NULL){
        printf("File is inaccessible!");
        return 1;
    }
    fscanf(fh, "%s%s%lf%lf%lf%lf%lf", student[x].firstName, student[x].lastName, &student[x].grades[0], &student[x].grades[1], &student[x].grades[2], &student[x].grades[3], &student[x].grades[4]);
    while(!feof(fh)){
        x = x + 1;
            fscanf(fh, "%s%s%lf%lf%lf%lf%lf", student[x].firstName, student[x].lastName, &student[x].grades[0], &student[x].grades[1], &student[x].grades[2], &student[x].grades[3], &student[x].grades[4]);
    }
    fclose(fh);
    return x;
}
void averageGrade(students student[], int i){
        double average;
        double total = 0;
        int j;
            for (j = 0; j < 5; j++){
                total = total + student[i].grades[j];
            }
            average = total / 5;
            printf(" average = %.1f", average);
            if ( average > 90 && average <= 100)
                printf(" The average grade is: A\n");
            else if (average > 80 && average <= 90)
                printf(" The average grade is: B\n");
            else if (average > 70 && average <= 80)
                printf(" The average grade is: C\n");
            else if (average > 60 && average <= 70)
                printf(" The average grade is: D\n");
            else if (average < 60)
                printf(" The average grade is: F\n");
}
