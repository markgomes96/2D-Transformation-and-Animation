// Developed by Mark Gomes
// Handles viewports and polygon animation and transformation
// 09/26/18

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <string>

#include "Graphics.h"

using namespace std;

//Variables to specify window position 
const int WINDOW_POS_X = 100;
const int WINDOW_POS_Y = 100;

//Variables to specify window size
const int WINDOW_MAX_X = 1000;
const int WINDOW_MAX_Y = 1000;

//Variables to specify veiwport dimensions
const int VIEWPORT_MIN_X = 100.0;
const int VIEWPORT_MAX_X = 900.0;
const int VIEWPORT_MIN_Y = 100.0;
const int VIEWPORT_MAX_Y = 900.0;


void mouse( int button, int state, int x, int y )
{ 
	int sy = VIEWPORT_MAX_Y - y;	//converts mouse coordinates to screen coordinates
	
	if ( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )	//handles right click
	{
	
	}
	
	if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )		//handles left click
	{
	
	}
}

void keyboard( unsigned char key, int x, int y )
{ 
	// Fill the polygon in with tesselation
	if ( key == 'f' || key == 'F')
	{
		//drawPolygon();
	}
	
	// Display outlines of triangles used in tesselation
	if ( key == 't' || key == 'T')
	{
		//tesselatePolygon(false);
	}

	// Return polyon to an outline
	if ( key == 'l' || key == 'L')
	{
		//drawOutline();
	}

	// Reflect current image about the vertical axis at center point
	if ( key == 'r' || key == 'R')
	{
		//tesselatePolygon(false);
	}

	// Stops any animations
	if ( key == 's' || key == 'S')
	{
		//drawOutline();
	}

	// Stops any animations and return tree to intial position
	if ( key == 'i' || key == 'I')
	{
		//drawOutline();
	}
	
	// Exit the program
	if ( key == 'q' || key == 'Q') 
	{
		printf("Goodbye...\n");
		exit(0);
	}
}

void SpecialInput(int key, int x, int y)
{
	switch(key)		//moves the center point 5 pixels in inputed direction
	{
		case GLUT_KEY_UP:
			printf("up pressed");
			break;
			
		case GLUT_KEY_DOWN:
			printf("down pressed");
			break;
			
		case GLUT_KEY_LEFT:
			printf("left pressed");
			break;
			
		case GLUT_KEY_RIGHT:
			printf("right pressed");
			break;
	}
}


int main(int argc, char** argv)
{
	Graphics graphics;
	
	graphics.setWindowPosition(WINDOW_POS_X, WINDOW_POS_Y);
	graphics.setWindowSize(WINDOW_MAX_X, WINDOW_MAX_Y);
	graphics.setViewportDim(VIEWPORT_MIN_X, VIEWPORT_MAX_X, VIEWPORT_MIN_Y, VIEWPORT_MAX_Y);
	
	graphics.myglutInit(argc,argv);
    	graphics.myInit();
	//graphics.display();	

	//glutDisplayFunc(graphics.display()); 		// display callback invoked when window opened
	
	glutMouseFunc(mouse);  			//checks for user input
	glutKeyboardFunc(keyboard);	 	
	glutSpecialFunc(SpecialInput);

	glutMainLoop();				//enters event loop
}
