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
    
	//Graphics::drawOutline(vertexlist, color(1.0, 0.0, 0.0));    //draw outline of shape

	//tessellate();
	//Graphics::drawTessPolygon(trianglelist, color(1.0, 0.0, 0.0));

	int vertCount = vertexlist.size();
	vertex templist[vertCount];		//create temp array of current vertexlist
	vertex *tmp;					//pointer to temp array
	tmp = &templist[0];

	vector<vertex>::iterator it;
	int index = 0;
	for(it = vertexlist.begin(); it != vertexlist.end(); ++it)	//copy vertex points over to a temp array
	{
		templist[index].x = it -> x;
		templist[index].y = it -> y;
		templist[index].z = it -> z;
		templist[index].w = it -> w;
		index++;
	}

	PipeLine(tmp, vertCount);			//apply transformations	

	Graphics::drawOutline(tmp, vertCount, color(1.0, 0.0, 0.0));
	
	glutSwapBuffers(); 					//forces buffer to be drawn
}

void PipeLine(vertex *vp, int vc)	//vp - pointer to temp array; vc - number of vertices
{
	// this routine will run the graphics transformation pipeline
	float transformMatrix[16];		//set up the tranformation matrix and pointer
	float *tm;
	tm = &transformMatrix[0];

	//Apply Scalar
	/*
	buildTranslate( -cp.x, -cp.y, 0.0, tm);		//translate to origin 
	applyTransformation( vp, vc, tm );
	buildScale( scalarvect, tm );			//perform the scaling operation
	applyTransformation( vp, vc, tm );
	buildTranslate( cp.x, cp.y, 0.0,  tm );		//translate back to point
	applyTransformation( vp, vc, tm );
	*/

	//Apply Rotation
	buildTranslate( -cp.x, -cp.y, 0.0, tm);		//translate to origin 
	applyTransformation( vp, vc, tm );
	buildRotateZ( spin, tm );			//perform the rotation operation
	applyTransformation( vp, vc, tm );
	buildTranslate( cp.x, cp.y, 0.0,  tm );		//translate back to point
	applyTransformation( vp, vc, tm );

	//Apply Reflection
	buildTranslate( -cp.x, -cp.y, 0.0, tm);		//translate to origin 
	applyTransformation( vp, vc, tm );
	buildReflectVert( reflection, tm );		//perform the reflection operation
	applyTransformation( vp, vc, tm );
	buildTranslate( cp.x, cp.y, 0.0,  tm );		//translate back to point
	applyTransformation( vp, vc, tm );
}

void spinDisplay(void)
{
	spin = spin + deltaspin;
	if (spin > 360.0)
	{ 
		spin = spin - 360.0;
	}
	glutPostRedisplay();
}
