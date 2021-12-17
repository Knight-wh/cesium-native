// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!

#include "TilesetJsonWriter.h"

#include <Cesium3DTiles/Asset.h>
#include <Cesium3DTiles/BoundingVolume.h>
#include <Cesium3DTiles/Content.h>
#include <Cesium3DTiles/Extension3dTilesBoundingVolumeS2.h>
#include <Cesium3DTiles/Extension3dTilesContentGltf.h>
#include <Cesium3DTiles/Properties.h>
#include <Cesium3DTiles/Tile.h>
#include <Cesium3DTiles/Tileset.h>
#include <CesiumJsonWriter/ExtensionWriterContext.h>
#include <CesiumJsonWriter/JsonObjectWriter.h>
#include <CesiumJsonWriter/JsonWriter.h>
#include <CesiumJsonWriter/writeJsonExtensions.h>
#include <CesiumUtility/JsonValue.h>

namespace Cesium3DTilesWriter {

namespace {

void writeJson(
    const Cesium3DTiles::Extension3dTilesContentGltf& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context);

void writeJson(
    const Cesium3DTiles::Extension3dTilesBoundingVolumeS2& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context);

void writeJson(
    const Cesium3DTiles::Tileset& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context);

void writeJson(
    const Cesium3DTiles::Tile& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context);

void writeJson(
    const Cesium3DTiles::Content& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context);

void writeJson(
    const Cesium3DTiles::BoundingVolume& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context);

void writeJson(
    const Cesium3DTiles::Properties& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context);

void writeJson(
    const Cesium3DTiles::Asset& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context);

[[maybe_unused]] void writeJson(
    const std::string& str,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
  jsonWriter.String(str);
}

[[maybe_unused]] void writeJson(
    double val,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
  jsonWriter.Double(val);
}

[[maybe_unused]] void writeJson(
    bool val,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
  jsonWriter.Bool(val);
}

[[maybe_unused]] void writeJson(
    int64_t val,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
  jsonWriter.Int64(val);
}

[[maybe_unused]] void writeJson(
    int32_t val,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
  jsonWriter.Int64(val);
}

[[maybe_unused]] void writeJson(
    const CesiumUtility::JsonValue::Object& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
  jsonWriter.StartObject();
  for (const auto& item : obj) {
    jsonWriter.Key(item.first);
    CesiumJsonWriter::writeJsonValue(item.second, jsonWriter);
  }
  jsonWriter.EndObject();
}

[[maybe_unused]] void writeJson(
    const CesiumUtility::JsonValue& value,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
  CesiumJsonWriter::writeJsonValue(value, jsonWriter);
}

template <typename T>
[[maybe_unused]] void writeJson(
    const std::unordered_map<std::string, T>& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  jsonWriter.StartObject();
  for (const auto& item : obj) {
    jsonWriter.Key(item.first);
    writeJson(item.second, jsonWriter, context);
  }
  jsonWriter.EndObject();
}

template <typename T>
[[maybe_unused]] void writeJson(
    const std::vector<T>& list,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  jsonWriter.StartArray();
  for (const T& item : list) {
    writeJson(item, jsonWriter, context);
  }
  jsonWriter.EndArray();
}

template <typename T>
[[maybe_unused]] void writeJson(
    const std::optional<T>& val,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  if (val.has_value()) {
    writeJson(*val, jsonWriter, context);
  } else {
    jsonWriter.Null();
  }
}

void writeJson(
    const Cesium3DTiles::Extension3dTilesContentGltf& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  if (!obj.extensionsUsed.empty()) {
    jsonWriter.Key("extensionsUsed");
    writeJson(obj.extensionsUsed, jsonWriter, context);
  }

  if (!obj.extensionsRequired.empty()) {
    jsonWriter.Key("extensionsRequired");
    writeJson(obj.extensionsRequired, jsonWriter, context);
  }

  if (!obj.extensions.empty()) {
    jsonWriter.Key("extensions");
    writeJsonExtensions(obj, jsonWriter, context);
  }

  if (!obj.extras.empty()) {
    jsonWriter.Key("extras");
    writeJson(obj.extras, jsonWriter, context);
  }

  jsonWriter.EndObject();
}

void writeJson(
    const Cesium3DTiles::Extension3dTilesBoundingVolumeS2& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  jsonWriter.Key("token");
  writeJson(obj.token, jsonWriter, context);

  jsonWriter.Key("minimumHeight");
  writeJson(obj.minimumHeight, jsonWriter, context);

  jsonWriter.Key("maximumHeight");
  writeJson(obj.maximumHeight, jsonWriter, context);

  if (!obj.extensions.empty()) {
    jsonWriter.Key("extensions");
    writeJsonExtensions(obj, jsonWriter, context);
  }

  if (!obj.extras.empty()) {
    jsonWriter.Key("extras");
    writeJson(obj.extras, jsonWriter, context);
  }

  jsonWriter.EndObject();
}

void writeJson(
    const Cesium3DTiles::Tileset& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  jsonWriter.Key("asset");
  writeJson(obj.asset, jsonWriter, context);

  if (!obj.properties.empty()) {
    jsonWriter.Key("properties");
    writeJson(obj.properties, jsonWriter, context);
  }

  jsonWriter.Key("geometricError");
  writeJson(obj.geometricError, jsonWriter, context);

  jsonWriter.Key("root");
  writeJson(obj.root, jsonWriter, context);

  if (!obj.extensionsUsed.empty()) {
    jsonWriter.Key("extensionsUsed");
    writeJson(obj.extensionsUsed, jsonWriter, context);
  }

  if (!obj.extensionsRequired.empty()) {
    jsonWriter.Key("extensionsRequired");
    writeJson(obj.extensionsRequired, jsonWriter, context);
  }

  if (!obj.extensions.empty()) {
    jsonWriter.Key("extensions");
    writeJsonExtensions(obj, jsonWriter, context);
  }

  if (!obj.extras.empty()) {
    jsonWriter.Key("extras");
    writeJson(obj.extras, jsonWriter, context);
  }

  jsonWriter.EndObject();
}

void writeJson(
    const Cesium3DTiles::Tile& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  jsonWriter.Key("boundingVolume");
  writeJson(obj.boundingVolume, jsonWriter, context);

  if (obj.viewerRequestVolume.has_value()) {
    jsonWriter.Key("viewerRequestVolume");
    writeJson(obj.viewerRequestVolume, jsonWriter, context);
  }

  jsonWriter.Key("geometricError");
  writeJson(obj.geometricError, jsonWriter, context);

  if (obj.refine.has_value()) {
    jsonWriter.Key("refine");
    writeJson(obj.refine, jsonWriter, context);
  }

  static const std::vector<double> transformDefault =
      {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
  if (obj.transform != transformDefault) {
    jsonWriter.Key("transform");
    writeJson(obj.transform, jsonWriter, context);
  }

  if (obj.content.has_value()) {
    jsonWriter.Key("content");
    writeJson(obj.content, jsonWriter, context);
  }

  if (!obj.children.empty()) {
    jsonWriter.Key("children");
    writeJson(obj.children, jsonWriter, context);
  }

  if (!obj.extensions.empty()) {
    jsonWriter.Key("extensions");
    writeJsonExtensions(obj, jsonWriter, context);
  }

  if (!obj.extras.empty()) {
    jsonWriter.Key("extras");
    writeJson(obj.extras, jsonWriter, context);
  }

  jsonWriter.EndObject();
}

void writeJson(
    const Cesium3DTiles::Content& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  if (obj.boundingVolume.has_value()) {
    jsonWriter.Key("boundingVolume");
    writeJson(obj.boundingVolume, jsonWriter, context);
  }

  jsonWriter.Key("uri");
  writeJson(obj.uri, jsonWriter, context);

  if (!obj.extensions.empty()) {
    jsonWriter.Key("extensions");
    writeJsonExtensions(obj, jsonWriter, context);
  }

  if (!obj.extras.empty()) {
    jsonWriter.Key("extras");
    writeJson(obj.extras, jsonWriter, context);
  }

  jsonWriter.EndObject();
}

void writeJson(
    const Cesium3DTiles::BoundingVolume& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  if (!obj.box.empty()) {
    jsonWriter.Key("box");
    writeJson(obj.box, jsonWriter, context);
  }

  if (!obj.region.empty()) {
    jsonWriter.Key("region");
    writeJson(obj.region, jsonWriter, context);
  }

  if (!obj.sphere.empty()) {
    jsonWriter.Key("sphere");
    writeJson(obj.sphere, jsonWriter, context);
  }

  if (!obj.extensions.empty()) {
    jsonWriter.Key("extensions");
    writeJsonExtensions(obj, jsonWriter, context);
  }

  if (!obj.extras.empty()) {
    jsonWriter.Key("extras");
    writeJson(obj.extras, jsonWriter, context);
  }

  jsonWriter.EndObject();
}

void writeJson(
    const Cesium3DTiles::Properties& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  jsonWriter.Key("maximum");
  writeJson(obj.maximum, jsonWriter, context);

  jsonWriter.Key("minimum");
  writeJson(obj.minimum, jsonWriter, context);

  if (!obj.extensions.empty()) {
    jsonWriter.Key("extensions");
    writeJsonExtensions(obj, jsonWriter, context);
  }

  if (!obj.extras.empty()) {
    jsonWriter.Key("extras");
    writeJson(obj.extras, jsonWriter, context);
  }

  jsonWriter.EndObject();
}

void writeJson(
    const Cesium3DTiles::Asset& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  jsonWriter.Key("version");
  writeJson(obj.version, jsonWriter, context);

  if (obj.tilesetVersion.has_value()) {
    jsonWriter.Key("tilesetVersion");
    writeJson(obj.tilesetVersion, jsonWriter, context);
  }

  if (!obj.extensions.empty()) {
    jsonWriter.Key("extensions");
    writeJsonExtensions(obj, jsonWriter, context);
  }

  if (!obj.extras.empty()) {
    jsonWriter.Key("extras");
    writeJson(obj.extras, jsonWriter, context);
  }

  jsonWriter.EndObject();
}

} // namespace

void Extension3dTilesContentGltfJsonWriter::write(
    const Cesium3DTiles::Extension3dTilesContentGltf& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

void Extension3dTilesBoundingVolumeS2JsonWriter::write(
    const Cesium3DTiles::Extension3dTilesBoundingVolumeS2& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

void TilesetJsonWriter::write(
    const Cesium3DTiles::Tileset& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

void TileJsonWriter::write(
    const Cesium3DTiles::Tile& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

void ContentJsonWriter::write(
    const Cesium3DTiles::Content& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

void BoundingVolumeJsonWriter::write(
    const Cesium3DTiles::BoundingVolume& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

void PropertiesJsonWriter::write(
    const Cesium3DTiles::Properties& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

void AssetJsonWriter::write(
    const Cesium3DTiles::Asset& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

void registerExtensions(CesiumJsonWriter::ExtensionWriterContext& context) {
  (void)context;

  context.registerExtension<
      Cesium3DTiles::Tileset,
      Extension3dTilesContentGltfJsonWriter>();

  context.registerExtension<
      Cesium3DTiles::BoundingVolume,
      Extension3dTilesBoundingVolumeS2JsonWriter>();
}
} // namespace Cesium3DTilesWriter
