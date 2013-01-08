#pragma once

class txRgb;

class txImage
{
public:
	txImage(void);
	txImage(int width, int height, int ncomponents=3);
	~txImage(void);

	// Manipulation
	void SetPixelRGB(int row, int column, const txRgb& rgb);
	int WriteJPEG(const char *filename)const ;
	
private:
	int width;
	int height;
	int ncomponents;
	int rowsize;
	unsigned char *pixels;
};

