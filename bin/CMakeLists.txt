add_executable(bin main.cpp)

target_link_libraries(bin PRIVATE lib)
target_include_directories(bin PUBLIC ${PROJECT_SOURCE_DIR})