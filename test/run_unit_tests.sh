#!/usr/bin/env bash
set -eu

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
BIN_SUBDIR="${BUILD:-fast}-$(uname -m)"

# shellcheck source=/dev/null
. "$SCRIPT_DIR/test_runner.sh"

TEST_TIMEOUT="${FOX_TEST_TIMEOUT:-30s}"

run_test "unit::unit_cell_smoke" "$SCRIPT_DIR/bin/$BIN_SUBDIR/unit_cell_smoke"
run_test "unit::crystallography_workflow" "$SCRIPT_DIR/bin/$BIN_SUBDIR/crystallography_workflow"

run_test "unit::spacegroup" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_spacegroup" "spacegroup"
run_test "unit::spacegroup-alternate-settings" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_spacegroup" "spacegroup-alternate-settings"
run_test "unit::spacegroup-reflection-properties" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_spacegroup" "spacegroup-reflection-properties"
run_test "unit::spacegroup-symmetry-operations" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_spacegroup" "spacegroup-symmetry-operations"
run_test "unit::spacegroup-asymmetric-unit" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_spacegroup" "spacegroup-asymmetric-unit"

run_test "unit::scattering-power-atom" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_crystal" "scattering-power-atom"
run_test "unit::crystal-atom" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_crystal" "crystal-atom"
run_test "unit::crystal-scatterer-management" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_crystal" "crystal-scatterer-management"
run_test "unit::unitcell-geometry" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_crystal" "unitcell-geometry"

run_test "unit::molecule-atoms-bonds" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_molecule" "molecule-atoms-bonds"
run_test "unit::molecule-angles-dihedrals" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_molecule" "molecule-angles-dihedrals"
run_test "unit::molecule-formula-loglikelihood" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_molecule" "molecule-formula-loglikelihood"

run_test "unit::scatteringdata-singlecrystal" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_scattering" "scatteringdata-singlecrystal"
run_test "unit::scatteringdata-radiation-types" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_scattering" "scatteringdata-radiation-types"
run_test "unit::diffractiondata-observed" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_scattering" "diffractiondata-observed"
run_test "unit::singlecrystal-groundtruth-xray" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_scattering" "singlecrystal-groundtruth-xray"
run_test "unit::singlecrystal-groundtruth-neutron" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_scattering" "singlecrystal-groundtruth-neutron"
run_test "unit::singlecrystal-simulate-ungrouped" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_scattering" "singlecrystal-simulate-ungrouped"
run_test "unit::singlecrystal-simulate-grouped-equal" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_scattering" "singlecrystal-simulate-grouped-equal"
run_test "unit::singlecrystal-simulate-grouped-user" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_scattering" "singlecrystal-simulate-grouped-user"

run_test "unit::cif-import" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_cif" "cif-import"
run_test "unit::cif-data-fields" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_cif" "cif-data-fields"
run_test "unit::cif-coordinate-conversion" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_cif" "cif-coordinate-conversion"
run_test "unit::cif-truncated-values" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_cif" "cif-truncated-values"

run_test "unit::refinablepar" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_optimization" "refinablepar"
run_test "unit::refinableobj" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_optimization" "refinableobj"
run_test "unit::optimizationobj" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_optimization" "optimizationobj"
run_test "unit::optimizationobj-limits-options" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_optimization" "optimizationobj-limits-options"
run_test "unit::lsqnumobj" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_optimization" "lsqnumobj"
run_test "unit::lsqnumobj-residual-statistics" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_optimization" "lsqnumobj-residual-statistics"

run_test "unit::peaklist-simulate-volume" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_indexing" "peaklist-simulate-volume"
run_test "unit::peaklist-add-remove" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_indexing" "peaklist-add-remove"
run_test "unit::cellexplorer" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_indexing" "cellexplorer"
run_test "unit::cellexplorer-configuration" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_indexing" "cellexplorer-configuration"
run_test "unit::cellexplorer-dicvol-tetragonal" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_indexing" "cellexplorer-dicvol-tetragonal"
run_test "unit::cellexplorer-dicvol-monoclinic" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_indexing" "cellexplorer-dicvol-monoclinic"

run_test "unit::powderpattern-background" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_powderpattern" "powderpattern-background"
run_test "unit::powderpattern-diffraction" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_powderpattern" "powderpattern-diffraction"
run_test "unit::powderpattern-diffraction-mur" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_powderpattern" "powderpattern-diffraction-mur"
run_test "unit::powderpattern-diffraction-lebail-fhklobs" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_powderpattern" "powderpattern-diffraction-lebail-fhklobs"
run_test "unit::powderpattern-import" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_powderpattern" "powderpattern-import"
run_test "unit::scatteringcorr-subclasses" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_powderpattern" "scatteringcorr-subclasses"
run_test "unit::reflectionprofile-pseudo-voigt" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_powderpattern" "reflectionprofile-pseudo-voigt"
run_test "unit::reflectionprofile-double-exponential-pv" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_powderpattern" "reflectionprofile-double-exponential-pv"

# TODO: Re-enable these powder ground-truth regression checks once fixtures or
# tolerances are reconciled between upstream ObjCryst's default single-precision
# behavior and libobjcryst's double-precision build.
# run_test "unit::powder-groundtruth-xray-pv-gaussian" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_powderpattern" "powder-groundtruth-xray-pv-gaussian"
# run_test "unit::powder-groundtruth-xray-pv-lorentzian" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_powderpattern" "powder-groundtruth-xray-pv-lorentzian"
run_test "unit::reflectionprofile-pv-anisotropic-direct" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_powderpattern" "reflectionprofile-pv-anisotropic-direct"
# run_test "unit::powder-groundtruth-xray-anisotropic" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_powderpattern" "powder-groundtruth-xray-anisotropic"
# run_test "unit::powder-groundtruth-neutron-pv-gaussian" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_powderpattern" "powder-groundtruth-neutron-pv-gaussian"
# run_test "unit::powder-groundtruth-neutron-pv-lorentzian" "$SCRIPT_DIR/bin/$BIN_SUBDIR/api_powderpattern" "powder-groundtruth-neutron-pv-lorentzian"
