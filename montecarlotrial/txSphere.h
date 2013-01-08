#pragma once
#include "txVector3D.h"
class txMaterial;
class txSphere
{
public:
	txSphere(void);
	explicit txSphere(const txVector3D &centeri,double radiusi);
	~txSphere(void);

	void SetMaterial(txMaterial *pMaterial){this->pMaterial = pMaterial;};

private:
	txVector3D center;
	double radius;

	txMaterial *pMaterial;
};

