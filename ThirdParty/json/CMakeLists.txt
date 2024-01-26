add_library(nlohmann_json INTERFACE)
if (${CMAKE_VERSION} VERSION_LESS "3.8.0")
    target_compile_features(nlohmann_json INTERFACE cxx_range_for)
else()
    target_compile_features(nlohmann_json INTERFACE cxx_std_11)
endif()
option(JSON_ImplicitConversions "Enable implicit conversions." ON)
option(JSON_Diagnostics         "Use extended diagnostic messages." OFF)

target_compile_definitions(
    nlohmann_json
    INTERFACE
    JSON_USE_IMPLICIT_CONVERSIONS=$<BOOL:${JSON_ImplicitConversions}>
    JSON_DIAGNOSTICS=$<BOOL:${JSON_Diagnostics}>
)

target_include_directories(
    nlohmann_json
     INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/single_include/>
    $<INSTALL_INTERFACE:include>
)