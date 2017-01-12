#include "detector.h"

Detector::Detector()
{
}

void Detector::findKeypoints(FeatureImage& image)
{
    int minHessian = 400;
    cv::SurfFeatureDetector detector(minHessian);
    vector<cv::KeyPoint> keypoints;
    cv::SurfDescriptorExtractor extractor;
    cv::Mat descriptors;

    detector.detect(image.getImage(),keypoints);
    image.setKeypoints(keypoints);

    extractor.compute(image.getImage(),keypoints,descriptors);
    image.setDescriptor(descriptors);

}

void Detector::findKeypoints(SceneImage& image)
{
    int minHessian = 400;
    cv::SurfFeatureDetector detector(minHessian);
    vector<cv::KeyPoint> keypoints;
    cv::SurfDescriptorExtractor extractor;
    cv::Mat descriptors;

    detector.detect(image.getImage(),keypoints);
    image.setKeypoints(keypoints);

    extractor.compute(image.getImage(),keypoints,descriptors);
    image.setDescriptor(descriptors);

}

void Detector::compare(FeatureImage& object, SceneImage& scene)
{
    cv::FlannBasedMatcher matcher;
    vector<cv::DMatch> matches;
    double maxDist = 0;
    double minDist = 100;
    int i;
    vector<cv::DMatch> goodMatches;
    vector<cv::Point2f> objectG;
    vector<cv::Point2f> sceneG;
    cv::Mat H;
    vector<cv::Point2f> objCorners(4);
    vector<cv::Point2f> sceneCorners(4);
    cv::Mat copyScene = scene.getImage();
    PositionT temp;

    matcher.match(object.getDescriptor(),scene.getDescriptor(),matches);

    for(i=0; i<object.getDescriptor().rows; i++)
    {
        double dist = matches[i].distance;
            if( dist < minDist ) minDist = dist;
            if( dist > maxDist ) maxDist = dist;
    }

    for(i=0;i<object.getDescriptor().rows; i++)
    {
        if( matches[i].distance < 3*minDist)
        {
            goodMatches.push_back(matches[i]);
        }
    }

    for(i=0; i < goodMatches.size(); i++)
    {
        objectG.push_back(object.getKeypoints()[goodMatches[i].queryIdx].pt );
        sceneG.push_back(scene.getKeypoints()[goodMatches[i].trainIdx].pt );
    }

    H = cv::findHomography(objectG, sceneG, CV_RANSAC);

    objCorners[0] = cvPoint(0,0);
    objCorners[1] = cvPoint(object.getImage().cols, 0);
    objCorners[2] = cvPoint(object.getImage().cols, object.getImage().rows);
    objCorners[3] = cvPoint(0, object.getImage().rows);

    cv::perspectiveTransform(objectG, sceneG, H);

    cv::line( copyScene, sceneCorners[0] + cv::Point2f( object.getImage().cols, 0), sceneCorners[1] + cv::Point2f( object.getImage().cols, 0), cv::Scalar(0, 255, 0), 4 );
    cv::line( copyScene, sceneCorners[1] + cv::Point2f( object.getImage().cols, 0), sceneCorners[2] + cv::Point2f( object.getImage().cols, 0), cv::Scalar( 0, 255, 0), 4 );
    cv::line( copyScene, sceneCorners[2] + cv::Point2f( object.getImage().cols, 0), sceneCorners[3] + cv::Point2f( object.getImage().cols, 0), cv::Scalar( 0, 255, 0), 4 );
    cv::line( copyScene, sceneCorners[3] + cv::Point2f( object.getImage().cols, 0), sceneCorners[0] + cv::Point2f( object.getImage().cols, 0), cv::Scalar( 0, 255, 0), 4 );

    scene.setImage(copyScene);
}
