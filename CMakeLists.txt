project(testRttiQt)

add_executable(testRttiQt
	src/main.cpp
)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

target_link_libraries(testRttiQt
	Qt5::Widgets
)