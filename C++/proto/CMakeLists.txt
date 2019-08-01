FILE(GLOB proto_files ${CMAKE_CURRENT_SOURCE_DIR}/*.proto)

FOREACH(proto_file ${proto_files})
    #retrive proto filename only
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" proto_file_name ${proto_file})

    LIST(APPEND PROTOSRCS "${CMAKE_CURRENT_BINARY_DIR}/${proto_file_name}.pb.cc")
    LIST(APPEND PROTOHDRS "${CMAKE_CURRENT_BINARY_DIR}/${proto_file_name}.pb.h")
    ADD_CUSTOM_COMMAND(
            OUTPUT "${proto_file_name}.pb.h" "${proto_file_name}.pb.cc"
            COMMAND ${Protobuf_PROTOC_EXECUTABLE} --proto_path=${CMAKE_CURRENT_SOURCE_DIR}
            --cpp_out=${CMAKE_CURRENT_BINARY_DIR}/  ${proto_file_name}.proto
    )
ENDFOREACH(proto_file)

add_library(proto STATIC ${PROTOSRCS} ${PROTOHDRS})
target_link_libraries(proto PUBLIC protobuf-x64)
target_include_directories(proto PUBLIC  ${CMAKE_CURRENT_BINARY_DIR})