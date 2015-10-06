[![Build Status](https://travis-ci.org/diffpy/libobjcryst.svg?branch=master)]
(https://travis-ci.org/diffpy/libobjcryst)

# libobjcryst

[ObjCryst++](http://objcryst.sourceforge.net) repackaged
for installation as a system shared library.

ObjCryst++ is Object-Oriented Crystallographic Library for C++ developed
by Vincent Favre-Nicolin.  libobjcryst is a mirror of the
ObjCryst++ sources from https://sourceforge.net/projects/objcryst/,
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

For Mac OS X machine with the MacPorts package manager the installation
command is

```sh
sudo port install scons boost
```


## INSTALLATION

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
If administrator (root) access is not available, see the usage info from
`scons --help` for options to install to a user-writable location.

To verify libobjcryst installation, compile and run the included
test code [examples/testlib.cpp](examples/testlib.cpp)

```sh
cd examples
c++ testlib.cpp -lObjCryst
./a.out
```

If compilation fails because of missing header files or missing libObjCryst
library, adjust the `CPATH` and `LIBRARY_PATH` environment variables or
use the `-I` or `-L` compiler options.  If the libObjCryst shared library
cannot be found at runtime, adjust the `LD_LIBRARY_PATH` environment variable.
