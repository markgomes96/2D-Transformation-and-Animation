#include "includes.h"
#include "prototypes.h"

#include "Graphics.h"
#include "globals.h"

void mouse( int button, int state, int x, int y )
{ 	
	switch (button) 
	{
        	case GLUT_LEFT_BUTTON:
		    	if (state == GLUT_DOWN)
		    	{
		        	deltaspin = deltaspin - 2.0;
		        	glutIdleFunc(spinDisplay);
		    	}
            	break;
        	case GLUT_RIGHT_BUTTON:
		    	if (state == GLUT_DOWN)
		    	{
		        	deltaspin = deltaspin + 2.0;
		        	glutIdleFunc(spinDisplay);
		    	}
            	break;
        	default:
            	break;
    	}
}

void keyboard( unsigned char key, int x, int y )
{ 
	// Fill the polygon in with tesselation
	if ( key == 'f' || key == 'F')
	{
		
	}
	
	// Display outlines of triangles used in tesselation
	if ( key == 't' || key == 'T')
	{
		
	}

	// Return polyon to an outline
	if ( key == 'l' || key == 'L')
	{
		
	}

	// Reflect current image about the vertical axis at center point
	if ( key == 'r' || key == 'R')
	{
		reflection = reflection * -1;
		spin = spin * -1;
	}

	// Stops any animations
	if ( key == 's' || key == 'S')
	{
		
	}

	// Stops any animations and return tree to intial position
	if ( key == 'i' || key == 'I')
	{
		
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
