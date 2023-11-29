#ifndef PROCESSSTATS_HPP
#define PROCESS_STATS_HPP

    #define RESOURCE_CATEGORY_COUNT 3

    struct ProcessResources {

        

        //Holds the current allocation of each resource
        //Allocates to 0's automatically
        //allocated[0] = A's resource count
        //allocated[1] = B's resource count
        //allocated[2] = C's resource count
        int allocated[3] = {0,0,0};


        //Holds the max allocation of each resource
        //Allocates to 0's automatically
        //maxAllocated[0] = A's resource count
        //maxAllocated[1] = B's resource count
        //maxAllocated[2] = C's resource count
        int maxAllocated[3] = {0,0,0};


    };





#endif