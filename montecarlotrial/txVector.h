#pragma once
class txVector
{
public:
	txVector(void);
	txVector(const txVector& vector);
	~txVector(void);

	// Assign operator
	txVector & operator=(const txVector& vector);

private:
	double v[3];
};

