#include "imagesnapperproxy.h"

ImageSnapperProxy::ImageSnapperProxy()
{
    this->setImagePath("C:\\SP1\\scene.png");
}

void ImageSnapperProxy::setImagePath(string path)
{
    this->scenePath = path;
}

string ImageSnapperProxy::getImagePath()
{
    return this->scenePath;
}

cv::Mat ImageSnapperProxy::getImage()
{
/*
    cv::Mat src =  cv::imread(this->getImagePath());
    cv::Mat dst = cv::Mat(src.rows, src.cols, CV_8UC3);
    cv::flip(src, dst, 1);

    cv::Point2f src_center(dst.cols/2.0F, dst.rows/2.0F);

    cv::Mat rot_matrix = cv::getRotationMatrix2D(src_center, 180.0, 1.0);

    cv::Mat rotated_img(cv::Size(dst.size().height, dst.size().width), dst.type());

    cv::warpAffine(dst, rotated_img, rot_matrix, dst.size());
    return rotated_img;
*/
    return cv::imread(this->getImagePath());
}
