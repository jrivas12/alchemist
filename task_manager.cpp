#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Task {
    int id;
    string category;
    string description;
    bool completed;
};

// Function to add a new task
void addTask(const string& username, const string& category, const string& description) {
    ifstream taskFile("tasks.txt");
    int taskId;
    string storedUsername;
    while (taskFile >> storedUsername >> taskId) {
        if (username == storedUsername) {
            taskId++;
        }
    }
    taskFile.close();

    ofstream outFile("tasks.txt", ios::app);
    outFile << username << " " << taskId << " " << category << " " << description << " " << false << endl;
    outFile.close();

    cout << "Task added successfully!" << endl;
}

// Function to display tasks
void displayTasks(const string& username) {
    ifstream taskFile("tasks.txt");
    string storedUsername;
    int taskId;
    string category, description;
    bool completed;
    while (taskFile >> storedUsername >> taskId >> category >> description >> completed) {
        if (username == storedUsername) {
            cout << "ID: " << taskId << endl;
            cout << "Category: " << category << endl;
            cout << "Description: " << description << endl;
            cout << "Status: " << (completed ? "Completed" : "Incomplete") << endl;
            cout << endl;
        }
    }
    taskFile.close();
}

// Function to mark a task as complete
void markTaskComplete(const string& username, int taskId) {
    vector<Task> tasks;
    ifstream taskFile("tasks.txt");
    string storedUsername;
    int storedTaskId;
    string category, description;
    bool completed;
    while (taskFile >> storedUsername >> storedTaskId >> category >> description >> completed) {
        if (username == storedUsername) {
            Task task = {storedTaskId, category, description, completed};
            tasks.push_back(task);
        }
    }
    taskFile.close();

    bool found = false;
    for (Task& task : tasks) {
        if (task.id == taskId) {
            task.completed = true;
            found = true;
            break;
        }
    }

    if (found) {
        ofstream taskFile("tasks.txt");
        for (const Task& task : tasks) {
            taskFile << username << " " << task.id << " " << task.category << " " << task.description << " " << task.completed << endl;
        }
        taskFile.close();
        cout << "Task marked as complete!" << endl;
    } else {
        cout << "Invalid task ID." << endl;
    }
}

// Function to delete a task
void deleteTask(const string& username, int taskId) {
    vector<Task> tasks;
    ifstream taskFile("tasks.txt");
    string storedUsername;
    int storedTaskId;
    string category, description;
    bool completed;
    while (taskFile >> storedUsername >> storedTaskId >> category >> description >> completed) {
        if (username == storedUsername && taskId != storedTaskId) {
            Task task = {storedTaskId, category, description, completed};
            tasks.push_back(task);
        }
    }
    taskFile.close();

    ofstream outFile("tasks.txt");
    for (const Task& task : tasks) {
        outFile << username << " " << task.id << " " << task.category << " " << task.description << " " << task.completed << endl;
    }
    outFile.close();
    cout << "Task deleted successfully!" << endl;
}

int main() {
    string username;
    string masterPassword = "123456789";

    while (true) {
        int option;
        cout << "Task Management System" << endl;
        cout << "1. Authenticate User" << endl;
        cout << "2. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        if (option == 1) {
            string password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (password == masterPassword) {
                while (true) {
                    int subOption;
                    cout << "1. Add Task" << endl;
                    cout << "2. Display Tasks" << endl;
                    cout << "3. Mark Task as Complete" << endl;
                    cout << "4. Delete Task" << endl;
                    cout << "5. Logout" << endl;
                    cout << "Choose an option: ";
                    cin >> subOption;

                    if (subOption == 1) {
                        string category, description;
                        cout << "Enter category: ";
                        cin >> category;
                        cout << "Enter description: ";
                        cin.ignore();
                        getline(cin, description);
                        addTask(username, category, description);
                    } else if (subOption == 2) {
                        displayTasks(username);
                    } else if (subOption == 3) {
                        int taskId;
                        cout << "Enter the ID of the task to mark as complete: ";
                        cin >> taskId;
                        markTaskComplete(username, taskId);
                    } else if (subOption == 4) {
                        int taskId;
                        cout << "Enter the ID of the task to delete: ";
                        cin >> taskId;
                        deleteTask(username, taskId);
                    } else if (subOption == 5) {
                        cout << "Logging out..." << endl;
                        break;
                    } else {
                        cout << "Invalid choice." << endl;
                    }
                }
            } else {
                cout << "Authentication failed!" << endl;
            }
        } else if (option == 2) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
