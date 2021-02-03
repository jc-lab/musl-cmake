if (NOT DEFINED MUSL_WITHOUT_CMAKE_PROJECT_HEAD OR NOT MUSL_WITHOUT_CMAKE_PROJECT_HEAD)
    cmake_minimum_required(VERSION 2.8)
    project(musl C)
endif()

set(MUSL_ARCH x86_64 CACHE STRING "musl platform architecture")
set(MUSL_NON_LINUX ON CACHE STRING "musl non-linux architecture")

set(MUSL_ENABLE_AIO OFF CACHE BOOL "musl aio features")
set(MUSL_ENABLE_CONF OFF CACHE BOOL "musl conf features")
set(MUSL_ENABLE_DIRENT OFF CACHE BOOL "musl dirent features")
set(MUSL_ENABLE_EXIT OFF CACHE BOOL "musl exit features")
set(MUSL_ENABLE_FCNTL OFF CACHE BOOL "musl fcntl features")
set(MUSL_ENABLE_FENV OFF CACHE BOOL "musl fenv features")
set(MUSL_ENABLE_LDSO OFF CACHE BOOL "musl ldso features")
set(MUSL_ENABLE_IPC OFF CACHE BOOL "musl ipc features")
set(MUSL_ENABLE_LINUX OFF CACHE BOOL "musl linux features")
set(MUSL_ENABLE_MALLOC OFF CACHE BOOL "musl malloc features")
set(MUSL_ENABLE_MISC OFF CACHE BOOL "musl misc features")
set(MUSL_ENABLE_MMAN OFF CACHE BOOL "musl mman features")
set(MUSL_ENABLE_MQ OFF CACHE BOOL "musl mq features")
set(MUSL_ENABLE_NETWORK OFF CACHE BOOL "musl network features")
set(MUSL_ENABLE_PASSWD OFF CACHE BOOL "musl passwd features")
set(MUSL_ENABLE_PROCESS OFF CACHE BOOL "musl process features")
set(MUSL_ENABLE_SCHED OFF CACHE BOOL "musl sched features")
set(MUSL_ENABLE_SIGNAL OFF CACHE BOOL "musl signal features")
set(MUSL_ENABLE_STAT OFF CACHE BOOL "musl stat features")
set(MUSL_ENABLE_TERMIOS OFF CACHE BOOL "musl thrmios features")
set(MUSL_ENABLE_THREAD OFF CACHE BOOL "musl thread features")
set(MUSL_ENABLE_UNISTD OFF CACHE BOOL "musl unistd features")

include(src_files.cmake)

set(FEATURES aio complex conf crypt ctype dirent env errno exit fcntl fenv internal ipc ldso legacy linux locale malloc math misc mman mq multibyte network passwd prng process regex sched search select setjmp signal stat stdio stdlib string temp termios thread time unistd)

set(MUSL_ENABLED_FEATURES)
set(SRC_FILES)
foreach(feat IN LISTS FEATURES)
    string(TOUPPER ${feat} feat_upper)
    set(enable_varname MUSL_ENABLE_${feat_upper})
    set(src_files_varname FEATURE_${feat}_SRC_FILES)
    if (DEFINED ${enable_varname})
        if (${enable_varname})
            list(APPEND MUSL_ENABLED_FEATURES ${feat})
            list(APPEND SRC_FILES ${${src_files_varname}})
        endif()
    else()
        list(APPEND MUSL_ENABLED_FEATURES ${feat})
        list(APPEND SRC_FILES ${${src_files_varname}})
    endif()
endforeach()

message("MUSL_ENABLED_FEATURES = ${MUSL_ENABLED_FEATURES}")
message("SRC_FILES = ${SRC_FILES}")

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/bits)
add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/include/bits/alltypes.h
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/include/bits
        COMMAND sed -f ${CMAKE_CURRENT_SOURCE_DIR}/tools/mkalltypes.sed
            ${CMAKE_CURRENT_SOURCE_DIR}/arch/${MUSL_ARCH}/bits/alltypes.h.in
            ${CMAKE_CURRENT_SOURCE_DIR}/include/alltypes.h.in > ${CMAKE_CURRENT_BINARY_DIR}/include/bits/alltypes.h
        DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/tools/mkalltypes.sed
        ${CMAKE_CURRENT_SOURCE_DIR}/arch/${MUSL_ARCH}/bits/alltypes.h.in
        ${CMAKE_CURRENT_SOURCE_DIR}/include/alltypes.h.in
)
list(APPEND SRC_FILES ${CMAKE_CURRENT_BINARY_DIR}/include/bits/alltypes.h)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/priv-include)
add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/priv-include/version.h
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tools/version.h.in
        COMMAND ${CMAKE_COMMAND}
        -DSCRIPT_FILE=${CMAKE_CURRENT_SOURCE_DIR}/tools/version.sh
        -DINPUT_FILE=${CMAKE_CURRENT_SOURCE_DIR}/tools/version.h.in
        -DOUTPUT_FILE=${CMAKE_CURRENT_BINARY_DIR}/priv-include/version.h
        -P ${CMAKE_CURRENT_SOURCE_DIR}/tools/update_version.cmake
)
list(APPEND SRC_FILES ${CMAKE_CURRENT_BINARY_DIR}/priv-include/version.h)

add_library(musl STATIC ${SRC_FILES})
target_compile_options(musl
        PRIVATE
        -std=c99
        -nostdinc
        -D_XOPEN_SOURCE=700
        -ffreestanding -fexcess-precision=standard -frounding-math -Wa,--noexecstack
        -Os -pipe -fomit-frame-pointer -fno-unwind-tables -fno-asynchronous-unwind-tables -ffunction-sections -fdata-sections -Wno-pointer-to-int-cast -Werror=implicit-function-declaration -Werror=implicit-int -Werror=pointer-sign -Werror=pointer-arith -Werror=int-conversion -Werror=incompatible-pointer-types -Werror=discarded-qualifiers -Werror=discarded-array-qualifiers -Waddress -Warray-bounds -Wchar-subscripts -Wduplicate-decl-specifier -Winit-self -Wreturn-type -Wsequence-point -Wstrict-aliasing -Wunused-function -Wunused-label -Wunused-variable
        -fno-stack-protector -DCRT
        )
target_link_options(musl
        PRIVATE
        -nostdlib
        )
#target_compile_definitions(musl
#        PUBLIC
#        _BSD_SOURCE
#        )
target_include_directories(musl
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/internal
        ${CMAKE_CURRENT_SOURCE_DIR}/src/include
        ${CMAKE_CURRENT_BINARY_DIR}/priv-include
        )

if (MUSL_NON_LINUX)
    target_include_directories(musl
            PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/noarch/include>
            )
endif()

target_include_directories(musl
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/arch/${MUSL_ARCH}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/arch/generic>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

add_subdirectory(test)
