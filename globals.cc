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

DisplayState displayState = outline;		//states
AnimState animState = playanim;

vertex startcp = vertex(WINDOW_MAX_X/2, WINDOW_MAX_Y/2, 0, 1);		//starting center point
vertex cp = vertex(WINDOW_MAX_X/2, WINDOW_MAX_Y/2, 0, 1);		//current center point

float viewportMinX = 0.0;		//resize boundary
float viewportMaxX = 0.0;
float viewportMinY = 0.0;
float viewportMaxY = 0.0;
bool resizeBoundMode = false;

#endif
