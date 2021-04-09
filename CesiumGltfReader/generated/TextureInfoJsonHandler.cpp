// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "TextureInfoJsonHandler.h"
#include "CesiumGltf/TextureInfo.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

TextureInfoJsonHandler::TextureInfoJsonHandler(
    const ReaderContext& context) noexcept
    : ExtensibleObjectJsonHandler(context),
      _index(context),
      _texCoord(context) {}

void TextureInfoJsonHandler::reset(
    IJsonReader* pParent,
    TextureInfo* pObject) {
  ExtensibleObjectJsonHandler::reset(pParent, pObject);
  this->_pObject = pObject;
}

TextureInfo* TextureInfoJsonHandler::getObject() { return this->_pObject; }

void TextureInfoJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

IJsonReader*
TextureInfoJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyTextureInfo(
      TextureInfo::TypeName,
      str,
      *this->_pObject);
}

IJsonReader* TextureInfoJsonHandler::readObjectKeyTextureInfo(
    const std::string& objectType,
    const std::string_view& str,
    TextureInfo& o) {
  using namespace std::string_literals;

  if ("index"s == str)
    return property("index", this->_index, o.index);
  if ("texCoord"s == str)
    return property("texCoord", this->_texCoord, o.texCoord);

  return this->readObjectKeyExtensibleObject(objectType, str, *this->_pObject);
}
