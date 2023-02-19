#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <ctime>

int adminHighYears = 50;
int adminLowYears = 21;

time_t now = time(0);
char *dateAccessed = ctime(&now);


#endif