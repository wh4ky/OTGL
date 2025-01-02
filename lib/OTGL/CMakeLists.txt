# lib/OTGL/CMakeLists.txt

message(STATUS "Building: ${OTGL_OUTPUT_TYPE}")

if(OTGL_OUTPUT_TYPE STREQUAL "static")
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BIN_OUT_DIR})

  # Static library
  add_library(OTGL STATIC
  color.c
  video.c
  )

  # Static library properties
  set_target_properties(OTGL PROPERTIES
  OUTPUT_NAME ${PROJECT_NAME}_${PROJECT_VERSION}
  )
  if(DEV)
    target_compile_options(OTGL PRIVATE ${CMAKE_C_FLAGS} -Wall -Wextra -g)
  endif()

elseif(TE_OUTPUT_TYPE STREQUAL "dynamic")
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BIN_OUT_DIR})

  # Dynamic library
  add_library(OTGL SHARED
  color.c
  video.c
  )

  # Dynamic library properties
  set_target_properties(OTGL PROPERTIES
  OUTPUT_NAME ${PROJECT_NAME}_${PROJECT_VERSION}
  )
  if(DEV)
    target_compile_options(OTGL PRIVATE ${CMAKE_C_FLAGS} -Wall -Wextra -g)
  endif()
endif()
