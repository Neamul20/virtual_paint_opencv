#include "VirtualPaint.h"

VirtualPaint::VirtualPaint(): m_cap(0)
{

}

VirtualPaint::~VirtualPaint()
{

}

std::vector<std::vector<int>> VirtualPaint::findColor(cv::Mat img)
{
    cv::Mat imgHSV;
	cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);

	for (int i = 0; i < m_myColors.size(); i++)
	{
		cv::Scalar lower(m_myColors[i][0], m_myColors[i][1], m_myColors[i][2]);
		cv::Scalar upper(m_myColors[i][3], m_myColors[i][4], m_myColors[i][5]);
		cv::Mat mask;
		cv::inRange(imgHSV, lower, upper, mask);
		//imshow(to_string(i), mask);
		cv::Point myPoint = getContours(mask);
		if (myPoint.x != 0 ) {
			m_newPoints.push_back({ myPoint.x,myPoint.y,i });
		}
	}
	return m_newPoints;

}


cv::Point VirtualPaint::getContours(cv::Mat image) {


	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	findContours(image, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
	std::vector<std::vector<cv::Point>> conPoly(contours.size());
	std::vector<cv::Rect> boundRect(contours.size());

	cv::Point myPoint(0, 0);

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		std::cout << area << std::endl;

		std::string objectType;

		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			std::cout << conPoly[i].size() << std::endl;
			boundRect[i] = boundingRect(conPoly[i]);
			myPoint.x = boundRect[i].x + boundRect[i].width / 2;
			myPoint.y = boundRect[i].y;

			//drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			//rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
		}
	}
	return myPoint;
}

void VirtualPaint::drawOnCanvas(std::vector<std::vector<int>> newPoints, std::vector<cv::Scalar> myColorValues)
{

	for (int i = 0; i < newPoints.size(); i++)
	{
		circle(m_img, cv::Point(newPoints[i][0],newPoints[i][1]), 10, myColorValues[newPoints[i][2]], cv::FILLED);
	}
}
