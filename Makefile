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

INCLUDES   = includes.h
HEADERS    = constants.h structs.h Graphics.h
PROTOTYPES = prototypes.h
OBJS 	   = Graphics.o input.o display.o

all : anitran

anitran: main.o $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(OBJS) 
	$(C++) -o anitran main.o $(OBJS) $(INCDIRS) $(LIBDIRS) $(LDLIBS) 

Graphics.o : Graphics.cc  $(OBJS) $(INCLUDES) $(HEADERS) $(PROTOTYPES)
	$(C++) -c Graphics.cc

display.o : display.cc $(OBJS) $(INCLUDES) $(HEADERS) $(PROTOTYPES) 
	$(C++) -c display.cc

input.o : input.cc $(INCLUDES)  
	$(C++) -c input.cc

main.o : main.cc $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(OBJS) 
	$(C++) -c main.cc 

clean :
	rm *.o

reset :
	rm *.o
	rm anitran
