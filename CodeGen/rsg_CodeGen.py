# relentless-sg - Persistent data scene graph. Copyright (c) 2022 Ulrik Lindahl
# Licensed under the MIT license https://github.com/Cooolrik/relentless-sg/blob/main/LICENSE

# add an import path to the code generator in pds
import sys
if len(sys.argv) > 1:
	print("Adding code generator folder: " + sys.argv[1])
	sys.path.append(sys.argv[1])

# import the code generators
import CodeGeneratorHelpers as hlp
from EntitiesHelpers import *

from Versions import v1_0

import Nodes.NodeTransform
import Nodes.NodeGeometry
import Scene.Scene
import Scene.SceneLayer
import Geometry.Mesh

rsg = Package( "rsg", 
	path = "../Include/rsg", 
	versions = [  
		Version( "v1_0", previousVersion = None, items = v1_0 ) 
		] 
	)

hlp.run_module('PackageGenerator', rsg, "Latest" )

