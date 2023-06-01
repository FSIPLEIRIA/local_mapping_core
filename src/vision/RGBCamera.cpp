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

    Eigen::Matrix<double,3,4> RGBCamera::getTfToBaseAsRt() const {
        Eigen::Matrix3d rotation = this->tfToBase.rotation();
        Eigen::Vector3d translation = this->tfToBase.translation();

        Eigen::Matrix<double,3,4> m;
        m.block<3,3>(0,0) = rotation;
        m.block<3,1>(0,3) = translation;

        return m;
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