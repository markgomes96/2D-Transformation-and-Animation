#Mark Gomes
#Makefile for programming assignment 2
#This Makefile compiles all the files in this project
# To use this Makefile, you type:
#
#        make anitran
#                   
#       
# A binary named anitran will be produced

CC = gcc
C++ = g++ 
LIBDIRS = -L/usr/lib64
INCDIRS = -I/usr/include
LDLIBS =  -lglut -lGL -lGLU -lX11 -lm
OBJS = Graphics.o
HDRS = Graphics.h

all : anitran

anitran : main.o $(OBJS)    
	$(CC)  $(CCFLAGS) main.o $(OBJS) $(INCDIRS) $(LIBDIRS) $(LDLIBS) -o anitran 

main.o : main.cc  $(HDRS)     
	$(CC) $(CCFLAGS) main.cc  -c 

Graphics.o : Graphics.cc  Graphics.h $(HDRS)  
	$(CC) $(CCFLAGS)  Graphics.cc  -c 

clean :
	rm *.o
