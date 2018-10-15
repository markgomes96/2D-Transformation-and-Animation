#ifndef STRUCTS
#define STRUCTS

typedef struct vertex 
{ 
    float x;
    float y;
    float z;
    float w;

    vertex(float _x, float _y, float _z, float w)
    {
        x = _x;
        y = _y;
        z = _z;
	w = _w;
    }
} vertex;

typedef struct vector		//stores data for a 3D vector used for calcualtions
{
	float x;
	float y;
	float z;

	vector(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
} vector;

typedef struct triangle		//stores vertexes for a triangle used for tesselation
{
	vertex v1;
	vertex v2;
	vertex v3;

	triangle(vertex _v1, vertex _v2, vertex _v3)
	{
		v1 = _v1;
		v2 = _v2;
		v3 = _v3;
	}
} triangle;

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
