#include <stdio.h>                                                                                                                                                              

int main(void)
{
        printf("Your Wage for this Week\n");
        int choice;
        double managerWeeklySalary = 1000.00;
        double hourlyWage = 15;
        double numberOfHours, fullTimeHours, overTimeHours;
        double commissionBase = 250;
        double grossWeeklySales;
        double salary;
        double pieceAmount = 1.5;
        int piecesNum;

        do{
                printf("1. Manager\n");
                printf("2. Employee\n");
                printf("3. Commission Worker\n");
                printf("4. Piece Worker\n");
                printf("5. Exit\n");
                scanf("%d", &choice);

        switch(choice){

                case 1:

                        printf("Your Weekly Salary is: %lf\n", managerWeeklySalary);
                        break;

                case 2:

                        printf("Employee\n");
                        printf("Enter the number of hours worked:");
                        scanf("%lf", &numberOfHours);

                        if(numberOfHours > 40){

                        fullTimeHours = 40;
                        overTimeHours = numberOfHours - 40;
                        }

                        else{
                        fullTimeHours = numberOfHours;
                        overTimeHours = 0;
                        }

                        salary = fullTimeHours * hourlyWage + overTimeHours * hourlyWage * 1.5;
                        printf("Your Weekly Salary is: %.2f\n", salary);
                        break;

                case 3:

                        printf("Enter Your Weekly Sales:\n");
                        scanf("%lf", &grossWeeklySales);
                        salary = commissionBase + grossWeeklySales * 5.7/100;
                        printf("Your Weekly Salary is: %.2f\n", salary);
                        break;

                case 4:
                		printf("How many pieces did you make?\n");
                        scanf("%d", &piecesNum);
                        salary = piecesNum * pieceAmount;
                        printf("Your Weekly Salary is: %.2f\n", salary);
                        break;

                case 5:

                        printf("Goodbye!");
                        break;
                        }

        }while(choice!=5);

        return 0;

}