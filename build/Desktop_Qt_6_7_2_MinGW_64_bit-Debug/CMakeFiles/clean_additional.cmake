# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\NotepadApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\NotepadApp_autogen.dir\\ParseCache.txt"
  "NotepadApp_autogen"
  )
endif()
