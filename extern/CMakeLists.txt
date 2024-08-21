set(DRLIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dr_libs)
add_library(DrLibs INTERFACE)

target_include_directories(DrLibs INTERFACE ${DRLIBS_DIR})