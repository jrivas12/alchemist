#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Employee {
    string username;
    string password;
};

struct Task {
    string description;
    bool isComplete;
};

class HRProgram {
private:
    vector<Employee> employees;
    Employee currentUser;

    void loadEmployeesFromFile() {
        ifstream file("users.txt");
        if (file.is_open()) {
            string username, password;
            while (file >> username >> password) {
                Employee employee;
                employee.username = username;
                employee.password = password;
                employees.push_back(employee);
            }
            file.close();
        }
    }

    void loadTasksFromFile(const string& filename, vector<Task>& tasks) {
        ifstream file(filename);
        if (file.is_open()) {
            string description;
            bool isComplete;
            while (file >> description >> isComplete) {
                Task task;
                task.description = description;
                task.isComplete = isComplete;
                tasks.push_back(task);
            }
            file.close();
        }
    }

    void saveTasksToFile(const string& filename, const vector<Task>& tasks) {
        ofstream file(filename);
        if (file.is_open()) {
            for (const Task& task : tasks) {
                file << task.description << " " << task.isComplete << endl;
            }
            file.close();
        }
    }

public:
    HRProgram() {
        loadEmployeesFromFile();
    }

    void run() {
        bool HRProgram = false;
        login();
        while (true) {
            if (isAdmin()) {
                displayAdminMenu();
            } else {
                displayEmployeeMenu();
            }
        }
    }

private:
    void login() {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        for (const Employee& employee : employees) {
            if (employee.username == username && employee.password == password) {
                currentUser = employee;
                return;
            }
        }

        cout << "Invalid username or password. Please try again." << endl;
        login();
    }

    bool isAdmin() {
        return currentUser.username == "admin";
    }

    void displayAdminMenu() {
        cout << "Welcome, Admin!" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. View Employee Analytics" << endl;
        cout << "3. Display Tasks" << endl;
        cout << "4. Mark Task Complete" << endl;
        cout << "5. Change Password" << endl;
        cout << "6. Logout" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                viewEmployeeAnalytics();
                break;
            case 3:
                displayTasks("admin_tasks.txt");
                break;
            case 4:
                markTaskComplete("admin_tasks.txt");
                break;
            case 5:
                changePassword();
                break;
            case 6:
               // logout(!choice);
                logout();
              //  HRProgram = true;
                break;
//                return; // Exit the run() function
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    void displayEmployeeMenu() {
        cout << "Welcome, " << currentUser.username << "!" << endl;
        cout << "1. Display Tasks" << endl;
        cout << "2. Mark Task Complete" << endl;
        cout << "3. Logout" << endl;

        int choice;
        cout << "Enter your choice: ";
                cin >> choice;

        switch (choice) {
            case 1:
                displayTasks(currentUser.username + "_tasks.txt");
                break;
            case 2:
                markTaskComplete(currentUser.username + "_tasks.txt");
                break;
            case 3:
                logout();
               // HRProgram = true;
                break;
    //            return 0; // Exit the run() function
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    void addEmployee() {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        Employee employee;
        employee.username = username;
        employee.password = password;
        employees.push_back(employee);

        saveEmployeesToFile();
        cout << "Employee added successfully." << endl;
    }

    void viewEmployeeAnalytics() {
        // Implement the logic to display employee analytics
        // This is specific to your use case and requirements
        // You can gather data from employees vector and perform necessary computations
    }

    void displayTasks(const string& filename) {
        vector<Task> tasks;
        loadTasksFromFile(filename, tasks);

        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].isComplete) {
                cout << " [Complete]";
            }
            cout << endl;
        }
    }

    void markTaskComplete(const string& filename) {
        vector<Task> tasks;
        loadTasksFromFile(filename, tasks);

        cout << "Enter the index of the task to mark as complete: ";
        int index;
        cin >> index;

        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].isComplete = true;
            saveTasksToFile(filename, tasks);
            cout << "Task marked as complete." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void logout() {
        currentUser.username = "";
        currentUser.password = "";
        cout << "Logged out successfully." << endl;
     //   break;
    }

    void changePassword() {
        string newPassword;
        cout << "Enter the new password: ";
        cin >> newPassword;

        currentUser.password = newPassword;
        saveEmployeesToFile();
        cout << "Password changed successfully." << endl;
    }

    void saveEmployeesToFile() {
        ofstream file("users.txt");
        if (file.is_open()) {
            for (const Employee& employee : employees) {
                file << employee.username << " " << employee.password << endl;
            }
            file.close();
        } else {
            cout << "Error: Unable to save employee data." << endl;
        }
    }
};

int main() {
    HRProgram program;
    program.run();

    return 0;
}