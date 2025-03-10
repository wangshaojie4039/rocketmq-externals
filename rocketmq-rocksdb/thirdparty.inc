# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.
# The ASF licenses this file to You under the Apache License, Version 2.0
# (the "License"); you may not use this file except in compliance with
# the License.  You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


# Edit definitions below to specify paths to include files and libraries of all 3rd party libraries

# TODO: Make this work with find_package and/or get rid of it
#
# This example assumes all the libraries locate in directories under THIRDPARTY_HOME environment variable
# Set environment variable THIRDPARTY_HOME to point to your third party libraries home (Unix style dir separators)
# or change the paths below to reflect where the libraries actually reside
#
set (THIRDPARTY_LIBS "")         # Initialization, don't touch

#
# Defaults
#
set(GFLAGS_HOME $ENV{THIRDPARTY_HOME}/gflags-2.2.0)
set(GFLAGS_INCLUDE ${GFLAGS_HOME}/target/include)
set(GFLAGS_LIB_DEBUG ${GFLAGS_HOME}/target/lib/Debug/gflags_static.lib)
set(GFLAGS_LIB_RELEASE ${GFLAGS_HOME}/target/lib/Release/gflags_static.lib)

# ================================================== GFLAGS ==================================================
# For compatibility
if (GFLAGS)
  set(WITH_GFLAGS ON)
endif ()

if (WITH_GFLAGS)
  message(STATUS "GFLAGS library is enabled")
  
  if(DEFINED ENV{GFLAGS_INCLUDE})
    set(GFLAGS_INCLUDE $ENV{GFLAGS_INCLUDE})
  endif()
  
  if(DEFINED ENV{GFLAGS_LIB_DEBUG})
    set(GFLAGS_LIB_DEBUG $ENV{GFLAGS_LIB_DEBUG})
  endif()

  if(DEFINED ENV{GFLAGS_LIB_RELEASE})
    set(GFLAGS_LIB_RELEASE $ENV{GFLAGS_LIB_RELEASE})
  endif()
  
  set(GFLAGS_CXX_FLAGS -DGFLAGS=gflags)
  set(GFLAGS_LIBS debug ${GFLAGS_LIB_DEBUG} optimized ${GFLAGS_LIB_RELEASE})

  add_definitions(${GFLAGS_CXX_FLAGS})
  include_directories(${GFLAGS_INCLUDE})
  set (THIRDPARTY_LIBS ${THIRDPARTY_LIBS} ${GFLAGS_LIBS})
else ()
  message(STATUS "GFLAGS library is disabled")
endif ()

# ================================================== SNAPPY ==================================================
#
# Edit these 4 lines to define paths to Snappy
#
set(SNAPPY_HOME $ENV{THIRDPARTY_HOME}/snappy-1.1.9)
set(SNAPPY_INCLUDE ${SNAPPY_HOME} ${SNAPPY_HOME}/build)
set(SNAPPY_LIB_DEBUG ${SNAPPY_HOME}/build/Debug/snappy.lib)
set(SNAPPY_LIB_RELEASE ${SNAPPY_HOME}/build/Release/snappy.lib)

# For compatibility
if(SNAPPY)
  set(WITH_SNAPPY ON)
endif ()

if (WITH_SNAPPY)
  message(STATUS "SNAPPY library is enabled")

  if(DEFINED ENV{SNAPPY_INCLUDE})
    set(SNAPPY_INCLUDE $ENV{SNAPPY_INCLUDE})
  endif()

  if(DEFINED ENV{SNAPPY_LIB_DEBUG})
    set(SNAPPY_LIB_DEBUG $ENV{SNAPPY_LIB_DEBUG})
  endif()

  if(DEFINED ENV{SNAPPY_LIB_RELEASE})
    set(SNAPPY_LIB_RELEASE $ENV{SNAPPY_LIB_RELEASE})
  endif()

  set(SNAPPY_CXX_FLAGS -DSNAPPY)
  set(SNAPPY_LIBS debug ${SNAPPY_LIB_DEBUG} optimized ${SNAPPY_LIB_RELEASE})

  add_definitions(${SNAPPY_CXX_FLAGS})
  include_directories(${SNAPPY_INCLUDE})
  set (THIRDPARTY_LIBS ${THIRDPARTY_LIBS} ${SNAPPY_LIBS})
else ()
  message(STATUS "SNAPPY library is disabled")
endif ()

# ================================================== LZ4 ==================================================
#
# Edit these 4 lines to define paths to LZ4
#
set(LZ4_HOME $ENV{THIRDPARTY_HOME}/lz4-1.9.4)
set(LZ4_INCLUDE ${LZ4_HOME}/lib)
set(LZ4_LIB_DEBUG ${LZ4_HOME}/build/VS2022/bin/x64_Debug/liblz4_static.lib)
set(LZ4_LIB_RELEASE ${LZ4_HOME}/build/VS2022/bin/x64_Release/liblz4_static.lib)

# For compatibility
if (LZ4)
  set(WITH_LZ4 ON)
endif ()

if (WITH_LZ4)
  message(STATUS "LZ4 library is enabled")
  
  if(DEFINED ENV{LZ4_INCLUDE})
    set(LZ4_INCLUDE $ENV{LZ4_INCLUDE})
  endif()
  
  if(DEFINED ENV{LZ4_LIB_DEBUG})
    set(LZ4_LIB_DEBUG $ENV{LZ4_LIB_DEBUG})
  endif()

  if(DEFINED ENV{LZ4_LIB_RELEASE})
    set(LZ4_LIB_RELEASE $ENV{LZ4_LIB_RELEASE})
  endif()
  
  set(LZ4_CXX_FLAGS -DLZ4)
  set(LZ4_LIBS debug ${LZ4_LIB_DEBUG} optimized ${LZ4_LIB_RELEASE})

  add_definitions(${LZ4_CXX_FLAGS})
  include_directories(${LZ4_INCLUDE})
  set (THIRDPARTY_LIBS ${THIRDPARTY_LIBS} ${LZ4_LIBS})
else ()
  message(STATUS "LZ4 library is disabled")
endif ()

# ================================================== ZLIB ==================================================
#
# Edit these 4 lines to define paths to ZLIB
#
set(ZLIB_HOME $ENV{THIRDPARTY_HOME}/zlib-1.2.13)
set(ZLIB_INCLUDE ${ZLIB_HOME})
set(ZLIB_LIB_DEBUG ${ZLIB_HOME}/contrib/vstudio/vc14/x64/ZlibStatDebug/zlibstat.lib)
set(ZLIB_LIB_RELEASE ${ZLIB_HOME}/contrib/vstudio/vc14/x64/ZlibStatRelease/zlibstat.lib)

# For compatibilty
if (ZLIB)
  set(WITH_ZLIB ON)
endif ()

if (WITH_ZLIB)
  message(STATUS "ZLIB library is enabled")

  if(DEFINED ENV{ZLIB_INCLUDE})
    set(ZLIB_INCLUDE $ENV{ZLIB_INCLUDE})
  endif()
  
  if(DEFINED ENV{ZLIB_LIB_DEBUG})
    set(ZLIB_LIB_DEBUG $ENV{ZLIB_LIB_DEBUG})
  endif()

  if(DEFINED ENV{ZLIB_LIB_RELEASE})
    set(ZLIB_LIB_RELEASE $ENV{ZLIB_LIB_RELEASE})
  endif()
  
  set(ZLIB_CXX_FLAGS -DZLIB)
  set(ZLIB_LIBS debug ${ZLIB_LIB_DEBUG} optimized ${ZLIB_LIB_RELEASE})

  add_definitions(${ZLIB_CXX_FLAGS})
  include_directories(${ZLIB_INCLUDE})
  set (THIRDPARTY_LIBS ${THIRDPARTY_LIBS} ${ZLIB_LIBS})
else ()
  message(STATUS "ZLIB library is disabled")
endif ()

# ================================================== XPRESS ==================================================
# This makes use of built-in Windows API, no additional includes, links to a system lib

# For compatibilty
if (XPRESS)
  set(WITH_XPRESS ON)
endif ()

if (WITH_XPRESS)
  message(STATUS "XPRESS is enabled")

  add_definitions(-DXPRESS)
  
  # We are using the implementation provided by the system
  set (SYSTEM_LIBS ${SYSTEM_LIBS} Cabinet.lib)
else ()
  message(STATUS "XPRESS is disabled")
endif ()


# ================================================== ZSTD ==================================================
#
# Edit these 4 lines to define paths to ZSTD
#
set(ZSTD_HOME $ENV{THIRDPARTY_HOME}/zstd-1.5.2)
set(ZSTD_INCLUDE ${ZSTD_HOME}/lib ${ZSTD_HOME}/lib/dictBuilder)
set(ZSTD_LIB_DEBUG ${ZSTD_HOME}/build/VS2010/bin/x64_Debug/libzstd_static.lib)
set(ZSTD_LIB_RELEASE ${ZSTD_HOME}/build/VS2010/bin/x64_Release/libzstd_static.lib)

# For compatibility
if (ZSTD)
  set(WITH_ZSTD ON)
endif ()

if (WITH_ZSTD)
  message(STATUS "ZSTD library is enabled")

  if(DEFINED ENV{ZSTD_INCLUDE})
    set(ZSTD_INCLUDE $ENV{ZSTD_INCLUDE})
  endif()
  
  if(DEFINED ENV{ZSTD_LIB_DEBUG})
    set(ZSTD_LIB_DEBUG $ENV{ZSTD_LIB_DEBUG})
  endif()

  if(DEFINED ENV{ZSTD_LIB_RELEASE})
    set(ZSTD_LIB_RELEASE $ENV{ZSTD_LIB_RELEASE})
  endif()

  # ZSTD_STATIC_LINKING_ONLY only allows us to create an allocation functions override
  # When jemalloc is in use
  set(ZSTD_LIBS debug ${ZSTD_LIB_DEBUG} optimized ${ZSTD_LIB_RELEASE})

  add_definitions(-DZSTD -DZSTD_STATIC_LINKING_ONLY)
  include_directories(${ZSTD_INCLUDE})
  set (THIRDPARTY_LIBS ${THIRDPARTY_LIBS} ${ZSTD_LIBS})
else ()
  message(STATUS "ZSTD library is disabled")
endif ()

#
# Edit these 4 lines to define paths to Jemalloc
#
set(JEMALLOC_HOME $ENV{THIRDPARTY_HOME}/Jemalloc.Library)
set(JEMALLOC_INCLUDE ${JEMALLOC_HOME}/build/native/inc)
set(JEMALLOC_LIB_DEBUG ${JEMALLOC_HOME}/lib/native/debug/amd64/jemalloc.lib)
set(JEMALLOC_LIB_RELEASE ${JEMALLOC_HOME}/lib/native/retail/amd64/jemalloc.lib)

# ================================================== JEMALLOC ==================================================
if(JEMALLOC)
  set(WITH_JEMALLOC ON)
endif()

if (WITH_JEMALLOC)
  message(STATUS "JEMALLOC library is enabled")
  set(JEMALLOC_CXX_FLAGS "-DROCKSDB_JEMALLOC -DJEMALLOC_EXPORT= -DJEMALLOC_NO_RENAME")
  
  if(DEFINED ENV{JEMALLOC_INCLUDE})
    set(JEMALLOC_INCLUDE $ENV{JEMALLOC_INCLUDE})
  endif()
  
  if(DEFINED ENV{JEMALLOC_LIB_DEBUG})
    set(JEMALLOC_LIB_DEBUG $ENV{JEMALLOC_LIB_DEBUG})
  endif()

  if(DEFINED ENV{JEMALLOC_LIB_RELEASE})
    set(JEMALLOC_LIB_RELEASE $ENV{JEMALLOC_LIB_RELEASE})
  endif()

  set(JEMALLOC_LIBS debug ${JEMALLOC_LIB_DEBUG} optimized ${JEMALLOC_LIB_RELEASE})

  add_definitions(${JEMALLOC_CXX_FLAGS})
  include_directories(${JEMALLOC_INCLUDE})
  set (THIRDPARTY_LIBS ${THIRDPARTY_LIBS} ${JEMALLOC_LIBS})
  set (ARTIFACT_SUFFIX "_je")

else ()
  set (ARTIFACT_SUFFIX "")
  message(STATUS "JEMALLOC library is disabled")
endif ()
