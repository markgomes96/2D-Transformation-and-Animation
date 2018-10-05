#include "includes.h"
#include "constants.h"
#include "structs.h"

using namespace std;

class Graphics 
{
     public:
	
	Graphics();
	
	/*
	void setWindowPosition(int _windowPosX, int _windowPosY);
	void setWindowSize(int _windowMinX, int _windowMaxY);
	void setViewportDim(int _viewportMinX, int _viewportMaxX, int _viewportMinY, int _viewportMaxY);
      	*/

	void myglutInit( int argc, char** argv );
	void myInit(void);
	//void display(void);
	
	void drawPoint( int x, int y );
	void drawOutline( void );
	void drawPolygon( void );
	
    private:
	/*
	//Variables to specify window position and size
	int windowPosX;
	int windowPosY;
	int windowMaxX;
	int windowMaxY;

	//Variables to specify veiwport dimensions
	int viewportMinX;
	int viewportMaxX;
	int viewportMinY;
	int viewportMaxY;

	int red;
	int green;
	int blue;
	*/
};

