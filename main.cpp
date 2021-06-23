//vs2010+opencv2.2
//zdd
//zddmail@gmail.com
//Just for fun


#include <windows.h>

#include <iostream>
using namespace std;

#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
using namespace cv;

#include "sift.h"


int main(int argc, char **argv)
{
	Mat src = imread("jobs_512.jpg");

	if(src.empty())
	{
		cout << "jobs_512.jpg open error! "<<endl;
		getchar();
		return -1;
	}

	if(src.channels()!=3)
		return -2;

	Vector<Keypoint> features;

	Sift(src, features, 1.6);
//	DrawKeyPoints(src, features);
	DrawSiftFeatures(src, features);

	write_features(features, "descriptor.txt");

	imshow("src", src);

	waitKey();
	return 0;
}
