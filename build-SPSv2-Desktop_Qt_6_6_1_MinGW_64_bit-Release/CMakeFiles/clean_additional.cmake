# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\SPSv2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SPSv2_autogen.dir\\ParseCache.txt"
  "SPSv2_autogen"
  )
endif()
