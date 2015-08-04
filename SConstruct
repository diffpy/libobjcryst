MY_SCONS_HELP = """\
SCons build rules for the libobjcryst C++ library
Usage: scons [target] [var=value]

Targets:

lib                 build the shared library object [default]
install             install everything under prefix directory
install-lib         install the shared library object
install-include     install the C++ header files

Build configuration variables:
%s
Variables can be also assigned in a user-written script sconsvars.py.
SCons construction environment can be customized in sconscript.local script.
"""

import os
import platform

def subdictionary(d, keyset):
    return dict([kv for kv in d.items() if kv[0] in keyset])

# copy system environment variables related to compilation
DefaultEnvironment(ENV=subdictionary(os.environ, '''
    PATH PYTHONPATH
    CPATH CPLUS_INCLUDE_PATH LIBRARY_PATH
    LD_LIBRARY_PATH DYLD_LIBRARY_PATH DYLD_FALLBACK_LIBRARY_PATH
    MACOSX_DEPLOYMENT_TARGET
    '''.split())
)

# Create construction environment
env = DefaultEnvironment().Clone()

# Variables definitions below work only with 0.98.1 or later.
env.EnsureSConsVersion(0, 98, 1)

# Customizable compile variables
vars = Variables('sconsvars.py')

vars.Add(EnumVariable('build',
    'compiler settings', 'fast',
    allowed_values=('debug', 'fast')))
vars.Add(BoolVariable('profile',
    'build with profiling information', False))
vars.Add('REAL', 'floating point type', 'double')
vars.Add(BoolVariable('with_shared_cctbx',
    'compile and link with the shared cctbx library', False))
vars.Add(PathVariable('prefix',
    'installation prefix directory', '/usr/local'))
vars.Update(env)
vars.Add(PathVariable('libdir',
    'object code library directory [prefix/lib]',
    env['prefix'] + '/lib',
    PathVariable.PathAccept))
vars.Add(PathVariable('includedir',
    'installation directory for C++ header files [prefix/include]',
    env['prefix'] + '/include',
    PathVariable.PathAccept))
vars.Update(env)
env.Help(MY_SCONS_HELP % vars.GenerateHelpText(env))

builddir = env.Dir('build/%s-%s' % (env['build'], platform.machine()))

Export('env')

if os.path.isfile('sconscript.local'):
    env.SConscript('sconscript.local')

SConscript("src/SConscript", variant_dir=builddir)

# vim: ft=python
