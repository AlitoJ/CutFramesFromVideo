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

	 //	提取视频的高、宽、fps、帧总数
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
		 cout << "正在处理第" << currentFrame << "帧" << endl;
		 printf("\n");

		 // 每50帧获取一次帧
		 if (currentFrame % 100 == 0) {
			 // 将帧转成图片输出
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