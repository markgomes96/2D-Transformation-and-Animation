// Developed by Mark Gomes
// Handles viewports and polygon animation and transformation
// 09/26/18

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

//typedef enum {false, true} bool;

// Specity the values to place and size the window on the screen

const int WINDOW_POSITION_X = 100;
const int WINDOW_POSITION_Y = 100;
const int WINDOW_MAX_X = 800;
const int WINDOW_MAX_Y = 800;

// Specify the coordinate ranges for the world coordinates in the 2D Frame

const float WORLD_COORDINATE_MIN_X = 0.0;
const float WORLD_COORDINATE_MAX_X = 800.0;
const float WORLD_COORDINATE_MIN_Y = 0.0;
const float WORLD_COORDINATE_MAX_Y = 800.0;


void mouse( int button, int state, int x, int y )
{ 
	int sy = WORLD_COORDINATE_MAX_Y - y;	//converts mouse coordinates to screen coordinates
	
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
		//do something here
			break;
			
		case GLUT_KEY_DOWN:
		//do something here
			break;
			
		case GLUT_KEY_LEFT:
		//do something here
			break;
			
		case GLUT_KEY_RIGHT:
		//do something here
			break;
	}
}

int main(int argc, char** argv)
{
	glutSpecialFunc(SpecialInput);

}
