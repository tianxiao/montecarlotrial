#pragma once
//#include "txTriangle.h"
//#include "txBox.h"
//#include "txSphere.h"
#include <vector>
class txTriangle;
class txSphere;


class txScene
{
public:
	txScene(void);
	~txScene(void);

	void AddTriangle(txTriangle* pTri);
	void AddShpere(txSphere *pSphere);

private:
	std::vector<txSphere*> spheres;
	std::vector<txTriangle*> triangles;
};

