cmake_minimum_required(VERSION 3.2)
project(oat2dex)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -fpermissive")
set(CMAKE_NDK_ROOT D:/sdk/android-ndk-r10d)

include_directories(${CMAKE_NDK_ROOT}/platforms/android-9/arch-arm/usr/include
                    ${CMAKE_NDK_ROOT}/platforms/android-9/arch-arm/usr/include/EGL
                    ${CMAKE_NDK_ROOT}/sources/cxx-stl/stlport/stlport
                    )
set(SOURCE_FILES
    elf/elfloader.cpp
    oat/DexHeader.cpp
    oat/OATHeader.cpp
    oat/OATParser.cpp
    StringPiece.cpp
    main.cpp
)
add_executable(oat2dex ${SOURCE_FILES})