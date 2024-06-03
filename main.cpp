#include<iostream>
#include "workflow.h"

int main() {
    {
     // linear workflow
    Workflow workflow;
   
    // linear task
    workflow.addTask(std::make_unique<PickingTask>("Picking task"));
    workflow.addTask(std::make_unique<CheckingTask>("Checking Task"));    
    workflow.addTask(std::make_unique<LabelingTask>("Labeling Task"));
    workflow.addTask(std::make_unique<WrappingTask>("Wrapping Task"));

    workflow.execute();
    workflow.report();
    }

    {
     // conditional workflow
    Workflow workflow;

    // add conditional task
    workflow.addTask(std::make_unique<ConditionalTask>("Conditional Task 1", std::make_unique<ShippingTask>("Shipping Task"), false));
    workflow.addTask(std::make_unique<ConditionalTask>("Conditional Task 1", std::make_unique<ShippingTask>("Shipping Task"), true));

    workflow.execute();
    workflow.report();
    }

    {
     // Parallel workflow
    Workflow workflow;

    // add parallelling task
    auto parallelTask = std::make_unique<ParallelTask>("parallelling task 1");
    parallelTask->addTask(std::make_unique<PickingTask>("Picking task"));
    parallelTask->addTask(std::make_unique<LabelingTask>("Labeling Task"));
    parallelTask->addTask(std::make_unique<ShippingTask>("Shipping Task"));
    workflow.addTask(std::move(parallelTask));

    workflow.execute();
    workflow.report();
    }

    {
     // loop workflow
    Workflow workflow;

    // add loop task
    workflow.addTask(std::make_unique<LoopTask>("Loop task 1", std::make_unique<MovingContainersTask>("MovingContainers Task"), 10));

    workflow.execute();
    workflow.report();
    }

    return 0;
}