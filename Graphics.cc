#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"

#include "Graphics.h"

using namespace std;
/*
Graphics :: Graphics()		//default constructor
{

}
*/
void Graphics :: myglutInit( int argc, char** argv )
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_MAX_X, WINDOW_MAX_Y); 		                // set pixel window
	glutInitWindowPosition(WINDOW_POS_X, WINDOW_POS_Y); 		// place window top left on display
	glutCreateWindow("Polygon Animation");	                        //window title
}

void Graphics :: myInit(void)
{
	//standard OpenGL attributes
	glClearColor(0.0, 0.0, 0.0, 1.0);           //black background
	glColor3f(1.0, 0.0, 0.0);                   // draw in red
	glPointSize(10.0);
	glLineWidth(3.0);

	//set up viewing window with origin lower left
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WINDOW_MAX_X, 0.0, WINDOW_MAX_Y);
	glMatrixMode(GL_MODELVIEW);
	
	//glutDisplayFunc(display);
}

void Graphics :: drawPoint( int x, int y )		//Draw point onto the screen
{
	glColor3ub( 255, 0, 0 );
    
	glBegin(GL_POINTS);
		glVertex2i( x, y ); 
	glEnd();
 
	glFlush();
}


void Graphics :: drawOutline(vector<vertex> vl, color c)		//Draw outline of polygon with line loops
{
	glColor3f (c.red, c.green, c.blue);			//change color to prefered color
	
	glBegin ( GL_LINE_LOOP );
  vector<vertex>::iterator it;
  for(it = vl.begin(); it != vl.end(); it++)
  {
    glVertex2i ( it -> x , it -> y );
  }
	glEnd();
	
	glFlush();
}

void Graphics :: drawPolygon(vector<vertex> vl, color c)		//Draw filled polygon from list of points
{
	glColor3f (c.red, c.green, c.blue);			//change color to prefered color
	
	glBegin ( GL_POLYGON );
  vector<vertex>::iterator it;
  for(it = vl.begin(); it != vl.end(); it++)
  {
    glVertex2i ( it -> x , it -> y );
  }
	glEnd();
	
	glFlush();
}
