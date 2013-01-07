#include "StdAfx.h"
#include "txTriangle.h"


txTriangle::txTriangle(void)
{
	index[0]=0;
	index[1]=0;
	index[2]=0;
}

txTriangle::txTriangle(unsigned int i0, unsigned int i1, unsigned int i2){
	index[0] = i0;
	index[1] = i1;
	index[2] = i2;
}

txTriangle::~txTriangle(void)
{
}
