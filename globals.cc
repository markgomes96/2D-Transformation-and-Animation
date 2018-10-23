#ifndef INC_GLOBALS_CC
#define INC_GLOBALS_CC

#include "structs.h"
#include "includes.h"

using namespace std;

vector<vertex> vertexlist;
vector<triangle> trianglelist;

float deltaspin = 0.0;				//rotation
float spin = 0.0;
vector3D scalarvect = vector3D(1.0, 1.0, 1.0);	//scaling
int reflection = 1;				//reflection

vertex cp = vertex(WINDOW_MAX_X/2, WINDOW_MAX_Y/2, 0, 1);		//center point

#endif
