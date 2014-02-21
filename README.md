# libobjcryst

[ObjCryst++](http://objcryst.sourceforge.net) repackaged
for installation as a system shared library.

ObjCryst++ is Object-Oriented Crystallographic Library for C++ developed
by Vincent Favre-Nicolin.  libobjcryst is a mirror of the
ObjCryst++ sources (https://sourceforge.net/projects/objcryst/)
expanded with SCons build scripts that aim to make it easier to
install as a system shared library.  libobjcryst does not contain GUI related
sources from ObjCryst++.  This distribution also includes required sources
from [cctbx](http://cctbx.sourceforge.net/current/) and
[newmat](http://www.robertnz.net/nm_intro.htm) projects.

For more information about the ObjCryst++ library, see the upstream project at
http://objcryst.sourceforge.net.  For Python bindings to ObjCryst++ see the
pyobjcryst project at https://github.com/diffpy/pyobjcryst.


## REQUIREMENTS

libobjcryst requires C++ compiler and the following software:

* `scons` - software constructions tool (1.0 or later)
* `libboost-dev` - Boost C++ libraries development files

Required software is typically available in system package manager,
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
https://github.com/diffpy/libobjcryst/releases

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

If C++ compiler cannot find ObjCryst header files or the libobjcryst library,
adjust the `CPATH` and `LIBRARY_PATH` environment variables or use the `-I`
or `-L` compiler options.  If libobjcryst shared library cannot be found at
runtime, adjust the `LD_LIBRARY_PATH` environment variable.
