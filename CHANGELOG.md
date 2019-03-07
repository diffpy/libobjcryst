# Release notes

## Unreleased - Version 2017.2.1

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
