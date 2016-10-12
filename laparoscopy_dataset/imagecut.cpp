#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <boost/algorithm/string.hpp>


#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>
#include <cstdlib>

using namespace cv;
using namespace std;

int main()
{
ifstream newfile("train.new"); 
string str((std::istreambuf_iterator<char>(newfile)),std::istreambuf_iterator<char>()); //copying content to string
std::vector<std::string> strs;
boost::split(strs, str, boost::is_any_of("\n")); //splitting with lines
int iter=1;
int pic_id=1174;
int prev_id=0;
for(iter=0;iter<strs.size();iter++)
{
	if(strs[iter].length()<8)
	{
		//cout<<strs[iter]<<endl;
		pic_id++;
	}
	else
	{
		
		stringstream ss;
		ss << pic_id;
		string filename="trainData/00"+ss.str()+".png";
		//cout<<filename<<endl;
		std::vector<std::string> info;
		boost::split(info,strs[iter], boost::is_any_of(" "));
		Mat src = imread(filename, CV_LOAD_IMAGE_COLOR);
		if(prev_id==pic_id) //second tool
		{
			cout<<"THE SECOND TOOL"<<endl;
			Rect secondrect;
			secondrect.y = std::stoi(info[1])-32;
			secondrect.x = std::stoi(info[2])-32;
			secondrect.width = 64;
			secondrect.height = 64;
			Mat croppedTool;
			croppedTool = src(secondrect);
			cout<<croppedTool.rows<<"  "<<croppedTool.cols<<endl;
			namedWindow("damn", CV_WINDOW_NORMAL);
			imshow("damn", croppedTool);
			imwrite( "genData/pos/second/second00"+ss.str()+".png", croppedTool );
		}
		else //first tool
		{
			cout<<"THE FIRST TOOL"<<endl;
			Rect firstrect;
			firstrect.y = std::stoi(info[1])-32;
			firstrect.x = std::stoi(info[2])-32;
			firstrect.width = 64;
			firstrect.height = 64;
			Mat croppedTool;
			croppedTool = src(firstrect);
			cout<<croppedTool.rows<<"  "<<croppedTool.cols<<endl;
			namedWindow("damn", CV_WINDOW_NORMAL);
			imshow("damn", croppedTool);
			imwrite( "genData/pos/first/first00"+ss.str()+".png", croppedTool );

		}
		// 
		// namedWindow("Image", CV_WINDOW_NORMAL);
		// imshow("Image", src);
		// waitKey(0);
		prev_id=pic_id;
	}
}
}