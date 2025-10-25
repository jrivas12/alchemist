#include <stdio.h>

struct record{
        int inputMovie;
        char title[25]/*(dataInput)*/;
        char dir[25];
        char date[11];
        int length;
}movieArray[3];

int archMenu();
//int displayMov( void );
void dataMenu(int i);
void printMovie(int recordNum);
void printArchive(int recordNum);
//void readMovie( FILE *fMov);
//void newMovie( FILE *fMov );

void printArchive(int recordNum);
int main() { 
        //FILE *fMov;
        int dataInput=0;
        int recordNum = 0;
        //open
        //read movie
        int choiceData=0;
        do{
                dataInput = archMenu();
                switch(dataInput){
                        case 1:
                                printf("Initializing archive tools: \n");
                                dataMenu(recordNum);
                                recordNum++;
                                break;
                        case 2:
                                printf("Display Movie Data: \n");
                                printMovie(recordNum);
                                recordNum++;
                                break;
                        case 3:
                                printf("Listing All Archive Data: \n");
                                break;
                        case 4:
                                printf("Thanks for using the movie library.\n\n");
                                break;
                        default:
                                printf("error: Please enter a correct option!\n");
                                break;    
                    
                        
                        }   
                   
                }while(dataInput!=4);
                //riteto filer(file);
                //readmovie
        
        return 0;
}
int archMenu() {
//1. determinant menu
        //double dataInput;
        int choice=0;
        printf("Welcome to the Movie Library!\n");
        printf("**************************\n");
        printf("\nEnter Option\n");
        printf("\n1) Insert Movie Record\n");
        printf("\n2) List Movie\n");
        printf("\n3) Movie Catalog\n");
        printf("\n4) Exit?\n");
        printf("**************************\n");
     do{
                printf("Option: \n");
                scanf("%d", &choice);
      }while(choice<1 || choice>4);
        return choice;
}

void dataMenu(int i) {
/*1A newMov data input*/
        while((getchar())!='\n');
        printf("\t\tEnter Movie Title: ");
        fgets(movieArray[i].title,25, stdin);
        while((getchar())!='\n');
        printf("\t\tEnter Director: ");
        fgets(movieArray[i].dir,25, stdin);
        fflush(stdin);
        while((getchar())!='\n');
        printf("\t\tEnter Release Date: ");
        fgets(movieArray[i].date, 11, stdin);
        //scanf("%s",&movieArray[i].date);
        printf("\t\tEnter Length: ");
        scanf("%d",&movieArray[i].length);
}
//printmovie
void printMovie(int recordNum){
    if (recordNum<0){
        printf("Title: %s\n", movieArray[recordNum-1].title);
        printf("Director: %s\n", movieArray[recordNum-1].dir);
        printf("Date: %s\n", movieArray[recordNum-1].date);
        fprintf("Length: %d\n", movieArray[recordNum-1].length);
    }
    else
        printf("No movie found");
}
void printArchive(int recordNum){
    if(recordNum>0){
        for(int i=0; i<recordNum; i++){
            printf("Title: %s\n", movieArray[i].title);
            printf("Director: %s\n", movieArray[i].dir);
            printf("Date: %s\n", movieArray[i].date);
            printf("Lenght: %d\n", movieArray[i].length);
        }
    }
}

//void record( FILE *newMov)
//{
//    FILE *fMov; 
//    struct inputData record = { 0, 0, 0, 0 };

 
//    if ( ( newMov = fopen( "fmov.txt", "w" ) ) == NULL ) {
//        printf( "File could not be opened.\n" );
//    } 
 //   else {
//        rewind( readMov ); 
//        fprintf( newMov   , "title",
//                "dir", "date", "lenght");
//
//        while ( !feof( newMov ) ) {
//            fread( &record, sizeof( struct record ), 1, newMov );
//            
//            if (record.movie != 0 ) {
//                fprintf( newMov, "%-c%-c%-d%d\n",
//                        record.tille, record.dir, record.date, record.lengh );       
//            } 
//        } 
//     fclose( newMov );
//   } 
//  } 