#pragma once
#include "txVector3D.h"
class txBox
{
public:
	txBox(void);
	explicit txBox(const txVector3D &minPti, const txVector3D &maxPti);
	explicit txBox(const txVector3D &centerPt, const double lx, const double ly, const double lz);
	~txBox(void);

private:
	txVector3D minPt;
	txVector3D maxPt;
};

