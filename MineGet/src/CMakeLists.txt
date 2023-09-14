
find_package(CURL REQUIRED)

include_directories(${MineGet_SOURCE_DIR}/MineGet/include)
include_directories(${MineGet_SOURCE_DIR}/external)

add_executable(mineget
    mineget.cc
    parseCommands.cc
    callAPI.cc
)

include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(mineget ${CURL_LIBRARIES})
set_target_properties(mineget PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${MineGet_SOURCE_DIR}/build/bin)
