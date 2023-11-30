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

Each process is a structure, which stores it's max and currently used resources. All of the processes are stored in an array. The Banker's algorithm will go through ##FINISH##


<br><br>

### Compilation
The algorithm implementation is separate from reading in the resource table from a provided text (.txt) file

<br>

#### Banker:
The following make command will compile the banker's algorithm file for execution
```
    make banker
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
To run both of the producer and consumer at the same time, for Linux and Unix systems, there are two options. 


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
