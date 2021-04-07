#pragma once

#include "CesiumGltf/JsonReader.h"
#include "CesiumGltf/Reader.h"

namespace CesiumGltf {
class BoolJsonHandler : public JsonHandler {
public:
  BoolJsonHandler(const JsonReaderContext& context) noexcept;
  void reset(IJsonHandler* pParent, bool* pBool);

  virtual IJsonHandler* readBool(bool b) override;

private:
  bool* _pBool = nullptr;
};
} // namespace CesiumGltf
