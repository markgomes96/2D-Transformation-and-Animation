#include "includes.h"
#include "constants.h"
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
				if(checkBounds(x, y))		//point within bounds
				{
					if(deltaspin > -10.0)		//max CCW spin at 10 degrees per iteration
					{
						deltaspin = deltaspin - 0.5;	//increase rotation in CCW
		        			glutIdleFunc(spinDisplay);
					}
					animState = playanim;
				}
				else				//point outside bounds
				{
					scalarvect.x += 0.05;		//increase scale
					scalarvect.y += 0.05;
					glutPostRedisplay();
				}
		    	}
            	break;
        	case GLUT_RIGHT_BUTTON:
		    	if (state == GLUT_DOWN)
		    	{
				if(checkBounds(x, y))		//point within bounds
				{
					if(deltaspin < 10.0)		//max CW spin at 10 degrees per iteration
					{
						deltaspin = deltaspin + 0.5;	//increase rotation CW
		        			glutIdleFunc(spinDisplay);
					}
					animState = playanim;
				}
				else				//point outside bounds
				{
					if(scalarvect.x > 0.0)		//prevent scale from reversing
					{
						scalarvect.x -= 0.05;		//decrease scale
						scalarvect.y -= 0.05;
						glutPostRedisplay();
					}
				}
		    	}
            	break;
        	default:
            	break;
    	}
}

bool checkBounds(int x, int y)		//returns true is within bounds
{
	if(x > viewportMinX && x < viewportMaxX)
	{
		if(y > viewportMinY && y < viewportMaxY)
		{
			return true;
		}
	}
	return false;
}

void keyboard( unsigned char key, int x, int y )
{ 
	if ( key == 'f' || key == 'F')		// Fill the polygon in with tesselation
	{
		displayState = tessfill;
	}	
	if ( key == 't' || key == 'T')		// Display outlines of triangles used in tesselation
	{
		displayState = tesstriangle;
	}
	if ( key == 'l' || key == 'L')		// Return polyon to an outline
	{
		displayState = outline;
	}
	if ( key == 'r' || key == 'R')		//reflect current image about the vertical axis at center point
	{
		reflection = reflection * -1;
		spin = spin * -1;
	}
	if ( key == 's' || key == 'S')		//stops any animations
	{
		animState = stopanim;
	}
	if ( key == 'i' || key == 'I')		//stops any animations and return tree to intial position
	{
		animState = resetanim;
	}
	if ( key == 'b' || key == 'B')		//toggles on/off bound resizing
	{
		if(resizeBoundMode)
			resizeBoundMode = false;
		else
			resizeBoundMode = true;
	}
	if ( key == 'q' || key == 'Q') 		//exit the program
	{
		printf("FARWELL, POWERING OFFFF...\n");
		exit(0);
	}
	glutPostRedisplay();
}

void SpecialInput(int key, int x, int y)
{
	switch(key)		//moves the center point 5 pixels in inputed direction
	{
		case GLUT_KEY_UP:
			if(resizeBoundMode)
			{
				viewportMinY -= 5;
				viewportMaxY += 5;
			}
			else
			{
				cp.y += 5;
			}
			break;
			
		case GLUT_KEY_DOWN:
			if(resizeBoundMode)
			{
				viewportMinY += 5;
				viewportMaxY -= 5;
			}
			else
			{
				cp.y -= 5;
			}
			break;
			
		case GLUT_KEY_LEFT:
			if(resizeBoundMode)
			{
				viewportMinX += 5;
				viewportMaxX -= 5;
			}
			else
			{
				cp.x -= 5;
			}
			break;
			
		case GLUT_KEY_RIGHT:
			if(resizeBoundMode)
			{
				viewportMinX -= 5;
				viewportMaxX += 5;
			}
			else
			{
				cp.x += 5;
			}
			break;
	}
	glutPostRedisplay();
}
