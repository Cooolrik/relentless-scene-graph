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

int main()
	{
	eh = new pds::EntityHandler();

	if( eh->Initialize( "./TestFolder", { rsg::GetPackageRecord() } ) != pds::Status::Ok )
		return -1;

	MakeScene();
	
	eh->UnloadNonReferencedEntities();

	delete eh;

	return 0;
	}

