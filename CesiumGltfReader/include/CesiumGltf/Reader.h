#pragma once

#include "CesiumGltf/IExtensionJsonReader.h"
#include "CesiumGltf/Model.h"
#include "CesiumGltf/ReadModelOptions.h"
#include "CesiumGltf/ReaderLibrary.h"
#include <cstddef>
#include <functional>
#include <gsl/span>
#include <optional>
#include <string>
#include <vector>

namespace CesiumGltf {

struct JsonReaderContext;

/**
 * @brief The result of reading a glTF model with {@link readModel}.
 */
struct CESIUMGLTFREADER_API ModelReaderResult {
  /**
   * @brief The read model, or std::nullopt if the model could not be read.
   */
  std::optional<Model> model;

  /**
   * @brief Errors, if any, that occurred during the load process.
   */
  std::vector<std::string> errors;

  /**
   * @brief Warnings, if any, that occurred during the load process.
   */
  std::vector<std::string> warnings;
};

/**
 * @brief The result of reading an image with {@link readImage}.
 */
struct CESIUMGLTFREADER_API ImageReaderResult {

  /**
   * @brief The {@link ImageCesium} that was read.
   *
   * This will be `std::nullopt` if the image could not be read.
   */
  std::optional<ImageCesium> image;

  /**
   * @brief Error messages that occurred while trying to read the image.
   */
  std::vector<std::string> errors;

  /**
   * @brief Warning messages that occurred while reading the image.
   */
  std::vector<std::string> warnings;
};

/**
 * @brief The state of a glTF extension.
 */
enum class ExtensionState {
  /**
   * @brief The extension is enabled.
   *
   * If a statically-typed class is available for the extension, it will be
   * used. Otherwise the extension will be represented as a {@link JsonValue}.
   */
  Enabled,

  /**
   * @brief The extension is enabled but will always be deserialized as a {@link
   * JsonValue}.
   *
   * Even if a statically-typed class is available for the extension, it will
   * not be used.
   */
  JsonOnly,

  /**
   * @brief The extension is disabled.
   *
   * It will not be represented in the loaded model at all.
   */
  Disabled
};

class CESIUMGLTFREADER_API Reader {
public:
  /**
   * @brief Registers an extension for a glTF object.
   *
   * @tparam TExtended The glTF object to extend.
   * @tparam TExtensionHandler The extension's {@link JsonHandler}.
   * @param extensionName The name of the extension.
   */
  template <typename TExtended, typename TExtensionHandler>
  void registerExtension(const std::string& extensionName) {
    auto it =
        this->_extensions.emplace(extensionName, TObjectTypeToReader()).first;
    it->insert_or_assign(
        TExtended::TypeName,
        [](const JsonReaderContext& context) {
          return TExtensionHandler(context);
        });
  }

  /**
   * @brief Registers an extension for a glTF object.
   *
   * The extension name is obtained from `TExtensionHandler::ExtensionName`.
   *
   * @tparam TExtended The glTF object to extend.
   * @tparam TExtensionHandler The extension's {@link JsonHandler}.
   */
  template <typename TExtended, typename TExtensionHandler>
  void registerExtension() {
    auto it =
        this->_extensions
            .emplace(TExtensionHandler::ExtensionName, TObjectTypeToReader())
            .first;
    it->insert_or_assign(
        TExtended::TypeName,
        [](const JsonReaderContext& context) {
          return TExtensionHandler(context);
        });
  }

  /**
   * @brief Enables or disables a glTF extension.
   *
   * @param extensionName The name of the extension to be enabled or disabled.
   * @param newState The new state for the extension.
   */
  void
  setExtensionState(const std::string& extensionName, ExtensionState newState);

  /**
   * @brief Reads a glTF or binary glTF (GLB) from a buffer.
   *
   * @param data The buffer from which to read the glTF.
   * @param options Options for how to read the glTF.
   * @return The result of reading the glTF.
   */
  ModelReaderResult readModel(
      const gsl::span<const std::byte>& data,
      const ReadModelOptions& options = ReadModelOptions()) const;

  /**
   * @brief Reads an image from a buffer.
   *
   * The [stb_image](https://github.com/nothings/stb) library is used to decode
   * images in `JPG`, `PNG`, `TGA`, `BMP`, `PSD`, `GIF`, `HDR`, or `PIC` format.
   *
   * @param data The buffer from which to read the image.
   * @return The result of reading the image.
   */
  ImageReaderResult readImage(const gsl::span<const std::byte>& data) const;

  std::unique_ptr<IExtensionJsonReader> createExtensionReader(
      const JsonReaderContext& context,
      const std::string_view& extensionName,
      const std::string& extendedObjectType) const;

private:
  using ExtensionReaderFactory =
      std::function<std::unique_ptr<IExtensionJsonReader>(
          const JsonReaderContext&)>;
  using ObjectTypeToReader = std::map<std::string, ExtensionReaderFactory>;
  using ExtensionNameMap = std::map<std::string, ObjectTypeToReader>;

  ExtensionNameMap _extensions;
  std::unordered_map<std::string, ExtensionState> _extensionStates;
};

} // namespace CesiumGltf
