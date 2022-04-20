cmake_minimum_required(VERSION 2.8.12)
project(EventHelper)

add_definitions(-std=c++11)

find_package(OpenCV 3.3 REQUIRED)


set(CeleX_LIB CeleX)
set(CeleX_CeleDriver_LIB CeleDriver)
set(CeleXStereo_LIB CeleXStereo)

include_directories(./include/CeleX/celex5)
include_directories(./include/celex5)
include_directories(./include)
include_directories(${OpenCV_INCLUDE_DIRS})
message(${OpenCV_INCLUDE_DIRS})

link_directories(./lib)

# LINK_LIBRARIES(libCeleX.so)

# #specify the executable directory 
# set_target_properties(EventHelper PROPERTIES OUTPUT_NAME ./build/EventHelper)


#=================RecordEventData
add_executable(EventHelper ./src/main.cpp ./src/RecordEventData.cpp ./src/fileHelper.cpp)

target_link_libraries(EventHelper ${CeleX_LIB} ${OpenCV_LIBS})


#=================RecordEventData-Stereo
add_executable(StereoHelper ./src/main-Stereo.cpp ./src/RecordEventData-Stereo.cpp ./src/fileHelper.cpp)

target_link_libraries(StereoHelper ${OpenCV_LIBS})
target_link_libraries(StereoHelper ${CeleXStereo_LIB})
target_link_libraries(StereoHelper ${CeleX_CeleDriver_LIB})