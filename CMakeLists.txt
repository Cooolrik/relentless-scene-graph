cmake_minimum_required(VERSION 3.21)

set( CMAKE_DEBUG_POSTFIX _d )

project( relentless-sg )

# lots of warnings and all warnings as errors
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# big object files
if (MSVC)
  add_compile_options(/bigobj)
else ()
  add_compile_options(-Wa,-mbig-obj)
endif ()

add_subdirectory( ./Dependencies/persistent-ds )
		
# if this is the main build of rsg, build the testing code
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)			
				
	# dowload gtest
	include(FetchContent)
	FetchContent_Declare(
	  googletest
	  URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
	)
	FetchContent_MakeAvailable(googletest)			
	
	# SystemTest run full system tests
	add_executable( SystemTest
					./Tests/SystemTest.cpp 
					./Include/rsg/rsg.cpp 
					)	
	target_include_directories(	SystemTest 
								PUBLIC
									"${PROJECT_SOURCE_DIR}/Include"
									
									# direct dependencies and dependencies of pds
									"${PROJECT_SOURCE_DIR}/Dependencies/persistent-ds/Include"
									"${PROJECT_SOURCE_DIR}/Dependencies/persistent-ds/Dependencies/ctle"
									"${PROJECT_SOURCE_DIR}/Dependencies/persistent-ds/Dependencies/fast_float/include"
									"${PROJECT_SOURCE_DIR}/Dependencies/persistent-ds/Dependencies/glm"
									"${PROJECT_SOURCE_DIR}/Dependencies/persistent-ds/Dependencies/librock_sha256"
								)
	target_link_libraries( 	SystemTest 
							Rpcrt4
							)

endif()