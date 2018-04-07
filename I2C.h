#pragma once
#include <unistd.h>			
#include <fcntl.h>			
#include <sys/ioctl.h>		
#include <linux/i2c-dev.h>	

#define READPACKETSIZE 10


void I2Copen(int addr);
unsigned char* I2Cread();
void I2Cwrite(char buffer[],int len);