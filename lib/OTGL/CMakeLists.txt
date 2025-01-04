# lib/OTGL/CMakeLists.txt

set(SOURCES
  color.c
  video.c
)

message(STATUS "Building: ${OTGL_OUTPUT_TYPE}")

if(OTGL_OUTPUT_TYPE STREQUAL "static")
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BIN_OUT_DIR})

  # Static library
  add_library(OTGL STATIC ${SOURCES})

  # Static library properties
  set_target_properties(OTGL PROPERTIES
  OUTPUT_NAME ${PROJECT_NAME}_${PROJECT_VERSION}
  )

  target_compile_options(OTGL PRIVATE
    ${CMAKE_C_FLAGS}
    $<$<CONFIG:Debug>:${CMAKE_C_FLAGS_DEBUG}>
    $<$<CONFIG:Release>:${CMAKE_C_FLAGS_RELEASE}>
  )

elseif(OTGL_OUTPUT_TYPE STREQUAL "dynamic")
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BIN_OUT_DIR})

  # Dynamic library
  add_library(OTGL SHARED ${SOURCES})

  # Dynamic library properties
  set_target_properties(OTGL PROPERTIES
  OUTPUT_NAME ${PROJECT_NAME}_${PROJECT_VERSION}
  )

  target_compile_options(OTGL PRIVATE
    ${CMAKE_C_FLAGS}
    $<$<CONFIG:Debug>:${OTGL_FLAGS_DEBUG}>
    $<$<CONFIG:Release>:${OTGL_FLAGS_RELEASE}>
  )

endif()
