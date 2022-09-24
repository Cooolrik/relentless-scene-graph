# relentless-sg - Persistent data scene graph. Copyright (c) 2022 Ulrik Lindahl
# Licensed under the MIT license https://github.com/Cooolrik/relentless-sg/blob/main/LICENSE

from EntitiesHelpers import *
from Items import Items

Items.append(
    Entity(
        name = "Scene", 
        dependencies = [ Dependency("pds","BidirectionalMap", include_in_header = True) ],

        templates = [ Template("scene_layers", template = "BidirectionalMap", types = ["entity_ref","string"] ) ],

        variables = [ Variable("scene_layers" , "Layers") ]
        )
    )

