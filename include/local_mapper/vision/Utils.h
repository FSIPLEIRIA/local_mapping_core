//
// Created by carlostojal on 01-06-2023.
//

#ifndef LOCAL_MAPPING_CORE_UTILS_H
#define LOCAL_MAPPING_CORE_UTILS_H

#include <local_mapper/vision/types.h>
#include <chrono>

namespace t24e {
    namespace local_mapper {
        namespace vision {

            class Utils {
                public:
                    static t24e::local_mapper::vision::StampedImage make_stamped_image(const cv::Mat& img);
            };

        } // t24e
    } // local_mapper
} // vision

#endif //LOCAL_MAPPING_CORE_UTILS_H
