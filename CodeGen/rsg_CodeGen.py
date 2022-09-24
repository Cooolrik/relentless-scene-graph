# relentless-sg - Persistent data scene graph. Copyright (c) 2022 Ulrik Lindahl
# Licensed under the MIT license https://github.com/Cooolrik/relentless-sg/blob/main/LICENSE

# add an import path to the code generator in pds
import sys
sys.path.append('../Dependencies/persistent-ds/CodeGen')

# import the code generators
import CodeGeneratorHelpers as hlp
from EntitiesHelpers import *

from Items import Items

import Nodes.NodeTransform
import Nodes.NodeGeometry
import Scene.Scene
import Scene.SceneLayer
import Geometry.Mesh

package = Package( "rsg" , "../Include/rsg" ,  "../Src" , Items )

# run the generator
hlp.run_module('PackageGenerator', package)
