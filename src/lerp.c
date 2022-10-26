#include "../include/lerp.h"

float lerp ( float a, float b, float t )
{
	return ( 1.0f - t ) * a + b * t;
}

float inv_lerp ( float a, float b, float v )
{
	return ( v - a ) / ( b - a );
}

float remap ( float imin, float imax, float omin, float omax, float v )
{
	float t = inv_lerp ( imin, imax, v );
	return lerp ( omin, omax, t );
}
