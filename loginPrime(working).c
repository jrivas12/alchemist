#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_SCHEDULE_LENGTH 20
#define MAX_TASKS 100
#define MAX_EMPLOYEES 5

struct Employee {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct Employee employees[] = {
    { "John", "123456" },
    { "Joe", "123456" },
    { "Martha", "123456" },
    { "Edward", "123456" },
    { "Sarah", "123456" }
};

struct Task {
    int id;
    char description[100];
    int status;
};


struct Task schedule[MAX_SCHEDULE_LENGTH];
struct Task tasks[MAX_TASKS];

int numEmployees = sizeof(employees) / sizeof(employees[0]);
char loggedInUser[MAX_USERNAME_LENGTH];

void login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < numEmployees; i++) {
        if (strcmp(username, employees[i].username) == 0 && strcmp(password, employees[i].password) == 0) {
            strcpy(loggedInUser, username);
            printf("Login successful!\n");
            return;
        }
    }

    printf("Invalid username or password.\n");
}

void viewSchedule() {
    printf("----- Schedule -----\n");

    char filename[50];
    sprintf(filename, "%s_tasks.txt", loggedInUser); // Constructing the filename

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening task file.\n");
        return;
    }

    int id, status;
    char description[100];

    while (fscanf(file, "%d ", &id) != EOF) {
        fgets(description, sizeof(description), file);
        fscanf(file, "%d", &status);
        fgetc(file); // Read the newline character

        printf("%d %s %d\n", id, description, status);
    }

    fclose(file);
}




void addTask() {
    int id;
    char description[100];

    printf("Enter the task ID: ");
    scanf("%d", &id);
    printf("Enter the task description: ");
    scanf(" %[^\n]s", description);

    int index = -1;
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].id == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        tasks[index].id = id;
        strcpy(tasks[index].description, description);
        tasks[index].status = 1;

        char filename[50];
        sprintf(filename, "%s_tasks.txt", loggedInUser);
        FILE *file = fopen(filename, "a");
        if (file != NULL) {
            fprintf(file, "%d %s %d\n", id, description, 1);
            fclose(file);
            printf("Task added successfully!\n");
        } else {
            printf("Error opening task file.\n");
        }
    } else {
        printf("Task storage is full. Cannot add more tasks.\n");
    }
}


void removeTask() {
    int id;

    printf("Enter the task ID to remove: ");
    scanf("%d", &id);

    char filename[50];
    sprintf(filename, "%s_tasks.txt", loggedInUser);
    FILE *file = fopen(filename, "r+");
            if (file != NULL) {
                for (int j = 0; j < MAX_TASKS; j++) {
                    if (tasks[j].id != 0) {
                        fprintf(file, "%d %s %d\n", tasks[j].id, tasks[j].description, tasks[j].status);
                    }
                }
                fclose(file);
                printf("Task removed successfully!\n");
                return;
            } else {
                printf("Error opening task file.\n");
                return;
            }
        }
    //}

//    printf("No task found with the specified ID.\n");
//}
int main() {
    login();

    if (strlen(loggedInUser) == 0) {
        printf("Authentication failed. Exiting...\n");
        return 0;
    }

    int choice;
    do {
        printf("\n----- Employee Scheduler -----\n");
        printf("1. View Schedule\n");
        printf("2. Add Task\n");
        printf("3. Remove Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewSchedule();
                break;
            case 2:
                addTask();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
