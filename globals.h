#ifndef INC_GLOBALS_H
#define INC_GLOBALS_H

#include "structs.h"
#include "includes.h"

using namespace std;

extern vector<vertex> vertexlist;
extern vector<triangle> trianglelist;

extern float deltaspin;
extern float spin;
extern vector3D scalarvect;
extern int reflection;

extern DisplayState displayState;
extern AnimState animState;

extern vertex startcp;
extern vertex cp;

extern float viewportMinX;
extern float viewportMaxX;
extern float viewportMinY;
extern float viewportMaxY;
extern bool resizeBoundMode;

#endif
