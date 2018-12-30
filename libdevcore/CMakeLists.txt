file(GLOB headers "*.h")
if(BUILD_GM)
set(sources
	CommonData.cpp
	CommonIO.cpp
	Exceptions.cpp
	IndentedWriter.cpp
	JSON.cpp
	GmHash.cpp
	StringUtils.cpp
	SwarmHash.cpp
	UTF8.cpp
	Whiskers.cpp
)	
else()
set(sources
	CommonData.cpp
	CommonIO.cpp
	Exceptions.cpp
	IndentedWriter.cpp
	JSON.cpp
	SHA3.cpp
	StringUtils.cpp
	SwarmHash.cpp
	UTF8.cpp
	Whiskers.cpp
)
endif()
if(BUILD_GM)
	aux_source_directory(./sm3 sources)
	include_directories(./sm3)
endif()
add_library(devcore ${sources} ${headers})
target_link_libraries(devcore PRIVATE jsoncpp ${Boost_FILESYSTEM_LIBRARIES} ${Boost_REGEX_LIBRARIES} ${Boost_SYSTEM_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(devcore PUBLIC "${CMAKE_SOURCE_DIR}")
target_include_directories(devcore SYSTEM PUBLIC ${Boost_INCLUDE_DIRS})
add_dependencies(devcore solidity_BuildInfo.h)
