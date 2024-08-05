cmake_minimum_required(VERSION 3.10)

project(QemuWrapper)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static -O3 -s")

file(GLOB_RECURSE SOURCES "qemu-*.c")

foreach(SOURCE ${SOURCES})
    get_filename_component(EXE ${SOURCE} NAME_WE)
    add_executable(${EXE} ${SOURCE})
    install(TARGETS ${EXE} DESTINATION bin)
endforeach()
