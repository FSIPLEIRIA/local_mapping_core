//
// Created by carlostojal on 01-06-2023.
//

#include <local_mapper/vision/RGBDCamera.h>

namespace t24e::local_mapper::vision {

    cv::Mat RGBDCamera::getLastDepthImage() const {
        return this->lastDepthImage;
    }

    void RGBDCamera::captureDepthImage(const cv::Mat &img) {
        this->depthImageSet = true;
        this->lastDepthImage = img;
    }

    bool RGBDCamera::hasDepthImage() const {
        return this->depthImageSet;
    }

} // RGBDCamera