#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
//调用摄像头
int main()
{
	VideoCapture cap;          //实例化一个videocapture类，名称为cap
	cap.open(0);              //打开本机的第一个摄像头
	if (!cap.isOpened())     //isOpened()检查视频是否开启，正常开启返回1
	{
		std::cout << "不可打开视频文件" << std::endl;
		return -1;
	}
	double fps = cap.get(CAP_PROP_FPS);//通过get()及不同参数可以获得视频的fps
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		cv::Mat frame;
		cv::Mat dst;
		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "不能从视频中读取帧" << std::endl;
			break;
		}
		else
		{
            //中值滤波函数
			medianBlur(frame, dst, 3);
			cv::imshow("frame ", frame);
			cv::imshow("dst ", dst);
		}
		waitKey(30);

	}
	return 0;
}