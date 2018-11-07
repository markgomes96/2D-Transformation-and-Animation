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
	vertex intTempList[dc+1];		//array to check for intersection

	for(int i = 0; i < dc; i++)		//copy draw array over to temp arrays
	{
		tempList[i] = *(dl+i);
		intTempList[i] = *(dl+i);
		cout << "( " << (dl+i) -> x << " , " << (dl+i) -> y << " ) " << endl;		//print all points going in
	}
	//tempList[dc] = *(dl);
	intTempList[dc] = *(dl);

	//Earclipping algorithm
	vertex fp, mp, ep;				//first point, midpoint, endpoint
	vector3D v1, v2, cp;				//vectors to calculate the crossproduct
	bool intersectFlag = false;
	while(vertCount > 3)
	{
		//Get next 3 points based on point index
		fp = tempList[pi];
		mp = tempList[pi+1];
		ep = tempList[pi+2];

        	//check the cross product to see if points go counter clockwise
		v1 = vector3D((fp.x - mp.x), (fp.y - mp.y), 0);
		v2 = vector3D((ep.x - mp.x), (ep.y - mp.y), 0);
       		cp = crossProduct(v1, v2);

		if(cp.z == 0.0)
		{
			Graphics::drawCenterPoint(fp, color(1.0, 0.0, 0.0));
			Graphics::drawCenterPoint(ep, color(0.0, 0.0, 1.0));
			Graphics::drawCenterPoint(mp, color(0.0, 0.0, 0.0));

			cout << "fp : ( " << fp.x << " , " << fp.y << " , " << fp.z << " , " << fp.w << " ) " << endl;
			cout << "mp : ( " << mp.x << " , " << mp.y << " , " << mp.z << " , " << mp.w << " ) " << endl;
			cout << "ep : ( " << ep.x << " , " << ep.y << " , " << ep.z << " , " << ep.w << " ) " << endl << endl;

			cout << "v1 : < " << v1.x << " , " << v1.y << " , " << v1.z << " > " << endl;
			cout << "v2 : < " << v2.x << " , " << v2.y << " , " << v2.z << " > " << endl << endl;
		}

		intersectFlag = false;				//flag to check if line cuases an intersections
		//check if current 3 points are CCW
        	if(cp.z < 0.0)
        	{
			for(int i = 0; i < dc+1; i++)		//check intersection for line between ep -> fp with all lines
			{
				//makes sure lines with same points aren't tested for intersection
                		if(sharePoint(ep, intTempList[i]) || sharePoint(ep, intTempList[i+1]) || sharePoint(fp, intTempList[i]) || sharePoint(fp, intTempList[i+1]))
               			{
             				//lines share a point
                		}
				else if(checkIntersection(intTempList[i], intTempList[i+1], ep, fp))	//checks if interior line intersects anterior lines
				{
					intersectFlag = true;
					break;
				}
			}
		
			if(!intersectFlag)
			{
				v1 = vector3D((mp.x - ep.x), (mp.y - ep.y), 0);					//check if interior angle is smaller than anterior angle
				v2 = vector3D((tempList[pi+3].x - ep.x), (tempList[pi+3].y - ep.y), 0);

				if(crossProduct(v1, v2).z < 0)			//check if next two lines are CCW
				{
					if(vectorAngle(mp, ep, fp) > vectorAngle(mp, ep, tempList[pi+3]))		//check if line is an interior line
					{
						intersectFlag = true;
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

				cout << "***points were VALID***" << endl << endl;
			}
			else
			{
				//move to the next set of 3 points
				pi++;
				cout << "***points were NOT VALID***" << endl << endl;
			}
        	}
        	else if(cp.z == 0.0)
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
			cout << "***points were COLINEAR***" << endl << endl;
        	}
        	else
        	{
            		//move to the next set of 3 points 
			pi++;
			cout << "***points were CW***" << endl << endl;
        	}

		for(int i = 0; i < dc; i++)
			cout << "( " << tempList[i].x << " , " << tempList[i].y << " )" << endl;	//print templist
		cout << "****************" << endl << endl;
	}

	//Add last 3 vertices
	trianglelist.push_back(triangle(tempList[0], tempList[1], tempList[2]));
	
	/*
	for(int i = 0; i < dc; i++)
	{	
		cout << i << " : ( " << tempList[i].x << " , " << tempList[i].y << " )" << endl << endl;
	}
	*/
	cout << "****colinearCounter: " << colinearCounter << " ****" << endl << endl;
}

bool sharePoint(vertex p1, vertex p2)		//determines if two points are the same
{
    if(p1.x == p2.x || p1.y == p2.y)
        return true;
    else
        return false;
}

float vectorAngle(vertex fp, vertex mp, vertex ep)		//***Check if it works***//
{
	//find the angle of two vectors sharing middle point
	vector3D v1 = vector3D( (fp.x - mp.x), (fp.y - mp.y), 0);
	vector3D v2 = vector3D( (ep.x - mp.x), (ep.y - mp.y), 0);

	float va = acos( (double)dotProduct(v1, v2) / ( vectorMagnitude(v1) * vectorMagnitude(v2) ) );
	va = (va * 180) / M_PI;
	return va;
}   

bool checkIntersection(vertex p1, vertex p2, vertex p3, vertex p4)		//***Check if it works***//
{
	float ADet = 0.0;
	float tADet = 0.0;
	float tBDet = 0.0;
	float tA = 0.0;
	float tB = 0.0;

	ADet = (float)( (p2.x - p1.x) * (-(p4.y - p3.y)) ) - ( (p2.y - p1.y) * (-(p4.x - p3.x)) );
	if(ADet == 0)		//Check if lines are parallel
	{
		float slope = (p2.y - p1.y) / (p2.x - p1.x);
		float yIntA = (slope * -p1.x) + p1.y;
		float yIntB = (slope * -p3.x) + p3.y;
		
		if(yIntA == yIntB)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	tADet = (float)( (p3.x - p1.x) * (-(p4.y - p3.y)) ) - ( (p3.y - p1.y) * (-(p4.x - p3.x)) );
	tBDet = (float)( (p2.x - p1.x) * (p3.y - p1.y) ) - ( (p2.y - p1.y) * (p3.x - p1.x) );

	tA = (float)tADet / (float)ADet;
	tB = (float)tBDet / (float)ADet;

	if( (tA >= 0.0 && tA <= 1.0) && (tB >= 0.0 && tB <= 1.0) )
	{
		return true;
	}
	else
	{
		return false;
	}
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
