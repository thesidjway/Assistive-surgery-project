#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <boost/algorithm/string.hpp>

#define minx 20
#define maxx 320
#define miny 20
#define maxy 220
#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>
#include <cstdlib>

using namespace cv;
using namespace std;

int main()
{
int i=0,j=0;
Mat src = imread("crop.png", CV_LOAD_IMAGE_COLOR);

for (i=0;i<160;i=i+2)
{
	for(j=0;j<112;j=j+2)
	{	std::stringstream is;
		string ist;
		//cout<<"i"<<i<<"j"<<j<<endl;
		Rect arbitrect;
		arbitrect.y = j;
		arbitrect.x = i;
		arbitrect.width = 32;
		arbitrect.height = 32;
		Mat croppedArbit;
		is <<"imageData/imi"<<i<<"j"<<j<<".png" ;
		ist = is.str();
		croppedArbit = src(arbitrect);
		namedWindow("damn", CV_WINDOW_NORMAL);
		imshow("damn", croppedArbit);
		imwrite( ist, croppedArbit );

	}
}
}
