#include "../include/util.hpp"


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