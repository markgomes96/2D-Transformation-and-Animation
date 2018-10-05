#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"

void display( void )
{
	glClear(GL_COLOR_BUFFER_BIT);		//clear the window

	//glColor3ub( red, green, blue ); 
 	glColor3ub( 255, 0, 0 );   
    
	glBegin(GL_POINTS);
		glVertex2i(400, 400); 
	glEnd();
    
	glFlush(); 					//forces buffer to be drawn
}
