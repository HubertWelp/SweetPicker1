#include "sceneimage.h"

SceneImage::SceneImage()
{
}
void SceneImage::setImage(cv::Mat img)
{
    if(!img.data)
      { cout << "Error reading images " << endl;}
    else this->image = img;
}

cv::Mat SceneImage::getImage()
{
    return this->image;
}

void SceneImage::setKeypoints(vector<cv::KeyPoint> keypoints)
{
    this->keypoints_scene = keypoints;
}

vector<cv::KeyPoint> SceneImage::getKeypoints()
{
    return this->keypoints_scene;
}

void SceneImage::setPosition(PositionT pos)
{
    this->position = pos;
}

PositionT  SceneImage::getPosition()
{
    return this->position;
}

void SceneImage::setDescriptor(cv::Mat descriptor)
{
    this->descriptors_scene = descriptor;
}

cv::Mat SceneImage::getDescriptor()
{
    return this->descriptors_scene;
}
