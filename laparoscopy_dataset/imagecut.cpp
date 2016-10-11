#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

char data[100000];
int main()
{
ifstream xmlfile;
xmlfile.open("train.xml",ios::in);
xmlfile >> data; 
int i=0;
for (i=0;i<100;i++)
{
cout<<data[i];
}
}