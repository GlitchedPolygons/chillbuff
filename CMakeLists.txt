#  Copyright 2019 Raphael Beck
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#  http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.

cmake_minimum_required(VERSION 3.1)
project(chillbuff C)

set(CMAKE_C_STANDARD 11)

option(CHILLBUFF_PLATFORM_MALLOC_ALT "Build the library with alternate `malloc` implementation." OFF)
option(CHILLBUFF_PLATFORM_CALLOC_ALT "Build the library with alternate `calloc` implementation." OFF)
option(CHILLBUFF_PLATFORM_REALLOC_ALT "Build the library with alternate `realloc` implementation." OFF)

if (CHILLBUFF_PLATFORM_MALLOC_ALT)
    add_compile_definitions("CHILLBUFF_PLATFORM_MALLOC_ALT=1")
else ()
    add_compile_definitions("CHILLBUFF_PLATFORM_MALLOC_ALT=0")
endif ()

if (CHILLBUFF_PLATFORM_CALLOC_ALT)
    add_compile_definitions("CHILLBUFF_PLATFORM_CALLOC_ALT=1")
else ()
    add_compile_definitions("CHILLBUFF_PLATFORM_CALLOC_ALT=0")
endif ()

if (CHILLBUFF_PLATFORM_REALLOC_ALT)
    add_compile_definitions("CHILLBUFF_PLATFORM_REALLOC_ALT=1")
else ()
    add_compile_definitions("CHILLBUFF_PLATFORM_REALLOC_ALT=0")
endif ()


add_library(chillbuff INTERFACE)
target_include_directories(chillbuff INTERFACE include)
