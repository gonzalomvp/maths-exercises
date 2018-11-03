//
//  VECTOR3D.h
//  StereoRendering
//
//  Created by Jose Maria Benito on 09/12/13.
//  Copyright (c) 2013 Jose Maria. All rights reserved.
//

#ifndef StereoRendering_VECTOR3D_h
#define StereoRendering_VECTOR3D_h

#define ABS(x) (x < 0 ? -(x) : (x))
#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)
#define TRUE  1
#define FALSE 0
#define ESC 27
#define PI 3.141592653589793238462643
#define DTOR            0.0174532925    // degrees to radians
#define RTOD            57.2957795      // radians to degrees


typedef struct {
    double x,y,z;
} VECTOR3D;


typedef struct {
    double r,g,b;
} COLOUR;

typedef struct {
    VECTOR3D column0;
    VECTOR3D column1;
    VECTOR3D column2;
} MATRIX3;


typedef struct {
    float m[16];
} MATRIX4;

static const COLOUR grey = {0.7,0.7,0.7};
static const COLOUR red = {1,0,0};
static const COLOUR green = {0,1,0};
static const COLOUR blue = {0,0,1};

static const COLOUR darkred = {0.6,0,0};
static const COLOUR darkgreen = {0,0.6,0};

// TODO

VECTOR3D Add(VECTOR3D a, VECTOR3D b)
{
    VECTOR3D ret;
    ret.x = a.x + b.x;
    ret.y = a.y + b.y;
    ret.z = a.z + b.z;
    return ret;
}

VECTOR3D Substract(VECTOR3D a, VECTOR3D b)
{
	VECTOR3D ret;
	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return ret;
}

VECTOR3D Multiply(VECTOR3D a, VECTOR3D b)
{
	VECTOR3D ret;
	ret.x = a.x * b.x;
	ret.y = a.y * b.y;
	ret.z = a.z * b.z;
	return ret;
}

VECTOR3D MultiplyWithScalar(float scalar, VECTOR3D a)
{
	VECTOR3D ret;
	ret.x = a.x * scalar;
	ret.y = a.y * scalar;
	ret.z = a.z * scalar;
	return ret;
}


double Magnitude(VECTOR3D a)
{
	double ret;
	ret = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	return ret;
}

VECTOR3D Normalize(VECTOR3D a)
{
	VECTOR3D ret;
	ret.x = a.x / Magnitude(a);
	ret.y = a.y / Magnitude(a);
	ret.z = a.z / Magnitude(a);
	return ret;
}

VECTOR3D CrossProduct(VECTOR3D a, VECTOR3D b)
{
	VECTOR3D ret;
	ret.x = a.y * b.z - a.z * b.y;
	ret.y = a.z * b.x - a.x * b.z;
	ret.z = a.x * b.y - a.y * b.x;
	return ret;
}

double DotProduct(VECTOR3D a, VECTOR3D b)
{
	double ret;
	ret = a.x * b.x + a.y * b.y + a.z * b.z;
	return ret;
}

MATRIX3 Transpose(MATRIX3 m)
{
	MATRIX3 ret;

	ret.column0.x = m.column0.x;
	ret.column0.y = m.column1.x;
	ret.column0.z = m.column2.x;

	ret.column1.x = m.column0.y;
	ret.column1.y = m.column1.y;
	ret.column1.z = m.column2.y;

	ret.column2.x = m.column0.z;
	ret.column2.y = m.column1.z;
	ret.column2.z = m.column2.z;

	return ret;
}

VECTOR3D Transform (MATRIX3 m, VECTOR3D a)
{
	VECTOR3D ret;
	
	//ret.x = m.column0.x * a.x + m.column1.x * a.y + m.column2.x * a.z;
	//ret.y = m.column0.y * a.x + m.column1.y * a.y + m.column2.y * a.z;
	//ret.z = m.column0.z * a.x + m.column1.z * a.y + m.column2.z * a.z;

	MATRIX3 mt = Transpose(m);
	ret.x = DotProduct(mt.column0, a);
	ret.y = DotProduct(mt.column1, a);
	ret.z = DotProduct(mt.column2, a);

	return ret;
}

MATRIX4 InverseOrthogonalMatrix(MATRIX3 A, VECTOR3D t)
{
	MATRIX4 ret;
	MATRIX3 At = Transpose(A);

	VECTOR3D v = Transform(At, t);

	//Columna 0
	ret.m[0] = At.column0.x;
	ret.m[1] = At.column0.y;
	ret.m[2] = At.column0.z;
	ret.m[3] = 0.0;

	//Columna 1
	ret.m[4] = At.column1.x;
	ret.m[5] = At.column1.y;
	ret.m[6] = At.column1.z;
	ret.m[7] = 0.0;

	//Columna 2
	ret.m[8] = At.column2.x;
	ret.m[9] = At.column2.y;
	ret.m[10] = At.column2.z;
	ret.m[11] = 0.0;

	//Columna 3
	ret.m[12] = -v.x;
	ret.m[13] = -v.y;
	ret.m[14] = -v.z;
	ret.m[15] = 1.0;

	return ret;
}


#endif
