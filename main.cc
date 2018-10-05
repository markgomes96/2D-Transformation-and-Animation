// Developed by Mark Gomes
// Handles viewports and polygon animation and transformation
// 09/26/18

#include "includes.h"
#include "constants.h"
#include "prototypes.h"

#include "Graphics.h"

using namespace std;

int main(int argc, char** argv)
{
	Graphics graphics;
	
	/*
	graphics.setWindowPosition(WINDOW_POS_X, WINDOW_POS_Y);
	graphics.setWindowSize(WINDOW_MAX_X, WINDOW_MAX_Y);
	graphics.setViewportDim(VIEWPORT_MIN_X, VIEWPORT_MAX_X, VIEWPORT_MIN_Y, VIEWPORT_MAX_Y);
	*/

	graphics.myglutInit(argc,argv);
    	graphics.myInit();
	
	glutMouseFunc(mouse);  			//checks for user input
	glutKeyboardFunc(keyboard);	 	
	glutSpecialFunc(SpecialInput);
	glutDisplayFunc(display);		//display everyframe 
	glutMainLoop();				//enters event loop
}
