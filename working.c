#include <stdio.h>
#include <cstring>
              
struct record {                              
      char title[25];          /* account number */    
      char dir[ 25 ];  /* account last name */ 
      char date[ 11 ]; /* account fi+rst name */
      char length[5];       /* account balance */   
};

int main(){
    
    FILE *cfPtr;
       
    if ((cfPtr = fopen ("movie.txt", "r+") ) == NULL){
        puts("Fatal error...\n");
    //    exit(1);
   }
  //
       
    //printf("1. Movie One\n");
    //fputs("2. Movie Two\n");
    //puts("3. Movie Three\n");
    //fputs("Enter \"Exit\"");
          
      
    int i=0;
       //printf("Enter \"exit\" as Title for exit.");
    //se{
            struct record movieArray[3];
       while(!feof(cfPtr)){
       {
           //do{
          while((getchar())!='n');
          printf("%s", "\nEnter Title");
          fgets(movieArray[i].title, 25, stdin);
          fflush(stdin);
          while((getchar())!='n');
          printf("%s", "\nEnter Director");
          fgets(movieArray[i].dir, 25, stdin);
          fflush(stdin);
          while((getchar())!='n');
          printf("%s", "\nEnter Date");
          fgets(movieArray[i].date, 11, stdin);
        //fflush(stdin);
        //while((getchar())!='n');
          printf("%s", "\nEnter Title");
          fgets(movieArray[i].length, 5,stdin);
          fflush(stdin);
          
          
         //if (fwrite(movieArray[i].title, "exit") == 0);
          //  exit(1);
          //  do{
          
         fwrite(&movieArray[i], sizeof(struct record movieArr[i]
       }
    

    }fclose(cfPtr);
      //eturn 0;
   }