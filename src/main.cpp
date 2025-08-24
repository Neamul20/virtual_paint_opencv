#include "VirtualPaint.h"
#include <iostream>

int main()
{
    VirtualPaint virtualPaint;
    while (true)
    {
        virtualPaint.m_cap.read(virtualPaint.m_img);
        virtualPaint.m_newPoints = virtualPaint.findColor(virtualPaint.m_img);


        virtualPaint.drawOnCanvas(virtualPaint.m_newPoints, virtualPaint.m_myColorValues);

		cv::imshow("Image", virtualPaint.m_img);
		cv::waitKey(1);


    }

    return 0;
}