# Programming Assignment 2 - Banker's Algorithm

<br>

### Author: Elliott Hager
### Fall 2023 Semester
### CS-33211: Operating Systems
### Dr. Qiang Guan
### Kent State University

<br><br>

#### Description (Provided from the assignment instructions)
Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances, with the snapshot provided of the system at time t0.



Use the Banker's Algorithm to determine if the system is in a safe state. If the system is in a safe state, provide the path that is safe.


<br><br>


### Implementation

Each process is a structure, which stores it's max and currently used resources. All of the processes are stored in an array. The Banker's algorithm will go through and check for a safe path. This is where all processes get the maximum resources allocated to them, while finding a sequence that does not cause deadlock. If no safe path is found, then it is reported back that with the current resource table given to the algorithm, it is not possible for safe allocation and continuation of the processes.

If there is a safe way to allocate all the resources to each process, the specific path is found, recorded, and returned as the safe route, given the current resource table given to the algorithm.


### Resource Table Formatting
The resource table is formatted in the following way:

```
{Process number (0-based)}; {Allocated resource numbers, separated with a comma, until the last (i.e. 1,2,3)}; {Max resource numbers, separated with a comma, until the last (i.e. 1,2,3)}; {available resources,separated with a comma, until the last (i.e. 1,2,3)};

```

<br><br>

### Compilation
The algorithm implementation is separate from reading in the resource table from a provided text (.txt) file

<br>

#### Banker:
The following make command will compile the banker's algorithm file for execution
```
    make banker
```

### Util
The following make command will compile only the utility functions of the application
```
    make util
```

### Run:
The following make command will compile the banker's algorithm file and execute the program with the ````./assets/resource_table.txt``` file as input 
```
    make run
```


### Clean:
The following make command will remove the compiled and executable program files
```
    make clean
```

<br><br>

### Run Instructions:
To compile and run the Banker's algorithm, there is a couple ways of doing so.


#### 1.) Manually/Command
```
    ./out/banker ./assets/resource_table.txt
```

### 2.) Using Make (Preferred)
Using the ```make run``` command will compile and run the algorithm
This is the preferred method of compilation and running the project.

<br><br>





### Documentation:
Please see the ```Doc``` folder for a PDF manual/documentation packet.



<br><br>

### Libraries & Tech Stack
* C++
* Make
* G++
