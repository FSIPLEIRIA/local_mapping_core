//
// Created by carlostojal on 01-06-2023.
//

#ifndef LOCAL_MAPPING_CORE_RGBCAMERA_H
#define LOCAL_MAPPING_CORE_RGBCAMERA_H

#include <opencv2/opencv.hpp>
#include <eigen3/Eigen/Dense>
#include <utility>
#include <chrono>
#include <local_mapper/vision/types.h>

namespace t24e::local_mapper::vision {

    /*! \brief This class represents any RGB camera attached to the car.
     *
     * It keeps the latest color image and the transform between the camera and the car's base referential.
     */
    class RGBCamera {

        protected:
            /*! \brief The last color image captured by this camera. */
            StampedImage lastColorImage;

            /*! \brief Was a color image ever defined? */
            bool colorImageSet = false;

            /*! \brief Transform between this camera's optical axis and the car's base axis. */
            Eigen::Affine3d tfToBase;

            /*! \brief Was the transform to the base referential defined? */
            bool tfToBaseSet = false;

            /*! \brief Camera's intrinsic matrix. */
            Eigen::Matrix3d K;

            /*! \brief Was the intrinsic matrix set? */
            bool kSet = false;

        public:
            /*! \brief Get the last color image. */
            StampedImage getLastColorImage() const;

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

            /*! \brief Get the defined intrinsic matrix. */
            Eigen::Matrix3d getK() const;

            /*! \brief Set the camera's intrinsic matrix. */
            void setK(const Eigen::Matrix3d& k);

            /*! \brief Is the intrinsic matrix set? */
            bool isKSet() const;

    };

} // vision

#endif //LOCAL_MAPPING_CORE_RGBCAMERA_H
