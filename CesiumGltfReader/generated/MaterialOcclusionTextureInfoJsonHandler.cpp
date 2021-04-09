// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "MaterialOcclusionTextureInfoJsonHandler.h"
#include "CesiumGltf/MaterialOcclusionTextureInfo.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

MaterialOcclusionTextureInfoJsonHandler::
    MaterialOcclusionTextureInfoJsonHandler(
        const ReaderContext& context) noexcept
    : TextureInfoJsonHandler(context), _strength(context) {}

void MaterialOcclusionTextureInfoJsonHandler::reset(
    IJsonReader* pParent,
    MaterialOcclusionTextureInfo* pObject) {
  TextureInfoJsonHandler::reset(pParent, pObject);
  this->_pObject = pObject;
}

MaterialOcclusionTextureInfo*
MaterialOcclusionTextureInfoJsonHandler::getObject() {
  return this->_pObject;
}

void MaterialOcclusionTextureInfoJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

IJsonReader* MaterialOcclusionTextureInfoJsonHandler::readObjectKey(
    const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyMaterialOcclusionTextureInfo(
      MaterialOcclusionTextureInfo::TypeName,
      str,
      *this->_pObject);
}

IJsonReader* MaterialOcclusionTextureInfoJsonHandler::
    readObjectKeyMaterialOcclusionTextureInfo(
        const std::string& objectType,
        const std::string_view& str,
        MaterialOcclusionTextureInfo& o) {
  using namespace std::string_literals;

  if ("strength"s == str)
    return property("strength", this->_strength, o.strength);

  return this->readObjectKeyTextureInfo(objectType, str, *this->_pObject);
}
