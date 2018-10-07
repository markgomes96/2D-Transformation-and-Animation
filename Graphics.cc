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
	/*
	typedef GLfloat point[2];     
	point p;
 
	glColor3ub( red, green, blue );
   
	p[0] = x;
	p[1] = y;  
    
	glBegin(GL_POINTS);
		glVertex2fv(p); 
	glEnd();
	glFlush();
	*/
}


void Graphics :: drawOutline( void )		//Draw outline of polygon with line loops
{
	/*
	glClear ( GL_COLOR_BUFFER_BIT );
	glColor3f (1.0, 0.0, 0.0);			//change color to red

	glBegin ( GL_LINE_LOOP );
		point *current = startPoint -> next;
		while (current -> next != NULL)
	    	{
			glVertex2i ( current -> x, current -> y );
			current = current -> next;
	    	}
		glVertex2i ( current -> x, current -> y);
	glEnd();

	for(int i = 0; i < ti; i++)
	{
		//display triangle outline on screen
		glBegin ( GL_LINE_LOOP );
			glVertex2i ( triangleList[i].v1.x, triangleList[i].v1.y );
			glVertex2i ( triangleList[i].v2.x, triangleList[i].v2.y );
			glVertex2i ( triangleList[i].v3.x, triangleList[i].v3.y );
		glEnd();
	}

	glFlush();
	*/
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
