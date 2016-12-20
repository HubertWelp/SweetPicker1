#include "featureimage.h"

FeatureImage::FeatureImage()
{
}

void FeatureImage::setImage(string path)
{
    this->image = cv::imread(path,CV_LOAD_IMAGE_COLOR);
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
