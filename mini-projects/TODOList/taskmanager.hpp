#include <string>
#include <vector>

enum class TaskStatus { NOT_STARTED = 0, IN_PROGRESS = 1, COMPLETED = 2 };

struct Task {
    int id;
    std::string description;
    TaskStatus status;

    Task(const int id, const std::string description) : id(id), description(description), status(TaskStatus::NOT_STARTED) {}

    void UpdateStatus(const int new_status) {
        if(new_status == -1 && this->status != TaskStatus::COMPLETED) { // new_status = -1 = autoupdate to the next status
            this->status = static_cast<TaskStatus>(static_cast<int>(status) + 1);;
        } else if (new_status == -1 && this->status == TaskStatus::COMPLETED) {
            this->status = TaskStatus::COMPLETED; // Do not update a status is it's already Done
        } else {
            this->status = static_cast<TaskStatus>(new_status);
        }
    }

    void Display() const {
        switch(static_cast<int>(this->status)) {
            case 0 : std::cout << "| " << this->id << " | " << this->description << " | NOT STARTED |" << std::endl; break;
            case 1 : std::cout << "| " << this->id << " | " << this->description << " | IN PROGRESS |" << std::endl; break;
            case 2 : std::cout << "| " << this->id << " | " << this->description << " | FINISHED    |" << std::endl; break;
        }
        
    }

    Task& operator=(const Task& other) {
        this->id = other.id;
        this->description = other.description;
        this->status = other.status;

        return *this;
    }

};


struct TaskManager {
    std::vector<Task> tasks;
    int max_id = 0;

    TaskManager() {}

    void add_Task(const std::string description) {
        tasks.emplace_back(this->max_id, description);
        max_id += 1;
    }

    void remove_task(const int id) {
        int curr_id = this->tasks[0].id;
        int i = 0;
        while(curr_id != id) {
            i += 1;
            curr_id = this->tasks[i].id;
        }

        this->tasks.erase(this->tasks.begin() + i);
    }

    void reset_index() {
        for(size_t i = 0; i < this->tasks.size(); ++i){
            this->tasks[i].id = static_cast<int>(i);
        }
    }

    void update_status(const int id) {
        int curr_id = this->tasks[0].id;
        int i = 0;
        while(curr_id != id) {
            i += 1;
            curr_id = this->tasks[i].id;
        }

        this->tasks[i].UpdateStatus(-1);
    }

    void Display() {

        std::cout << "| ID:  | Description: | Status: |" << std::endl;
        for(size_t i = 0; i < tasks.size(); ++i){
            tasks[i].Display();

            
        }

    }

};

