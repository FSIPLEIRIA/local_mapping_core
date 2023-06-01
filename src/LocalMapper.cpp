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

            auto addImageRoutine = [](std::unordered_map<std::string,std::shared_ptr<vision::RGBCamera>>& cameras,
                    const std::string& cameraName, const cv::Mat& img, std::mutex& camerasMutex) {
                camerasMutex.lock();
                if(cameras.contains(cameraName)) {
                    cameras[cameraName]->captureColorImage(img);
                } else {
                    std::shared_ptr<vision::RGBCamera> newCamera = std::make_shared<vision::RGBCamera>();
                    newCamera->captureColorImage(img);
                    cameras[cameraName] = newCamera;
                }
                camerasMutex.unlock();
            };

            std::thread addImageThread(addImageRoutine, std::ref(this->cameras), std::ref(cameraName), std::ref(img),
                                       std::ref(this->camerasMutex));
            addImageThread.detach();
        }

        void LocalMapper::setCameraTf(const std::string &cameraName, const Eigen::Affine3d& tf) {

            auto setTfRoutine = [](std::unordered_map<std::string,std::shared_ptr<vision::RGBCamera>>& cameras,
                    const std::string& cameraName, const Eigen::Affine3d& tf, std::mutex& camerasMutex) {
                camerasMutex.lock();
                if(cameras.contains(cameraName)) {
                    cameras[cameraName]->setTfToBase(tf);
                } else {
                    std::shared_ptr<vision::RGBCamera> newCamera = std::make_shared<vision::RGBCamera>();
                    newCamera->setTfToBase(tf);
                    cameras[cameraName] = newCamera;
                }
                camerasMutex.unlock();
            };

            std::thread setTfThread(setTfRoutine, std::ref(this->cameras), std::ref(cameraName), std::ref(tf),
                                    std::ref(this->camerasMutex));
            setTfThread.detach();
        }

        pcl::PointCloud<pcl::PointXYZL> LocalMapper::getCurrentMap() const {
            return this->currentMap;
        }
    } // t24e
} // local_mapper