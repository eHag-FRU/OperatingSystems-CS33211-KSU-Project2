/**
 * @file util.cpp
 * @author Elliott Hager
 * @brief The implementation of the File I/O and debugging functionality to read in the resource table for the Banker's Algorithm to analyze 
 * @date 2023-12-01
 * 
 */

#include "../include/util.hpp"

/**
     * @brief Print out each array and its contents, with multiple dimensions indicated (where applicable) for debugging purposes
     * 
     * @param allocated The 2-D array that holds the allocated resource counts for each process
     * @param max The 2-D array that holds the maximum resource counts needed for each process
     * @param available The 1-D array that holds the available resource counts the system has currently available
     */
void printTables(int allocated[][RESOURCE_CATEGORIES], int max[][RESOURCE_CATEGORIES], int* available) {
    std::cout << "FINISHED PROCESSING, HERE ARE THE RESULTS: " << std::endl << std::endl << std::endl;

    std::cout << "ALLOCATED" << std::endl;
    for (int i = 0; i < PROCESSES; ++i) {
        std::cout << "P" << i << " {";
        for (int j = 0; j < RESOURCE_CATEGORIES - 1; ++j) {
            std::cout << allocated[i][j] << ", ";
        }
        std::cout << allocated[i][RESOURCE_CATEGORIES - 1];

        std::cout << "}" << std::endl;
    }

    std::cout << std::endl << std::endl << std::endl;

    std::cout << "MAX" << std::endl;
        for (int i = 0; i < PROCESSES; ++i) {
            std::cout << "P" << i << " {";
            for (int j = 0; j < RESOURCE_CATEGORIES - 1; ++j) {
                std::cout << max[i][j] << ", ";
            }
            std::cout << max[i][RESOURCE_CATEGORIES - 1];

            std::cout << "}" << std::endl;
    }

    std::cout << std::endl << std::endl << std::endl;


    std::cout << "AVAILABLE" << std::endl;
    std::cout << "{";
    for (int j = 0; j < RESOURCE_CATEGORIES - 1; ++j) {
        std::cout << available[j] << ", ";
    }
    std::cout << available[RESOURCE_CATEGORIES-1];

    std::cout << "}" << std::endl;

    std::cout << std::endl << std::endl << std::endl;
}





 /**
     * @brief Processes the provided file for a resource table and fills allocated, maximum, and available resource arrays for algorithm processing and operations
     * 
     * @param file_name  The file name of the resource table
     * @param allocated The 2-D array that holds the allocated resource counts for each process
     * @param max  The 2-D array that holds the maximum resource counts needed for each process
     * @param available The 1-D array that holds the available resource counts the system has currently available
     */
void processResourceTable(char* file_name, int allocated[][RESOURCE_CATEGORIES], int max[][RESOURCE_CATEGORIES], int* available) {

    //Tracking variables for processing
    int currentProcess =  0;
    int curentResourcePosition = 0;
    std::string currentLine;


    //Open file, read only
    std::ifstream resourceTable(file_name, std::ifstream::in);


    while(!resourceTable.eof()) {
        std::getline(resourceTable, currentLine, LINE_DELIMITER);

        if (std::stoi(currentLine) < 0) {   //This means that the available resources line in the file has been reached
            for (int i = 0; i < RESOURCE_CATEGORIES; ++i) {
                std::getline(resourceTable, currentLine, LIST_DELIMITER);

                available[i] = std::stoi(currentLine);
            }

            //Finished
            break;
        }

        currentProcess = std::stoi(currentLine);

        //Handels the allocated resources
        for (curentResourcePosition = 0; curentResourcePosition < RESOURCE_CATEGORIES; ++curentResourcePosition) {
            if (curentResourcePosition == (RESOURCE_CATEGORIES - 1))  { //At end
                std::getline(resourceTable, currentLine, LINE_DELIMITER);
            } else {
                std::getline(resourceTable, currentLine, LIST_DELIMITER);
            }

    
            allocated[currentProcess][curentResourcePosition] = std::stoi(currentLine);
        }



        //Handels the MAX resources
            for (curentResourcePosition = 0; curentResourcePosition < RESOURCE_CATEGORIES; ++curentResourcePosition) {
                if (curentResourcePosition == (RESOURCE_CATEGORIES - 1))  { //At end
                    std::getline(resourceTable, currentLine, LINE_DELIMITER);
                } else {
                    std::getline(resourceTable, currentLine, LIST_DELIMITER);
                }

                
                
                max[currentProcess][curentResourcePosition] = std::stoi(currentLine);
            }

    }
}