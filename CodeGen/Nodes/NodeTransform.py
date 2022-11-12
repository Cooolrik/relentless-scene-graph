# relentless-sg - Persistent data scene graph. Copyright (c) 2022 Ulrik Lindahl
# Licensed under the MIT license https://github.com/Cooolrik/relentless-sg/blob/main/LICENSE

from EntitiesHelpers import *
from Versions import v1_0

v1_0.append(
    NewItem(
        name = "NodeTransform", 
        variables = [ Variable("fvec3", "Translation"),
                      Variable("fvec3", "Rotation"),
                      Variable("fvec3", "Scale") ]
        )
    )
