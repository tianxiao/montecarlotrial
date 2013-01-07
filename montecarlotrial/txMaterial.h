#pragma once
#include <vector>
#include "txType.h"
class txBrdf;
class txTexture;
class txMaterial
{
public:
	txMaterial(void);
	~txMaterial(void);
	explicit txMaterial(const txBrdf* brdf);
	explicit txMaterial(const txTexture *texture);
	explicit txMaterial(const txBrdf *brdf, const txTexture *texture);

private:
	const txBrdf *brdf;
	const txTexture *texture;
	txFlags flags;
};

