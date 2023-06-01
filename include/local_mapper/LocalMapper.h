//
// Created by carlostojal on 01-06-2023.
//

#ifndef LOCAL_MAPPING_CORE_LOCALMAPPER_H
#define LOCAL_MAPPING_CORE_LOCALMAPPER_H

#include <vector>
#include <local_mapper/vision/RGBCamera.h>

namespace t24e::local_mapper {

    class LocalMapper {

        private:
            std::vector<local_mapper::vision::RGBCamera> cameras;
    };

} // local_mapper

#endif //LOCAL_MAPPING_CORE_LOCALMAPPER_H
