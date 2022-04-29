cmake_minimum_required(VERSION 2.8.12)
project(EventHelper)

add_definitions(-std=c++11)

find_package(OpenCV 3.3 REQUIRED)


set(CeleX_LIB CeleX)
set(CeleX_CeleDriver_LIB CeleDriver)
set(CeleXStereo_LIB CeleXStereo)

include_directories(./include/CeleX/celex5)
include_directories(./include/Celex)
include_directories(./include)
include_directories(${OpenCV_INCLUDE_DIRS})
message(${OpenCV_INCLUDE_DIRS})

link_directories(./lib)

# LINK_LIBRARIES(libCeleX.so)

# #specify the executable directory 
# set_target_properties(EventHelper PROPERTIES OUTPUT_NAME ./build/EventHelper)

#=================bin2txt
add_executable(BinHelper ./src/bin2txt.cpp)

target_link_libraries(BinHelper ${CeleX_LIB} ${OpenCV_LIBS})


#=================RecordEventData
add_executable(EventHelper ./src/main.cpp ./src/RecordEventData.cpp ./src/fileHelper.cpp)

target_link_libraries(EventHelper ${CeleX_LIB} ${OpenCV_LIBS})


# #=================RecordEventData-Stereo             支持双事件相机的CeleX5库还未修改成功
# add_executable(StereoHelper ./src/main-Stereo.cpp ./src/RecordEventData-Stereo.cpp ./src/fileHelper.cpp)

# target_link_libraries(StereoHelper ${OpenCV_LIBS})
# target_link_libraries(StereoHelper ${CeleXStereo_LIB})
# target_link_libraries(StereoHelper ${CeleX_CeleDriver_LIB})


#=================main-Master
add_executable(Master ./src/main-Master.cpp ./src/SocketHelper.cpp ./src/RecordEventData.cpp ./src/fileHelper.cpp)
target_link_libraries(Master ${CeleX_LIB} ${OpenCV_LIBS})


#=================main-Slave
add_executable(Slave ./src/main-Slave.cpp ./src/SocketHelper.cpp ./src/RecordEventData.cpp ./src/fileHelper.cpp)
target_link_libraries(Slave ${CeleX_LIB} ${OpenCV_LIBS})


#=================test
add_executable(testSlave ./src/test-Slave.cpp ./src/RecordEventData.cpp ./src/fileHelper.cpp ./src/SocketHelper.cpp)
target_link_libraries(testSlave ${CeleX_LIB} ${OpenCV_LIBS})

add_executable(testMaster ./src/test-Master.cpp ./src/RecordEventData.cpp ./src/fileHelper.cpp ./src/SocketHelper.cpp)
target_link_libraries(testMaster ${CeleX_LIB} ${OpenCV_LIBS})