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
			Mat second(200, 200, CV_8UC3, Scalar(0));
		}
		else //first tool
		{
			cout<<"THE FIRST TOOL"<<endl;
			Mat first(48,48, CV_8UC3, Scalar(0));

		}
		// 
		// namedWindow("Image", CV_WINDOW_NORMAL);
		// imshow("Image", src);
		// waitKey(0);
		prev_id=pic_id;
	}
}
}