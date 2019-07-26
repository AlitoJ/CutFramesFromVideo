#include<stdio.h>
#include<iostream>
#include <windows.h> 
#include<omp.h>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/videoio.hpp>
#include<opencv.hpp>
 using namespace std;
 using namespace cv;

 int main()
 {
	 VideoCapture capture("Z:\\zhenni\\workfile\\zhenniTEST-Zhenni-2019-07-10\\videos\\2095test.mp4");
	 if (!capture.isOpened()) {
		 cout << "Error opening video stream or file" << endl;
		 return -1;
	 }

	 //	��ȡ��Ƶ�ĸߡ���fps��֡����
	 int frameH = (int)capture.get(CAP_PROP_FRAME_HEIGHT);
	 int frameW = (int)capture.get(CAP_PROP_FRAME_WIDTH);
	 int fps = (int)capture.get(CAP_PROP_FPS);
	 int numFrames = (int)capture.get(CAP_PROP_FRAME_COUNT);
	 printf("\tvideo height : %d\n\tvideo width : %d\n\tfps : %d\n\tframe numbers : %d\n", frameH, frameW, fps, numFrames);

	 Mat frame;
	 bool flags = true;
	 long currentFrame = 1;

	 while (flags) {
		 capture.read(frame);

		 stringstream str;
		 str << currentFrame << ".jpg";
		 //print the current frame number under processing
		 cout << "���ڴ����" << currentFrame << "֡" << endl;
		 printf("\n");

		 // ÿ50֡��ȡһ��֡
		 if (currentFrame % 100 == 0) {
			 // ��֡ת��ͼƬ���
			 imwrite("D:\\test\\" + str.str(), frame);
		 }

		 if (currentFrame > numFrames)
		 {
			 flags = false;
		 }
		 currentFrame++;
	 }
	 system("pause");
 }