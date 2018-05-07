#include<utils.h>

void delay (unsigned int secs) {
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);               // Loop until it arrives.
}