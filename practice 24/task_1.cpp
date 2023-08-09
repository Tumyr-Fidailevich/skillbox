#include <iostream>
#include <ctime>
#include <vector>

enum taskStatus
{
    done,
    not_done
};

struct Task
{
    std::string name = "";
    std::time_t startTime;
    std::time_t endTime;
    int status = not_done;
};

double get_runtime(Task &task)
{
    return std::difftime(task.endTime, task.startTime);
}

void list_tasks(std::vector<Task> &tasks)
{
    if(tasks.size() == 0)
    {
        std::cout << "You have not started any tasks yet" << std::endl;
    }
    else
    {
        for (int i = 0; i < tasks.size(); i++)
        {
            if(tasks[i].status == done)
            {
                std::cout << "Task: " << tasks[i].name << std::endl;
                std::cout << "Spent time: " << get_runtime(tasks[i]) << " hours"<< std::endl;
            }
            else
            {
                std::cout << "Current task: " << tasks[i].name << std::endl;
            }
            
        }
    }
}
void add_task(std::vector<Task> &tasks)
{
    Task task;
    std::cout << "Input your task: ";
    getline(std::cin, task.name);
    task.startTime = std::time(nullptr);
    tasks.push_back(task);
}

int main()
{
    std::string input;
    std::vector<Task> allTasks;
    while (input != "exit")
    {
        std::cout << "Input command: ";
        std::cin >> input;
        std::cin.ignore();
        if (input == "begin")
        {
            if (allTasks.size() != 0 && allTasks.back().status == not_done)
            {
                allTasks.back().endTime = std::time(nullptr);
                allTasks.back().status = done;
                add_task(allTasks);
            }
            else
            {
                add_task(allTasks);
            }
        }
        else if (input == "end" && allTasks.size() != 0)
        {
            allTasks.back().endTime = std::time(nullptr);
            allTasks.back().status = done;
        }
        else if (input == "status")
        {
            list_tasks(allTasks);
        }
    }
    return 0;
}