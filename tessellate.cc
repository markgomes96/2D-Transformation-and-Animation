#include "includes.h"
#include "constants.h"
#include "globals.h"
#include "structs.h"
#include "prototypes.h"
#include "Graphics.h"

void tessellate(vertex *dl, int dc)
{
	int colinearCounter = 0;
	int vertCount = dc;
	int pi = 0;

	vertex tempList[dc];			//array to implement ear clipping algorithm
	vertex intTempList[dc];		//array to check for intersection

	for(int i = 0; i < dc; i++)		//copy draw array over to temp arrays
	{
		tempList[i] = *(dl+i);
		intTempList[i] = *(dl+i);
		//cout << "( " << (dl+i) -> x << " , " << (dl+i) -> y << " ) " << endl;		//print all points going in
	}

	//Earclipping algorithm
	vertex fp, mp, ep;				//first point, midpoint, endpoint
	vector3D v1, v2, cp;				//vectors to calculate the crossproduct
	bool intersectFlag = false;
	vertex np;
	while(vertCount > 3)
	{
		//Get next 3 points based on point index
		fp = tempList[pi];
		mp = tempList[pi+1];
		ep = tempList[pi+2];

		/*
		cout << "pi :" << pi << endl;
		for(int i = 0; i < dc; i++)
			cout << "( " << tempList[i].x << " , " << tempList[i].y << " )" << endl;	//print templist
		cout << "****************" << endl << endl;
		*/
	
        	//check the cross product to see if points go counter clockwise
		v1 = vector3D((fp.x - mp.x), (fp.y - mp.y), 0.0);
		v2 = vector3D((ep.x - mp.x), (ep.y - mp.y), 0.0);
       		cp = crossProduct(v1, v2);

		intersectFlag = false;				//flag to check if line cuases an intersections

		if(abs(cp.z) < 0.0000001)		//check if points are colinear
        	{
			//cout << "( " << fp.x << " , " << fp.y << " )  ("<< mp.x << " , " << mp.y << " )  ( " << ep.x << " , " << ep.y << " )" << endl;
			//remove the midpoint
			vertCount--;

			//move up all points that aren't null
			for(int i = pi+1; i < vertCount; i++)
			{
				//tempList[i] = tempList[i+1];
				tempList[i].x = tempList[i+1].x;
				tempList[i].y = tempList[i+1].y;
				tempList[i].z = tempList[i+1].z;
				tempList[i].w = tempList[i+1].w;
			}
			//tempList[vertCount] = vertex(0.0, 0.0, 0.0, 0.0);
			tempList[vertCount].x = 0.0;
			tempList[vertCount].y = 0.0;
			tempList[vertCount].z = 0.0;
			tempList[vertCount].w = 0.0;

			//return to first 3 points
			pi = 0;
			colinearCounter++;
			//cout << "***points were COLINEAR***" << endl << endl;
        	}
        	else if(cp.z < 0.0)		//check if current 3 points are CCW
        	{
			//cout << "***points were CCW***" << endl << endl;
			for(int i = 0; i < dc; i++)		//check intersection for line between ep -> fp with all lines
			{
				if(isSamePoint(fp, intTempList[i]) || isSamePoint(mp, intTempList[i]) || isSamePoint(ep, intTempList[i]))
				{
					//test point is same as one of boundary points
				}
				else if(pointWithinBounds(fp, mp, ep, intTempList[i]))
				{
					intersectFlag = true;
					//cout << "Line Intersection : ( " << intTempList[i].x << " , " << intTempList[i].y << " ) " << endl << endl;
					break;
				}
			}
		
			if(!intersectFlag)
			{
				v1 = vector3D((mp.x - ep.x), (mp.y - ep.y), 0.0);					//check if interior angle is smaller than anterior angle
				
				if(pi+3 < vertCount)			//check if pi is at array end
				{
					np = tempList[pi+3];
				}
				else
				{
					np = tempList[0];
				}
				v2 = vector3D((np.x - ep.x), (np.y - ep.y), 0.0);	

				if(crossProduct(v1, v2).z < 0.0)			//check if next two lines are CCW
				{
					if(vectorAngle(mp, ep, fp) > vectorAngle(mp, ep, np))		//check if line is an interior line
					{
						intersectFlag = true;
						//cout << "Angle Intersection" << endl << endl;
					}
				}
			}

			//check if the lines intersect
			if(!intersectFlag)
			{
				//add triangle to triangle list
                		trianglelist.push_back(triangle(fp, mp, ep));

                		//remove the midpoint
				vertCount--;
	
                		//move up all the points that aren't null
                		for(int i = pi+1; i < vertCount; i++)
                		{
                    			//tempList[i] = tempList[i+1];
					tempList[i].x = tempList[i+1].x;
					tempList[i].y = tempList[i+1].y;
					tempList[i].z = tempList[i+1].z;
					tempList[i].w = tempList[i+1].w;
                		}
				//tempList[vertCount] = vertex(0.0, 0.0, 0.0, 0.0);
				tempList[vertCount].x = 0.0;
				tempList[vertCount].y = 0.0;
				tempList[vertCount].z = 0.0;
				tempList[vertCount].w = 0.0;

				//return to first 3 points
				pi = 0;

				//cout << "***points were VALID***" << endl << endl;
			}
			else
			{
				//move to the next set of 3 points
				pi++;
				//cout << "***points were NOT VALID***" << endl << endl;
			}
        	}
        	else		//check if points are CW
        	{
            		//move to the next set of 3 points 
			pi++;
			//cout << "***points were CW***" << endl << endl;
        	}
	}

	//Add last 3 vertices
	trianglelist.push_back(triangle(tempList[0], tempList[1], tempList[2]));
}

bool isSamePoint(vertex p1, vertex p2)		//determines if two points are the same
{
	if(abs(p1.x - p2.x) < 0.0000001 && abs(p1.y - p2.y) < 0.0000001)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float vectorAngle(vertex fp, vertex mp, vertex ep)		//***Check if it works***//
{
	//find the angle of two vectors sharing middle point
	vector3D v1 = vector3D( (fp.x - mp.x), (fp.y - mp.y), 0.0);
	vector3D v2 = vector3D( (ep.x - mp.x), (ep.y - mp.y), 0.0);

	float va = acos( (double)dotProduct(v1, v2) / ( vectorMagnitude(v1) * vectorMagnitude(v2) ) );
	va = (va * 180) / M_PI;
	return va;
}   

bool pointWithinBounds(vertex b1, vertex b2, vertex b3, vertex p1)
{
	bool insideBounds = true;
	vector3D boundvect, testvect, cpvect;

	boundvect = vector3D( b1.x - b2.x , b1.y - b2.y , b1.z - b2.z );			//check 1st boundary
	testvect = vector3D( p1.x - b2.x , p1.y - b2.y , p1.z - b2.z );
	cpvect = crossProduct(testvect, boundvect);		//check if first poly point is outside/inside
	if(cpvect.z != 0.0)
	{	
		if(cpvect.z < 0.0)			//point is outside bounds
		{
			insideBounds = false;
		}
	}
	else
	{
		if(!pointWithinLineBounds(p1, b1, b2))
		{
			insideBounds = false;
		}
	}

	boundvect = vector3D( b2.x - b3.x , b2.y - b3.y , b2.z - b3.z );		//check 2nd boundary
	testvect = vector3D( p1.x - b3.x , p1.y - b3.y , p1.z - b3.z );
	cpvect = crossProduct(testvect, boundvect);		//check if first poly point is outside/inside
	if(cpvect.z != 0.0)
	{	
		if(cpvect.z < 0.0)			//point is outside bounds
		{
			insideBounds = false;
		}
	}
	else
	{
		if(!pointWithinLineBounds(p1, b2, b3))
		{
			insideBounds = false;
		}
	}

	boundvect = vector3D( b3.x - b1.x , b3.y - b1.y , b3.z - b1.z );		//check 3rd boundary
	testvect = vector3D( p1.x - b1.x , p1.y - b1.y , p1.z - b1.z );
	cpvect = crossProduct(testvect, boundvect);		//check if first poly point is outside/inside
	if(cpvect.z != 0.0)
	{	
		if(cpvect.z < 0.0)			//point is outside bounds
		{
			insideBounds = false;
		}
	}
	else
	{
		if(!pointWithinLineBounds(p1, b3, b1))
		{
			insideBounds = false;
		}
	}

	return insideBounds;
}

float dotProduct(vector3D v1, vector3D v2)
{
	float dp;
	dp = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);

	return dp;
}

float vectorMagnitude(vector3D v1)
{
    float vm;
    vm  = sqrt((v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z));
    return vm;
}

vector3D crossProduct(vector3D v1, vector3D v2)
{
	vector3D cp;
	cp.x = (v1.y * v2.z) - (v2.y * v1.z);
	cp.y = (v1.x * v2.z) - (v2.x * v1.z);
	cp.z = (v1.x * v2.y) - (v2.x * v1.y);

	return cp;
}
