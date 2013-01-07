#include "StdAfx.h"
#include "txBox.h"


txBox::txBox(void)
{
}

txBox::txBox(const txVector3D &minPti, const txVector3D &maxPti)
	:minPt(minPti)
	,maxPt(maxPti)
{	
}

txBox::txBox(const txVector3D &centerPt, const double lx, const double ly, const double lz){
	minPt = txVector3D(centerPt.GetX()-0.5*lx,centerPt.GetY()-0.5*ly,centerPt.GetZ()-0.5*lz);
	maxPt = txVector3D(centerPt.GetX()+0.5*lx,centerPt.GetY()+0.5*ly,centerPt.GetZ()+0.5*lz);
}

txBox::~txBox(void)
{
}
