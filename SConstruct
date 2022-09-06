MY_SCONS_HELP = """\
SCons build rules for the libobjcryst C++ library
Usage: scons [target] [var=value]

Targets:

lib                 build the shared library object [default]
install             install everything under prefix directory
install-lib         install the shared library object
install-include     install the C++ header files
sdist               create source distribution tarball from git repository

Build configuration variables:
%s
Variables can be also assigned in a user-written script sconsvars.py.
SCons construction environment can be customized in sconscript.local script.
"""

import os
from os.path import join as pjoin
import platform


def subdictionary(d, keyset):
    return dict(kv for kv in d.items() if kv[0] in keyset)


def getsyspaths(*names):
    pall = sum((os.environ.get(n, '').split(os.pathsep) for n in names), [])
    rv = [p for p in pall if os.path.exists(p)]
    return rv


# copy system environment variables related to compilation
DefaultEnvironment(ENV=subdictionary(os.environ, '''
    PATH CPATH CPLUS_INCLUDE_PATH LIBRARY_PATH LD_RUN_PATH
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

# TODO: also amend paths when VIRTUAL_ENV variable exists,
#  if CONDA_PREFIX does not exist ?
if 'CONDA_PREFIX' in os.environ:
    # building for a conda environment
    vars.Add(PathVariable(
        'prefix',
        'installation prefix directory',
        os.environ['CONDA_PREFIX']))
    vars.Update(env)
    if platform.system().lower() == "windows":
        vars.Add(PathVariable(
            'libdir',
            'installation directory for compiled library [prefix/Library/lib]',
            pjoin(env['prefix'], 'Library', 'Lib'),
            PathVariable.PathAccept))
        vars.Add(PathVariable(
            'includedir',
            'installation directory for C++ header files [prefix/Library/include]',
            pjoin(env['prefix'], 'Library', 'include'),
            PathVariable.PathAccept))
    else:
        vars.Add(PathVariable(
            'libdir',
            'installation directory for compiled library [prefix/lib]',
            pjoin(env['prefix'], 'lib'),
            PathVariable.PathAccept))
        vars.Add(PathVariable(
            'includedir',
            'installation directory for C++ header files [prefix/include]',
            pjoin(env['prefix'], 'include'),
            PathVariable.PathAccept))
else:
    vars.Add(PathVariable(
        'prefix',
        'installation prefix directory',
        '/usr/local'))
    vars.Update(env)
    vars.Add(PathVariable(
        'libdir',
        'installation directory for compiled library [prefix/lib]',
        env['prefix'] + '/lib',
        PathVariable.PathAccept))
    vars.Add(PathVariable(
        'includedir',
        'installation directory for C++ header files [prefix/include]',
        env['prefix'] + '/include',
        PathVariable.PathAccept))

vars.Add(EnumVariable(
    'build',
    'compiler settings',
    'fast', allowed_values=('debug', 'fast')))
vars.Add(EnumVariable(
    'tool',
    'C++ compiler toolkit to be used',
    'default', allowed_values=('default', 'intelc')))
vars.Add(BoolVariable(
    'profile',
    'build with profiling information', False))
vars.Add(BoolVariable(
    'with_shared_cctbx',
    'compile and link with the shared cctbx library', False))
vars.Update(env)
env.Help(MY_SCONS_HELP % vars.GenerateHelpText(env))

if platform.system().lower() == "windows":
    # See https://scons.org/faq.html#Linking_on_Windows_gives_me_an_error
    env['ENV']['TMP'] = os.environ['TMP']
    # Prevent the generation of an import lib (.lib) in addition to the dll
    # Unused as we are using as static library for windows
    # env.AppendUnique(no_import_lib=1)
    if 'CONDA_PREFIX' in os.environ:
        env.Append(CPPPATH=pjoin(os.environ['CONDA_PREFIX'], 'include'))
        env.Append(CPPPATH=pjoin(os.environ['CONDA_PREFIX'], 'Library', 'include'))
        env.Append(LIBPATH=pjoin(os.environ['CONDA_PREFIX'], 'Library', 'lib'))
else:
    if 'CONDA_PREFIX' in os.environ:
        env.Append(CPPPATH=pjoin(os.environ['CONDA_PREFIX'], 'include'))
        env.Append(LIBPATH=pjoin(os.environ['CONDA_PREFIX'], 'lib'))

# the CPPPATH directories are checked by scons dependency scanner
cpppath = getsyspaths('CPLUS_INCLUDE_PATH', 'CPATH')
env.AppendUnique(CPPPATH=cpppath)
# Insert LIBRARY_PATH explicitly because some compilers
# ignore it in the system environment.
env.PrependUnique(LIBPATH=getsyspaths('LIBRARY_PATH'))
# This disable automated versioned named e.g. libboost_date_time-vc142-mt-s-x64-1_73.lib
# so we can use conda-installed libraries
env.AppendUnique(CPPDEFINES='BOOST_ALL_NO_LIB')

builddir = env.Dir('build/%s-%s' % (env['build'], platform.machine()))

Export('env')

if os.path.isfile('sconscript.local'):
    env.SConscript('sconscript.local')

SConscript("src/SConscript", variant_dir=builddir)

# vim: ft=python
