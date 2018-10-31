#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"
#include "Graphics.h"
#include "globals.h"

/*
*Retrace through and check everything
*Check every possible shape
*Check for multiple shapes
*Check for colinear lines(slopes the same)
*/

void clipPolygon(vertex *vp, int vc, vertex *bp, int bpc)
{	
	vector3D boundvect;
	vertex boundstart;
	vertex boundend;

	vector3D polyvect;
	vertex polystart;
	vertex polyend;

	vector3D cpvect;
	bool insideBounds;
	vertex intpoint;
	vector<vertex> inputlist;
	vector<vertex> outputlist;

	inputlist = *vp;	//move vp over to input list *error*
	for(int i = 0; i < bpc; i++)		//iterate through all boundary edges
	{
		boundstart = vertex((bp+i) -> x, (bp+i) -> y, (bp+i) -> z);		//update bound vertices and vectors

		if(i+1 == bpc)
			boundend = vertex((bp) -> x, (bp) -> y, (bp) -> z);		//if last point use first point as end
		else
			boundend = vertex((bp+i+1) -> x, (bp+i+1) -> y, (bp+i+1) -> z);

		boundvect = vector3D( boundend.x - boundstart.x , boundend.y - boundstart.y , boundend.z - boundstart.z );

		for(int j = 0; j < inputlist.size(); j++)	//check boundary intersection for all lines
		{
			polystart = vertex(inputlist[j].x, inputlist[j].y, inputlist[j].z, 1);		//update poly vertices and vectors

			if(j+1 == inputlist.size())		//if last point use first point as end
				polyend = vertex(inputlist[0].x, inputlist[0].y, inputlist[0].z, 1);
			else
				polyend = vertex(inputlist[j+1].x, inputlist[j+1].y, inputlist[j+1].z, 1);

			polyvect = vector3D( boundstart.x - polystart.x , boundstart.y - polystart.y , boundstart.z - polystart.z );

			cpvect = crossProduct(polyvect, boundvect);		//check if first poly point is outside/inside
			if(cpvect.z < 0)			//point is outside bounds
				insideBounds = false;
			else					//point is inside bounds
				insideBounds = true;

			intpoint = getLineIntersection(boundstart, boundend, polystart, polyend);	//get point of line intersection
			if(pointWithinLineBounds(intpoint, polystart, polyend)				//check if point is within line segment bounds
			{
				if(insideBounds = false)	//going outside -> inside
				{
					outputlist.push_back(intpoint);		//add boundary intercept
				}
				else				//going inside -> outside
				{
					outputlist.push_back(polystart);		//add inside point / boundary intercept
					outputlist.push_back(intpoint);
				}
			}
			else 
			{
				outputlist.push_back(polystart);		//add startpoint
			}
		}
		inputlist = outputlist;		//copy over output to new input
	}
}

vertex getLineIntersection(vertex p1, vertex p2, vertex p3, vertex p4)
{
	float slope1 = (p2.y - p1.y) / (p2.x - p1.x);
	float yint1 = (slope1 * p1.x) + p1.y;
	float slope2 = (p4.y - p3.y) / (p4.x - p3.x);
	float yint2 = (slope2 * p3.x) + p3.y;

	vertex intpoint = vertex(0,0,0,1);
	//check if lines have the same slope, if they do then -> ?
	intpoint.x = (yint2 - yint1) / (slope1 - slope2);
	intpoint.y = (slope1 * intpoint.x) + yint1;

	return intpoint;
}

bool pointWithinLineBounds(vertex p, vertex lstart, vertex lend)
{
	if(p.x > min(lstart.x, lend.x) && p.x < max(lstart.x, lend.x))
	{
		if(p.y > min(lstart.y, lend.y) && p.y < max(lstart.y, lend.y))
		{
			return true;		//point is within line bounds
		}
	}
	return false;			//point not within line bounds
}
