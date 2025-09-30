
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 25
#define MAX 100

  typedef struct {
    char item[SIZE]; //item for the company
    char company[SIZE]; //company that sells the item
    int intStock; //how many of the item are instock
    char lastShipDate[SIZE]; //last ship date of that item
    double cost; //cost to make the item
    double price; //price of the item 
    } gaming;

//prompts the user to get a selection
int Menu(void);

//display the options to the user
void DisplayOptions(void);

//display some entries for inventory
void HardCodeEntries(gaming entry[],int *size);

//function to add a new entry to the inventory
void AddNewEntry(gaming entry[], int *size);

//function to delete a selected entry from inventory
void Delete(gaming entry[], int *size, int location);

//display the current inventory to screen
void Display(gaming entry[], int size);

//save the current inventory to file
void SaveInventory(gaming br[], int *size);

//clears out the entire inventory
void Clear(int *size);

//load the inventory from the file that is being saved
void LoadSalesRecords(gaming br[], int *size);

//find location of entry that is going to be edited or deleted
int FindLocation(gaming entry[], int size);

//display the options for editing an entry
int EditMenuOptions(void);

//function to edit selected entry
void Edit(gaming entry[], int location);

int main()
{
    int selection;
    gaming entry [150];
    int size=0;
    char trash;
    int choice;
    int location;

    //display size of inventory before and after
    printf("\nSIZE before: %d", size);
    HardCodeEntries(entry, &size);
    printf("\nSIZE after: %d\n\n", size);

    DisplayOptions();

    selection= Menu();

    while(selection != 8)
    {
          if (selection==1)
          { 
              printf("ADD ENTRIES\n\n");
              //display size of inventory before adding entries
              printf("\nSIZE BEFORE ADDING: %d\n", size);

              AddNewEntry(entry, &size);

              //display size of inventory after adding entries
              printf("\nSIZE AFTER ADDING: %d\n", size);
          }
          else if(selection==2)
          {
              printf("DELETE\n\n");
              //get location of entry to be deleted

              location = FindLocation(entry,size);
              printf("\nLOCATION: %d\n", location);

              Delete(entry, &size, location);
          }
          else if(selection==3)
          {
              printf("EDIT\n\n");

              //get the location of entry to be edited
              location = FindLocation(entry, size);

              printf("\nLOCATION: %d\n", location);
              Edit(entry, location);
          }
          else if(selection==4)
          {
              printf("DISPLAY OF INVENTORY\n\n");
              Display(entry, size);
          }
          else if(selection==5)
          {
              printf("SAVING CURRENT INVENTORY TO FILE\n\n");
              SaveInventory(entry, &size);
              //saves to file
          }
          else if(selection==6)
          {
              printf("CLEARING ENTIRE DATA\n\n");
              Clear(&size);
          }
          else if(selection==7)
          {
              printf("LOADING SALES RECORDS FROM FILE\n\n");
              LoadSalesRecords(entry, &size);
          }
          else
          {
              printf("COMMAND NOT RECOGNIZED\n\n");
          }

          printf("\n\n");
          DisplayOptions();

          //clears buffer
          scanf("%c", &trash);

          selection = Menu();
    }

    if (selection==8)
    {
        printf("\nHAVE A NICE DAY!!!\n\n");
    }
    return 0;
}

//display the options to the user
void DisplayOptions(void)
{
    printf("HELLO, WELCOME TO THE INVENTORY PROGRAM.\n");
    printf("THIS PROGRAM HOLDS INVENORY FOR ELECTRONICS COMPANIES ALONG WITH THEIR ITEMS, COST TO PRODUCE, PRICE,\n");
    printf("LAST SHIP DATE AND NUMBER IN STOCK\n");
    printf("THERE ARE COMPANIES IN THE INVENTORY ALREADY\n");
    printf("*********************************************\n\n");
    printf("HERE ARE YOUR OPTIONS\n");
    printf("1--ADD A NEW ENTRY\n");
    printf("2--DELETE AN ENTRY\n");
    printf("3--EDIT AN ENTRY\n");
    printf("4--DISPLAY THE INVENTORY\n");
    printf("5--SAVE CURRENT INVENTORY TO FILE\n");
    printf("6--CLEAR THE ENTIRE INVENTORY\n");
    printf("7--LOAD SALES RECORD FROM FILE\n");
    printf("8--QUIT\n");
}

//prompts the user to get a selection
int Menu(void)
{
    int selection;
    printf("\nENTER SELECTION: ");
    scanf("%d", &selection);

    return selection;
}

//display some entries for inventory
void HardCodeEntries(gaming entry[], int *size)
{
    strcpy(entry[0].item,"Xbox360");
    strcpy(entry[0].lastShipDate,"04/10/12");
    entry[0].cost=200.00;
    strcpy(entry[0].company,"Microsoft");
    entry[0].price=300.0;
    entry[0].intStock=150;

    *size = *size + 1;

    strcpy(entry[1].item,"PlayStation3");
    strcpy(entry[1].lastShipDate,"04/10/12");
    entry[1].cost=200.00;
    strcpy(entry[1].company,"Sony");
    entry[1].price=450.00;
    entry[1].intStock=100;

    *size = *size + 1;

    strcpy(entry[2].item,"XboxController");
    strcpy(entry[2].lastShipDate,"04/10/12");
    entry[2].cost=25.00;
    strcpy(entry[2].company,"Microsoft");
    entry[2].price=50.00;
    entry[2].intStock=50;

    *size = *size + 1;

    strcpy(entry[3].item,"PS3Controller");
    strcpy(entry[3].lastShipDate,"04/10/12");
    entry[3].cost=30.00;
    strcpy(entry[3].company,"Sony");
    entry[3].price=45.00;
    entry[3].intStock=50;

    *size = *size + 1;

    strcpy(entry[4].item,"Wii");
    strcpy(entry[4].lastShipDate,"04/10/12");
    entry[4].cost=100.00;
    strcpy(entry[4].company,"Nintendo");
    entry[4].price=200.00;
    entry[4].intStock=150;

    *size = *size + 1;

}

//function to add a new enty to the inventory
void AddNewEntry(gaming entry[], int *size)
{
    printf("\nENTER ITEM:\t\t");
    scanf("%s", entry[*size].item);

    printf("ENTER SHIP DATE:\t");
    scanf("%s", entry[*size].lastShipDate);

    printf("ENTER COST TO MAKE:\t\t");
    scanf("%lf", &entry[*size].cost);

    printf("ENTER COMPANY:\t\t");
    scanf("%s", entry[*size].company);

    printf("ENTER PRICE:\t\t");
    scanf("%lf", &entry[*size].price);

    printf("ENTER NUMBER IN STOCK:\t");
    scanf("%d", &entry[*size].intStock);

    *size = *size + 1;
}

//function to delete a selected entry from inventory
void Delete(gaming entry[], int *size, int location)
{
    entry[location] = entry[*size - 1];
    *size = *size - 1;
}

//display the current inventory onto the screen
void Display(gaming entry[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("\n");
        printf("ITEM:\t\t %s\n", entry[i].item);
        printf("LAST SHIP DATE:\t %s\n", entry[i].lastShipDate);
        printf("COST:\t\t %4.2f\n",entry[i].cost);
        printf("COMPANY:\t %s\n", entry[i].company);
        printf("PRICE:\t\t %4.2f\n", entry[i].price);
        printf("IN STOCK:\t %d\n", entry[i].intStock);
    }
}

//save the current inventory to a file
void SaveInventory(gaming br[], int *size)
{
    FILE *outp;

    if((outp = fopen("output.txt","w"))==0)
    {
        printf("\nCANNOT OPEN FILE\n");
        return;
    }

    //connect to the file
    outp= fopen("output.txt","w");

    fprintf(outp,"%d", *size);
    fwrite(br, sizeof(gaming),*size,outp);

    //close file pointer
    fclose(outp);
}

//clears out the entire inventory
void Clear(int *size)
{
    *size = 0;
}

//load the inventory from the file that is being saved
void LoadSalesRecords(gaming br[], int *size)
{
    FILE * inp;

    if((inp = fopen("output.txt","r"))==0)
    {
        printf("CANNOT OPEN FILE\n");
        return;
    }
    //connect to file
    inp = fopen("output.txt","r");

    fscanf(inp,"%d",size);
    fread(br, sizeof(gaming),*size,inp);

    //close file pointer
    fclose(inp);
}

//find location of entry that is going to be edited or deleted
int FindLocation(gaming entry[], int size)
{
    int i;
    int j;
    int length;
    char userItem[SIZE];

    //enter the item to delete
    printf("ENTER ITEM TO EDIT OR DELETE: ");
    scanf("%s", userItem);
    length = strlen(userItem);

    for(i=0; i<length; i++)
    {
        userItem[i] = toupper(userItem[i]);
    }
    printf("\nYOUR BRAND IN UPPER CASE IS:  %s\n", userItem);

    for(j=0; j<size; j++)
    {
        if(strcmp(entry[j].item,userItem)==0)
        {
            return j;
        }
    }
    return -1;
}

//function to edit a selected entry
void Edit(gaming entry[], int location)
{
    int choice;

    choice = EditMenuOptions();

    if(choice==1)
    {
        printf("\nENTER NEW ITEM: ");
        scanf("%s", &entry[location].item);
    }
    else if(choice==2)
    {
        printf("\nENTER SHIP DATE: ");
        scanf("%s", &entry[location].lastShipDate);
    }
    else if(choice==3)
    {
        printf("\nENTER COST TO MAKE: ");
        scanf("%lf", &entry[location].cost);
    }
    else if(choice==4)
    {
        printf("\nENTER COMPANY: ");
        scanf("%s", &entry[location].company);
    }
    else if (choice==5)
    {
        printf("\nENTER PRICE: ");
        scanf("%lf", &entry[location].price);
    }
    else if (choice==6)
    {
        printf("\nENTER HOW MANY IN STOCK: ");
        scanf("%d", &entry[location].intStock);
    }
    else if (choice==7)
    {

        printf("\nENTER NEW ITEM: ");
        scanf("%s", &entry[location].item);
        printf("\nENTER SHIP DATE: ");
        scanf("%s", &entry[location].lastShipDate);
        printf("\nENTER COST TO MAKE: ");
        scanf("%lf", &entry[location].cost);
        printf("\nENTER COMPANY: ");
        scanf("%s", &entry[location].company);
        printf("\nENTER PRICE: ");
        scanf("%lf", &entry[location].price);
        printf("\nENTER HOW MANY IN STOCK: ");
        scanf("%d", &entry[location].intStock);
    }
    else
    {
        printf("Invalid Entry");
    }
}

//display the options for edditing an entry
int EditMenuOptions(void)
{
    int choice;

    printf("\nENTER 1 TO EDIT ITEM\n");
    printf("ENTER 2 TO EDIT DATE\n");
    printf("ENTER 3 TO EDIT COST\n");
    printf("ENTER 4 TO EDIT COMPANY\n");
    printf("ENTER 5 TO EDIT PRICE\n");
    printf("ENTER 6 TO EDIT NUMBERS IN STOCK\n");
    printf("ENTER 7 TO EDIT ALL DATA\n");
    printf("\nENTER SELECTION: ");
    scanf("%d", &choice);
    return choice;
}