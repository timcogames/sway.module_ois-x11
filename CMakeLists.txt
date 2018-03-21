# Проверяем версию CMake
cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

# Устанавливаем имя проекта
set(MODULE_OIS_PROJECT_NAME module_ois)
project(${MODULE_OIS_PROJECT_NAME})

# Устанавливаем версию библиотеки
set(MODULE_OIS_VERSION_MAJOR 0)
set(MODULE_OIS_VERSION_MINOR 1)
set(MODULE_OIS_VERSION_PATCH 0)
set(MODULE_OIS_VERSION_STRING ${MODULE_OIS_VERSION_MAJOR}.${MODULE_OIS_VERSION_MINOR}.${MODULE_OIS_VERSION_PATCH})

# Определяем каталог вывода по умолчанию
if(CMAKE_BUILD_TYPE MATCHES Debug)
	set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/dbg)
	set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/dbg)
else()
	set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
	set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
endif()

set(MODULE_OIS_DIR ${CMAKE_CURRENT_LIST_DIR})

include_directories(${MODULE_OIS_DIR}/include)
include_directories(${MODULE_OIS_DIR}/modules/sway.module_core/include)
include_directories(${MODULE_OIS_DIR}/modules/sway.module_math/include)

file(GLOB_RECURSE MODULE_OIS_HEADERS ${MODULE_OIS_DIR}/include/*.*)
file(GLOB_RECURSE MODULE_OIS_SOURCE ${MODULE_OIS_DIR}/src/*.*)

find_package(X11 REQUIRED)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.58.0 COMPONENTS system filesystem thread)
if (Boost_FOUND)
endif()

add_library(${MODULE_OIS_PROJECT_NAME} SHARED ${MODULE_OIS_SOURCE})

target_link_libraries(${MODULE_OIS_PROJECT_NAME} X11 Boost::system Boost::filesystem Boost::thread)

set_target_properties(${MODULE_OIS_PROJECT_NAME} PROPERTIES SUFFIX ".so.${MODULE_OIS_VERSION_STRING}")
set_target_properties(${MODULE_OIS_PROJECT_NAME} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)