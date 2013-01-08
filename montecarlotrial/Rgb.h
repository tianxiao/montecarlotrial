#pragma once
class txRgb
{
public:
	txRgb(void);
	txRgb(double red, double green, double blue);
	~txRgb(void);

	// Property functions
	const double R(void) const {return red;};
	const double G(void) const {return green;};
	const double B(void) const {return blue;};

	const double Luminance() const {
		return 0.30*red + 0.59*green + 0.11*blue;
	};

private:
	double red; 
	double green;
	double blue;
};

