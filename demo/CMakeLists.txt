# demo/CMakeLists.txt

if(ENABLE_DEMOS)
  add_executable(hello_world_demo ${CMAKE_CURRENT_SOURCE_DIR}/hello_world.c)
  target_link_libraries(hello_world_demo OTGL)

  set_target_properties(hello_world_demo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_OUT_DIR}
  )

  if(DEV)
    target_compile_options(hello_world_demo PRIVATE ${CMAKE_C_FLAGS} -Wall -Wextra -g)
  endif()
endif()
