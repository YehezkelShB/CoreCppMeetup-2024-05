cmake_minimum_required(VERSION 3.26)

project(Printing)

if (ENABLED_ASAN)
	add_compile_options(-fsanitize=address)
	if(NOT MSVC)
		add_link_options(-fsanitize=address)
	endif()
endif()

include(cmake/CompilerSettings.cmake)

add_executable(${PROJECT_NAME})

add_subdirectory(include)
add_subdirectory(src)
