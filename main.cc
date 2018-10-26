// Developed by Mark Gomes
// Handles viewports and polygon animation and transformation
// 09/26/18

#include "includes.h"
#include "constants.h"
#include "globals.h"
#include "prototypes.h"

#include "Graphics.h"
#include "Shape.h"

using namespace std;


int main(int argc, char** argv)
{
	viewportMinX = VIEWPORT_MIN_X;
	viewportMaxX = VIEWPORT_MAX_X;
	viewportMinY = VIEWPORT_MIN_Y;
	viewportMaxY = VIEWPORT_MAX_Y;

	cout << "***ATTENTION***" << endl;
	cout << "Screen can be resized by toggling [b/B] and using the [arrow] keys : " << endl;
	cout << "				      [^] UP - Increase Vertically" << endl;
	cout << "[<-] LEFT - Decrease Horizontally" << "					[->] RIGHT - Increase Horizontally" << endl;
	cout << "				      [!] DOWN - Increase Vertically" << endl;

	Graphics::myglutInit(argc,argv);     //set up the graphics
	Graphics::myInit();
    
	Shape::defineBasePoints();        //set up the initial shape of tree
	
	glutMouseFunc(mouse);               //checks for user input
	glutKeyboardFunc(keyboard);	 	
	glutSpecialFunc(SpecialInput);
	glutDisplayFunc(display);		    //display everyframe 
	glutMainLoop();				        //enters event loop
}
