#pragma once

class txTriangle
{
public:
	txTriangle(void);
	explicit txTriangle(unsigned int i0, unsigned int i1, unsigned int i2);
	~txTriangle(void);

private:
	unsigned int index[3];
};

