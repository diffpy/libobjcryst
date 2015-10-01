#!/bin/bash

export CPATH="$PREFIX/include:$CPATH"
MYNCPU=$(( (CPU_COUNT > 4) ? 4 : CPU_COUNT ))

scons -j $MYNCPU
scons install prefix=$PREFIX
