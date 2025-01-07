# test/CMakeLists.txt

if(ENABLE_TESTS)
  enable_testing()

  set(TEST_SOURCES
    video_test
  )

  foreach(test IN LISTS TEST_SOURCES)
    add_executable(${test} ${CMAKE_CURRENT_SOURCE_DIR}/${test}.c)
    target_link_libraries(${test} OTGL)

    target_compile_options(${test} PRIVATE
      ${CMAKE_C_FLAGS}
    )

    add_test(
      NAME ${test}
      COMMAND ${test}
    )
  endforeach()
endif()
