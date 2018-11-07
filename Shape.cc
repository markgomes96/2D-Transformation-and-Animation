#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"

#include "Shape.h"
#include "Graphics.h"
#include "globals.h"
#include "globals.cc"

using namespace std;

void Shape :: defineBasePoints(void)
{
	/*
	vertexlist.push_back(vertex(200, 425, 0, 1.0));		//add in base of tree, goes CCW
	vertexlist.push_back(vertex(700, 475, 0, 1.0));    

	createCircle(150, 650, 500);    //add in circle top of tree

	vertexlist.push_back(vertex(700, 525, 0, 1.0));
	vertexlist.push_back(vertex(200, 575, 0, 1.0));
	*/
	
	vertexlist.push_back(vertex(700, 475, 0, 1.0)); 
	createCircle(150, 650, 500);    //add in circle top of tree
	vertexlist.push_back(vertex(700, 525, 0, 1.0));
	vertexlist.push_back(vertex(200, 575, 0, 1.0));
	vertexlist.push_back(vertex(200, 425, 0, 1.0));
}

void Shape :: createCircle(int radius, int cx, int cy)
{
	vector<vertex> quad1, quad2, quad3, quad4, quad5, quad6;

	int x, y;
	int wx, wy;
	float d;

	x = 0;
	y = radius;
	d = 5.0 / 4.0 - radius;

	while(y > x)
	{
		if(d <= 0)
		{
			d += x * 2.0 + 3;
			//x++;
			x = x + 25;
		}
		else
		{
			d += (x - y) * 2.0 + 5.0;
			//x++;
			//y--;
			x = x + 25;
			y = y - 25;
		}

		quad1.push_back(vertex( (-x) + cx,   y  + cy, 0, 1.0));    //reflect point along circle symmetries
		quad2.push_back(vertex(   x  + cx,   y  + cy, 0, 1.0));        //convert to world coordinates
		quad3.push_back(vertex(   y  + cx,   x  + cy, 0, 1.0));
		quad4.push_back(vertex(   y  + cx, (-x) + cy, 0, 1.0));
		quad5.push_back(vertex(   x  + cx, (-y) + cy, 0, 1.0));
		quad6.push_back(vertex( (-x) + cx, (-y) + cy, 0, 1.0));
	}

	reverse(quad6.begin(), quad6.end());					//insert each segment in right order
	vertexlist.insert(vertexlist.end(), quad6.begin(), quad6.end());

	vertexlist.insert(vertexlist.end(), quad5.begin(), quad5.end());

	reverse(quad4.begin(), quad4.end());
	vertexlist.insert(vertexlist.end(), quad4.begin(), quad4.end());
	
	vertexlist.insert(vertexlist.end(), quad3.begin(), quad3.end());
	
	reverse(quad2.begin(), quad2.end());
	vertexlist.insert(vertexlist.end(), quad2.begin(), quad2.end());

	vertexlist.insert(vertexlist.end(), quad1.begin(), quad1.end());
}
