#ifndef CAMERA_H
#define CAMERA_H

#include "Global.h"
#include "Object.h"

namespace Video
{
	// this class will access the Web Camera and after processing the data, will send them to Engine
	class Camera
	{
	public:
		Camera();
		~Camera();

		// start the camera
		bool Start();
		// stop the camera
		bool Stop();

		void Record();

		Core::Object object;

	private:
		// handler for Camera
		bool _isRunning;
		bool _isTracking;

		// object associated to web camera
		cv::VideoCapture _webUpCameraID;
		cv::VideoCapture _webSideCameraID;
		// images
		cv::Mat _imgOriginalUpView;
		cv::Mat _imgOriginalSideView;
		cv::Mat _img1HSV;
		cv::Mat _img2HSV;
		cv::Mat _img1Thresh;
		cv::Mat _img2Thresh;
		cv::Mat _imgLines1;
		cv::Mat _imgLines2;
		cv::Mat _imgTmp1;
		cv::Mat _imgTmp2;

		int iLowH, iLowS, iLowV, iHighH, iHighS, iHighV;

		// object moving mark
		cv::Rect _objectBoundingRectangle = cv::Rect(0, 0, 0, 0);
		int _theObject[2] = { 0, 0 };

		// Threshold window
		void CreateControlWindow();

		void CreateThreshHold();

		void CalculateTrackedObjectPosition(int &iLast1X, int &iLast1Y, int &iLast2X, int &iLast2Y);

		void WindowsManipulation();

		// search object moving
		void SearchForMove(cv::Mat thresholdImage, cv::Mat &cameraFeed);

		// keyboard event watcher
		void KeyboardEvent();
	};
}

#endif // !CAMERA_H
