# OperatingSystem_OS
///
OS-Lab/
│── README.md
│
├── -Processes/
│   ├── process_creation.cpp
│   ├── zombie_orphan.cpp
│   └── README.md
│
├── -Threads/
│   ├── create_join.cpp
│   ├── pass_parameters.cpp
│   ├── deadlock_simulation.cpp
│   └── README.md
│
├── -Scheduling/
│   ├── fcfs.cpp
│   ├── sjf.cpp
│   ├── priority.cpp
│   ├── round_robin.cpp
│   └── README.md
│
├── -Synchronization/
│   ├── producer_consumer_mutex.cpp
│   ├── producer_consumer_semaphore.cpp
│   ├── reader_writer_mutex.cpp
│   ├── dining_philosophers.cpp
│   └── README.md
│
├── -FileManagement/
│   ├── create_delete.cpp
│   ├── copy_move.cpp
│   └── README.md
│
└── -ShellScripting/
    ├── system_info.sh
    ├── file_ops.sh
    ├── calculator.sh
    └── README.md

# Operating Systems Lab

This repository contains programs and assignments for Operating Systems Lab, implemented in C, C++, and Shell Scripting.

## Folder Structure

- -Processes → Process creation, termination, zombie/orphan processes  
- -Threads → Thread creation, joining, passing parameters, deadlock simulation  
- -Scheduling → CPU scheduling algorithms (FCFS, SJF, Priority, Round Robin)  
- -Synchronization → Producer-Consumer, Reader-Writer, Dining Philosophers  
- -FileManagement → File operations using system calls (create, delete, copy, move)  
- -ShellScripting → Basic shell scripts for system info, file handling, and automation  

## Compilation & Execution

### C / C++ Programs
```bash
g++ filename.cpp -o output -pthread
./output




## Example Subfolder README (`03-Scheduling/README.md`)

```markdown
# CPU Scheduling Algorithms

This folder contains implementations of CPU scheduling algorithms:

1. First Come First Serve (FCFS)
2. Shortest Job First (SJF)
3. Priority Scheduling
4. Round Robin (RR)

## Example Run (FCFS)

### Input


Processes: P1, P2, P3
Burst Times: 5, 8, 12
Arrival Times: 0, 1, 2



### Output


Gantt Chart: P1 | P2 | P3
Average Waiting Time = 4.3
Average Turnaround Time = 9.7




///
