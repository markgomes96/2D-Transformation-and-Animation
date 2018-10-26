#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"
#include "Graphics.h"
#include "globals.h"

void clipPolygon(vertex *vp, int vc, vertex *bp, int bpc)
{
	vector<vertex> cv;		//resizable vector for clipped points

	cv.push_back(*(vp+i));
	for(int i = 0; i < bpc-1; i++)		//iterate through all boundary edges
	{
		if(
	}

	//convert vector to array
	//make *vp point to new clipped array
}


