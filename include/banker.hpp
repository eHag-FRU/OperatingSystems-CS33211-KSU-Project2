#ifndef BANKER_HPP
#define BANKER_HPP
    #include <fstream>
    #include <string>

    #include "../include/process.hpp"




    //Global constants for max of each resource
    #define A 10
    #define B 5
    #define C 7

    



    void resourceTableRead(std::string, ProcessResources*);

#endif