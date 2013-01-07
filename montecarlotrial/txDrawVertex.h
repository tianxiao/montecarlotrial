#pragma once
#include "txVector3D.h"
#include "txVector2D.h"
class txDrawVertex
{
public:
	txVector3D xyz;
	txVector2D st;
	txVector3D normal;
	txVector3D tangents[2];
	//byte color[4];

public:
	txDrawVertex(void);
	explicit txDrawVertex(const txDrawVertex &drawVertex);
	~txDrawVertex(void);
};

