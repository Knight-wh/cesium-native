// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "DictionaryJsonHandler.h"
#include "ExtensibleObjectJsonHandler.h"
#include "IntegerJsonHandler.h"
#include <CesiumGltf/Reader.h>

namespace CesiumGltf {
struct KHR_draco_mesh_compression;

class KHR_draco_mesh_compressionJsonHandler
    : public ExtensibleObjectJsonHandler,
      public IExtensionJsonReader {
public:
  static inline const std::string ExtensionName = "KHR_draco_mesh_compression";

  KHR_draco_mesh_compressionJsonHandler(
      const ReaderContext& context) noexcept;
  void reset(IJsonReader* pHandler, KHR_draco_mesh_compression* pObject);
  KHR_draco_mesh_compression* getObject();
  virtual void reportWarning(
      const std::string& warning,
      std::vector<std::string>&& context = std::vector<std::string>()) override;

  virtual IJsonReader* readObjectKey(const std::string_view& str) override;

  virtual void reset(
      IJsonReader* pParentHandler,
      ExtensibleObject& o,
      const std::string_view& extensionName) override;

  virtual IJsonReader* readNull() override {
    return ExtensibleObjectJsonHandler::readNull();
  };
  virtual IJsonReader* readBool(bool b) override {
    return ExtensibleObjectJsonHandler::readBool(b);
  }
  virtual IJsonReader* readInt32(int32_t i) override {
    return ExtensibleObjectJsonHandler::readInt32(i);
  }
  virtual IJsonReader* readUint32(uint32_t i) override {
    return ExtensibleObjectJsonHandler::readUint32(i);
  }
  virtual IJsonReader* readInt64(int64_t i) override {
    return ExtensibleObjectJsonHandler::readInt64(i);
  }
  virtual IJsonReader* readUint64(uint64_t i) override {
    return ExtensibleObjectJsonHandler::readUint64(i);
  }
  virtual IJsonReader* readDouble(double d) override {
    return ExtensibleObjectJsonHandler::readDouble(d);
  }
  virtual IJsonReader* readString(const std::string_view& str) override {
    return ExtensibleObjectJsonHandler::readString(str);
  }
  virtual IJsonReader* readObjectStart() override {
    return ExtensibleObjectJsonHandler::readObjectStart();
  }
  virtual IJsonReader* readObjectEnd() override {
    return ExtensibleObjectJsonHandler::readObjectEnd();
  }
  virtual IJsonReader* readArrayStart() override {
    return ExtensibleObjectJsonHandler::readArrayStart();
  }
  virtual IJsonReader* readArrayEnd() override {
    return ExtensibleObjectJsonHandler::readArrayEnd();
  }

protected:
  IJsonReader* readObjectKeyKHR_draco_mesh_compression(
      const std::string& objectType,
      const std::string_view& str,
      KHR_draco_mesh_compression& o);

private:
  KHR_draco_mesh_compression* _pObject = nullptr;
  IntegerJsonHandler<int32_t> _bufferView;
  DictionaryJsonHandler<int32_t, IntegerJsonHandler<int32_t>> _attributes;
};
} // namespace CesiumGltf
