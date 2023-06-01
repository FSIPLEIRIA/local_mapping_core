//
// Created by carlostojal on 01-06-2023.
//

#include <local_mapper/vision/RGBCamera.h>

namespace t24e::local_mapper::vision {

    cv::Mat RGBCamera::getLastColorImage() const {
        return lastColorImage;
    }

    void RGBCamera::captureColorImage(const cv::Mat &img) {
        this->colorImageSet = true;
        this->lastColorImage = img;
    }

    Eigen::Affine3d RGBCamera::getTfToBase() const {
        return this->tfToBase;
    }

    void RGBCamera::setTfToBase(const Eigen::Affine3d &tf) {
        this->tfToBaseSet = true;
        this->tfToBase = tf;
    }

    bool RGBCamera::hasColorImage() const {
        return this->colorImageSet;
    }

    bool RGBCamera::isTfDefined() const {
        return this->tfToBaseSet;
    }
} // vision