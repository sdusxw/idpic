#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "jpg_codec.h"

int main(int argc, char ** argv)
{
	if(argc != 3)
	{
		std::cout << "usage:\t "  <<  argv[0] << " filename1\t filename2" << std::endl;
		exit(-1);
	}
	cv::Mat img1 = cv::imread(argv[1]);
	cv::Mat img2 = cv::imread(argv[2]);
	cv::imshow("img1", img1);
	cv::imshow("img2", img2);
	cv::Mat diff;
	cv::absdiff(img1, img2, diff);
	cv::imshow("diff", diff);
	cv::imwrite("diff.bmp", diff);
	cv::waitKey();
	return 0;
}
