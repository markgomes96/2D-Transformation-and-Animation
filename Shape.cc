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
  vector<vertex> vl;
  //vl.push_back(vertex(550, 350, 0));
  vl.push_back(vertex(700, 475, 0));    //add in base of tree, goes CCW
  vl.push_back(vertex(200, 425, 0));
  vl.push_back(vertex(200, 575, 0));
  vl.push_back(vertex(700, 525, 0));
  //vl.push_back(vertex(550, 650, 0));  
  shapelist = vl;
  
  createCircle(150, shapelist.front().x - 50, shapelist.front().y + ((shapelist.back().y - shapelist.front().y) / 2));    //add in circle top of tree
}

void Shape :: createCircle(int radius, int cx, int cy)
{
  vector<vertex> quad1, quad2, quad3, quad4, quad5, quad6;

  int x, y;
  int wx, wy;
  float d;
  
  x = 0; //cx;
  y = radius; //cy + radius;
  d = 5.0 / 4.0 - radius;
  
  while(y > x)
  {
    if(d <= 0)
    {
      d += x * 2.0 + 3;
      x++;
    }
    else
    {
      d += (x - y) * 2.0 + 5.0;
      x++;
      y--;
    }
    
    quad1.push_back(vertex((-x) + cx , y + cy, 0));    //reflect point along circle symmetries
    quad2.push_back(vertex(x + cx , y + cy, 0));        //convert to world coordinates
    quad3.push_back(vertex(y + cx, x + cy, 0));
    quad4.push_back(vertex(y + cx, (-x) + cy, 0));
    quad5.push_back(vertex(x + cx, (-y) + cy , 0));
    quad6.push_back(vertex((-x) + cx, (-y) + cy , 0));
  }
  
  reverse(quad1.begin(), quad1.end());
  shapelist.insert(shapelist.end(), quad1.begin(), quad1.end());
  
  shapelist.insert(shapelist.end(), quad2.begin(), quad2.end());
  
  reverse(quad3.begin(), quad3.end());
  shapelist.insert(shapelist.end(), quad3.begin(), quad3.end());
  
  shapelist.insert(shapelist.end(), quad4.begin(), quad4.end());
  
  reverse(quad5.begin(), quad5.end());
  shapelist.insert(shapelist.end(), quad5.begin(), quad5.end());
  
  shapelist.insert(shapelist.end(), quad6.begin(), quad6.end());
}