#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 50
//#define MAX 100

 typedef struct{
        char item[SIZE];
  // int entry[i];
        double quantity;
        double cost;
}inventory;

int menu(void);
int displayOptions(void);
void Display(inventory entry[], int size);
void AddNewEntry(inventory entry[], int *size);
void SaveInventory(inventory br[], int *size);

int main()
{
       int *size;
        int choice = 0;
        int entry=0;
    // inventory entry [SIZE];
        int size=0;

     // enterChoice();
       displayOptions();
        selection = menu();


//      printf("\nInventory before: %d", size);
//      defaultEntry(entry, &size);
//      printf("\nInventory after: %d\n\n", size);
//
        choice = menu();

        while(choice!= 5)
        {
                if(choice == 1)
                {
                        printf("Show Inventory:\n\n");
                //      \n\n");
                //      scanf("%s", entry[*size].item
        //      fscanf("
                        AddNewEntry( entry, &size);
                    break
                }
                else if(choice == 2)
                {
                        printf("DISPLAYING INVENTORY\n\n");
                        Display(entry, size);
                
                    break;
                }
                else if(choice == 3)
                        printf("Initializing input table\n\n");
                        AddNewEntry(entry, &size);
                    break;
        }
                else if(choice==4)
               {
                       printf("Saving item to inventory file...\n\n");
                       SaveInventory(entry, &size);
                    break;
               }
               else{
                    printf("Enter valid selection!\n\n");
                
                   break;
               }
              printf("\n\n");
              DisplayOptions();
              choice = menu();
    	}
	fwrite(*size)
  
   // {
   //         printf("\t\tThank you for using the tool inventory!!!\n\n");
 //   }
	return 0;

}
//Display menu
int displayOptions(void)
{
	int choice;
	printf("\nEnter Choice:\n");
	
 //   while(choice=>1 && choice <=5)
        //printf("\n*********************************************\n\n");
      //  printf("HELLO, WELCOME TO THE INVENTORY PROGRAM.\n");
        printf("\nEnter Inventory option:\n");
        printf("\n1 - Load Inventory\n");
        printf("\n2 - Show Inventory\n");
        printf("\n3 - Add an Item\n");
        printf("\n4 - Save \n");
        printf("\n5 - \"Exit\"\n");
       // printf("\n*********************************************\n\n");
        
    scanf("%d", &choice);
    return choice;
//;

}
void loadInventory(inventory br[], int *size)
{
    FILE *outPtr;
    
//  while(!feof(outPtr)){
        
        if((outPtr = fopen("inventory.txt","r"))==NULL)
        {
            printf("CANNOT OPEN FILE\n");
            return;
        }

        outPtr = fopen("inventory.txt","r+");
        fscanf(outPtr,"%d",size);
        fread(br, sizeof(inventory),*size,outPtr);
    
        fclose(outPtr);
}           
int displayInventory(inventory entry[SIZE], int size)
{
      int i;
  //    int entry[i];
  //    for (*size=i;i<size; i++)
                        {
                        printf("\n");
                        printf("Item:\t\t %s\n", entry[].);
                        printf("Quantity:\t\t %d\n", entry[].quantity);
                        printf("Price:\t\t %0.2f\n", entry[].cost);
                *size = *size + 1;
        
}

void AddNewEntry(inventory entry[i], int *size)
{
    int *size = 0;
    
    int i;
    for (i = 0; i<size; i=size++);
    {
        printf("\nEnter Item:\t\t");
        scanf("%s",inventory entry[*size].item);
        printf("\nEnter Quantity:\t\t");
        scanf("%d", entry[*size].quantity);
        printf("\nEnter Price:\t\t");
        scanf("%lf", entry[*size].quantity)
    }
    //while(*size = *size + 1);
}
int EditMenuOptions(void)
{
    int choice;

    printf("\nENTER 1 TO EDIT ITEM\n");
    printf("\n1. TO EDIT Quantity\n");
    printf("\n2. ENTER 3 TO EDIT COST\n");
//  printf("ENTER 4 TO EDIT COMPANY\n");
 // printf("ENTER 5 TO EDIT PRICE\n");
 // printf("ENTER 6 TO EDIT NUMBERS IN STOCK\n");
//  printf("ENTER 7 TO EDIT ALL DATA\n");
//  printf("\nENTER SELECTION: ");
    scanf("%d", &choice);
    return choice;
}
void SaveInventory(inventory br[], int *size)
{
    FILE *outp;

    if((outp = fopen("inventory.txt","w"))==NULL)
    {
        printf("\nCANNOT OPEN FILE\n");
        return;
    }

        outp= fopen("inventory.txt","w");

    fprintf(outp,"%d", *size);
    fwrite(br, sizeof(inventory),*size,outp);

    
    fclose(outp);
}