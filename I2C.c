#include "I2C.h"
int i2c;
void I2Copen(int addr)
{
		char *filename = (char*)"/dev/i2c-1";
	if ((i2c = open(filename, O_RDWR)) < 0)
	{
		printf("ERROR: Failed to open the i2c bus\n");
		return 1;
	}
	
	int addr1 = 0x27;
	if (ioctl(i2c, I2C_SLAVE, addr1) < 0)
	{
		printf("ERROR: Failed to acquire bus access and/or talk to slave.\n");
		return 1;
	}
    return 1;
}
	
unsigned char* I2Cread()
{
    char buffer;
	if (read(i2c,buffer, READPACKETSIZE) != READPACKETSIZE)
		printf("ERROR: Failed to read from the i2c bus.\n");
    return buffer;
}
	

void I2Cwrite(char buffer[],int length)
{
		if (write(i2c, buffer, length) != length)
    {
		printf("ERROR: Failed to write into the i2c bus. input %c\n",buffer[0]);
	}
}