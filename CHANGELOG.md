# Release notes

## Version 2026.1.1,  - 2026-01-xx

### Changed
- changed boost version to 1.88, switch to c++-14

## Version 2024.2.1,  - 2024-09-09

### Changed
- fixed windows installation and compilation

## Version 2024.2,  - 2024-09-07

### Changed
- Switch to a git submodule for the source of the upstream objcryst project

### Fixed
- update the ScatteringComponentList when a Scatterer is removed from a Crystal.
  [fixes https://github.com/diffpy/pyobjcryst/issues/41]


## Version 2024.1.1,  - 2024-02-06

### Added
- Make sure Molecule::BuildConnectivityTable() always list all atoms, 
  even if their connectivity list is empty (pathological case)

## Version 2022.1.4,  - 2022-12-03

### Added
- Add UnitCell::ChangeSpaceGroup(), which updates lattice parameter symmetry constraints. 

### Changed
- Take into account spacegroup clock in UnitCell::GetLatticePar and InitMatrices
- Throw an exception if alpha, beta or gamma are not within ]0;pi[ in UnitCell::Init()


## Version 2022.1.3,  - 2022-11-02

### Changed

- the list of HKL reflections will now be automatically be re-generated 
  for a PowderPatternDiffraction when the Crystal's spacegroup changes,  
  or the lattice parameters are modified by more than 0.5%
- Fixed the powder pattern indexing test

## Version 2022.1.2,  - 2022-10-16

### Added

- Recipes for windows and macOS (arm64) builds
- PowderPatternDiffraction::GetFhklObsSq() and HasFhklObsSq()

### Changed

- Use a valid XML output for a Molecule RigidGroup (not backwards-compatible)

## Version 2021.1.2 - 2021-11-28

### Added

- Add access to the weight (g/mol) for ScatteringPowerAtom and Crystal

### Changed

- Add relative_length_tolerance and absolute_angle_tolerance_degree to 
  SpaceGroupExplorer::Run() and RunAll()
- Crystal::XMLInput(): add a hook to re-use atomic scattering power when
  mDeleteSubObjInDestructor is False
- Better formula for Crystal and Molecule

### Fixed

- Crystal::XMLInput(): take into account mDeleteSubObjInDestructor.

## Version 2021.1.1 - 2021-06-04

### Added

- Add 3D crystal visualization widget using py3Dmol.

### Changed

- Improve the indexing functions.
- Better access to some global optimisation variables.
- Expose the ZScatterer2Molecule function inside Molecule.h.
- Add a cylindrical absorption correction (Lobanov & Alte da Veiga).

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
