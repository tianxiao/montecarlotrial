#include "StdAfx.h"
#include "txBrdf.h"


txBrdf::txBrdf(void)
{
}

txBrdf::txBrdf(
	const txVector3D &ambienti,
	const txVector3D &diffusei,
	const txVector3D &speculari,
	const txVector3D &emissioni,
	const double shininessi ,
	const double opacityi ,
	const double indexofrefractioni 
	)
	:ambient(ambienti)
	,diffuse(diffusei)
	,specular(speculari)
	,emission(emissioni)
	,shininess(shininessi)
	,opacity(opacityi)
	,indexOfRefraction(indexofrefractioni)
	,id(-1)
{}


txBrdf::~txBrdf(void)
{
}
