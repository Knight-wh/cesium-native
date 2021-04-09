// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "ArrayJsonHandler.h"
#include "DoubleJsonHandler.h"
#include "MeshPrimitiveJsonHandler.h"
#include "NamedObjectJsonHandler.h"
#include <CesiumGltf/Reader.h>

namespace CesiumGltf {
struct Mesh;

class MeshJsonHandler : public NamedObjectJsonHandler {
public:
  MeshJsonHandler(const ReaderContext& context) noexcept;
  void reset(IJsonReader* pHandler, Mesh* pObject);
  Mesh* getObject();
  virtual void reportWarning(
      const std::string& warning,
      std::vector<std::string>&& context = std::vector<std::string>()) override;

  virtual IJsonReader* readObjectKey(const std::string_view& str) override;

protected:
  IJsonReader* readObjectKeyMesh(
      const std::string& objectType,
      const std::string_view& str,
      Mesh& o);

private:
  Mesh* _pObject = nullptr;
  ArrayJsonHandler<MeshPrimitive, MeshPrimitiveJsonHandler> _primitives;
  ArrayJsonHandler<double, DoubleJsonHandler> _weights;
};
} // namespace CesiumGltf
