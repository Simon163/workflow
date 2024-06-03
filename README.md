


### What is a Workflow?

A workflow refers to a series of tasks and activities executed in a specific order to achieve a predetermined goal. The key elements of a workflow include tasks, participants, resources, and rules.

### Definition of Workflow

In software development, a workflow typically involves the following components:

-   **Tasks**: Specific work that needs to be completed.
-   **Participants**: People or systems that execute the tasks.
-   **Resources**: Tools and data required for task execution.
-   **Rules**: Logic that defines the order and conditions for task execution.

### Types of Workflows

Workflows can be classified into several types:

-   **Linear Workflow**: Tasks are executed in a fixed sequence.
-   **Conditional Workflow**: The execution order of tasks varies based on conditions.
-   **Parallel Workflow**: Multiple tasks can be executed simultaneously.
-   **Loop Workflow**: Tasks are repeatedly executed until specific conditions are met.

### Monitoring and reporting

In practical applications, workflow management systems need to monitor and generate reports in real-time.  The workflow class is extended to add monitoring and reporting functionalities.

### About the implementation
This repo is aimed at implementing the workflow using C++ features, including the following functionality:
1. support of all four kinds of workflows.
2. support of monitoring and reporting.

Note:
-   So far the implementation focuses on tasks, and other components related to workflow such as participants are not supported. I will add their support later.  
-   The implementation takes the workflow in the warehouse as an example where tasks include picking, labeling, wrapping, shipping, moving containers and so on.

Build and run:
build:
```
g++ main.cpp workflow.cpp -o workflow -lpthread
```
run:
```
./workflow
```
