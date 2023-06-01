//
// Created by carlostojal on 02-06-2023.
//

#ifndef LOCAL_MAPPING_CORE_TYPES_H
#define LOCAL_MAPPING_CORE_TYPES_H

#include <utility>
#include <cstdint>

namespace t24e::local_mapper::cnn {

    struct bounding_box_t {
        std::pair<std::pair<int,int>,std::pair<int,int>> box;
        uint32_t label;
    };
}

#endif //LOCAL_MAPPING_CORE_TYPES_H
