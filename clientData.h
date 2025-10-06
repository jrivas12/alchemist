#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include <stdio.h>

struct clientData {
    int acctNum;
    char lastName[15];
    char firstName[10];
    double balance;
};

/* function prototypes */
int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);

#endif
