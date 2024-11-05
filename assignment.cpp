#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

void displayMenu() {
    cout << "\n--- To-Do List Menu ---\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Mark Task as Completed\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore(); // Clear the newline left in the input buffer
    getline(cin, newTask.description);
    newTask.isCompleted = false;
    tasks.push_back(newTask);
    cout << "Task added!\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }
    cout << "\n--- To-Do List ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << (tasks[i].isCompleted ? "[Completed] " : "[Pending] ")
             << tasks[i].description << '\n';
    }
}

void deleteTask(vector<Task>& tasks) {
    viewTasks(tasks);
    cout << "Enter task number to delete: ";
    int taskNum;
    cin >> taskNum;
    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNum - 1);
        cout << "Task deleted!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void markTaskCompleted(vector<Task>& tasks) {
    viewTasks(tasks);
    cout << "Enter task number to mark as completed: ";
    int taskNum;
    cin >> taskNum;
    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks[taskNum - 1].isCompleted = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: deleteTask(tasks); break;
            case 4: markTaskCompleted(tasks); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
        
    } while (choice != 5);
    
    return 0;
}
