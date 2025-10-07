#include <stdio.h>
#include <stdlib.h>

int threeGrades ();
void averageGrade(int []);
int maxGrade(int []);
int minGrade(int []);


int main(){
        int i, grade[3], min, max, choice;
        while(1){
        printf("1. Enter three grades: \n");
        printf("2. Show Avarage \n");
        printf("3. Show Highest Grade \n");
        printf("4. Show Lowest Grade \n");
        printf("5. Exit \n");
        printf("Enter Option:\n");
        scanf("%d", &choice);
        switch(choice){

        case 1: for (i = 0; i < 3; i++){
                        grade[i] = threeGrades();
                        }
                break;

        case 2: averageGrade(grade);
                break;

        case 3: max = maxGrade(grade);
                printf("The Highest Grade is: %d \n", max);
                break;

        case 4: min = minGrade(grade);
                printf("The Lowest Grade is: %d \n", min);
                break;

        case 5: exit(0);

        default: printf("error: Please Enter a Correct Choice!\n");
        }
}

return 0;

}
int threeGrades(){
        int grade;
        while(1){
        printf("Enter Grade between 1-100:");
        scanf("%d", &grade);
        if (grade >= 1 && grade <= 100 );
        return grade;
        }
}
void averageGrade(int grade[]){
        double average;
        double total = 0;
        int i;
        for (i = 0; i < 3; i++){
        total = total + grade[i];
}
average = total / 3;
printf("average = %.1f", average);
        if (average > 90 && average <= 100)
                printf("The average grade is: A");
        else if (average > 80 && average <= 90)
                printf("The average grade is: B");
        else if (average > 70 && average <= 80)
                printf("The average grade is: C");
        else if (average > 60 && average <= 70)
                printf("The average grade is: D");
        else if (average < 60)
                printf("The average grade is: F");
}
int maxGrade(int grade[]){
int i;
int max;
max = grade[0];
 for (i = 0; i < 3; i++){
        if (grade[i] > max)
        max = grade[i];
        }
return max;
}
int minGrade(int grade[]){
int i;
int min;
min = grade[0];
        for (i = 0; i < 3; i++){
        if (grade[i] < min)
        min = grade[i];
        }
return min;
}
