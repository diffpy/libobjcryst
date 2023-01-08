# This is just a minimal test for linking and basic loading of a crystal structure
# For a more serious test, see the test suite in pyobjcryst at:
# https://github.com/diffpy/pyobjcryst/tree/master/src/pyobjcryst/tests

# In a conda environment, once libobjcryst has been installed, to compile and run the test example, use:

 gcc -o testlib testlib.cpp -I $CONDA_PREFIX/include -lObjCryst -L $CONDA_PREFIX/lib -lstdc++
 
 LD_LIBRARY_PATH=$CONDA_PREFIX/lib ./testlib
