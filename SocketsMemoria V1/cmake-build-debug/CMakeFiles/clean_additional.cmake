# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CLIENT_autogen"
  "CMakeFiles/CLIENT_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CLIENT_autogen.dir/ParseCache.txt"
  "CMakeFiles/MAIN_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/MAIN_autogen.dir/ParseCache.txt"
  "CMakeFiles/SERVER_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SERVER_autogen.dir/ParseCache.txt"
  "MAIN_autogen"
  "SERVER_autogen"
  )
endif()
