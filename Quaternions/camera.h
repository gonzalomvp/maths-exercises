//
//  camera.h
//  interpolation
//
//  Created by Jose Maria Benito on 28/10/14.
//  Copyright (c) 2014 Jose Maria. All rights reserved.
//

#ifndef interpolation_camera_h
#define interpolation_camera_h

typedef struct {
    VECTOR3D position;
    VECTOR3D direction;
    VECTOR3D up;
    
    double aperture;    // in degrees
    int screenwidth,screenheight;
    
} CAMERA;


typedef struct {
    double left;
    double right;
    double bottom;
    double top;
    double near;
    double far;
} FRUSTUM;

typedef struct {
	float yaw; // Rotation around the Y axis.
	float pitch; // Rotation around the X axis.
	float roll; // Rotation around the Z axis.
	QUATERNION orientation; // Cached quaternion equivalent of this euler object.
} EULER;

 // devuelve los valores de distancia de los planos a partir del fov horizontal
FRUSTUM makeFrustum(double fovX, double aspectRatio, double near, double far)
{
    const double DEG2RAD = 3.14159265 / 180;
    
    double tangent = tan(fovX/2 * DEG2RAD);     // tangent of half fovX
    double width = near * tangent;              // half width of near plane
    double height = width / aspectRatio;        // half height of near plane
    
    FRUSTUM ret;
    ret.left = -width;
    ret.right=  width;
    ret.bottom = -height;
    ret.top = height;
    ret.near = near;
    ret.far = far;
    return ret;
}

// TODO

MATRIX4 lookAt(VECTOR3D eyePosition, VECTOR3D target, VECTOR3D upVector)
{
	MATRIX4 ret;

	VECTOR3D forward = Normalize(Substract(target, eyePosition));
	VECTOR3D Inverseforward = Normalize(Substract(eyePosition, target));
	VECTOR3D side = Normalize(CrossProduct(forward, upVector));
	VECTOR3D up = CrossProduct(side, forward);

	MATRIX3 m;
	m.column0 = side;
	m.column1 = up;
	m.column2 = Inverseforward;

	ret = InverseOrthogonalMatrix(m, eyePosition);

	return ret;
}

void updateEulerOrientation(EULER& euler)
{
	VECTOR3D x_axis = { 1, 0, 0 };
	VECTOR3D y_axis = { 0, 1, 0 };
	VECTOR3D z_axis = { 0, 0, 1 };

	QUATERNION qpitch = QuaternionFromAngleAxis(euler.pitch, x_axis);
	QUATERNION qyaw = QuaternionFromAngleAxis(euler.yaw, y_axis);
	QUATERNION qroll = QuaternionFromAngleAxis(euler.roll, z_axis);

	euler.orientation = Multiply(Multiply(qyaw, qpitch), qroll);
}

VECTOR3D getForward(EULER euler)
{
	VECTOR3D minus_z_axis = { 0, 0, -1 };
	updateEulerOrientation(euler);

	return RotateWithQuaternion(minus_z_axis, euler.orientation);
}

#endif
