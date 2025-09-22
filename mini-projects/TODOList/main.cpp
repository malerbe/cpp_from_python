#include <iostream>
#include "taskmanager.hpp"

/*

Mini-project just to get used to the syntax of the C++ language. Far from being complete, additionnal points could be
taken into account:

- Manage invalid ids in methods
- Make separated update_status and next_status methods
- Better displaying, options to only show finished, in progress or not started tasks
- ...

*/

int main(int argc, char* argv[]) { 
    Task new_task(0, "test");

    std::cout << new_task.id << " " << new_task.description << " " << static_cast<int>(new_task.status) << std::endl;

    new_task.UpdateStatus(-1);

    std::cout << new_task.id << " " << new_task.description << " " << static_cast<int>(new_task.status) << std::endl;

    new_task.UpdateStatus(-1);

    std::cout << new_task.id << " " << new_task.description << " " << static_cast<int>(new_task.status) << std::endl;

    new_task.UpdateStatus(-1);

    std::cout << new_task.id << " " << new_task.description << " " << static_cast<int>(new_task.status) << std::endl;

    std::cout << "_____ Test copy task _____" << std::endl;

    Task other_task = new_task;
    std::cout << other_task.id << " " << other_task.description << " " << static_cast<int>(other_task.status) << std::endl;


    std::cout << "_____ Test Task Manager _____" << std::endl;

    std::cout << "_____ Task Manager Add Tasks _____" << std::endl;

    TaskManager new_taskmanager;
    new_taskmanager.add_Task("Learn C++");
    new_taskmanager.add_Task("Cook food for diner");
    new_taskmanager.add_Task("Find my keys");

    new_taskmanager.Display();

    std::cout << "_____ Task Manager Remove Tasks _____" << std::endl;

    new_taskmanager.remove_task(1);
    new_taskmanager.Display();

    std::cout << "_____ Task Manager Reset index _____" << std::endl;

    new_taskmanager.reset_index();
    new_taskmanager.Display();

    std::cout << "_____ Task Manager Update status _____" << std::endl;

    new_taskmanager.update_status(1); // Changes status to IN PROGRESS
    // new_taskmanager.update_status(1); // Changes status to FINISHED
    // new_taskmanager.update_status(1); // Keeps status to FINISHED
    new_taskmanager.Display();
}  


