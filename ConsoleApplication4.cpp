#include <iostream>
#include <string>

using namespace std;
//модель - функціональна логіка//
class TaskModel {
private:
    string task;
    bool hasTask;
public:
    TaskModel() : hasTask(false) {}

    void setTask(const string& t) {
        task = t;
        hasTask = true;
    }

    string getTask() const {
        return hasTask ? task : "No task added.";
    }

    bool taskExists() const {
        return hasTask;
    }
};
//відображення - представлення даних з моделі//
class TaskView {
public:
    string askToAddTask() {
        cout << "Add a new task? (yes/no): ";
        string answer;
        getline(cin, answer);
        return answer;
    }

    void showTask(const string& task) {
        cout << "\nTask: " << task << endl;
    }
};

//контролер - обробка виведення між моделлю та відображенням//
class TaskController {
private:
    TaskModel& model;
    TaskView& view;
public:
    TaskController(TaskModel& m, TaskView& v) : model(m), view(v) {}

    void processUserChoice() {
        string answer = view.askToAddTask();
        if (answer == "yes") {
            model.setTask("task added");
        }
    }

    void displayTask() {
        view.showTask(model.getTask());
    }
};
int main() {
    TaskModel model;
    TaskView view;
    TaskController controller(model, view);

    controller.processUserChoice();
    controller.displayTask();

    return 0;
}