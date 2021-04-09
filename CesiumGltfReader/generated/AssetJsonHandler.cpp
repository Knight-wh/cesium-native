// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "AssetJsonHandler.h"
#include "CesiumGltf/Asset.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

AssetJsonHandler::AssetJsonHandler(const ReaderContext& context) noexcept
    : ExtensibleObjectJsonHandler(context),
      _copyright(context),
      _generator(context),
      _version(context),
      _minVersion(context) {}

void AssetJsonHandler::reset(IJsonReader* pParent, Asset* pObject) {
  ExtensibleObjectJsonHandler::reset(pParent, pObject);
  this->_pObject = pObject;
}

Asset* AssetJsonHandler::getObject() { return this->_pObject; }

void AssetJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

IJsonReader* AssetJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyAsset(Asset::TypeName, str, *this->_pObject);
}

IJsonReader* AssetJsonHandler::readObjectKeyAsset(
    const std::string& objectType,
    const std::string_view& str,
    Asset& o) {
  using namespace std::string_literals;

  if ("copyright"s == str)
    return property("copyright", this->_copyright, o.copyright);
  if ("generator"s == str)
    return property("generator", this->_generator, o.generator);
  if ("version"s == str)
    return property("version", this->_version, o.version);
  if ("minVersion"s == str)
    return property("minVersion", this->_minVersion, o.minVersion);

  return this->readObjectKeyExtensibleObject(objectType, str, *this->_pObject);
}
