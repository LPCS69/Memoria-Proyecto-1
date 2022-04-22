# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Cliente_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Cliente_autogen.dir/ParseCache.txt"
  "CMakeFiles/Memoria_Proyecto1_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Memoria_Proyecto1_autogen.dir/ParseCache.txt"
  "CMakeFiles/Servidor_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Servidor_autogen.dir/ParseCache.txt"
  "Cliente_autogen"
  "Memoria_Proyecto1_autogen"
  "Servidor_autogen"
  )
endif()
