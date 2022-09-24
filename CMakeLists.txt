cmake_minimum_required(VERSION 3.21)

set( CMAKE_DEBUG_POSTFIX _d )

project( relentless-sg )

add_subdirectory( ./Dependencies/persistent-ds )

add_library( relentless-sg
			 ./Src/Mesh.cpp 
			 ./Src/NodeGeometry.cpp 
			 ./Src/Scene.cpp 
			 ./Src/SceneLayer.cpp 
			 )
			
target_include_directories( relentless-sg PUBLIC
							"${PROJECT_SOURCE_DIR}/include"
							"${PROJECT_SOURCE_DIR}/Dependencies/persistent-ds/Include"
							"${PROJECT_SOURCE_DIR}/Dependencies/persistent-ds/Dependencies/ctle"
							"${PROJECT_SOURCE_DIR}/Dependencies/persistent-ds/Dependencies/fast_float/include"
							"${PROJECT_SOURCE_DIR}/Dependencies/persistent-ds/Dependencies/glm"
							"${PROJECT_SOURCE_DIR}/Dependencies/persistent-ds/Dependencies/librock_sha256"
							)

add_executable( SystemTest 
				Test.cpp 
				)
							
target_link_libraries( SystemTest PUBLIC
					   relentless-sg
					   persistent-ds
					   )
