// pds - Persistent data structure framework, Copyright (c) 2022 Ulrik Lindahl
// Licensed under the MIT license https://github.com/Cooolrik/pds/blob/main/LICENSE

#include <glm/glm.hpp>

#include <pds/pds.inl>
#include <pds/Varying.inl>

#include <rsg/Scene.h>
#include <rsg/SceneLayer.h>
#include <rsg/Mesh.h>

#pragma warning( disable : 4189 )

pds::EntityHandler *eh;

rsg::entity_ref MakeGeom()
	{
	rsg::Mesh mesh;
	
	mesh.Coords().index().resize( 100 );
	mesh.Coords().values().resize( 30 );
	
	auto res = eh->AddEntity( std::make_shared<rsg::Mesh>(mesh) );
	return res.first;
	}

rsg::entity_ref MakeSceneLayer()
	{
	rsg::SceneLayer layer;
	rsg::item_ref ref;

	ref = rsg::item_ref::make_ref();
	layer.Geometries().Insert( ref ).Geometry() = MakeGeom();
	layer.Nodes().insert( ref, "geom1" );

	ref = rsg::item_ref::make_ref();
	layer.Geometries().Insert( ref ).Geometry() = MakeGeom();
	layer.Nodes().insert( ref, "geom2" );

	ref = rsg::item_ref::make_ref();
	layer.Geometries().Insert( ref ).Geometry() = MakeGeom();
	layer.Nodes().insert( ref, "geom3" );

	auto res = eh->AddEntity( std::make_shared<rsg::SceneLayer>(layer) );
	return res.first;
	}

rsg::entity_ref MakeScene()
	{
	rsg::Scene scene;

	scene.Layers().insert( MakeSceneLayer(), "layer1" );
	scene.Layers().insert( MakeSceneLayer(), "layer2" );
	scene.Layers().insert( MakeSceneLayer(), "layer3" );

	auto res = eh->AddEntity( std::make_shared<rsg::Scene>(scene) );
	return res.first;
	}

#include <windows.h>
#include <tlhelp32.h>

/**
Returns the thread count of the current process or -1 in case of failure.
*/
int GetCurrentThreadCount()
	{
	// first determine the id of the current process
	DWORD const  id = GetCurrentProcessId();

	// then get a process list snapshot.
	HANDLE const  snapshot = CreateToolhelp32Snapshot( TH32CS_SNAPALL, 0 );

	// initialize the process entry structure.
	PROCESSENTRY32 entry = { 0 };
	entry.dwSize = sizeof( entry );

	// get the current process info.
	BOOL  ret = true;
	ret = Process32First( snapshot, &entry );
	while( ret && entry.th32ProcessID != id ) {
		ret = Process32Next( snapshot, &entry );
		}
	CloseHandle( snapshot );
	return ret 
		?   entry.cntThreads
		:   -1;
	}

int main()
	{
	eh = new pds::EntityHandler();

	if( eh->Initialize( "./TestFolder", { rsg::GetPackageRecord() } ) != pds::Status::Ok )
		return -1;

	std::vector<std::future<std::pair<pds::entity_ref, pds::Status>>> futures;
	
	for( uint inx = 0; inx < 2000; ++inx )
		{
		rsg::Mesh mesh;
	
		mesh.Coords().index().resize( 10000 );
		mesh.Coords().values().resize( 3000 );
		mesh.Normals().Insert( "normals" );
		mesh.Normals()["normals"].index().resize(10000);
		mesh.Normals()["normals"].values().resize( 3000+inx );

		futures.emplace_back( std::move(eh->AddEntityAsync( std::make_shared<rsg::Mesh>( mesh ) )) );
		}
		
	for( size_t inx =0; inx<futures.size(); ++inx )
		{
		if( (inx % 100) == 0 )
			{
			std::cout << "Inx: " << inx << std::endl;
			std::cout << "Num threads: " << GetCurrentThreadCount() << std::endl;
			}
		futures[inx].wait();
		}

	std::cout << "all done" << std::endl;

	eh->UnloadNonReferencedEntities();

	delete eh;

	return 0;
	}

