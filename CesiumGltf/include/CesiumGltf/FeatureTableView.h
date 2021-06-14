#pragma once

#include "CesiumGltf/MetadataPropertyView.h"
#include "CesiumGltf/Model.h"
#include "CesiumGltf/ModelEXT_feature_metadata.h"
#include "CesiumGltf/PropertyType.h"
#include <optional>

namespace CesiumGltf {
class FeatureTableView {
public:
  FeatureTableView(const Model* model, const FeatureTable* featureTable);

  const ClassProperty* getClassProperty(const std::string& propertyName) const;

  template <typename T>
  std::optional<MetadataPropertyView<T>>
  getPropertyValues(const std::string& propertyName) const {
    auto featureTablePropertyIter =
        _featureTable->properties.find(propertyName);
    if (featureTablePropertyIter == _featureTable->properties.end()) {
      return std::nullopt;
    }

    const FeatureTableProperty& featureTableProperty =
        featureTablePropertyIter->second;

    if constexpr (IsNumeric<T>::value) {
      return getNumericPropertyValues<T>(propertyName, featureTableProperty);
    }

    if constexpr (IsBoolean<T>::value) {
      return getBooleanPropertyValues(propertyName, featureTableProperty);
    }

    if constexpr (IsString<T>::value) {
      return getStringPropertyValues(propertyName, featureTableProperty);
    }

    if constexpr (IsNumericArray<T>::value) {
      return getNumericArrayPropertyValues<typename ArrayType<T>::type>(
          propertyName,
          featureTableProperty);
    }

    if constexpr (IsBooleanArray<T>::value) {
      return getBooleanArrayPropertyValues(propertyName, featureTableProperty);
    }

    if constexpr (IsStringArray<T>::value) {
      return getStringArrayPropertyValues(propertyName, featureTableProperty);
    }
  }

private:
  template <typename T>
  std::optional<MetadataPropertyView<T>> getNumericPropertyValues(
      const std::string& propertyName,
      const FeatureTableProperty& featureTableProperty) const {
    const ClassProperty* classProperty = getClassProperty(propertyName);
    if (!classProperty) {
      return std::nullopt;
    }

    PropertyType type = convertStringToPropertyType(classProperty->type);
    if (TypeToPropertyType<T>::value != static_cast<uint32_t>(type)) {
      return std::nullopt;
    }

    gsl::span<const std::byte> valueBuffer =
        getBufferSafe(featureTableProperty.bufferView);
    if (valueBuffer.empty()) {
      return std::nullopt;
    }

    if (valueBuffer.size() % sizeof(T) != 0) {
      return std::nullopt;
    }

    if (valueBuffer.size() < _featureTable->count * sizeof(T)) {
      return std::nullopt;
    }

    return MetadataPropertyView<T>(
        valueBuffer,
        gsl::span<const std::byte>(),
        gsl::span<const std::byte>(),
        PropertyType::None,
        0,
        _featureTable->count);
  }

  std::optional<MetadataPropertyView<bool>> getBooleanPropertyValues(
      const std::string& propertyName,
      const FeatureTableProperty& featureTableProperty) const;

  std::optional<MetadataPropertyView<std::string_view>> getStringPropertyValues(
      const std::string& propertyName,
      const FeatureTableProperty& featureTableProperty) const;

  template <typename T>
  std::optional<MetadataPropertyView<MetaArrayView<T>>>
  getNumericArrayPropertyValues(
      const std::string& propertyName,
      const FeatureTableProperty& featureTableProperty) const {
    const ClassProperty* classProperty = getClassProperty(propertyName);
    if (!classProperty) {
      return std::nullopt;
    }

    if (classProperty->type != "ARRAY") {
      return std::nullopt;
    }

    if (!classProperty->componentType.isString()) {
      return std::nullopt;
    }

    PropertyType componentType =
        convertStringToPropertyType(classProperty->componentType.getString());
    if (TypeToPropertyType<T>::value != static_cast<uint32_t>(componentType)) {
      return std::nullopt;
    }

    gsl::span<const std::byte> valueBuffer =
        getBufferSafe(featureTableProperty.bufferView);
    if (valueBuffer.empty()) {
      return std::nullopt;
    }

    if (valueBuffer.size() % sizeof(T) != 0) {
      return std::nullopt;
    }

    size_t componentCount = classProperty->componentCount.value_or(0);
    if (componentCount > 0 && featureTableProperty.arrayOffsetBufferView >= 0) {
      return std::nullopt;
    }

    if (componentCount == 0 && featureTableProperty.arrayOffsetBufferView < 0) {
      return std::nullopt;
    }

    // fixed array
    if (componentCount > 0) {
      if (valueBuffer.size() != _featureTable->count * componentCount) {
        return std::nullopt;
      }

      return MetadataPropertyView<MetaArrayView<T>>(
          valueBuffer,
          gsl::span<const std::byte>(),
          gsl::span<const std::byte>(),
          PropertyType::None,
          componentCount,
          _featureTable->count);
    }

    // dynamic array
    PropertyType offsetType =
        convertOffsetStringToPropertyType(featureTableProperty.offsetType);
    if (offsetType == PropertyType::None) {
      return std::nullopt;
    }

    gsl::span<const std::byte> offsetBuffer = getOffsetBufferSafe(
        featureTableProperty.arrayOffsetBufferView,
        offsetType,
        valueBuffer.size(),
        _featureTable->count,
        false);
    if (offsetBuffer.empty()) {
      return std::nullopt;
    }

    return MetadataPropertyView<MetaArrayView<T>>(
        valueBuffer,
        offsetBuffer,
        gsl::span<const std::byte>(),
        offsetType,
        0,
        _featureTable->count);
  }

  std::optional<MetadataPropertyView<MetaArrayView<bool>>>
  getBooleanArrayPropertyValues(
      const std::string& propertyName,
      const FeatureTableProperty& featureTableProperty) const;

  std::optional<MetadataPropertyView<MetaArrayView<std::string_view>>>
  getStringArrayPropertyValues(
      const std::string& propertyName,
      const FeatureTableProperty& featureTableProperty) const;

  gsl::span<const std::byte> getBufferSafe(int32_t bufferViewIdx) const;

  gsl::span<const std::byte> getOffsetBufferSafe(
      int32_t bufferViewIdx,
      PropertyType offsetType,
      size_t valueBufferSize,
      size_t instanceCount,
      bool checkBitsSize) const;

  const Model* _model;
  const FeatureTable* _featureTable;
  const Class* _class;
};
} // namespace CesiumGltf
