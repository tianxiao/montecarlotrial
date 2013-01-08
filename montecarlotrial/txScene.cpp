#include "StdAfx.h"
#include "txScene.h"
#include <assert.h>

txScene::txScene(void)
{
}


txScene::~txScene(void)
{
}

void txScene::AddTriangle(txTriangle* pTri){
	assert(pTri);
	triangles.push_back(pTri);
}
void txScene::AddShpere(txSphere *pSphere){
	assert(pSphere);
	spheres.push_back(pSphere);
}
