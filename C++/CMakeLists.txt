PROJECT(protobuf_over_nanomsg)
CMAKE_MINIMUM_REQUIRED (VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(3rd_party)

ADD_SUBDIRECTORY(proto)

ADD_EXECUTABLE(protobuf_over_nanomsg main.cpp)
TARGET_LINK_LIBRARIES(protobuf_over_nanomsg proto nanomsg)
