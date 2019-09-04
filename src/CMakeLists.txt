find_package(Qt5 COMPONENTS Core REQUIRED)

add_library(wincamp_headers INTERFACE)
target_include_directories(wincamp_headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})

add_library(wincamp STATIC
hello.h
task.h
worker.h

hello.cpp
task.cpp
worker.cpp
)

target_link_libraries(wincamp
	Qt5::Core
	${Boost_LIBRARIES}
)


add_subdirectory(gui)
