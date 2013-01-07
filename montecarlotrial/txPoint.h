#pragma once
class txPoint
{
public:
	txPoint(void);
	txPoint(const txPoint&point);
	txPoint(double x, double y, double z);
	
	~txPoint(void);

	// Assignment operators
	txPoint & operator=(const txPoint& point);

private:
	double v[3];
};

