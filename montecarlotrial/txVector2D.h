#pragma once
class txVector2D
{
public:
	txVector2D(void);
	explicit txVector2D(double x, double y);
	// Actually the following code will generated by the compiler
	// and the Assignment operator function will also be generated by the compiler
	// The reason is the private member variables are all copyable
	explicit txVector2D(const txVector2D& vector2d);
	
	
	~txVector2D(void);

	// Assignmeng operator
	txVector2D& operator=(txVector2D &vector2d);

private:
	double x;
	double y;
};

