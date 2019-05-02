PROJECT(protobuf_over_nanomsg)
CMAKE_MINIMUM_REQUIRED (VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Debug)
#link_directories("/usr/local/lib")
ADD_SUBDIRECTORY(proto)

ADD_EXECUTABLE(protobuf_over_nanomsg main.cpp)
TARGET_LINK_LIBRARIES(protobuf_over_nanomsg proto)
