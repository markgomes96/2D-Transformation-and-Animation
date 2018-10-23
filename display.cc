#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"

#include "Graphics.h"
#include "globals.h"

/*
*convert vector list to an array
*make global be an array
*have pointer to temp array for transformed points
*/


void display( void )
{
	/*
	int inPoints;             // The number of points in the arrow 
	float point[MAX];         // Array to hold homogenous coordinates for arrow
	float *apts;              // Pointer for point array 

	struct vertex inVertexArray[MAX/4];	//array of vertices to hold points
	struct vertex *invp;                	//Pointer for inVertexArray
 
	apts = &point[0];         // the pointer to the array of points 
	invp = &inVertexArray[0]; // the pointer to the array of vertices
	*/

	glClear(GL_COLOR_BUFFER_BIT);		//clear the window

	glColor3f(1.0, 1.0, 1.0);
	glRecti(VIEWPORT_MIN_X, VIEWPORT_MIN_Y, VIEWPORT_MAX_X, VIEWPORT_MAX_Y);    //set viewport
    
	Graphics::drawOutline(vertexlist, color(1.0, 0.0, 0.0));    //draw outline of shape

	//tessellate();
	//Graphics::drawTessPolygon(trianglelist, color(1.0, 0.0, 0.0));

	/* Now start the process of rotating */
	PipeLine( apts, inPoints );			//apply transformations
	toVertex( apts, invp, inPoints );	
	
	glutSwapBuffers(); 					//forces buffer to be drawn
}

void PipeLine( float *vp, int vpts )
{
    // this routine will run the graphics transformation pipeline
    /* Set up useful temporary variables */
    float TransformationMatrix[16];
    float *TM;

    /* Don't forget to initialize the ponter! */
    TM = &TransformationMatrix[0];

    // Translate to origin  
    buildTranslate( -WINDOW_MAX/2, -WINDOW_MAX/2, 0.0,  TM );
    applyTransformation( vp, vpts, TM );   	
    // Perform the rotation operation
    buildRotateZ( SPIN, TM );	
    applyTransformation( vp, vpts, TM );
    // Translate back to point
    buildTranslate( WINDOW_MAX/2, WINDOW_MAX/2, 0.0,  TM );
    applyTransformation( vp, vpts, TM );   	

}
