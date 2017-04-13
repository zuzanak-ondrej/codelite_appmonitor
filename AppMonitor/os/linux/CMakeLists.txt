# Include paths
include_directories("${CL_SRC_ROOT}/${PLUGIN_NAME}")

FILE(GLOB SIGAR_OS_SOURCES "*.cpp" "*.c")

#add_library(SIGAR_OS_SOURCES STATIC ${SIGAR_OS_SOURCES})
