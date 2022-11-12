git submodule init
git submodule update

pushd Dependencies\persistent-ds\CodeGen
py CodeGenerator.py
popd