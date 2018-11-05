#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"
#include "Graphics.h"
#include "globals.h"

void clipPolygon(vertex *vp, int vc, vertex *bp, int bpc)
{	
	vector3D boundvect;
	vertex boundstart;
	vertex boundend;

	vector3D polyvect;
	vertex polystart;
	vertex polyend;

	vector3D cpvect;
	bool insideBounds = false;
	bool isColinear = false;
	vertex intpoint;
	vector<vertex> inputlist;
	vector<vertex> outputlist;
	inputlist.clear();
	outputlist.clear();

	for(int i = 0; i < vc; i++)		//move vp over to input list
	{
		inputlist.push_back(*(vp+i));
		(vp+i) -> x = 0.0;			//zero out temp array
		(vp+i) -> y = 0.0;
		(vp+i) -> z = 0.0;
		(vp+i) -> w = 0.0;
		//cout << "( " << (vp+i) -> x << " , " << (vp+i) -> y << " , " << (vp+i) -> z << " , " << (vp+i) -> w << " )" << endl;
	}
	
	for(int i = 0; i < bpc; i++)		//iterate through all boundary edges
	{
		boundstart = vertex((bp+i) -> x, (bp+i) -> y, (bp+i) -> z, 1);		//update bound vertices and vectors

		if(i+1 == bpc)
			boundend = vertex((bp) -> x, (bp) -> y, (bp) -> z, 1);			//if last point use first point as end
		else
			boundend = vertex((bp+i+1) -> x, (bp+i+1) -> y, (bp+i+1) -> z, 1);

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
			if(cpvect.z != 0)
			{
				if(cpvect.z < 0)			//point is outside bounds
					insideBounds = false;
				else					//point is inside bounds
					insideBounds = true;
			}
			else
			{
				isColinear = true;
			}
		
			if(!isColinear)
			{
				intpoint = getLineIntersection(boundstart, boundend, polystart, polyend);	//get point of line intersection

				if(pointWithinLineBounds(intpoint, polystart, polyend))				//check if point is within line segment bounds
				{
					if(insideBounds == false)	//going outside -> inside
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
					if(insideBounds == false)	//completly outside / outside boundary
					{
						//don't add any vertices
					}
					else				//completly outside / inside boundary
					{
						outputlist.push_back(polystart);		//add startpoint
						//cout << "completly outside / inside boundary" << endl;
					}
					
				}
			}
			else
			{
				outputlist.push_back(polystart);		//add startpoint if line is colinear with boundary
				isColinear = false;
			}
		}

		inputlist.clear();
		for(int k = 0; k < outputlist.size(); k++)	//copy over output to new input
		{
			inputlist.push_back(outputlist[k]);
		}
		outputlist.clear();		//empty out the outputlist
	}

	for(int i = 0; i < inputlist.size(); i++)		//copy over input list to vp (passed in array)
	{
		*(vp+i) = inputlist[i];
	}
}


vertex getLineIntersection(vertex p1, vertex p2, vertex p3, vertex p4)
{
	vertex intpoint = vertex(0,0,0,1);
	float slope1, yint1, slope2, yint2;
	
	vertex polystart, polyend;
	if(p3.x < p4.x)
	{
		polystart = p3;
		polyend = p4;
	}
	else
	{
		polystart = p4;
		polyend = p3;
	}

	if(p1.x == p2.x)	//check for vertical bound line
	{
		if(polystart.x == polyend.x)		//if polygon line is also vertical
		{
			intpoint.x = -1000;
			intpoint.y = -1000;
		}
		else if(polystart.y == polyend.y)		//if polygon line is horizontal
		{
			intpoint.x = p1.x;
			intpoint.y = polystart.y;
		}
		else				//if polygon line has a slope
		{
			slope2 = (polyend.y - polystart.y) / (polyend.x - polystart.x);
			yint2 = (-1 * slope2 * polystart.x) + polystart.y;

			intpoint.x = p1.x;
			intpoint.y = (slope2 * p1.x) + yint2;
		}
	}
	else if(p1.y == p2.y)		//check for horizontal bound line
	{
		if(polystart.y == polyend.y)		//if polygon line is also horizontal
		{
			intpoint.x = -1000;
			intpoint.y = -1000;
		}
		else if(polystart.x == polyend.x)		//if polygon line is vertical
		{
			intpoint.x = polystart.x;
			intpoint.y = p1.y;
		}
		else				//if polygon line has a slope
		{
			slope2 = (polyend.y - polystart.y) / (polyend.x - polystart.x);
			yint2 = (-1 * slope2 * polystart.x) + polystart.y;

			intpoint.x = (p1.y - yint2) / slope2;
			intpoint.y = p1.y;
		}
	}
	else		//check for sloped bound line
	{
		if(polystart.y == polyend.y)		//if polygon line is horizontal
		{
			slope1 = (p2.y - p1.y) / (p2.x - p1.x);
			yint1 = (slope1 * p1.x) + p1.y;

			intpoint.x = (polystart.y - yint1) / slope1;
			intpoint.y = polystart.y;
		}
		else if(polystart.x == polyend.x)		//if polygon line is vertical
		{
			slope1 = (p2.y - p1.y) / (p2.x - p1.x);
			yint1 = (slope2 * p1.x) + p1.y;

			intpoint.x = polystart.x;
			intpoint.y = (-1 * slope2 * polystart.x) + yint1;
		}
		else				//if polygon line has a slope
		{
			float slope1 = (p2.y - p1.y) / (p2.x - p1.x);
			float yint1 = (-1 * slope1 * p1.x) + p1.y;
			float slope2 = (polyend.y - polystart.y) / (polyend.x - polystart.x);
			float yint2 = (-1 * slope2 * polystart.x) + polystart.y;

			intpoint.x = (yint2 - yint1) / (slope1 - slope2);
			intpoint.y = (slope1 * intpoint.x) + yint1;
		}
	}

	return intpoint;
}


bool pointWithinLineBounds(vertex p, vertex lstart, vertex lend)
{
	if(p.x >= min(lstart.x, lend.x) && p.x <= max(lstart.x, lend.x))
	{
		if(p.y >= min(lstart.y, lend.y) && p.y <= max(lstart.y, lend.y))
		{
			return true;		//point is within line bounds
		}
	}
	return false;			//point not within line bounds
}
