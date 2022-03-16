// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "Cesium3DTiles/ClassProperty.h"
#include "Cesium3DTiles/Library.h"

#include <CesiumUtility/ExtensibleObject.h>

#include <optional>
#include <string>
#include <unordered_map>

namespace Cesium3DTiles {
/**
 * @brief A class containing a set of properties.
 */
struct CESIUM3DTILES_API Class final : public CesiumUtility::ExtensibleObject {
  static inline constexpr const char* TypeName = "Class";

  /**
   * @brief The name of the class, e.g. for display purposes.
   */
  std::optional<std::string> name;

  /**
   * @brief The description of the class.
   */
  std::optional<std::string> description;

  /**
   * @brief A dictionary, where each key is a property ID and each value is an
   * object defining the property. Property IDs must be alphanumeric identifiers
   * matching the regular expression `^[a-zA-Z_][a-zA-Z0-9_]*$`.
   */
  std::unordered_map<std::string, Cesium3DTiles::ClassProperty> properties;
};
} // namespace Cesium3DTiles
