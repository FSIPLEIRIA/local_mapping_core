//
// Created by carlostojal on 01-06-2023.
//

#ifndef LOCAL_MAPPING_CORE_DAMO_H
#define LOCAL_MAPPING_CORE_DAMO_H

#include <local_mapper/cnn/ConeDetector.h>

namespace t24e {
    namespace local_mapper {
        namespace cnn {

            class DAMO : ConeDetector {

                public:
                    bounding_box_t detectCones(cv::Mat img) override;
            };

        } // t24e
    } // local_mapper
} // cnn

#endif //LOCAL_MAPPING_CORE_DAMO_H
