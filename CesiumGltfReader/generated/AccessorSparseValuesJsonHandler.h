// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "ExtensibleObjectJsonHandler.h"
#include "IntegerJsonHandler.h"
#include <CesiumGltf/Reader.h>

namespace CesiumGltf {
struct AccessorSparseValues;

class AccessorSparseValuesJsonHandler : public ExtensibleObjectJsonHandler {
public:
  AccessorSparseValuesJsonHandler(const JsonReaderContext& context) noexcept;
  void reset(IJsonHandler* pHandler, AccessorSparseValues* pObject);
  AccessorSparseValues* getObject();
  virtual void reportWarning(
      const std::string& warning,
      std::vector<std::string>&& context = std::vector<std::string>()) override;

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* AccessorSparseValuesKey(
      const std::string& objectType,
      const std::string_view& str,
      AccessorSparseValues& o);

private:
  AccessorSparseValues* _pObject = nullptr;
  IntegerJsonHandler<int32_t> _bufferView;
  IntegerJsonHandler<int64_t> _byteOffset;
};
} // namespace CesiumGltf
