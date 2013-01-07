#pragma once
class txVector3D
{
public:
	txVector3D(void);
	explicit txVector3D(double x, double y, double z);
	~txVector3D(void);

	void SetX(double x){this->x = x;};
	void SetY(double y){this->y = y;};
	void SetZ(double z){this->z = z;};

	const double GetX()const {return x;};
	const double GetY()const {return y;};
	const double GetZ()const {return z;};

private:
	double x;
	double y;
	double z;
};

