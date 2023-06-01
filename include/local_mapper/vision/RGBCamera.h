//
// Created by carlostojal on 01-06-2023.
//

#ifndef LOCAL_MAPPING_CORE_RGBCAMERA_H
#define LOCAL_MAPPING_CORE_RGBCAMERA_H

#include <opencv2/opencv.hpp>
#include <eigen3/Eigen/Dense>

namespace t24e::local_mapper::vision {

    class RGBCamera {

        protected:
            /*! \brief The last color image captured by this camera. */
            cv::Mat lastColorImage;

            /*! \brief Was a color image ever defined? */
            bool colorImageSet = false;

            /*! \brief Transform between this camera's optical axis and the car's base axis. */
            Eigen::Affine3d tfToBase;

            /*! \brief Was the transform to the base referential defined? */
            bool tfToBaseSet = false;

        public:
            /*! \brief Get the last color image. */
            cv::Mat getLastColorImage() const;

            /*! \brief Provide this class a new color image. */
            void captureColorImage(const cv::Mat& img);

            /*! \brief Check if the camera has a color image to provide. */
            bool hasColorImage() const;

            /*! \brief Get the transform between the camera's optical axis and the car's axis. */
            Eigen::Affine3d getTfToBase() const;

            /*! \brief Set the transform between the camera's optical axis and the car's axis. */
            void setTfToBase(const Eigen::Affine3d& tf);

            /*! \brief Check if the transform between the camera's optical axis and the car's axis was defined. */
            bool isTfDefined() const;

    };

} // vision

#endif //LOCAL_MAPPING_CORE_RGBCAMERA_H
