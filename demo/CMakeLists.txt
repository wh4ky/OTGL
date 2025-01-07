# demo/CMakeLists.txt

if(ENABLE_DEMOS)
  set(CMAKE_C_STANDARD 11)
  set(CMAKE_C_STANDARD_REQUIRED true)
  set(CMAKE_C_EXTENSIONS OFF) 

  set(DEMO_SOURCES
    hello_world
    epilepsy
  )

  foreach(demo IN LISTS DEMO_SOURCES)
    add_executable(${demo} ${CMAKE_CURRENT_SOURCE_DIR}/${demo}.c)
    target_link_libraries(${demo} OTGL)

    set_target_properties(${demo} PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY ${BIN_OUT_DIR}
    )

    target_compile_options(${demo} PRIVATE
      ${CMAKE_C_FLAGS}
    )
  endforeach()
endif()
