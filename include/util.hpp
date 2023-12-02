/**
 * @file util.hpp
 * @author Elliott Hager
 * @brief Header file to define functions and global constants necessary for File I/O and debug output
 * @date 2023-12-01
 * 
 */

#ifndef UTILL_HPP
#define UTILL_HPP
    #include <iostream>
    #include <fstream>


    /**
     * @brief The number of different system resources
     * 
     */
    #define RESOURCE_CATEGORIES 3 
    
    
    
    /**
     * @brief The number of processes for the system
     * 
     */
    #define PROCESSES 5         



    /**
     * @brief The delimeter to indicate the end of the list of one numerical type in the resource table (i.e. allocated, maximum, etc.)
     * 
     */
    #define LINE_DELIMITER ';'


    /**
     * @brief The delimiter to indicate the end of one numerical value for the resource table (i.e. 1,2,3 => 1 of Resource A, 2 of Resource B, etc.)
     * 
     */
    #define LIST_DELIMITER ','


    
    void printTables(int allocated[][RESOURCE_CATEGORIES], int max[][RESOURCE_CATEGORIES], int* available);


   
    void processResourceTable(char* file_name, int allocated[][RESOURCE_CATEGORIES], int max[][RESOURCE_CATEGORIES], int* available);


#endif