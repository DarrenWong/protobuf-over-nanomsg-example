set(THIRDPARTY_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/platform)

#protobuf
add_library(protobuf-x64 INTERFACE)
target_link_libraries(protobuf-x64 INTERFACE ${THIRDPARTY_LIBRARY}/protobuf/x64/lib/libprotobuf.a)
target_include_directories(protobuf-x64 INTERFACE ${THIRDPARTY_LIBRARY}/protobuf/x64/include)
set(Protobuf_PROTOC_LIBRARIES ${THIRDPARTY_LIBRARY}/protobuf/x64/bin/protoc)

# nanomsg
add_library(nanomsg_static INTERFACE)
target_include_directories(nanomsg_static
        INTERFACE ${THIRDPARTY_LIBRARY}/nanomsg/include)
target_link_libraries(
        nanomsg_static
        INTERFACE ${THIRDPARTY_LIBRARY}/nanomsg/lib/libnanomsg.a anl)