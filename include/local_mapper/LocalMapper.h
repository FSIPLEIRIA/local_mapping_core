//
// Created by carlostojal on 01-06-2023.
//

#ifndef LOCAL_MAPPING_CORE_LOCALMAPPER_H
#define LOCAL_MAPPING_CORE_LOCALMAPPER_H

#include <local_mapper/vision/RGBCamera.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <vector>
#include <unordered_map>
#include <memory>
#include <thread>
#include <mutex>

namespace t24e::local_mapper {

    /*! \brief Main class of the project. Receives images from several cameras and returns cone detections in 3D space. */
    class LocalMapper {

        private:
            /*! \brief Map of camera's shared pointers indexed by a unique name. */
            std::unordered_map<std::string,std::shared_ptr<local_mapper::vision::RGBCamera>> cameras;

            /*! \brief Mutex which controls access to the cameras map. */
            std::mutex camerasMutex;

            /*! \brief Current map of cones. */
            pcl::PointCloud<pcl::PointXYZL> currentMap;

            /*! \brief Mutex which controls access to the cones map. */
            std::mutex mapMutex;

        public:
            LocalMapper();
            ~LocalMapper();

            /*! \brief Register a color image on a camera object. */
            void addColorImage(const std::string &cameraName, const cv::Mat &img);

            /*! \brief Declare the transform between a camera and the car's base frame. */
            void setCameraTf(const std::string& cameraName, const Eigen::Affine3d& tf);

            // TODO: keep the hash of the cameras to avoid re-computing when all the images are the same as the last time.
            /*! \brief Get the current cones map. Grabs the images from all the cameras, detects cones and
             * does 3D reconstruction. */
            pcl::PointCloud<pcl::PointXYZL> getCurrentMap() const;
    };

} // local_mapper

#endif //LOCAL_MAPPING_CORE_LOCALMAPPER_H
