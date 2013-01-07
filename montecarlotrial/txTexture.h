#pragma once
#include "txType.h"
#include <vector>
class txImage;
class txTexture
{
public:
	txTexture(void);
	~txTexture(void);

private:
	const txImage *image;
	txFlags flags;
	int id; // 0=null, <0=uloaded, >0=loaded
};

