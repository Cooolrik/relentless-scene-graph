# relentless-sg - Persistent data scene graph. Copyright (c) 2022 Ulrik Lindahl
# Licensed under the MIT license https://github.com/Cooolrik/relentless-sg/blob/main/LICENSE

import sys
sys.path.append('../Dependencies/persistent-ds/CodeGen')

import CodeGeneratorHelpers as hlp
from EntitiesHelpers import *

Items = []

import Nodes.NodeTransform 
import Nodes.NodeGeometry
import Scene.Scene 
import Scene.SceneLayer 
import Geometry.Mesh

hlp.run_module('EntityGenerator', "../Include/rsg" ,  "../Src" , Items)
