//
// Created by carlostojal on 01-06-2023.
//

#include <local_mapper/vision/ReconstructionFromDepth.h>

namespace t24e {
    namespace local_mapper {
        namespace vision {
            pcl::PointXYZ ReconstructionFromDepth::deprojectPixelToPoint(const RGBDCamera &cam, Eigen::Vector3d pixel) {

                return pcl::PointXYZ((pixel.x() - cam.getK()(0,2)) * pixel.z() / cam.getK()(0,0),
                                     (pixel.y() - cam.getK()(1,2)) * pixel.z() / cam.getK()(1,1),
                                     pixel.z());
            }
        } // t24e
    } // local_mapper
} // vision