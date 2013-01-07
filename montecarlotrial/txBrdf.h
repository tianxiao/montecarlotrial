#pragma once
#include "txVector3D.h"

typedef txVector3D txRGB;
class txBrdf
{
public:
	txBrdf(void);
	~txBrdf(void);

private:
	txRGB ambient;
	txRGB diffuse;
	txRGB specular;
	txRGB emission;
	float opacity;
	float indexOfRefraction;
	
};

