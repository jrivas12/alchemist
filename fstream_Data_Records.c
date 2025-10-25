#include <stdio.h>
#include <stdlib.h>

/* Structure definition */
struct clientData {
    int acctNum;
    char lastName[15];
    char firstName[10];
    double balance;
};

/* Function prototypes */
int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);

/* ==============================
   Main Function
   ============================== */
int main(void)
{
    FILE *cfPtr;
    int choice;

    /* Try to open file for read/write, create if missing */
    if ((cfPtr = fopen("credit.dat", "rb+")) == NULL) {
        if ((cfPtr = fopen("credit.dat", "wb+")) == NULL) {
            printf("File could not be opened.\n");
            return 1;
        }
    }

    /* Menu loop */
    while ((choice = enterChoice()) != 5) {
        switch (choice) {
        case 1:
            textFile(cfPtr);
            break;
        case 2:
            updateRecord(cfPtr);
            break;
        case 3:
            newRecord(cfPtr);
            break;
        case 4:
            deleteRecord(cfPtr);
            break;
        default:
            printf("Incorrect choice\n");
            break;
        }
    }

    fclose(cfPtr);
    return 0;
}

/* ==============================
   Display Menu
   ============================== */
int enterChoice(void)
{
    int menuChoice;
    printf("\nEnter your choice\n"
           "1 - store a formatted text file of accounts called\n"
           "    \"accounts.txt\" for printing\n"
           "2 - update an account\n"
           "3 - add a new account\n"
           "4 - delete an account\n"
           "5 - end program\n? ");
    scanf("%d", &menuChoice);
    return menuChoice;
}

/* ==============================
   Create Formatted Text File
   ============================== */
void textFile(FILE *readPtr)
{
    FILE *writePtr;
    struct clientData client = {0, "", "", 0.0};

    if ((writePtr = fopen("accounts.txt", "w")) == NULL) {
        printf("File could not be opened.\n");
        return;
    }

    rewind(readPtr);
    fprintf(writePtr, "%-6s%-16s%-11s%10s\n",
            "Acct", "Last Name", "First Name", "Balance");

    while (fread(&client, sizeof(struct clientData), 1, readPtr) == 1) {
        if (client.acctNum != 0) {
            fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n",
                    client.acctNum, client.lastName,
                    client.firstName, client.balance);
        }
    }

    fclose(writePtr);
    printf("accounts.txt created successfully.\n");
}

/* ==============================
   Update Record
   ============================== */
void updateRecord(FILE *fPtr)
{
    struct clientData client = {0, "", "", 0.0};
    int account;
    double transaction;

    printf("Enter account to update (1 - 100): ");
    scanf("%d", &account);

    fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
    fread(&client, sizeof(struct clientData), 1, fPtr);

    if (client.acctNum == 0) {
        printf("Account #%d has no information.\n", account);
    } else {
        printf("%-6d%-16s%-11s%10.2f\n\n",
               client.acctNum, client.lastName,
               client.firstName, client.balance);
        printf("Enter charge (+) or payment (-): ");
        scanf("%lf", &transaction);
        client.balance += transaction;

        printf("%-6d%-16s%-11s%10.2f\n",
               client.acctNum, client.lastName,
               client.firstName, client.balance);

        fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
        fwrite(&client, sizeof(struct clientData), 1, fPtr);
        fflush(fPtr);
    }
}

/* ==============================
   Delete Record
   ============================== */
void deleteRecord(FILE *fPtr)
{
    struct clientData client;
    struct clientData blankClient = {0, "", "", 0.0};
    int accountNum;

    printf("Enter account number to delete (1 - 100): ");
    scanf("%d", &accountNum);

    fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);
    fread(&client, sizeof(struct clientData), 1, fPtr);

    if (client.acctNum == 0) {
        printf("Account %d does not exist.\n", accountNum);
    } else {
        fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);
        fwrite(&blankClient, sizeof(struct clientData), 1, fPtr);
        fflush(fPtr);
        printf("Account %d deleted successfully.\n", accountNum);
    }
}

/* ==============================
   Add New Record
   ============================== */
void newRecord(FILE *fPtr)
{
    struct clientData client = {0, "", "", 0.0};
    int accountNum;

    printf("Enter new account number (1 - 100): ");
    scanf("%d", &accountNum);

    fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);
    fread(&client, sizeof(struct clientData), 1, fPtr);

    if (client.acctNum != 0) {
        printf("Account #%d already contains information.\n", client.acctNum);
    } else {
        printf("Enter last name, first name, balance\n? ");
        scanf("%s%s%lf", client.lastName, client.firstName, &client.balance);
        client.acctNum = accountNum;

        fseek(fPtr, (client.acctNum - 1) * sizeof(struct clientData), SEEK_SET);
        fwrite(&client, sizeof(struct clientData), 1, fPtr);
        fflush(fPtr);
        printf("Account #%d created successfully.\n", client.acctNum);
    }
}
