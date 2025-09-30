#include <stdio.h>

struct record{
        int inputMovie;
        char title[25];
        char dir[25];
        char date[11];
        char length[5];
}movieArray[3];

int choiceData=0;
int archMenu();
void dataMenu(int i);
void printArchive(int recordNum);

int main(void) {

        FILE * fp;
        int dataInput=0;
        int recordNum = 0;
        do{
                dataInput = archMenu();
                switch(dataInput){
                        case 1:
                                FILE * fp;
                                fp = fopen("movie.txt", "r+");
                                printf("Initializing movie one input: \n");
                                dataMenu(recordNum);
                                recordNum++;
                                fprintf;
                                break;
                        case 2:
                                FILE * twofp;
                                twofp=fopen("movie.txt","r+");
                                printf("Initializing movie two input: \n");
                                dataMenu(recordNum);
                                recordNum++;
                                fclose;
                        case 3:
                                FILE * threefp;
                                threefp = fopen("movie.txt", "r+");
                                printf("Initializing movie three input: \n");
                                dataMenu(recordNum);
                                recordNum++;
                                fprintf;
                                break;
                        default:
                                printf("Fatal error! Try Again. \n");

                          }
                        }while(dataInput!=4);
                fclose!=feof;
}
int archMenu() {
        FILE * fp, twofp, threefp;
        int fscanf(FILE * fp);
        fp = fopen("movie.txt", "w+");

        int choice=0;
        printf("Welcome to the Movie Library!\n");
        printf("**************************\n");
        printf("\nEnter Option\n");
                                                                                                                                                                                                                           62,28-35      Top
                              
                                FILE * threefp;
                                threefp = fopen("movie.txt", "r+");
                                printf("Initializing movie three input: \n");
                                dataMenu(recordNum);
                                recordNum++;
                                fprintf;
                                break;
                        default:
                                printf("Fatal error! Try Again. \n");

                          }
                        }while(dataInput!=4);
                fclose!=feof;
}
int archMenu() {
        FILE * fp, twofp, threefp;
        int fscanf(FILE * fp);
        fp = fopen("movie.txt", "w+");

        int choice=0;
        printf("Welcome to the Movie Library!\n");
        printf("**************************\n");
        printf("\nEnter Option\n");
        printf("\n1) Insert Movie One\n");
        printf("\n2) Insert Movie Two\n");
        printf("\n3) Insert Movie Three\n");
        printf("\n4) Exit?\n");
        printf("**************************\n");
        do{
                printf("Option: \n");
                scanf("%d", &choice);
        }while(choice<1 || choice>4);
        return choice;
}
void dataMenu(int i) {
        FILE *fp;
        int fscanf(FILE *fp);
        fp = fopen("movie.txt", "w+");
        fopen("movie.txt", "a+");
        while(choiceData>=1 && choiceData<=4 && choiceData!=5);
        while((getchar())!='\n');
        printf("\t\tEnter Movie Title: ");
        fgets(movieArray[i].title,25, stdin);
        while((getchar())!='\n');
        printf("\t\tEnter Director: ");
        fgets(movieArray[i].dir,25, stdin);
        while((getchar())!='\n');
        printf("\t\tEnter Release Date: ");
        fgets(movieArray[i].date,11, stdin);
        fflush(stdin);
        while((getchar())!='\n');
        printf("\t\tEnter Length: ");
        fgets(movieArray[i].length, 5, stdin);

        fprintf;
        //while(feof!=5);
}
