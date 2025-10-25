#include <stdio.h>
#include <string.h>
#define SIZE 50

typedef struct {
    char name[SIZE];
    int quantity;
    double cost;
} Inventory;

int menu(void);
void Display(Inventory entry[], int size);
void AddNewEntry(Inventory entry[], int *size);
void SaveInventory(Inventory entry[], int size);
void LoadInventory(Inventory entry[], int *size);

int main(void)
{
    Inventory entry[SIZE];
    int size = 0;
    int selection;

    while (1) {
        selection = menu();

        if (selection == 1) {
            printf("\nLoading inventory...\n");
            LoadInventory(entry, &size);
        }
        else if (selection == 2) {
            printf("\nDisplaying inventory...\n");
            Display(entry, size);
        }
        else if (selection == 3) {
            printf("\nAdding new entry...\n");
            AddNewEntry(entry, &size);
        }
        else if (selection == 4) {
            printf("\nSaving inventory...\n");
            SaveInventory(entry, size);
        }
        else if (selection == 5) {
            printf("\nExiting program. Goodbye!\n");
            break;
        }
        else {
            printf("\nInvalid selection! Please try again.\n");
        }

        printf("\n--------------------------------------\n");
    }

    return 0;
}

/* ==============================
   MENU FUNCTION
   ============================== */
int menu(void)
{
    int selection;
    printf("\n======================================\n");
    printf("      WELCOME TO THE INVENTORY TOOL\n");
    printf("======================================\n");
    printf("1 - Load Inventory from file\n");
    printf("2 - Display Inventory\n");
    printf("3 - Add New Item\n");
    printf("4 - Save Inventory to file\n");
    printf("5 - Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &selection);
    return selection;
}

/* ==============================
   ADD NEW ENTRY
   ============================== */
void AddNewEntry(Inventory entry[], int *size)
{
    if (*size >= SIZE) {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }

    printf("\nEnter Item Name:\t");
    scanf("%s", entry[*size].name);

    printf("Enter Quantity:\t\t");
    scanf("%d", &entry[*size].quantity);

    printf("Enter Price per Unit:\t");
    scanf("%lf", &entry[*size].cost);

    (*size)++;
    printf("\nItem added successfully!\n");
}

/* ==============================
   DISPLAY INVENTORY
   ============================== */
void Display(Inventory entry[], int size)
{
    if (size == 0) {
        printf("\nInventory is empty.\n");
        return;
    }

    printf("\n%-20s %-10s %-10s\n", "Item", "Quantity", "Price");
    printf("---------------------------------------------\n");

    for (int i = 0; i < size; i++) {
        printf("%-20s %-10d $%-10.2f\n",
               entry[i].name, entry[i].quantity, entry[i].cost);
    }
}

/* ==============================
   SAVE INVENTORY TO FILE
   ============================== */
void SaveInventory(Inventory entry[], int size)
{
    FILE *fp = fopen("inventory.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    fprintf(fp, "%d\n", size);
    for (int i = 0; i < size; i++) {
        fprintf(fp, "%s %d %.2f\n",
                entry[i].name, entry[i].quantity, entry[i].cost);
    }

    fclose(fp);
    printf("Inventory saved to 'inventory.txt'.\n");
}

/* ==============================
   LOAD INVENTORY FROM FILE
   ============================== */
void LoadInventory(Inventory entry[], int *size)
{
    FILE *fp = fopen("inventory.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    fscanf(fp, "%d", size);
    for (int i = 0; i < *size; i++) {
        fscanf(fp, "%s %d %lf",
               entry[i].name, &entry[i].quantity, &entry[i].cost);
    }

    fclose(fp);
    printf("Inventory loaded successfully from 'inventory.txt'.\n");
}
