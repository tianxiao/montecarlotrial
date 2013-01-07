#include "StdAfx.h"
#include "txGraphicsIO.h"
#include "txScene.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <vector>
#include "txDrawVertex.h"
#include "txTexture.h"
#include "txMaterial.h"
#include "txBrdf.h"
#include "txDrawVertex.h"
#include "txVector3D.h"
#include "txTriangle.h"
#include "txSphere.h"
#include "txBox.h"

txScene *txReadRayFile(const char *filename){
	FILE *fp;
	if (!(fp = fopen(filename, "r"))){
		assert(false);
		return NULL;
	}

	txScene *rtnScene = new txScene();
	assert(rtnScene);

	std::vector<txDrawVertex*> vertices;
	std::vector<txTexture*> textures;
	std::vector<txMaterial *> materials;

	bool cameraFound = false;

	// Read body
	char cmd[128];
	int cmd_num = 1;
	while (fscanf(fp, "%s", cmd)==1){
		if (!strcmp(cmd, "#vertex")){
			// Read data
			double px, py, pz;
			double nx, ny, nz;
			double ts, tt;
			if (fscanf(fp,"%lf%lf%lf%lf%lf%lf%lf%lf",&px,&py,&pz,&nx,&ny,&nz,&ts,&tt)!=8){
				assert(true);
				return NULL;
			}
			txDrawVertex *pDrawVertex = new txDrawVertex();
			pDrawVertex->xyz = txVector3D(px,py,pz);
			pDrawVertex->normal = txVector3D(nx,ny,nz);
			pDrawVertex->st = txVector2D(ts,tt);
			vertices.push_back(pDrawVertex);
		}else if(!strcmp(cmd, "#shape_triangle")){
			// Read data
			int m;
			int i0, i1, i2;
			if (fscanf(fp, "%d%d%d%d", &m, &i0, &i1, &i2)!=4){
				assert(true);
				return NULL;
			}
			//txDrawVertex *v0 = vertices[i0];
			txTriangle *pTriangle = new txTriangle(i0, i1, i2);
			// pick the right material for the new shape
			// TODO!!!

			// Creat a new node and Insert the node into scene
			// TODO!!! scene graphic inserting.
		}else if (!strcmp(cmd, "#shape_sphere")){
			// Read data
			int m; // m means the index of the material
			double cx, cy, cz, r;
			// "%lf" means read double
			// "%f"  means float
			if (fscanf(fp, "%d%lf%lf%lf%lf", &m, &cx, &cy, &cz, &r)!=5){
				assert(true);
				return NULL;
			}
			// Creat node
			txSphere *pSphere = new txSphere(txVector3D(cx, cy, cz),r);
		}else if(!strcmp(cmd, "#shape_box")){
			int m;
			double cx, cy, cz, lx, ly, lz;
			// TODO need give the error line of the input file
			if (fscanf(fp, "%d%lf%lf%lf%lf%lf%lf", &m, &cx, &cy, &cz, &lx, &ly, &lz)!=7){
				assert(true);
				return NULL;
			}
			txBox *pBox = new txBox(txVector3D(cx,cy,cz),lx,ly,lz);

		}else if (!strcmp(cmd, "#material")){// TODO I omit some geometry entities I will add if I need.
			// The following douobles are used to set the brdf parameters
			double ar, ag, ab, dr, dg, db, sr, sg, sb, er, eg, eb, ks, kt, ir;
			int texid;
			char string[64];
			if (fscanf(fp, "%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%d%s",
				&ar, &ag, &ab, &dr, &dg, &db, &sr, &sg, &sb, &er, &eg, &eb, &ks, &kt, &ir,
				&texid, string)!=17){
				assert(true);
				return NULL;
			}

			txTexture *pTexture = NULL;
			if (texid>=0){
				if (texid < (int) textures.size()){
					pTexture = textures[texid];
				}
			}else{
				// TODO!!! warning
			}

			// Creat brdf
			txVector3D ambient(ar, ag, ab);
			txVector3D diffuse(dr, dg, db);
			txVector3D specular(sr, sg, sb);
			txVector3D emission(er, eg, eb);
			txBrdf *pBrdf = new txBrdf(ambient, diffuse, specular, emission, ks, 1.0-kt,ir);

			txMaterial *pMaterial = new txMaterial(pBrdf, pTexture);
			materials.push_back(pMaterial);
		}else if (!strcmp(cmd, "#texture")){
			char texturePath[256];
			if (fscanf(fp, "%s", texturePath)!=1){
				assert(true);
				return NULL;
			}
			txTexture *pTexture = new txTexture(texturePath);
			textures.push_back(pTexture);
		}
	}

	fclose(fp);

	return rtnScene;
}