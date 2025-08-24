#ifndef VIRTUALPAINT_H
#define VIRTUALPAINT_H
#include <vector>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

#pragma once

class VirtualPaint
{
public:
    VirtualPaint();
    ~VirtualPaint();
std::vector<std::vector<int>> findColor(cv::Mat);
cv::Point getContours(cv::Mat image);
void drawOnCanvas(std::vector<std::vector<int>> newPoints, std::vector<cv::Scalar> myColorValues);


cv::Mat m_img;
cv::VideoCapture m_cap;
std::vector<std::vector<int>> m_newPoints;  // to store all points

// hmin, smin, vmin hmax, smax, vmax
const std::vector<std::vector<int>> m_myColors{{124,48,117,143,170,255}, // Purple
								               {68,72,156,102,126,255} };// Green

const std::vector<cv::Scalar> m_myColorValues{{255,0,255},		// Purple
								              {0,255,0} };// Green 

private:





};

#endif