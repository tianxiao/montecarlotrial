#include "StdAfx.h"
#include "txVector2D.h"


txVector2D::txVector2D(void)
	:x(0.0)
	,y(0.0)
{
	
}

txVector2D::txVector2D(double x, double y){
	this->x = x;
	this->y = y;
}

txVector2D::txVector2D(const txVector2D& vector2d)
	:x(vector2d.x)
	,y(vector2d.y)
{
}

txVector2D& txVector2D::operator=(txVector2D &vector2d){
	x = vector2d.x;
	y = vector2d.y;
	return *this;
}

txVector2D::~txVector2D(void)
{
}
