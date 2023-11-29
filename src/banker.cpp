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
    int currentResource;
    int currentProcessResourceIndex = 0;

    int count = 0;

    //Pull in input while not at EOF
    //Once per line!!!!
    do {

        ++count;

        //Grabs char
        char currentChar = resourceTable.get();
    
        //put in the process index
        //changes to index
        process = atoi(&currentChar);

        std::cout << "| " << process << "    |";
    

        //now grab each of the three for the allocated
        for (int i = 0; i < RESOURCE_CATEGORY_COUNT; ++i) {
            currentChar = resourceTable.get();
            std::cout << currentChar << ", ";
            //sticks the available in to the current position
            (arrayOfProcesses[process]).available[atoi(&currentChar)];
        }

        std::cout << "    |";


        

        //now grab each of the three for the max
         for (int i = 0; i < RESOURCE_CATEGORY_COUNT; ++i) {
            currentChar = resourceTable.get();

            std::cout << currentChar << ", ";

            //sticks the available in to the current position
            (arrayOfProcesses[process]).maxAllocated[atoi(&currentChar)];
        }


        //check if available is in the table
        if (resourceTable.peek() != ';') {
            //grab the three available
            for(int i = 0; i < RESOURCE_CATEGORY_COUNT; ++i) {
                currentChar = resourceTable.get();

                std::cout << currentChar << ", ";

                //sticks the available in to the current position
                (arrayOfProcesses[process]).available[atoi(&currentChar)];
            }
        }

        
        //Pull the end of the line (;)
        currentChar = resourceTable.get();
        currentChar = resourceTable.get();


    } while (!resourceTable.eof());

      





    //Close the file
    resourceTable.close();
}