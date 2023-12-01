#ifndef UTILL_HPP
#define UTILL_HPP
    #include <iostream>
    #include <fstream>



    #define RESOURCE_CATEGORIES 3 
    #define PROCESSES 5         

    #define LINE_DELIMITER ';'
    #define LIST_DELIMITER ','



    void printTables(int allocated[][RESOURCE_CATEGORIES], int max[][RESOURCE_CATEGORIES], int* available);

    void processResourceTable(char* file_name, int allocated[][RESOURCE_CATEGORIES], int max[][RESOURCE_CATEGORIES], int* available);


#endif