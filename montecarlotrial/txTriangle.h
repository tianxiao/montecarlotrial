#pragma once
class txMaterial;
class txTriangle
{
public:
	txTriangle(void);
	explicit txTriangle(unsigned int i0, unsigned int i1, unsigned int i2);
	~txTriangle(void);

	void SetMaterial(txMaterial *pMaterial){this->pMaterial = pMaterial;};

private:
	unsigned int index[3];
	txMaterial *pMaterial;
};

