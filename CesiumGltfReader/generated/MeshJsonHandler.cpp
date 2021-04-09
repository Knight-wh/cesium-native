// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "MeshJsonHandler.h"
#include "CesiumGltf/Mesh.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

MeshJsonHandler::MeshJsonHandler(const ReaderContext& context) noexcept
    : NamedObjectJsonHandler(context),
      _primitives(context),
      _weights(context) {}

void MeshJsonHandler::reset(IJsonReader* pParent, Mesh* pObject) {
  NamedObjectJsonHandler::reset(pParent, pObject);
  this->_pObject = pObject;
}

Mesh* MeshJsonHandler::getObject() { return this->_pObject; }

void MeshJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

IJsonReader* MeshJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyMesh(Mesh::TypeName, str, *this->_pObject);
}

IJsonReader* MeshJsonHandler::readObjectKeyMesh(
    const std::string& objectType,
    const std::string_view& str,
    Mesh& o) {
  using namespace std::string_literals;

  if ("primitives"s == str)
    return property("primitives", this->_primitives, o.primitives);
  if ("weights"s == str)
    return property("weights", this->_weights, o.weights);

  return this->readObjectKeyNamedObject(objectType, str, *this->_pObject);
}
