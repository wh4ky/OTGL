# test/CMakeLists.txt

if(ENABLE_TESTS)
  enable_testing()

  add_executable(video_test ${CMAKE_CURRENT_SOURCE_DIR}/video_test.c)
  target_link_libraries(video_test OTGL)

  if(DEV)
    target_compile_options(video_test PRIVATE ${CMAKE_C_FLAGS} -Wall -Wextra -g)
  endif()

  add_test(NAME video COMMAND video_test)
endif()
