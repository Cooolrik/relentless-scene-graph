# relentless-sg - Persistent data scene graph. Copyright (c) 2022 Ulrik Lindahl
# Licensed under the MIT license https://github.com/Cooolrik/relentless-sg/blob/main/LICENSE

from EntitiesHelpers import *
from rsg_CodeGen import Items

Items.append(
    Entity(
        name = "Mesh", 

        dependencies = [ Dependency("pds", "ItemTable", include_in_header = True),
                         Dependency("pds", "BidirectionalMap", include_in_header = True),
                         Dependency("pds", "IndexedVector", include_in_header = True),
                         Dependency("pds", "Varying"),
                         ],

        templates = [ Template("attribute_layers_fvec2", template = "ItemTable", types = ["string","IndexedVector<fvec2>"] ),
                      Template("attribute_layers_fvec3", template = "ItemTable", types = ["string","IndexedVector<fvec3>"] ),
                      Template("attribute_layers_fvec4", template = "ItemTable", types = ["string","IndexedVector<fvec4>"] ),
                      Template("attribute_layers_custom", template = "ItemTable", types = ["string","Varying"] )
                     ],

        variables = [ Variable("fvec3" , "Coords" , vector = True , indexed = True ),
                      Variable("attribute_layers_fvec2" , "TexCoords"),
                      Variable("attribute_layers_fvec3" , "Tangents"),
                      Variable("attribute_layers_fvec3" , "Bitangents"),
                      Variable("attribute_layers_fvec3" , "Normals"),
                      Variable("attribute_layers_fvec4" , "Colors"),
                      Variable("attribute_layers_custom" , "CustomLayers")
                      ],

        validations = [ ValidateAllKeysAreInTable("Tangents","TexCoords"),
                        ValidateAllKeysAreInTable("Tangents","Bitangents"),
                        ValidateAllKeysAreInTable("Bitangents","TexCoords"),
                        ValidateAllKeysAreInTable("Bitangents","Tangents")
                       ]
        )
    )

