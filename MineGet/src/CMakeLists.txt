include_directories(${MineGet_SOURCE_DIR}/MineGet/include)
add_executable(mineget mineget.cc)
set_target_properties(mineget PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${MineGet_SOURCE_DIR}/build/bin)