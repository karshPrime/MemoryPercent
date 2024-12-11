
add_executable(${PROJECT_NAME} main.c user_input.c calculations.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

