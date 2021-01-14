cmake_minimum_required(VERSION 3.0.0)
project(MyProject VERSION 0.1.0)

include(CTest)
enable_testing()

option(USE_INCLUDE "Use tutorial header library" ON)

# configure a header file to pass some of the CMake settings
# to the source code

if(USE_INCLUDE)
  add_subdirectory(INCLUDE)
  list(APPEND EXTRA_LIBS INCLUDE)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/INCLUDE")
endif()

add_executable(MyProject 
    INCLUDE/Myinclude.h
    INCLUDE/Mysecond.h

    SOURCES/Mysource.cpp
    SOURCES/Source.cpp

)

link_directories(/lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(MyProject PUBLIC sfml-audio sfml-graphics sfml-window sfml-system boost_system boost_thread boost_timer pthread X11
    ${EXTRA_LIBS}
)
target_include_directories(MyProject PUBLIC
                        "${PROJECT_BINARY_DIR}"
                        ${EXTRA_INCLUDES}
)



install(TARGETS MyProject DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/Myinclude.h"
  DESTINATION include
  )

install(FILES "${PROJECT_BINARY_DIR}/Mysecond.h"
  DESTINATION include
  )


