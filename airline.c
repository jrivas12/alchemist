#include <stdio.h>

int main()
{
int r[]={0,0,0,0,0,0,0,0,0,0}; 
int n=0;
while(n<10){
int myNum;
int mySeat=0;


printf("Choose the arrangement you want \n");
printf("Enter 1 for first class\n");
printf("Enter 2 for economy class\n");
scanf("%d", &myNum);



if (myNum==1){
printf("You chose  first class\n");
  for(int i=0;i<5;i++){
      if(r[i]==0){
         mySeat=i+1;
         r[i]=1;
        printf("Your sit number is %d",mySeat);
        printf("\n");
         break;
      }
  }
  if(mySeat==0){printf("All seats are full\n");}
}
else if(myNum==2){
printf("You choose economy class\n");
for(int i=5;i<=9;i++){
      if(r[i]==0){
         mySeat=i+1;
         r[i]=1;
         printf("Your sit number is %d",mySeat);
         printf("\n");
         break;
      }
      
  }
  if(mySeat==0){printf("All seats are full\n");}
}
    
}
    return 0;
}


        