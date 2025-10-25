#include <stdio.h>

struct record{
        int inputMovie;
        char title[25];
        char dir[25];
        char date[11];
        int length;
}movieArray[3];

int choiceData=0;
void write movie(FILE *movieArr[3])

int archMenu() {

       FILE *cfPtr

       //for(( cfPtr = fopen("program4.txt", "w"))==NULL)
                printf("file inaccessible!");
       
       // determinant menu

        int choice=0;
        printf("Welcome to the Movie Library!\n");
        printf("**************************\n");
        printf("\nEnter Option\n");
        printf("\n1) Insert Movie Record\n");
        printf("\n2) List Movie\n");
        printf("\n3) Movie Catalog\n");
        printf("\n4) Exit?\n");
        printf("**************************\n");
                while((getchar())!='\n');
            printf("\t\t1. Enter Movie Title: ");
        
        fgets(movieArray[i].title,25, stdin);
        //fflush(stdin);
        
        while((getchar())!='\n');
            printf("\t\tEnter Director: ");
        
        fgets(movieArray[i].dir,25, stdin);
        fflush(stdin);
        
        while((getchar())!='\n');
            printf("\t\tEnter Release Date: ");
        
        fgets(movieArray[i].date,11, stdin);
        fflush(stdin);
        printf("\t\tEnter Length: ");
        scanf("%d",&movieArray[i].length);
        
        while((getchar())!= '\n');
            printf("Exit(0)?");
        //exit(0);
}
     do{
                printf("Option: \n");
                scanf("%d", &choice);
      }while(choice<1 || choice>4);
        return choice;
}

//write movie (default)
void dataMenu(int i) {
        while((getchar())!='\n');
            printf("\t\t1. Enter Movie Title: ");
        
        fgets(movieArray[i].title,25, stdin);
        //fflush(stdin);
        
        while((getchar())!='\n');
            printf("\t\tEnter Director: ");
        
        fgets(movieArray[i].dir,25, stdin);
        fflush(stdin);
        
        while((getchar())!='\n');
            printf("\t\tEnter Release Date: ");
        
        fgets(movieArray[i].date,11, stdin);
        fflush(stdin);
        printf("\t\tEnter Length: ");
        scanf("%d",&movieArray[i].length);
        
        while((getchar())!= '\n');
            printf("Exit(0)?");
        //exit(0);
}
int main(void) {
    
    FILE* fptr;

    *fptr = fopen("program4.txt", "a");
    
    int dataInput=0;
    int recordNum = 0;
    
    // movie[3];
    
    //if(fptr!=NULL){
      //  while(fgets(movie, 3, fptr)){
        //    printf("%u","%d", "%d", movie, dataInput, recordNum);
       // }
   // }
    //else{
       // printf("file open unsuccesful");
    //}

     //   }
        
        do{
                dataInput = archMenu();
                switch(dataInput){
                        case 1:
                                printf("Insert Movie 1: \n");
                                dataMenu(recordNum);
                                recordNum++;
                                break;
                               
                        case 2:
                                printf("Insert Movie 2\n");
                                dataMenu(recordNum);
                                recordNum++;
                                break;
                                

                        case 3:
                                printf("Insert Movie 3\n\n");
                                dataMenu(recordNum);
                                recordNum++;
                                break;
                             
                        default:
                                printf("error: Please enter a correct option!\n");
                }
        }while(dataInput!=4);
       
        return 0;
}
   int archMenu( void )
   {
      int choice; /* variable to store user's choice */


      printf( "\nEnter your choice\n"
         "1 - First Movie \n"
         "    \"accounts.txt\" for printing\n"
         "2 - Second account\n"
         "3 - Third Movie \n"
         "4 - Exit\n?"
         "5 - end program\n? " );

      scanf( "%d", &Choice ); /* receive choice from user */

      return choice;

   } 
prototype read
void readMovie

prototype write