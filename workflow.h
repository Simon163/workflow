#pragma once

#include <string>
#include <vector>
#include <memory>

#include "logs.h"

class Workflow;

// task interface
class Task {
    
public:
    virtual void execute() = 0;
    virtual std::string getTaskName() = 0;
    virtual ~Task() = default;
};

// picking task in warehouse
class PickingTask : public Task {
public:
    PickingTask(std::string name);
    void execute() override;
    std::string getTaskName() override;

private:
    std::string taskName;
};

// checking task in warehouse
class CheckingTask : public Task {
public:
    CheckingTask(std::string name);
    void execute() override;
    std::string getTaskName() override;

private:
    std::string taskName;
};

// labeling task in warehouse
class LabelingTask : public Task {
public:
    LabelingTask(std::string name);
    void execute() override;
    std::string getTaskName() override;

private:
    std::string taskName;
};

// wrapping task in warehouse
class WrappingTask : public Task {
public:
    WrappingTask(std::string name);
    void execute() override;
    std::string getTaskName() override;

private:
    std::string taskName;
};

// shipping task in warehouse
class ShippingTask : public Task {
public:
    ShippingTask(std::string name);
    void execute() override;
    std::string getTaskName() override;

private:
    std::string taskName;
};

// moving containers task in warehouse
class MovingContainersTask : public Task {
public:
    MovingContainersTask(std::string name);
    void execute() override;
    std::string getTaskName() override;

private:
    std::string taskName;
};

// conditional task is executed when certain condition is met only
class ConditionalTask : public Task {
private:
    std::unique_ptr<Task> task;
    bool condition;

public:
    ConditionalTask(std::string name, std::unique_ptr<Task> task, bool condition);
    void execute() override;
    std::string getTaskName() override;

private:
    std::string taskName;
};

// parallel task refer to multiple tasks that can be executed in parallel
class ParallelTask : public Task {
private:
    std::vector<std::unique_ptr<Task>> tasks;

public:
    ParallelTask(std::string name);
    void addTask(std::unique_ptr<Task> task);
    void execute() override;
    std::string getTaskName() override;

private:
    std::string taskName;
};

// loop task refer to tasks that need to be executed multiple times
class LoopTask : public Task {
private:
    std::unique_ptr<Task> task;
    int maxIterations;

public:
    LoopTask(std::string name, std::unique_ptr<Task> task, int maxIterations);
    void execute() override;
    std::string getTaskName() override;

private:
    std::string taskName;
};

// workflow
class Workflow {

private:
    // tasks list
    std::vector<std::unique_ptr<Task>> tasks;

public:
    // add an task to work flow
    void addTask(std::unique_ptr<Task> task);

    // execute tasks
    void execute();

    // report motoring logs  
    void report() const;

public:
    // logs
    static Logs logs;
};






