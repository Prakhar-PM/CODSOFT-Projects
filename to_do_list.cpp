#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100; // maximum number of tasks

struct Task {
    string name;
    bool completed;
};

Task tasks[MAX_TASKS]; 
int numTasks = 0; 
void addTask() {
    if (numTasks >= MAX_TASKS) {
        cout << "Sorry, the to-do list is full." << endl;
        return;
    }

    cout << "Enter a new task: ";
    getline(cin, tasks[numTasks].name);
    tasks[numTasks].completed = false;
    numTasks++;
    cout << "Task added successfully." << endl;
}

void viewTasks() {
    cout << "To-Do List:" << endl;
    for (int i = 0; i < numTasks; ++i) {
        cout << i + 1 << ". " << tasks[i].name;
        if (tasks[i].completed) {
            cout << " - Completed";
        }
        cout << endl;
    }
}

void markTaskAsCompleted() {
    viewTasks(); 

    int taskNum;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNum;

    if (taskNum <= 0 || taskNum > numTasks) {
        cout << "Invalid task number." << endl;
        return;
    }

    tasks[taskNum - 1].completed = true;
    cout << "Task marked as completed." << endl;
}

void removeTask() {
    viewTasks(); 

    int taskNum;
    cout << "Enter the task number to remove: ";
    cin >> taskNum;

    if (taskNum <= 0 || taskNum > numTasks) {
        cout << "Invalid task number." << endl;
        return;
    }

    cout << "Task '" << tasks[taskNum - 1].name << "' removed." << endl;
    for (int i = taskNum - 1; i < numTasks - 1; ++i) {
        tasks[i] = tasks[i + 1]; 
    }
    numTasks--;
}

int main() {
    int choice;
    while (true) {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Thank you for using the To-Do List Manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    }

    return 0;
}
