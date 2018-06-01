project(gdalproj5)
cmake_minimum_required(VERSION 3.0)

if(WIN32)
  # we have to use custom FindGDAL on windows
  list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake/Modules.win32)
endif()

message(STATUS ${CMAKE_MODULE_PATH})

find_package(GDAL REQUIRED)

add_executable(gdalproj5 main.cpp)
target_link_libraries(gdalproj5 ${GDAL_LIBRARIES})
target_include_directories(gdalproj5 PUBLIC ${GDAL_INCLUDE_DIR})
