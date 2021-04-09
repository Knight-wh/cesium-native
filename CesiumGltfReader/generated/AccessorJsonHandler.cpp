// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "AccessorJsonHandler.h"
#include "CesiumGltf/Accessor.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

AccessorJsonHandler::AccessorJsonHandler(
    const ReaderContext& context) noexcept
    : NamedObjectJsonHandler(context),
      _bufferView(context),
      _byteOffset(context),
      _componentType(context),
      _normalized(context),
      _count(context),
      _type(context),
      _max(context),
      _min(context),
      _sparse(context) {}

void AccessorJsonHandler::reset(IJsonReader* pParent, Accessor* pObject) {
  NamedObjectJsonHandler::reset(pParent, pObject);
  this->_pObject = pObject;
}

Accessor* AccessorJsonHandler::getObject() { return this->_pObject; }

void AccessorJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

IJsonReader* AccessorJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyAccessor(Accessor::TypeName, str, *this->_pObject);
}

IJsonReader* AccessorJsonHandler::readObjectKeyAccessor(
    const std::string& objectType,
    const std::string_view& str,
    Accessor& o) {
  using namespace std::string_literals;

  if ("bufferView"s == str)
    return property("bufferView", this->_bufferView, o.bufferView);
  if ("byteOffset"s == str)
    return property("byteOffset", this->_byteOffset, o.byteOffset);
  if ("componentType"s == str)
    return property("componentType", this->_componentType, o.componentType);
  if ("normalized"s == str)
    return property("normalized", this->_normalized, o.normalized);
  if ("count"s == str)
    return property("count", this->_count, o.count);
  if ("type"s == str)
    return property("type", this->_type, o.type);
  if ("max"s == str)
    return property("max", this->_max, o.max);
  if ("min"s == str)
    return property("min", this->_min, o.min);
  if ("sparse"s == str)
    return property("sparse", this->_sparse, o.sparse);

  return this->readObjectKeyNamedObject(objectType, str, *this->_pObject);
}

void AccessorJsonHandler::TypeJsonHandler::reset(
    IJsonReader* pParent,
    Accessor::Type* pEnum) {
  JsonReader::reset(pParent);
  this->_pEnum = pEnum;
}

IJsonReader*
AccessorJsonHandler::TypeJsonHandler::readString(const std::string_view& str) {
  using namespace std::string_literals;

  assert(this->_pEnum);

  if ("SCALAR"s == str)
    *this->_pEnum = Accessor::Type::SCALAR;
  else if ("VEC2"s == str)
    *this->_pEnum = Accessor::Type::VEC2;
  else if ("VEC3"s == str)
    *this->_pEnum = Accessor::Type::VEC3;
  else if ("VEC4"s == str)
    *this->_pEnum = Accessor::Type::VEC4;
  else if ("MAT2"s == str)
    *this->_pEnum = Accessor::Type::MAT2;
  else if ("MAT3"s == str)
    *this->_pEnum = Accessor::Type::MAT3;
  else if ("MAT4"s == str)
    *this->_pEnum = Accessor::Type::MAT4;
  else
    return nullptr;

  return this->parent();
}
