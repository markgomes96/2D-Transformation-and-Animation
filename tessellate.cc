#include "includes.h"
#include "constants.h"
#include "globals.h"
#include "structs.h"
#include "prototypes.h"

void tessellate(void)
{
	int vertCount = vertexlist.size();
	int pi = 0;

	vertex tempList[vertCount];			//array to implement ear clipping algorithm
	vertex intTempList[vertCount+1];		//array to check for intersection

	vector<vertex>::iterator it;
	int index = 0;
	for(it = vertexlist.begin(); it != vertexlist.end(); ++it)	//copy vertex points over to temp arrays
	{
		tempList[index] = *it;
		intTempList[index] = *it;
		index++;
	}
	intTempList[index] = vertexList.front();

	//*Earclipping algorithm*
	vertex fp, mp, ep;				//first point, midpoint, endpoint
	vector v1, v2, cp;				//vectors to calculate the crossproduct
	bool intersectFlag = false;
	int direction = 0;			//get direction of first 3 points
	while(vertCount > 3)
	{
		//Get next 3 points based on point index
		fp = tempList[pi];
		mp = tempList[pi+1];
		ep = temptList[pi+2];

        	//check the cross product to see if points go counter clockwise
        	v1 = vector((mp.x - fp.x), (mp.y - fp.y), 0);
        	v2 = vector((mp.x - ep.x), (mp.y - ep.y), 0);
       		cp = crossProduct(v1, v2);
		
		/*
 		*Check start direction first, store as 1 or -1
 		*/
		if(direction == 0)
		{
			direction = sign(cp.z);
		}

		//check if current 3 points are going in initial polygon direction
        	if(sign(cp.z) == direction)
        	{
			//flag to check if line cuases an intersections
			intersectFlag = false;
			
			for(int i = 0; i < verticesCount; i++)
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
	
			if(!intersectFlag)		//check if interior angle is smaller than anterior angle
			{
				v1 = vector((ep.x - mp.x), (ep.y - mp.y), 0);
				v2 = vector((ep.x - pointList[pi+3].x), (ep.y - pointList[pi+3].y), 0);

				if(sign(crossProduct(v1, v2).z) == direction)			//check if next two lines are CCW
				{
					if(vectorAngle(mp, ep, fp) > vectorAngle(mp, ep, intTempList[pi+3]))		//check if line is an interior line
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
                		ti++;

                		//remove the midpoint
				vertCount--;
	
                		//move up all the points that aren't null
                		for(int i = pi+1; i < vertCount; i++)
                		{
                    			tempList[i] = tempList[i+1];
                		}
				tempList[vertCount] = vertex(0, 0, 0, 0);

				//return to first 3 points
				pi = 0;
			}
			else
			{
				//move to the next set of 3 points
				pi++;
			}
        	}
        	else if(cp.z == 0)
        	{
			//remove the midpoint
			vertCount--;

			//move up all points that aren't null
			for(int i = pi+1; i < vertCount; i++)
			{
				templist[i] = tempList[i+1];
			}
        	}
        	else
        	{
            		//move to the next set of 3 points 
            		pi++;
        	}
	}

	//Add last 3 vertices
	trianglelist.push_back(triangle(tempList[0], tempList[1], tempList[2]));
	ti++;


	//***move to graphics class
	//either draw the tesselated filled polygon or draw triangle outlines and list out the triangle information
	glClear ( GL_COLOR_BUFFER_BIT );
	glColor3f(0.0, 0.0, 1.0);	//change color to blue
	for(int i = 0; i < ti; i++)
	{
		glBegin ( GL_POLYGON );
			glVertex2i ( triangleList[i].v1.x, triangleList[i].v1.y );
			glVertex2i ( triangleList[i].v2.x, triangleList[i].v2.y );	
        		glVertex2i ( triangleList[i].v3.x, triangleList[i].v3.y );		
		glEnd();
	}

	glFlush();
	//***
}

int sign(int num)
{
	if(num > 0)
		return 1;
	else if (num < 0)
		return -1;
	else
		return 0;
}

bool sharePoint(vertex p1, vertex p2)		//determines if two points are the same
{
    if(p1.x == p2.x || p1.y == p2.y)
        return true;
    else
        return false;
}

double vectorAngle(vertex fp, vertex mp, vertex ep)
{
	//find the angle of two vectors sharing middle point
	vector v1 = (vector){.x = (mp.x - fp.x), .y = (mp.y - fp.y), .z = 0};
	vector v2 = (vector){.x = (mp.x - ep.x), .y = (mp.y - ep.y), .z = 0};

	double va = acos( ((double)(dotProduct(v1, v2))) / (vectorMagnitude(v1) * vectorMagnitude(v2)) );
	return va;
}   

bool checkIntersection(vertex p1, vertex p2, vertex p3, vertex p4)
{
	float ADet = 0;
	float tADet = 0;
	float tBDet = 0;
	float tA = 0;
	float tB = 0;

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

	if( (tA >= 0 && tA <= 1) && (tB >= 0 && tB <= 1) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

int dotProduct(vector v1, vector v2)
{
	int dp;
	dp = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);

	return dp;
}

double vectorMagnitude(vector v1)
{
    double vm;
    vm  = sqrt((v1.x * v1.x) + (v1.y * v1.y));
    return vm;
}

vector crossProduct(vector v1, vector v2)
{
	vector cp;
	cp.x = (v1.y * v2.z) - (v2.y * v1.z);
	cp.y = (v1.x * v2.z) - (v2.x * v1.z);
	cp.z = (v1.x * v2.y) - (v2.x * v1.y);

	return cp;
}
