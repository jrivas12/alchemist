#include <stdio.h>

void checkGrade(int grade);
double average(int x, int y, int z);
int max(int x, int y, int z);
int min(int x, int y, int z);


int main()
{
    int gradeA=90;
    int gradeB=80;
    int gradeC=70;
    
    
    printf("1) Enter three grades: \n");
    printf("2) Show Avarage \n");
    printf("3) Show Highest Grade \n");
    printf("4) Show Lowest Grade \n");
    printf("5) Exit \n");
    

    return 0;
}

void checkGrade(int grade){
    
}

double average(int x, int y, int z){
    
    double average(x + y + z)/3;
    return average;
}
int max(int x, int y, int z){
    if (x >= y && x >= z)
    max = x;
    else if (y >=x && y >=z)
    max = y;
    else
    max = z;
}
int min(int x, int y, int z){
    
}
