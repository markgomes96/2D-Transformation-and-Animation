#ifndef STRUCTS
#define STRUCTS

typedef struct vertex 
{ 
    int x;
    int y;
    int z;
    
    vertex(int _x, int _y, int _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
} vertex;

typedef struct color
{
    float red;
    float green;
    float blue;
    
    color(float _red, float _green, float _blue)
    {
        red = _red;
        green = _green;
        blue = _blue;
    }
} color;

#endif
