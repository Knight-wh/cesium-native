// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/AnimationChannelTarget.h"
#include "ExtensibleObjectJsonHandler.h"
#include "IntegerJsonHandler.h"
#include <CesiumGltf/Reader.h>

namespace CesiumGltf {
struct AnimationChannelTarget;

class AnimationChannelTargetJsonHandler : public ExtensibleObjectJsonHandler {
public:
  AnimationChannelTargetJsonHandler(const JsonReaderContext& context) noexcept;
  void reset(IJsonHandler* pHandler, AnimationChannelTarget* pObject);
  AnimationChannelTarget* getObject();
  virtual void reportWarning(
      const std::string& warning,
      std::vector<std::string>&& context = std::vector<std::string>()) override;

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* AnimationChannelTargetKey(
      const std::string& objectType,
      const std::string_view& str,
      AnimationChannelTarget& o);

private:
  class PathJsonHandler : public JsonHandler {
  public:
    PathJsonHandler(const JsonReaderContext& context) noexcept
        : JsonHandler(context) {}
    void reset(IJsonHandler* pParent, AnimationChannelTarget::Path* pEnum);
    virtual IJsonHandler* readString(const std::string_view& str) override;

  private:
    AnimationChannelTarget::Path* _pEnum = nullptr;
  };

  AnimationChannelTarget* _pObject = nullptr;
  IntegerJsonHandler<int32_t> _node;
  PathJsonHandler _path;
};
} // namespace CesiumGltf
