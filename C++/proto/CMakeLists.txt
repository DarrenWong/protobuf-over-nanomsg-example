# specifying installation prefixes to be searched by the find_package(),
# find_program(), find_library(), find_file(), and find_path() commands.
# prefer use protobuf 3.7.1 as example and we install separately with ubuntu 16.04 default 2.6.1 version
set(CMAKE_PREFIX_PATH "/usr/local/protobuf"
        "${CMAKE_PREFIX_PATH}")
FIND_PACKAGE(Protobuf REQUIRED)
FILE(GLOB protofiles "${CMAKE_CURRENT_SOURCE_DIR}/*.proto")
PROTOBUF_GENERATE_CPP(PROTOSRCS PROTOHDRS ${protofiles})
add_library(proto STATIC ${PROTOSRCS} ${PROTOHDRS})
target_link_libraries(proto protobuf ${PROTOBUF_LIBRARIES})
target_include_directories(proto PUBLIC ${PROTOBUF_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})