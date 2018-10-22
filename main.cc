// Developed by Mark Gomes
// Handles viewports and polygon animation and transformation
// 09/26/18

#include "includes.h"
#include "constants.h"
#include "prototypes.h"

#include "Graphics.h"
#include "Shape.h"

using namespace std;


int main(int argc, char** argv)
{
	Graphics::myglutInit(argc,argv);     //set up the graphics
	Graphics::myInit();
    
	Shape::defineBasePoints();        //set up the initial shape of tree
	
	glutMouseFunc(mouse);               //checks for user input
	glutKeyboardFunc(keyboard);	 	
	glutSpecialFunc(SpecialInput);
	glutDisplayFunc(display);		    //display everyframe 
	glutMainLoop();				        //enters event loop
}
