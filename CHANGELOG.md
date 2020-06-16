# Release notes

## Version 2017.2.3 - 2020-06-15

### Added
- Move SpaceGroupExplorer in a separate class for non-GUI access.
  Allow keeping or not the tested spacegroup, or the best solution.
  Sort solutions by the GoF multiplied by the ratio of the number 
  of non-extinct reflections in the spacegoup relative to P1.
- MonteCarloObj: add public access to AutoLSQ option
- OptimizationObj: add access to Options by number or name
- RefinableObj: provide access to options by name
- Add STL-type methods (begin, end, size) for ObjRegistry and Molecule objects
- Add Crystal.GetFormula(). Use formula to automatically name Crystal and 
  DiffractionDataSingleCrystal when imported from CIF and no name is given

### Changed
- Better format for ObjRegistry::Print()
- sync with upstream-objcryst v2017.2-52-gd5e3585

### Fixed
- Correct EstimateCellVolume estimation for orthorombic F

## Version 2017.2.2 – 2019-05-14

### Changed

- Throw `invalid_argument` when space group lookup fails.
- Sync with upstream-objcryst v2017.2-37-g5ae17765.

### Fixed

- Infinite recursion in `SpaceGroup("bad")` and `ChangeSpaceGroup("bad")`.


## Version 2017.2.1 – 2019-03-08

Notable differences from version 2017.1.1.

### Added

- Support compilation from standard git-archive tarball, i.e,
  expand version metadata with `export-subst` git attribute.
- Make scons scripts compatible with Python 3 and Python 2.
- Declare compatible version requirements for client Anaconda packages.
- Sync with upstream-objcryst v2017.2.

### Changed

- Remove no-op GL functions which are relevant only for fox-objcryst.
- Anaconda package recipe to use Anaconda C++ compilers.
- Use c++98 language standard even if Anaconda environment sets later.

### Deprecated

- Macro `LIBOBJCRYST_GIT_SHA` replaced with `LIBOBJCRYST_GIT_COMMIT`.
- Member `libobjcryst_version_info::git_sha` replaced with `git_commit`.

### Removed

- Hard-coded diagnostic output in `SetPowderPatternObs`.

### Fixed

- Source typos, e.g., missed braces, misleading indentation, missing include.
- Incomplete `scons install` when shared library fails to build.
- `SetPowderPatternX` crash for empty vector argument.
- Incorrectly doubled return value from `GetInversionCenter`.
- Memory leak for a copy-constructed empty `CrystVector`.
