#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"

#include "Shape.h"
#include "globals.h"
#include "globals.cc"

using namespace std;

/*
Shape :: Shape()		//default constructor
{}
*/

void Shape :: defineBasePoints(void)
{
    vector<vertex> vl;
    vl.push_back(vertex(200, 200, 0));
    vl.push_back(vertex(400, 200, 0));
    vl.push_back(vertex(400, 400, 0));
    vl.push_back(vertex(200, 400, 0));
    
    shapelist = vl;
}