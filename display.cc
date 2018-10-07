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
  glRecti(VIEWPORT_MIN_X, VIEWPORT_MIN_Y, VIEWPORT_MAX_X, VIEWPORT_MAX_Y);
    
  /*
	glBegin(GL_POINTS);
		glVertex2i(400, 400); 
	glEnd();
  */

  //drawPolygon(vl, color(1.0, 0.0, 0.0));
  //cout << shapelist[0].x << endl;
  Graphics::drawPolygon(shapelist, color(1.0, 0.0, 0.0));

	glFlush(); 					//forces buffer to be drawn
}
