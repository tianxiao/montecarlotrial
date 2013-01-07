#pragma once
#include "txVector3D.h"
class txSphere
{
public:
	txSphere(void);
	explicit txSphere(const txVector3D &centeri,double radiusi);
	~txSphere(void);

private:
	txVector3D center;
	double radius;
};

