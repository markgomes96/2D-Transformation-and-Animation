#include "includes.h"
#include "prototypes.h"

void mouse( int button, int state, int x, int y )
{ 	
	switch (button) 
	{
        	case GLUT_LEFT_BUTTON:
		    	if (state == GLUT_DOWN)
		    	{
		        	DELTA_SPIN = DELTA_SPIN - 1.0;
		        	glutIdleFunc(SpinDisplay);
		    	}
            	break;
        	case GLUT_RIGHT_BUTTON:
		    	if (state == GLUT_DOWN)
		    	{
		        	DELTA_SPIN = DELTA_SPIN + 1.0;
		        	glutIdleFunc(SpinDisplay);
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
