// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "ArrayJsonHandler.h"
#include "IntegerJsonHandler.h"
#include "NamedObjectJsonHandler.h"
#include <CesiumGltf/Reader.h>

namespace CesiumGltf {
struct Skin;

class SkinJsonHandler : public NamedObjectJsonHandler {
public:
  SkinJsonHandler(const JsonReaderContext& context) noexcept;
  void reset(IJsonHandler* pHandler, Skin* pObject);
  Skin* getObject();
  virtual void reportWarning(
      const std::string& warning,
      std::vector<std::string>&& context = std::vector<std::string>()) override;

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler*
  SkinKey(const std::string& objectType, const std::string_view& str, Skin& o);

private:
  Skin* _pObject = nullptr;
  IntegerJsonHandler<int32_t> _inverseBindMatrices;
  IntegerJsonHandler<int32_t> _skeleton;
  ArrayJsonHandler<int32_t, IntegerJsonHandler<int32_t>> _joints;
};
} // namespace CesiumGltf
