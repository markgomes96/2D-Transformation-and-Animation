#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"
#include "Graphics.h"
#include "globals.h"

void applyTransformation(vertex *vp, int vc, float *tm) 	//applies the given transformation matrix TM to the vector vp containing
{
	float temp[4];
	float *tmp;
	tmp = &temp[0];

	for (int i = 0; i < vc; i++)
	{
		*(tmp+0) = (vp+i) -> x;		//move point over to temp float array
		*(tmp+1) = (vp+i) -> y;
		*(tmp+2) = (vp+i) -> z;
		*(tmp+3) = (vp+i) -> w;
		matrixVectorMult( 4, tm, tmp);		//apply transformation to point
		(vp+i) -> x = *(tmp+0); 	//store back the transformed point
		(vp+i) -> y = *(tmp+1); 
		(vp+i) -> z = *(tmp+2); 
		(vp+i) -> w = *(tmp+3); 
        }
}

void matrixVectorMult (int SIZE, float *pA, float *pB)	//pA -> matrix A; pB -> matrix B; B returns transformed coordinates
{
	int i, j;
	float temp[4];

	for (i=0; i<SIZE; i++)
	{
		temp[i] = 0.0;
	}

	for (i=0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			temp[i] += *(pA+(i*SIZE+j)) * *(pB+j);	//pointer magic
		}
	}
   
	for (i=0; i<SIZE; i++)
	{
		*(pB+i) = temp[i];
	}
}

void buildTranslate( float x, float y, float z, float *pA )	//constructs tranlation matrix to translate along x, y, z axes
{
	pA[ 0] = 1.0; pA[ 1] = 0.0; pA[ 2] = 0.0; pA[ 3] =   x;
	pA[ 4] = 0.0; pA[ 5] = 1.0; pA[ 6] = 0.0; pA[ 7] =   y;
	pA[ 8] = 0.0; pA[ 9] = 0.0; pA[10] = 1.0; pA[11] =   z;
	pA[12] = 0.0; pA[13] = 0.0; pA[14] = 0.0; pA[15] = 1.0;
}


void buildRotateZ( float theta, float *pA )	//constructs rotation matrix about Z axis
{
	float phi;

	phi = theta * M_PI / 180.0;	// convert degrees to radians

	pA[ 0] =  cos(phi); pA[ 1] = sin(phi); pA[ 2] = 0.0; pA[ 3] = 0.0;
	pA[ 4] = -sin(phi); pA[ 5] = cos(phi); pA[ 6] = 0.0; pA[ 7] = 0.0;
	pA[ 8] = 0.0;       pA[ 9] = 0.0;      pA[10] = 1.0; pA[11] = 0.0;
	pA[12] = 0.0;       pA[13] = 0.0;      pA[14] = 0.0; pA[15] = 1.0;
} 

void buildScale( vector3D sv, float *pA )		//constructs scaling matrix to scale outward from center
{
	pA[ 0] = sv.x; pA[ 1] =  0.0; pA[ 2] =  0.0; pA[ 3] = 0.0;
	pA[ 4] =  0.0; pA[ 5] = sv.y; pA[ 6] =  0.0; pA[ 7] = 0.0;
	pA[ 8] =  0.0; pA[ 9] =  0.0; pA[10] = sv.z; pA[11] = 0.0;
	pA[12] =  0.0; pA[13] =  0.0; pA[14] =  0.0; pA[15] = 1.0;
}

void buildReflectVert( int ref, float *pA )		//constructs reflection matrix to reflect vertically
{
	pA[ 0] = ref*1.0; pA[ 1] = 0.0; pA[ 2] = 0.0; pA[ 3] = 0.0;
	pA[ 4] =     0.0; pA[ 5] = 1.0; pA[ 6] = 0.0; pA[ 7] = 0.0;
	pA[ 8] =     0.0; pA[ 9] = 0.0; pA[10] = 1.0; pA[11] = 0.0;
	pA[12] =     0.0; pA[13] = 0.0; pA[14] = 0.0; pA[15] = 1.0;
}
