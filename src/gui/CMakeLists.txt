set(CMAKE_AUTORCC True)
set(CMAKE_AUTOUIC True)

add_executable(WinCAMP
mainwindow.h

mainwindow.cpp
main.cpp

mainwindow.ui
)

target_include_directories(WinCAMP
	PRIVATE
		..
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
target_link_libraries(WinCAMP
	Qt5::Widgets
	
    wincamp
)
