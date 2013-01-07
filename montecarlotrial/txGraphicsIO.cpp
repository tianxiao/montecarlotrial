#include "StdAfx.h"
#include "txGraphicsIO.h"
#include "txScene.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <vector>
#include "txDrawVertex.h"
#include "txTexture.h"

txScene *txReadRayFile(const char *filename){
	FILE *fp;
	if (!(fp = fopen(filename, "r"))){
		assert(false);
		return NULL;
	}

	txScene *rtnScene = new txScene();
	assert(rtnScene);

	std::vector<txDrawVertex> vertices;
	std::vector<txTexture> textures;


	return NULL;
}