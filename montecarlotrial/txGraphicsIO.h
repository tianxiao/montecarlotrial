#pragma once
#include <vector>

class txScene;
class txDrawVertex;
class txTexture;
class txMaterial;
// TODO! This manager class can be a single ton 
// Let the other resource to share with.
class txResourceManageer{
public:
	txScene *txReadRayFile(const char *filename);

	~txResourceManageer();

private:
	void ReleaseResources();

private:
	std::vector<txDrawVertex* > vertices;
	std::vector<txTexture*> textures;
	std::vector<txMaterial *> materials;
};

