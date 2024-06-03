#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>

#include "workflow.h"

Logs Workflow::logs;

PickingTask :: PickingTask(std::string name) : taskName(name) {};

std::string PickingTask :: getTaskName() {return taskName;};

void PickingTask :: execute() {
        std::cout << "Executing Picking Task" << std::endl;
    }

CheckingTask :: CheckingTask(std::string name) : taskName(name) {};

std::string CheckingTask :: getTaskName() {return taskName;};

void CheckingTask :: execute() {
    std::cout << "Executing Checking Task" << std::endl;
}

LabelingTask :: LabelingTask(std::string name) : taskName(name) {};

std::string LabelingTask :: getTaskName() {return taskName;};

void LabelingTask :: execute() {
    std::cout << "Executing Labeling Task" << std::endl;
}

WrappingTask :: WrappingTask(std::string name) : taskName(name) {};

std::string WrappingTask :: getTaskName() {return taskName;};

void WrappingTask :: execute() {
    std::cout << "Executing Wrapping Task" << std::endl;
}

ShippingTask :: ShippingTask(std::string name) : taskName(name) {};

std::string ShippingTask :: getTaskName() {return taskName;};

void ShippingTask :: execute() {
    std::cout << "Executing Shipping Task" << std::endl;
}

MovingContainersTask :: MovingContainersTask(std::string name) : taskName(name) {};

std::string MovingContainersTask :: getTaskName() {return taskName;};

void MovingContainersTask :: execute() {
    std::cout << "Executing Moving Containers Task" << std::endl;
}

ConditionalTask :: ConditionalTask(std::string name, std::unique_ptr<Task> task, bool condition)
    : taskName(name), task(std::move(task)), condition(condition) {};

std::string ConditionalTask :: getTaskName() {return taskName;};

void ConditionalTask :: execute() {
    std::cout << "Executing Conditional Task" << std::endl;
    if (condition) {
        task->execute();
        Workflow::logs.writeLog(task->getTaskName() + " executed");
    } else {
        std::cout << "Condition not met, skipping task" << std::endl;
    }
}

ParallelTask :: ParallelTask(std::string name) : taskName(name) {}; 

std::string ParallelTask :: getTaskName() {return taskName;};

void ParallelTask :: addTask(std::unique_ptr<Task> task) {
    tasks.push_back(std::move(task));
}
void ParallelTask :: execute() {
    std::cout << "Executing Parallel Task" << std::endl;
    std::vector<std::thread> threads;
    for (const auto& task : tasks) {
        threads.emplace_back([&task]() {
            task->execute();
            Workflow::logs.writeLog(task->getTaskName() + " executed");
        });
    }
    for (auto& thread : threads) {
        thread.join();
    }
}

LoopTask :: LoopTask(std::string name, std::unique_ptr<Task> task, int maxIterations)
    : taskName(name), task(std::move(task)), maxIterations(maxIterations) {}
    
std::string LoopTask :: getTaskName() {return taskName;};

void LoopTask :: execute() {
    std::cout << "Executing loop Task" << std::endl;
    for (int i = 0; i < maxIterations; ++i) {
        task->execute();        
    }
    Workflow::logs.writeLog(task->getTaskName() + " executed");
}

void Workflow :: addTask(std::unique_ptr<Task> task) {
    tasks.push_back(std::move(task));
}

void Workflow :: execute() {
    std::cout << "===Executing work flow===" << std::endl;
    for (const auto& task : tasks) {
        task->execute();
        logs.writeLog(task->getTaskName() + " executed");
    }
}

void Workflow :: report() const {
    std::cout << "Workflow Report:" << std::endl;
    auto contents = logs.readLog();
    for (const auto& log : contents) {
        std::cout << log << std::endl;
    }
    std::cout << std::endl;
    logs.clearLog();
}
