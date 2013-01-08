#include "StdAfx.h"
#include "txMaterial.h"
#include "txBrdf.h"
#include "txTexture.h"


txMaterial::txMaterial(void)
	:brdf(NULL)
	,texture(NULL)
{
}

txMaterial::txMaterial(const txBrdf* brdf)
{
	this->brdf = brdf;
	this->texture = NULL;
}
txMaterial::txMaterial(const txTexture *texture){
	this->brdf = NULL;
	this->texture = texture;
}
txMaterial::txMaterial(const txBrdf *brdf, const txTexture *texture){
	this->brdf = brdf;
	this->texture = texture;
}


txMaterial::~txMaterial(void)
{
}
