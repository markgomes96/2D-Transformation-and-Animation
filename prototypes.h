#include "structs.h"

void display( void );

void mouse( int , int , int , int );
void keyboard( unsigned char , int , int );
void SpecialInput( int , int , int );

void tessellate( void );
int sign( int );
bool sharePoint( vertex , vertex );
double vectorAngle( vertex , vertex , vertex );
bool checkIntersection( vertex , vertex , vertex , vertex );
int dotProduct( vector3D , vector3D );
double vectorMagnitude( vector3D );
vector3D crossProduct( vector3D , vector3D );

int main( int , char** );
