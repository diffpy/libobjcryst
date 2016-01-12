[![Build Status](https://travis-ci.org/diffpy/libobjcryst.svg?branch=master)]
(https://travis-ci.org/diffpy/libobjcryst)

# libobjcryst

[ObjCryst++](http://objcryst.sourceforge.net) repackaged
for installation as a system shared library.

ObjCryst++ is Object-Oriented Crystallographic Library for C++ developed
by Vincent Favre-Nicolin.  libobjcryst is a mirror of the
ObjCryst++ sources from https://sourceforge.net/projects/objcryst,
expanded with SCons build scripts to make it easier to install as
a system shared library.  libobjcryst does not include GUI related
files from ObjCryst++.  This distribution contains required
sources from [cctbx](http://cctbx.sourceforge.net/current/) and
[newmat](http://www.robertnz.net/nm_intro.htm) that are used in
ObjCryst++.

For more information about the ObjCryst++ library, see the upstream project at
http://objcryst.sourceforge.net.  For Python bindings to ObjCryst++ see the
pyobjcryst project at https://github.com/diffpy/pyobjcryst.


## REQUIREMENTS

libobjcryst requires C++ compiler and the following software:

* `scons` - software constructions tool (1.0 or later)
* `libboost-dev` - Boost C++ libraries development files

Required software is commonly available in the system package manager,
for example, on Ubuntu Linux the dependencies can be installed as:

```sh
sudo apt-get install build-essential scons libboost-dev
```

libobjcryst is also available as a pre-compiled package for
[Anaconda Python](https://www.continuum.io/downloads) and it
gets automatically installed together with pyobjcryst for
Anaconda.


## INSTALLATION

### Installation from sources

Download and extract the latest libobjcryst bundle from
https://github.com/diffpy/libobjcryst/releases/latest:

```sh
tar xzf libobjcryst-VERSION.tar.gz
cd libobjcryst-VERSION
```

To build and install the libobjcryst library use

```sh
sudo scons -j4 install
```

This installs libobjcryst for all users under the `/usr/local` directory.
If administrator (root) access is not available, see the output from
`scons --help` for options to install to a user-writable location.

To verify libobjcryst installation, compile and run the included
test code [examples/testlib.cpp](examples/testlib.cpp)

```sh
cd examples
c++ testlib.cpp -lObjCryst
./a.out
```

If there is an error due to missing headers or missing libObjCryst
library, adjust the `CPATH` and `LIBRARY_PATH` environment variables or
use the `-I` and `-L` compiler options.  If the libObjCryst shared library
cannot be found at runtime, adjust the `LD_LIBRARY_PATH` environment variable.

### Installation for Anaconda Python

The libobjcryst library is available in the "diffpy" channel of Anaconda
packages

```sh
conda config --add channels diffpy
conda install libobjcryst
```

libobjcryst is also included in the "diffpy-cmi" collection of packages
for structure analysis

```sh
conda install diffpy-cmi
```

When compiling with the Anaconda version of libobjcryst it is essential to
specify header path, library path and runtime path of the active Anaconda
environment

```sh
# resolve prefix directory P of the active Anaconda environment
P="$(conda info --json | grep default_prefix | cut -d\" -f4)"
cd examples
c++ testlib.cpp -I$P/include -L$P/lib -Wl,-rpath,$P/lib -lObjCryst
./a.out
```

On Mac OS X the Anaconda libobjcryst is built for OS X version
10.6 which may be incompatible with codes compiled on a newer OS.
To fix this pass the `-mmacosx-version-min=10.6` option to the
c++ compiler or set it via an environment variable as
`export MACOSX_DEPLOYMENT_TARGET=10.6`.
