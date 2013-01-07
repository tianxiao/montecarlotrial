#include "StdAfx.h"
#include "txPoint.h"


txPoint::txPoint(void)
{
	v[0]=0.0;
	v[1]=0.0;
	v[2]=0.0;
}

txPoint::txPoint(const txPoint&point){
	v[0] = point.v[0];
	v[1] = point.v[1];
	v[2] = point.v[2];
}

txPoint::txPoint(double x, double y, double z){
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

txPoint & txPoint::operator=(const txPoint& point){
	v[0] = point.v[0];
	v[1] = point.v[1];
	v[2] = point.v[2];
	return *this;
}


txPoint::~txPoint(void)
{
}
