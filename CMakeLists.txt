cmake_minimum_required(VERSION 3.21)

include(FetchContent)

set( CMAKE_DEBUG_POSTFIX _d )

project( relentless-sg )

# pds 
FetchContent_Declare(
	pds
	GIT_REPOSITORY https://github.com/Cooolrik/persistent-ds.git
	GIT_TAG        main
)

# lots of warnings and all warnings as errors
# big object files
if(MSVC)
    add_compile_options(/W4 /WX)
	add_compile_options(/bigobj)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
	add_compile_options(-Wa,-mbig-obj)
endif()

# if this is the main build of rsg, build the testing code
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)			
				
	# dowload gtest
	include(FetchContent)
	FetchContent_Declare(
	  googletest
	  URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
	)
	
	FetchContent_MakeAvailable( 
		pds 
		glm
		ctle 
		librocksha256 
		googletest 
		)
	
	# SystemTest run full system tests
	add_executable( systemtest
					./Tests/SystemTest.cpp 
					./Include/rsg/rsg.cpp 
					)	
	target_include_directories(	systemtest
								PUBLIC ${PROJECT_SOURCE_DIR}/Include
									
								# direct dependencies and dependencies of pds
								PUBLIC ${pds_SOURCE_DIR}/Include
								PUBLIC ${glm_SOURCE_DIR}
								PUBLIC ${librocksha256_SOURCE_DIR}/include
								PUBLIC ${ctle_SOURCE_DIR}
								)
	target_link_libraries( 	systemtest 
							Rpcrt4
							)

endif()