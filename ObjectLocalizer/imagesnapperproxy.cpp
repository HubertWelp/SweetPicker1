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
    return cv::imread(this->getImagePath());
}
