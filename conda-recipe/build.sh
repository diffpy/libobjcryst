#!/bin/bash

MYNCPU=$(( (CPU_COUNT > 8) ? 8 : CPU_COUNT ))

# Apply sconscript.local customizations.
cp ${RECIPE_DIR}/sconscript.local ./

scons -j $MYNCPU
scons install prefix=$PREFIX
