// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/Library.h"
#include <CesiumUtility/ExtensibleObject.h>
#include <cstdint>
#include <unordered_map>

namespace CesiumGltf {
    /**
     * @brief KHR_draco_mesh_compression extension
     */
    struct CESIUMGLTF_API ExtensionKhrDracoMeshCompression final : public CesiumUtility::ExtensibleObject {
        static inline constexpr const char* TypeName = "ExtensionKhrDracoMeshCompression";
        static inline constexpr const char* ExtensionName = "KHR_draco_mesh_compression";

        /**
         * @brief The index of the bufferView.
         */
        int32_t bufferView = -1;

        /**
         * @brief A dictionary object, where each key corresponds to an attribute and its unique attribute id stored in the compressed geometry.
         */
        std::unordered_map<std::string, int32_t> attributes;

    };
}
