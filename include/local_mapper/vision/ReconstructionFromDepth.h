//
// Created by carlostojal on 01-06-2023.
//

#ifndef LOCAL_MAPPING_CORE_RECONSTRUCTIONFROMDEPTH_H
#define LOCAL_MAPPING_CORE_RECONSTRUCTIONFROMDEPTH_H

#include <pcl/point_types.h>
#include <local_mapper/vision/RGBDCamera.h>
#include <utility>
#include <eigen3/Eigen/Dense>

namespace t24e {
    namespace local_mapper {
        namespace vision {

            class ReconstructionFromDepth {
                public:
                    static pcl::PointXYZ deprojectPixelToPoint(const local_mapper::vision::RGBDCamera& cam,
                                                               Eigen::Vector3d pixel);
            };

        } // t24e
    } // local_mapper
} // vision

#endif //LOCAL_MAPPING_CORE_RECONSTRUCTIONFROMDEPTH_H
