#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function to add a task to the list
void addTask(vector<Task>& todoList, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    todoList.push_back(newTask);
    cout << "Task added successfully." << endl;
}

// Function to display the list of tasks
void viewTasks(const vector<Task>& todoList) {
    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << i + 1 << ". ";
        if (todoList[i].completed)
            cout << "[X] ";
        else
            cout << "[ ] ";
        cout << todoList[i].description << endl;
    }
}

// Function to mark a task as completed
void markCompleted(vector<Task>& todoList, int index) {
    if (index >= 1 && index <= todoList.size()) {
        todoList[index - 1].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& todoList, int index) {
    if (index >= 1 && index <= todoList.size()) {
        todoList.erase(todoList.begin() + index - 1);
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> todoList;
    char choice;

    do {
        cout << "Choose an option:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore(); // Ignore any remaining newline characters in the input buffer
                getline(cin, taskDescription);
                addTask(todoList, taskDescription);
                break;
            }
            case '2':
                viewTasks(todoList);
                break;
            case '3': {
                int taskIndex;
                cout << "Enter task number to mark as completed: ";
                cin >> taskIndex;
                markCompleted(todoList, taskIndex);
                break;
            }
            case '4': {
                int taskIndex;
                cout << "Enter task number to remove: ";
                cin >> taskIndex;
                removeTask(todoList, taskIndex);
                break;
            }
            case '5':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != '5');

    return 0;
}
