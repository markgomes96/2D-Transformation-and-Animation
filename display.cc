#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"

#include "Graphics.h"
#include "globals.h"

void display( void )
{
	glClear(GL_COLOR_BUFFER_BIT);		//clear the window

	glColor3f(1.0, 1.0, 1.0);
  glRecti(VIEWPORT_MIN_X, VIEWPORT_MIN_Y, VIEWPORT_MAX_X, VIEWPORT_MAX_Y);    //set viewport
    
  Graphics::drawOutline(shapelist, color(1.0, 0.0, 0.0));    //draw outline of shape

	glFlush(); 					//forces buffer to be drawn
}
