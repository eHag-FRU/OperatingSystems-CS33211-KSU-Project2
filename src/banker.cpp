#include <iostream>



#include "../include/banker.hpp"








int main(int argc, char** argv) {
    //check for the arguments
    if (argc < 2) {
        std::cerr << "ERROR: Resource Table not found\n";
        exit(1);
    }


    //Set up an array of processes
    ProcessResources processes[5];

    for(int i = 0; i < argc; ++i) {
        std::cout << std::endl  << i << "  " << argv[i] << std::endl << std::endl;
    }

    std::cout << std::endl;

    //Open and read the resource table
    resourceTableRead(argv[1], processes);



    //Now handle the 

    return 0;
}






void resourceTableRead(std::string fileName, ProcessResources* arrayOfProcesses) {
    std::cout << "Opened the file" << std::endl;
    
    //Opens the file for READ ONLY!
    std::ifstream resourceTable(fileName, std::ifstream::in);


    //Now we need to pull in the values from the file

    int process;
    int currentProcessResourceIndex = 0;
    //Pull in input while not at EOF
    //Once per line!!!!
    do {
        char currentPosition = resourceTable.get();

        //First is the process
        process = atoi(&currentPosition);


        //Next to pull in is the ALLOCATION for each
        for (int i = 0; i < RESOURCE_CATEGORY_COUNT; ++i) {
            currentPosition = resourceTable.get();

            arrayOfProcesses[process].allocated[i] = atoi(&currentPosition);
        }


        //Next to pull in is the MAX for each
        for (int i = 0; i < RESOURCE_CATEGORY_COUNT; ++i) {
            currentPosition = resourceTable.get();

            arrayOfProcesses[process].maxAllocated[i] = atoi(&currentPosition);
        }


        //Pull the end of the line (;)
        currentPosition = resourceTable.get();
        currentPosition = resourceTable.get();


    } while (!resourceTable.eof() && resourceTable.peek() != '*');

      

    //Now at the available
    





    //Close the file
    resourceTable.close();
}