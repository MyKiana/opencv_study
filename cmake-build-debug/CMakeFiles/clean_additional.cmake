# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\opencv_study_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\opencv_study_autogen.dir\\ParseCache.txt"
  "opencv_study_autogen"
  )
endif()
