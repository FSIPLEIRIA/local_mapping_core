//
// Created by carlostojal on 01-06-2023.
//

#include <local_mapper/LocalMapper.h>

namespace t24e {
    namespace local_mapper {
        LocalMapper::LocalMapper() {

        }

        LocalMapper::~LocalMapper() {
            // delete all camera pointers
            for(auto & c : this->cameras) {
                c.second.reset();
            }
        }

        void LocalMapper::addColorImage(const std::string &cameraName, const cv::Mat &img) {

            if(this->cameras.contains(cameraName)) {
                this->cameras[cameraName]->captureColorImage(img);
            } else {
                std::shared_ptr<vision::RGBCamera> newCamera = std::make_shared<vision::RGBCamera>();
                newCamera->captureColorImage(img);
                this->cameras[cameraName] = newCamera;
            }
        }

        void LocalMapper::setCameraTf(const std::string &cameraName, const Eigen::Affine3d& tf) {
            if(this->cameras.contains(cameraName)) {
                this->cameras[cameraName]->setTfToBase(tf);
            } else {
                std::shared_ptr<vision::RGBCamera> newCamera = std::make_shared<vision::RGBCamera>();
                newCamera->setTfToBase(tf);
                this->cameras[cameraName] = newCamera;
            }
        }

        pcl::PointCloud<pcl::PointXYZL> LocalMapper::getCurrentMap() const {
            return this->currentMap;
        }
    } // t24e
} // local_mapper