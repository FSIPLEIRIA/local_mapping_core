//
// Created by carlostojal on 01-06-2023.
//

#ifndef LOCAL_MAPPING_CORE_RGBDCAMERA_H
#define LOCAL_MAPPING_CORE_RGBDCAMERA_H

#include <local_mapper/vision/RGBCamera.h>
#include <local_mapper/vision/Utils.h>

namespace t24e::local_mapper::vision {

    /*! \brief This class represents any RGB-D camera attached to the car.
     *
     * Besides the functionality offered by the RGB camera class, it keeps the latest depth image.
     */
    class RGBDCamera : RGBCamera {

        private:
            /*! \brief The latest depth image captured by the camera. */
            StampedImage lastDepthImage;

            /*! \brief Was a depth image set? */
            bool depthImageSet = false;

        public:
            StampedImage getLastDepthImage() const;
            void captureDepthImage(const cv::Mat& img);

            bool hasDepthImage() const;
    };

} // t24e

#endif //LOCAL_MAPPING_CORE_RGBDCAMERA_H
