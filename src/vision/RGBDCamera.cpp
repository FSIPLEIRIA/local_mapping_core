//
// Created by carlostojal on 01-06-2023.
//

#include <local_mapper/vision/RGBDCamera.h>

namespace t24e::local_mapper::vision {

    StampedImage RGBDCamera::getLastDepthImage() const {
        return this->lastDepthImage;
    }

    void RGBDCamera::captureDepthImage(const cv::Mat &img) {
        this->depthImageSet = true;
        this->lastDepthImage = local_mapper::vision::Utils::make_stamped_image(img);
    }

    bool RGBDCamera::hasDepthImage() const {
        return this->depthImageSet;
    }

} // RGBDCamera