#include <iostream>

#include "../include/banker.hpp"
#include "../include/util.hpp"





int main(int argc, char* argv[]) {
    //Check for the proper amount of arguments
    if (argc < 2) {
        std::cerr << "ERROR: Not Enough Arguments, include the file name/path to the resource table" << std::endl;
        exit(1);
    }

    char* resourceTable = argv[1];

    //Each row is a process then each column is an count of the resources
    //Resources: 0 = A, 1 = B, 2 = C
    //Processes: 0 = P0, 1 = P1, 2 = P2, etc.

    /*REMOVE VALUES WHEN FINISHED WITH ALGO!*/
    int allocated[PROCESSES][RESOURCE_CATEGORIES] = {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };


    int max[PROCESSES][RESOURCE_CATEGORIES] = {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };

    int available[RESOURCE_CATEGORIES] {
        3,3,2
    };


    //Call to read in from the table
    //processResourceTable(resourceTable, allocated, max, available);

    //Finish holds which processes are finished by a bit (1/0), indicies are the process numbers
    //Anwser holds the process numbers that are a safe path if it exists
    //index is the curent index in anwser
    int finished[PROCESSES], anwser[PROCESSES], index = 0;

    //initlizes the finished array to 0's
    for (int k = 0; k < PROCESSES; ++k) {
        finished[k] = 0;
    }

    //Create the array that holds all of the resources still needed by the processes
    //Formula: Max - Allocation => for each resource in each process
    int need[PROCESSES][RESOURCE_CATEGORIES];

    //Finds the needed for each resource for each process
    for (int i = 0; i < PROCESSES; ++i) {
        for (int j = 0; j < RESOURCE_CATEGORIES; ++j) {
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }


    //Now starts to check paths and find ones that are safe
    for (int k = 0; k < PROCESSES; ++k) {
        for (int currentProcess = 0; currentProcess < PROCESSES; ++currentProcess) {   //check if each process is finished
            if (finished[currentProcess] == 0) {
                int flag = 0;


                //delegates the resources
                for (int currentResource = 0; currentResource < RESOURCE_CATEGORIES; ++currentResource) {
                    //NOT ENOUGH RESOURCES, stop 
                    if (need[currentProcess][currentResource] > available[currentResource]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    anwser[index++] = currentProcess;


                    for (int finishedProcess = 0; finishedProcess < RESOURCE_CATEGORIES; ++finishedProcess) {
                        available[finishedProcess] += allocated[currentProcess][finishedProcess];

                        finished[currentProcess] = 1;
                    }
                }
            }
        }
    }
    

        int safeFlag = 1 ;

        //Checking sequence saftey
        for (int currentProcess = 0; currentProcess < PROCESSES; ++currentProcess) {
            //Esnures that each of the processes have finsihed with the allocated resources
            //If one doesn't then sequence is entirely not safe!
            if (finished[currentProcess] == 0) {
                safeFlag = 0;
                std::cout << "The given sequence is not safe!!!" << std::endl;
                break;
            }
        }

            //sequence is safe, print path
            if (safeFlag == 1) {


                std::cout << "The following sequence is safe" << std::endl;
                

                for (int currentProcess = 0; currentProcess < PROCESSES - 1; ++currentProcess) {
                    std::cout << " P" << anwser[currentProcess] << " ->";
                    
                }

                std::cout << " P" << anwser[PROCESSES - 1] << std::endl;
            }


    return 0;
}