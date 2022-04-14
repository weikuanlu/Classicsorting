project(Sort)
aux_source_directory(src SRC_SUR)
aux_source_directory(. SRC_CUR)
add_executable(main ${SRC_SUR} ${SRC_CUR})
