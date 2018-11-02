#ifndef STRUCTS
#define STRUCTS

enum DisplayState { outline, tessfill, tesstriangle };
enum AnimState { playanim, stopanim, resetanim };

typedef struct vertex 
{ 
	float x;
	float y;
	float z;
	float w;

	vertex()
	{}

	vertex(float _x, float _y, float _z, float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}
} vertex;

typedef struct vector3D		//stores data for a 3D vector used for calcualtions
{
	float x;
	float y;
	float z;

	vector3D()
	{}

	vector3D(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
} vector3D;

typedef struct triangle		//stores vertexes for a triangle used for tesselation
{
	vertex v1;
	vertex v2;
	vertex v3;

	triangle()
	{}

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
    
	color()
	{};

	color(float _red, float _green, float _blue)
	{
		red = _red;
		green = _green;
		blue = _blue;
	}
} color;

typedef struct boundtracker
{
	bool wentOutside;
	int boundIndex;

	boundtracker()
	{};
	
	boundtracker(bool _wentOutside, int _boundIndex)
	{
		wentOutside = _wentOutside;
		boundIndex = _boundIndex;
	}
} boundtracker;

#endif
