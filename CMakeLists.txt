cmake_minimum_required(VERSION 3.26)
project(image_processing)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_OSX_ARCHITECTURES arm64)
set(CMAKE_PREFIX_PATH "/Users/jaechoi/Qt/6.5.2/macos/lib/cmake")
set(OIIO_PATH "/opt/homebrew/Cellar/openimageio/2.4.13.0/")
set(PROJECT_SOURCES main.cpp)

find_package(Openimageio REQUIRED )
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(image_processing main.cpp
        src/Image.cpp
        headers/Image.h
        src/ImageProcess.cpp
        headers/ImageProcess.h
        src/Viewer2d.cpp
        headers/Viewer2d.h
        src/Viewer3d.cpp
        headers/Viewer3d.h)

include_directories(${OIIO_PATH}/include/)

target_link_libraries(image_processing ${OIIO_PATH}lib/libOpenImageIO.dylib)
target_link_libraries(image_processing Qt${QT_VERSION_MAJOR}::Widgets)