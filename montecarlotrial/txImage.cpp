#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>
#include "txImage.h"
#include <assert.h>
#include "Rgb.h"


// jpeglib header files
#include "../libs/jpeg8d/include/jpeglib.h"
#include "../libs/jpeg8d/include/jmorecfg.h"
#include "../libs/jpeg8d/include/jconfig.h"

#define JPEG_OUTPUT_QUALITY 75

txImage::txImage(void)
	:width(0)
	,height(0)
	,ncomponents(0)
	,rowsize(0)
	,pixels(NULL)
{
}

txImage::txImage(int width, int height, int ncomponents)
	:width(width)
	,height(height)
	,ncomponents(ncomponents)
	,rowsize(0)
	,pixels(NULL)
{
	rowsize = ncomponents*width;
	if ((rowsize%4)!=0) rowsize = (rowsize/4+1)*4;
	int nbytes = rowsize * height;
	pixels = new unsigned char[nbytes];
	assert(pixels);
	unsigned char *p = pixels;
	while (--nbytes) *(p++) = 0;
}

txImage::~txImage(void)
{
	delete[] pixels;
	pixels = NULL;
}


void txImage::SetPixelRGB(int row, int column, const txRgb& rgb){
	unsigned char *pixel = &(pixels[column*rowsize + row*ncomponents]);

	switch(ncomponents){
	case 1:
		*(pixel++) = (unsigned char)(255*rgb.Luminance());
		break;
	case 2:
		*(pixel++) = (unsigned char) (255*rgb.Luminance());
		*(pixel++) = (unsigned char) 255;
		break;
	case 3:
		*(pixel++) = (unsigned char) (255 * rgb.R());
		*(pixel++) = (unsigned char) (255 * rgb.G());
		*(pixel++) = (unsigned char) (255 * rgb.B());
		break;
	case 4:
		*(pixel++) = (unsigned char) (255 * rgb.R());
		*(pixel++) = (unsigned char) (255 * rgb.G());
		*(pixel++) = (unsigned char) (255 * rgb.B());
		*(pixel++) = (unsigned char) 255;
		break;
	}

}


int txImage::WriteJPEG(const char *filename)const {
	FILE *fpw = fopen(filename, "wb");
	if (!fpw){
		assert (true);
		return 0;
	}

	struct jpeg_compress_struct cinfow;
	struct jpeg_error_mgr jerrw;
	cinfow.err = jpeg_std_error(&jerrw);
	jpeg_create_compress(&cinfow);
	jpeg_stdio_dest(&cinfow, fpw);
	cinfow.image_width = width;
	cinfow.image_height = height;
	cinfow.input_components = ncomponents; // color component
	cinfow.in_color_space = JCS_RGB; // colorspace of input image
	cinfow.dct_method = JDCT_ISLOW;
	jpeg_set_defaults(&cinfow);
	cinfow.optimize_coding = TRUE;
	jpeg_set_quality(&cinfow,JPEG_OUTPUT_QUALITY,TRUE);
	jpeg_start_compress(&cinfow, TRUE);

	// ouput scan lines
	// First jpeg pixel is top-left, so write in opposite scan-line order
	// See the following explainings
	while (cinfow.next_scanline < cinfow.image_height) {
		int scanline = cinfow.image_height - cinfow.next_scanline - 1;
		unsigned char *row_pointer = &pixels[scanline * rowsize];
		jpeg_write_scanlines(&cinfow, &row_pointer, 1);
	}

	// Free JPEG
	jpeg_finish_compress(&cinfow);
	jpeg_destroy_compress(&cinfow);

	fclose(fpw);

	return NULL;
}

// A JPEG layout
/*
^
|
|
|
|
|
|
|
+---------------------->
The coding coordinate

The JPEG coordinate // From top left
+---------------------->
|
|
|
|
|
|
\/

*/
//