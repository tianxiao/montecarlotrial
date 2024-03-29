// montecarlotrial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Noise.h"
#include "txGraphicsIO.h"
#include "txScene.h"
#include "txImage.h"
#include "Rgb.h"


class txImage;
class txScene;

double g_state = 0;
double g_i = 0;
double g_j = 0;

static char *g_sceneName = "..//media//boxscene.ray";
static char *g_imageName = NULL;
static const int g_ImageWidth = 512;
static const int g_ImageHeight = g_ImageWidth/4*3;
static const int g_ActualHeight = 512;
static const int g_ActualWidth = 512;

int g_GridDimension = 3;
int g_RenderPassese = 1;

int g_LinesRendered = 0;
int g_LinesDrawn = 0;

float g_PixelSums[g_ImageWidth][g_ImageHeight][4]={0};
float g_PixelVal[g_ActualWidth][g_ActualHeight][4]={0};
int g_PixelCounts[g_ImageWidth][g_ImageHeight] = {0};

int g_Win;
bool g_Changed = true;

txImage *g_Image;
txScene *g_Scene;


int _tmain(int argc, _TCHAR* argv[])
{
	NoiseInit();

	txResourceManageer resource;
	txScene *scene = resource.txReadRayFile(g_sceneName);

	if (!scene) exit(1);

	// trial save file
	char * filenamebkp = "D:\\pictures\\trial.jpg";
	txImage image(512,512);
	txRgb equalcolor(0.5,0.5,0.5);
	for (size_t i=0; i<512; i++){
		image.SetPixelRGB(i,40,equalcolor);
		image.SetPixelRGB(i,41,equalcolor);
		image.SetPixelRGB(i,42,equalcolor);
	}
	image.WriteJPEG(filenamebkp);

	return 0;
}

