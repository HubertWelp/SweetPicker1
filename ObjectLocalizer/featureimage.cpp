#include "featureimage.h"

FeatureImage::FeatureImage()
{
}

void FeatureImage::setImage(cv::Mat img)
{
    if(!img.data)
      { cout << "Error reading images " << endl;}
    else this->image = img;
}

cv::Mat FeatureImage::getImage()
{
    return this->image;
}

void FeatureImage::setKeypoints(vector<cv::KeyPoint> keypoints)
{
    this->keypoints_object = keypoints;
}

vector<cv::KeyPoint> FeatureImage::getKeypoints()
{
    return this->keypoints_object;
}

void FeatureImage::setDescriptor(cv::Mat descriptor)
{
    this->descriptors_obj = descriptor;
}

cv::Mat FeatureImage::getDescriptor()
{
    return this->descriptors_obj;
}
