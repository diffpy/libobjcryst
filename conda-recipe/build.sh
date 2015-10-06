#!/bin/bash

export CPATH="$PREFIX/include:$CPATH"
MYNCPU=$(( (CPU_COUNT > 4) ? 4 : CPU_COUNT ))

scons -j $MYNCPU
scons install prefix=$PREFIX

grep '^#define LIBOBJCRYST_VERSION_STR' < "${PREFIX}/include/ObjCryst/version.h" |
    cut -d '"' -f 2 > __conda_version__.txt
