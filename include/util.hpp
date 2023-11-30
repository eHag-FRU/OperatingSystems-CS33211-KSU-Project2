#ifndef UTILL_HPP
#define UTILL_HPP

#define RESOURCE_CATEGORIES 3   //M
#define PROCESSES 5             //N

bool is_digit(std::string str);

void processResourceTable(char* file_name, int allocated[][RESOURCE_CATEGORIES], int max[][RESOURCE_CATEGORIES], int* available);


#endif