//
// Created by carlostojal on 01-06-2023.
//

#ifndef LOCAL_MAPPING_CORE_CONEDETECTOR_H
#define LOCAL_MAPPING_CORE_CONEDETECTOR_H

#include <local_mapper/cnn/types.h>
#include <opencv2/opencv.hpp>

namespace t24e {
    namespace local_mapper {
        namespace cnn {

            class ConeDetector {

                public:
                    virtual bounding_box_t detectCones(cv::Mat img) = 0;
            };

        } // t24e
    } // local_mapper
} // cnn

#endif //LOCAL_MAPPING_CORE_CONEDETECTOR_H
