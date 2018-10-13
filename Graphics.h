#include "includes.h"
#include "constants.h"
#include "structs.h"

using namespace std;

class Graphics 
{
     public:
	//Graphics();

	static void myglutInit( int argc, char** argv );
	static void myInit(void);
	
	static void drawPoint( int x, int y );
	static void drawOutline( vector<vertex> vl, color c );
	static void drawPolygon( vector<vertex> vl, color c );
	
     private:
};

