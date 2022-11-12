# relentless-sg - Persistent data scene graph. Copyright (c) 2022 Ulrik Lindahl
# Licensed under the MIT license https://github.com/Cooolrik/relentless-sg/blob/main/LICENSE

from EntitiesHelpers import *
from Versions import v1_0

v1_0.append(
    NewEntity(
        name = "Scene", 
        dependencies = [],

        templates = [ Template("scene_layers", template = "BidirectionalMap", types = ["entity_ref","string"] ) ],

        variables = [ Variable("scene_layers" , "Layers") ]
        )
    )

