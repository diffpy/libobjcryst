This directory provides an independent unit-test harness for running the
upstream ObjCryst non-GUI unit tests against the libobjcryst library built in
this repository.

Usage:

1. Build libobjcryst in-tree with SCons, for example:
   `PREFIX=/path/to/env python -m SCons -Q lib`
2. Build and run the unit tests:
   `CONDA_PREFIX=/path/to/env make -C test`

The makefile expects the library under `build/<build>-<arch>/src/` and uses
`build=fast` by default. Override `BUILD_DIR`, `BUILD`, `ARCH`, or `LIBOBJCRYST`
when using a different in-tree layout.

On macOS with a conda toolchain, pass `CONDA_PREFIX` so the test binaries add
the environment runtime library directory to their rpath.
