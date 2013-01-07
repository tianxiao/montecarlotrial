#include "StdAfx.h"
#include "txDrawVertex.h"


txDrawVertex::txDrawVertex(void)
	:xyz(0.0,0.0,0.0)
	,st(0.0,0.0)
	,normal(0.0,0.0,0.0)
{
	tangents[0].SetX(0.0);
	tangents[1].SetY(0.0);
	tangents[2].SetZ(0.0);
	tangents[0].SetX(0.0);
	tangents[1].SetY(0.0);
	tangents[2].SetZ(0.0);
	
}


txDrawVertex::~txDrawVertex(void)
{
}
