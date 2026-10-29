# CPU Process Scheduling Simulator in C

## About the Project

The **CPU Process Scheduling Simulator** is a Data Structures and Algorithms (DSA) project developed using the C programming language. It simulates how a CPU schedules processes using two scheduling algorithms: First Come First Serve (FCFS) and Non-Preemptive Priority Scheduling.

The program calculates the waiting time and turnaround time for each process and displays the average waiting time and average turnaround time.

## Features

* Implements FCFS Scheduling
* Implements Non-Preemptive Priority Scheduling
* Accepts process burst time and priority
* Calculates waiting time for each process
* Calculates turnaround time for each process
* Displays average waiting and turnaround times
* Uses a simple console-based interface

## Technologies Used

* **Language:** C
* **Concepts:** Data Structures and Algorithms
* **Compiler:** GCC

## Scheduling Algorithms

### 1. First Come First Serve (FCFS)

Processes are executed in the order they are entered.

### 2. Priority Scheduling

Processes are executed according to priority. A smaller priority number indicates a higher priority. Processes with equal priority retain their original input order.

Both algorithms use non-preemptive scheduling, and all processes are assumed to arrive at time 0.

## Formulas

* **Waiting Time (WT)** = Turnaround Time − Burst Time
* **Turnaround Time (TAT)** = Waiting Time + Burst Time
* **Average Waiting Time** = Total Waiting Time / Number of Processes
* **Average Turnaround Time** = Total Turnaround Time / Number of Processes

## How to Run

### Step 1: Clone the repository

```bash
git clone https://github.com/YOUR-USERNAME/cpu-process-scheduling-simulator.git
```

### Step 2: Open the project folder

```bash
cd cpu-process-scheduling-simulator
```

### Step 3: Compile the program

```bash
gcc cpu.c -o cpu
```

### Step 4: Run the program

On Linux or macOS:

```bash
./cpu
```

On Windows:

```bash
cpu.exe
```

## Sample Input

| Process | Burst Time | Priority |
| ------- | ---------: | -------: |
| P1      |          5 |        2 |
| P2      |          3 |        1 |
| P3      |          2 |        3 |

## Sample Results

| Algorithm           | Average Waiting Time | Average Turnaround Time |
| ------------------- | -------------------: | ----------------------: |
| FCFS                |                 4.33 |                    7.67 |
| Priority Scheduling |                 3.67 |                    7.00 |

*Results are based on the sample input above.*

## Time Complexity

| Operation                        | Time Complexity |
| -------------------------------- | --------------- |
| FCFS Scheduling                  | O(n)            |
| Priority Sorting (Bubble Sort)   | O(n²)           |
| Priority Scheduling Calculations | O(n)            |

## Learning Outcomes

* Understanding CPU scheduling algorithms
* Learning the difference between FCFS and Priority Scheduling
* Implementing sorting and scheduling logic in C
* Calculating waiting time and turnaround time
* Applying DSA concepts to an operating systems problem

## Future Enhancements

* Implement Round Robin Scheduling
* Add Shortest Job First (SJF) Scheduling
* Support different process arrival times
* Display a Gantt chart
* Compare more scheduling algorithms

## Author

Developed as a college Data Structures and Algorithms project using C.

## License

This project is available for educational and learning purposes.
