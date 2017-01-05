#include "sceneimage.h"

SceneImage::SceneImage()
{
}
void SceneImage::setImage(string path)
{
    this->image = cv::imread(path,CV_LOAD_IMAGE_COLOR);
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
