cmake_minimum_required(VERSION 3.21)
project( relentless-sg )

find_package(PythonInterp REQUIRED)
find_package(Python REQUIRED)
include(FetchContent)

# pds 
FetchContent_Declare(
	pds
	GIT_REPOSITORY https://github.com/Cooolrik/persistent-ds.git
	GIT_TAG        main
)
FetchContent_MakeAvailable( pds )
	
# generate the rsg code
execute_process( 
	COMMAND 			${PYTHON_EXECUTABLE} rsg_CodeGen.py ${pds_SOURCE_DIR}/CodeGen
	WORKING_DIRECTORY 	${CMAKE_CURRENT_LIST_DIR}/CodeGen
	RESULT_VARIABLE 	py_result
)
message(STATUS "Result of rsg_CodeGen.py: ${py_result}")

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
		librock_sha256 
		googletest 
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
	set( CMAKE_DEBUG_POSTFIX _d )
	
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
								PUBLIC ${librock_sha256_SOURCE_DIR}
								PUBLIC ${ctle_SOURCE_DIR}
								)
	target_link_libraries( 	systemtest 
							Rpcrt4
							)

endif()