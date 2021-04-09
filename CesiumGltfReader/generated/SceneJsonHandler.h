// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "ArrayJsonHandler.h"
#include "IntegerJsonHandler.h"
#include "NamedObjectJsonHandler.h"
#include <CesiumGltf/Reader.h>

namespace CesiumGltf {
struct Scene;

class SceneJsonHandler : public NamedObjectJsonHandler {
public:
  SceneJsonHandler(const ReaderContext& context) noexcept;
  void reset(IJsonReader* pHandler, Scene* pObject);
  Scene* getObject();
  virtual void reportWarning(
      const std::string& warning,
      std::vector<std::string>&& context = std::vector<std::string>()) override;

  virtual IJsonReader* readObjectKey(const std::string_view& str) override;

protected:
  IJsonReader* readObjectKeyScene(
      const std::string& objectType,
      const std::string_view& str,
      Scene& o);

private:
  Scene* _pObject = nullptr;
  ArrayJsonHandler<int32_t, IntegerJsonHandler<int32_t>> _nodes;
};
} // namespace CesiumGltf
