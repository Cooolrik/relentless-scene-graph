# relentless-sg - Persistent data scene graph. Copyright (c) 2022 Ulrik Lindahl
# Licensed under the MIT license https://github.com/Cooolrik/relentless-sg/blob/main/LICENSE

from EntitiesHelpers import *
from rsg_CodeGen import Items

Items.append(
    Item(
        name = "NodeGeometry", 
        variables = [ Variable("entity_ref" , "Geometry") ]
        )
    )
