//
//  shapes.h
//  interpolation
//
//  Created by Jose Maria Benito on 28/10/14.
//  Copyright (c) 2014 Jose Maria. All rights reserved.
//

#ifndef interpolation_shapes_h
#define interpolation_shapes_h

#include "GLInclude.h"
#include <vector>


void drawDot(VECTOR3D position, float sradius = 1, COLOUR color = grey)
{
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);

    
    VECTOR3D p[4],n[4];
    int STEP = 30;
    for (int i=0;i<360;i+=STEP) {
        for (int j=-90;j<90;j+=STEP) {
            
            p[0].x = sradius * cos(j*DTOR) * cos(i*DTOR);
            p[0].y = sradius * sin(j*DTOR);
            p[0].z = sradius * cos(j*DTOR) * sin(i*DTOR);
            n[0] = p[0];
            
            p[1].x = sradius * cos((j+STEP)*DTOR) * cos(i*DTOR);
            p[1].y = sradius * sin((j+STEP)*DTOR);
            p[1].z = sradius * cos((j+STEP)*DTOR) * sin(i*DTOR);
            n[1] = p[1];
            
            p[2].x = sradius * cos((j+STEP)*DTOR) * cos((i+STEP)*DTOR);
            p[2].y = sradius * sin((j+STEP)*DTOR);
            p[2].z = sradius * cos((j+STEP)*DTOR) * sin((i+STEP)*DTOR);
            n[2] = p[2];
            
            p[3].x = sradius * cos(j*DTOR) * cos((i+STEP)*DTOR);
            p[3].y = sradius * sin(j*DTOR);
            p[3].z = sradius * cos(j*DTOR) * sin((i+STEP)*DTOR);
            n[3] = p[3];
            
            glBegin(GL_POLYGON);
            if (i % (STEP*4) == 0)
                glColor3f(color.r,color.g,color.b);
            else
                glColor3f(color.r*0.5,color.g*0.5,color.b*0.5);
            for (int k=0;k<4;k++) {
                glNormal3f(n[k].x,n[k].y,n[k].z);
                glVertex3f(p[k].x,p[k].y,p[k].z);
            }
            glEnd();
        }
    }
    
    glPopMatrix();
}

typedef struct {
    std::vector<VECTOR3D> P;
} LINE;

typedef struct {
	std::vector<VECTOR3D> P;
} CURVE;

void drawLine(LINE line, COLOUR color = grey, bool doDrawDots = false)
{
	
	glColor3f(color.r, color.g, color.b);
	
	glBegin(GL_LINE_STRIP);
	for (size_t i = 0; i < line.P.size(); i++)
	{
		glVertex3f(line.P[i].x, line.P[i].y, line.P[i].z);
	}
	glEnd();
	if (doDrawDots)
	{
		for (size_t i = 0; i < line.P.size(); i++)
		{
			drawDot(line.P[i], 0.07f, color);
		}
	}
}

void drawAxis()
{
	LINE x_axis;
	LINE y_axis;
	LINE z_axis;

	int start = -5;
	int end = 5;
	int steps = end - start + 1;

	x_axis.P.resize(steps);
	y_axis.P.resize(steps);
	z_axis.P.resize(steps);

	for (int i = 0; i < steps; i++)
	{
		VECTOR3D vx = { (float)start + i, 0, 0 };
		VECTOR3D vy = { 0, (float)start + i, 0 };
		VECTOR3D vz = { 0, 0, (float)start + i };

		x_axis.P[i] = vx;
		y_axis.P[i] = vy;
		z_axis.P[i] = vz;
	}

	drawLine(x_axis, red, false);
	drawLine(y_axis, green, false);
	drawLine(z_axis, blue, false);
}

VECTOR3D interpolate(CURVE curve, float t)
{
	VECTOR3D ret;

	if (curve.P.size() == 1) {
		ret = curve.P[0];
	}
	else {
		std::vector<VECTOR3D> points1(curve.P.begin(), curve.P.end() - 1);
		CURVE p1Curve;
		p1Curve.P = points1;

		std::vector<VECTOR3D> points2(curve.P.begin() + 1, curve.P.end());
		CURVE p2Curve;
		p2Curve.P = points2;

		VECTOR3D p1 = interpolate(p1Curve, t);
		VECTOR3D p2 = interpolate(p2Curve, t);

		ret = Add(MultiplyWithScalar(1 - t, p1), MultiplyWithScalar(t, p2));
	}

	return ret;
}

void drawCurve(CURVE curve)
{
	LINE line;
	for (float t = 0.0f; t <= 1.0f; t += 0.001f)
	{
		VECTOR3D p = interpolate(curve, t);
		line.P.push_back(p);
	}
	drawLine(line);
}

#endif
