all:compileAll

compileAll: cpuTemp

cpuTemp:
	gcc cpuTemp.c -o cpuTemp

I2C.o:
	gcc I2C.c -c -o I2C.o

LCD.o:
	gcc LCD.c -c -o LCD.o

clear:
	rm *.o

LCD: I2C.o LCD.o
	gcc I2C.o LCD.o main.c -o LCDTest
