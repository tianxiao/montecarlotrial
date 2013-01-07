#pragma once
#include "txType.h"
#include "txVector3D.h"

typedef txVector3D txRGB;
class txBrdf
{
public:
	txBrdf(void);
	explicit txBrdf(
		const txVector3D &ambienti,
		const txVector3D &diffusei,
		const txVector3D &speculari,
		const txVector3D &emissioni,
		const double shininessi = 0.0,
		const double opacityi = 1.0,
		const double indexofrefractioni = 1.0
		);
	~txBrdf(void);

private:
	txRGB ambient;
	txRGB diffuse;
	txRGB specular;
	txRGB emission;
	double shininess;
	double opacity;
	double indexOfRefraction;
	txFlags flags;
	int id;
};

