//
// Created by carlostojal on 01-06-2023.
//

#ifndef LOCAL_MAPPING_CORE_RGBDCAMERA_H
#define LOCAL_MAPPING_CORE_RGBDCAMERA_H

#include <local_mapper/vision/RGBCamera.h>

namespace t24e::local_mapper::vision {

    class RGBDCamera : RGBCamera {

        private:
            cv::Mat lastDepthImage;

            bool depthImageSet = false;

        public:
            cv::Mat getLastDepthImage() const;
            void captureDepthImage(const cv::Mat& img);

            bool hasDepthImage() const;
    };

} // t24e

#endif //LOCAL_MAPPING_CORE_RGBDCAMERA_H
