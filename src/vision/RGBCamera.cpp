//
// Created by carlostojal on 01-06-2023.
//

#include <local_mapper/vision/RGBCamera.h>
#include <local_mapper/vision/Utils.h>

namespace t24e::local_mapper::vision {

    StampedImage RGBCamera::getLastColorImage() const {
        return lastColorImage;
    }

    void RGBCamera::captureColorImage(const cv::Mat &img) {
        this->colorImageSet = true;
        this->lastColorImage = t24e::local_mapper::vision::Utils::make_stamped_image(img);;
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

    Eigen::Matrix3d RGBCamera::getK() const {
        return this->K;
    }

    void RGBCamera::setK(const Eigen::Matrix3d &k) {
        this->K = k;
    }

    bool RGBCamera::isKSet() const {
        return this->kSet;
    }
} // vision