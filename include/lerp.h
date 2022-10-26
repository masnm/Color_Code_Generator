#ifndef __LERP_H__
#define __LERP_H__

float lerp ( float a, float b, float t );
float inv_lerp ( float a, float b, float v );
float remap ( float imin, float imax, float omin, float omax, float v );

#endif // __LERP_H__
