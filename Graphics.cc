#include "includes.h"
#include "structs.h"
#include "globals.h"
#include "constants.h"

#include "Graphics.h"

using namespace std;

void Graphics :: myglutInit( int argc, char** argv )
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_MAX_X, WINDOW_MAX_Y); 		                // set pixel window
	glutInitWindowPosition(WINDOW_POS_X, WINDOW_POS_Y); 		// place window top left on display
	glutCreateWindow("Polygon Animation");	                        //window title
}

void Graphics :: myInit(void)
{
	//standard OpenGL attributes
	glClearColor(0.0, 0.0, 0.0, 1.0);           //black background
	glColor3f(1.0, 0.0, 0.0);                   // draw in red
	glPointSize(1.0);
	glLineWidth(1.0);

	//set up viewing window with origin lower left
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WINDOW_MAX_X, 0.0, WINDOW_MAX_Y);
	glMatrixMode(GL_MODELVIEW);
}

void Graphics :: drawCenterPoint(vertex v, color c)		//Draw point onto the screen
{
	glColor3f (c.red, c.green, c.blue);		//change color to prefered color
    
	glBegin( GL_LINES );
		glVertex2f( v.x - 10 , v.y);		//draw cross at center point
		glVertex2f( v.x + 10 , v.y);

		glVertex2f( v.x , v.y + 10);
		glVertex2f( v.x , v.y - 10);
	glEnd();
}


void Graphics :: drawOutline(vector<vertex> vl, color c)		//Draw outline of polygon with line loops
{
	glColor3f (c.red, c.green, c.blue);			//change color to prefered color
	
	glBegin ( GL_LINE_LOOP );
		vector<vertex>::iterator it;
  		for(it = vl.begin(); it != vl.end(); it++)
		{
			glVertex2f ( it -> x , it -> y );
		}
	glEnd();
}

void Graphics :: drawTessPolygon(vector<triangle> tl, color c)
{
	glColor3f (c.red, c.green, c.blue);			//change color to prefered color
	
	vector<triangle>::iterator it;
	for(it = trianglelist.begin(); it != trianglelist.end(); ++it)
	{
		glBegin ( GL_POLYGON );
			glVertex2f ( it -> v1.x, it -> v1.y );
			glVertex2f ( it -> v2.x, it -> v2.y );	
        		glVertex2f ( it -> v3.x, it -> v3.y );	
		glEnd();
	}
}

void Graphics :: drawTessTriangle(vector<triangle> tl, color c)
{
	glColor3f (c.red, c.green, c.blue);			//change color to prefered color
	
	vector<triangle>::iterator it;
	for(it = trianglelist.begin(); it != trianglelist.end(); ++it)
	{
		glBegin ( GL_LINE_LOOP );
			glVertex2f ( it -> v1.x, it -> v1.y );
			glVertex2f ( it -> v2.x, it -> v2.y );	
        		glVertex2f ( it -> v3.x, it -> v3.y );	
			cout << "( " << it -> v1.x << " , " << it -> v1.y << " )" << endl;
			cout << "( " << it -> v2.x << " , " << it -> v2.y << " )" << endl;
			cout << "( " << it -> v3.x << " , " << it -> v3.y << " )" << endl;
			cout << endl;
		glEnd();
	}
}
