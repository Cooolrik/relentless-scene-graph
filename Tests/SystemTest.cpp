// pds - Persistent data structure framework, Copyright (c) 2022 Ulrik Lindahl
// Licensed under the MIT license https://github.com/Cooolrik/pds/blob/main/LICENSE

#include <glm/glm.hpp>

#include <pds/pds.inl>
#include <pds/Varying.inl>

#include <rsg/Scene.h>
#include <rsg/Mesh.h>

#pragma warning( disable : 4189 )

int main()
	{
	pds::EntityHandler eh;

	if( eh.Initialize( "./TestFolder", { rsg::GetPackageRecord() } ) != pds::Status::Ok )
		return -1;

	//rsg::Mesh mesh;
	//
	//mesh.Coords().index().resize( 100000000 );
	//mesh.Coords().values().resize( 30000000 );
	//
	//auto ref = eh.AddEntity( std::make_shared<rsg::Mesh>(mesh) );

	auto ref = pds::entity_ref( hex_string_to_value<hash>( "1a44dec174c347ace1455c0014e4a168de1cfe42cfae69c3af4692f1b13c419e" ) );
	auto fut = eh.LoadEntity( ref );
	auto pmesh = rsg::Mesh::MF::EntitySafeCast( eh.GetLoadedEntity( ref ) );
	auto &mesh = *(pmesh);

	std::cout << "size: " << mesh.Coords().index().size() << std::endl;

	eh.UnloadNonReferencedEntities();

	std::cout << "size: " << mesh.Coords().index().size() << std::endl;

	return 0;
	}

