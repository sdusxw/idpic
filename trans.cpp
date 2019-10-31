#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "jpg_codec.h"

int main(int argc, char ** argv)
{
	if(argc != 2)
	{
		std::cout << "usage:\t "  <<  argv[0] << " filename" << std::endl;
		exit(-1);
	}
	EyeJpegCodec ejc;
	ejc.init();
	cv::Mat id_org = cv::imread(argv[1]);
	cv::imshow("id_org", id_org);
	cv::Mat id_pic;
	cv::resize(id_org, id_pic, cv::Size(102, 126));
	cv::imshow("id_pic", id_pic);
	char * p_jpg = (char*)malloc(10240);
	int jpg_size = 0;
	ejc.JpegCompress(102, 126, (const char*)id_pic.data, 102*126*3, p_jpg, &jpg_size);
	std::cout << "PIC size:\t" << jpg_size << std::endl;
	FILE * pFile;
	if((pFile = fopen ("id.jpg", "wb"))==NULL)
	{
		printf("cant open the file");
		exit(0);
	}
	fwrite (p_jpg , jpg_size, 1, pFile);
	fclose (pFile);
	free(p_jpg);
	
	cv::Mat img=cv::imread("id.jpg");
	cv::blur(img, img, cv::Size(3,3));
	cv::imwrite("id.bmp", img);
	
	cv::waitKey();
	return 0;
}
