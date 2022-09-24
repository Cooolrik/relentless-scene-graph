# relentless-sg - Persistent data scene graph. Copyright (c) 2022 Ulrik Lindahl
# Licensed under the MIT license https://github.com/Cooolrik/relentless-sg/blob/main/LICENSE

from EntitiesHelpers import *
from Items import Items

Items.append(
    Item(
        name = "NodeTransform", 
        dependencies = [ Dependency("pds","DataValuePointers", include_in_header = True) ],
        variables = [ Variable("fvec3", "Translation"),
                      Variable("fvec3", "Rotation"),
                      Variable("fvec3", "Scale") ]
        )
    )
