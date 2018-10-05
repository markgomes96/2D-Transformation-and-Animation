#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"

#include "Graphics.h"

using namespace std;

Graphics :: Graphics()		//default constructor
{
	/*
	windowPosX = 100;
	windowPosY = 100;
	
	windowMaxX = 800;
	windowMaxY = 800;

	viewportMinX = 0.0;
	viewportMaxX = 800.0;
	viewportMinY = 0.0;
	viewportMaxY = 800.0;

	red = 255;	//set default color to red
	green = 0;
	blue = 0;
	*/
	
	//glutDisplayFunc(display); 		// display callback invoked when window opened
}

/*
void Graphics :: setWindowPosition(int _windowPosX, int _windowPosY)
{
	windowPosX = _windowPosX;
	windowPosY = _windowPosY;
}

void Graphics :: setWindowSize(int _windowMaxX, int _windowMaxY)
{
	windowMaxX = _windowMaxX;
	windowMaxY = _windowMaxY;
}

void Graphics :: setViewportDim(int _viewportMinX, int _viewportMaxX, int _viewportMinY, int _viewportMaxY)
{
	viewportMinX = _viewportMinX;
	viewportMaxX = _viewportMaxX;
	viewportMinY = _viewportMinY;
	viewportMaxY = _viewportMaxY;
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
	glClearColor(1.0, 1.0, 1.0, 1.0);           //white background
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

void Graphics :: drawPolygon( void )		//Draw filled polygon without tesselation
{
	/*
	glClear ( GL_COLOR_BUFFER_BIT );
	glColor3f (1.0, 0.0, 1.0);			//change color to purple
	
	glBegin ( GL_POLYGON );
		point *current = startPoint -> next;
		while (current -> next != NULL)
		{
			glVertex2i ( current ->  x, current -> y );
			current = current -> next;
		}
		glVertex2i ( current -> x, current -> y);
	glEnd();
	
	for(int i = 0; i < ti; i++)
	{
		glBegin ( GL_POLYGON );
			glVertex2i ( triangleList[i].v1.x, triangleList[i].v1.y );
			glVertex2i ( triangleList[i].v2.x, triangleList[i].v2.y );	
        		glVertex2i ( triangleList[i].v3.x, triangleList[i].v3.y );		
		glEnd();
	}
	
	glFlush();
	*/
}
