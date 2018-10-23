#include "includes.h"
#include "structs.h"

using namespace std;

class Graphics 
{
     public:
	//Graphics();

	static void myglutInit( int argc, char** argv );
	static void myInit( void );
	
	static void drawPoint( int x, int y );
	static void drawOutline( vertex *vl, int vc, color c);
	static void drawPolygon( vector<vertex> vl, color c );
	static void drawTessPolygon( vector<triangle> tl, color c);
	
     private:
};

