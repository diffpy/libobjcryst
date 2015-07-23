#include <cctbx/sgtbx/reference_settings.h>

namespace cctbx { namespace sgtbx { namespace reference_settings {

  matrix_group::code const&
  matrix_group_code_table(std::size_t i)
  {
    static const matrix_group::code table[] = {
      matrix_group::unknown,
// BEGIN_COMPILED_IN_REFERENCE_DATA
      matrix_group::code_1,
      matrix_group::code_1b,
      matrix_group::code_2,
      matrix_group::code_2,
      matrix_group::code_2,
      matrix_group::code_m,
      matrix_group::code_m,
      matrix_group::code_m,
      matrix_group::code_m,
      matrix_group::code_2_m,
      matrix_group::code_2_m,
      matrix_group::code_2_m,
      matrix_group::code_2_m,
      matrix_group::code_2_m,
      matrix_group::code_2_m,
      matrix_group::code_222,
      matrix_group::code_222,
      matrix_group::code_222,
      matrix_group::code_222,
      matrix_group::code_222,
      matrix_group::code_222,
      matrix_group::code_222,
      matrix_group::code_222,
      matrix_group::code_222,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mm2,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_mmm,
      matrix_group::code_4,
      matrix_group::code_4,
      matrix_group::code_4,
      matrix_group::code_4,
      matrix_group::code_4,
      matrix_group::code_4,
      matrix_group::code_4b,
      matrix_group::code_4b,
      matrix_group::code_4_m,
      matrix_group::code_4_m,
      matrix_group::code_4_m,
      matrix_group::code_4_m,
      matrix_group::code_4_m,
      matrix_group::code_4_m,
      matrix_group::code_422,
      matrix_group::code_422,
      matrix_group::code_422,
      matrix_group::code_422,
      matrix_group::code_422,
      matrix_group::code_422,
      matrix_group::code_422,
      matrix_group::code_422,
      matrix_group::code_422,
      matrix_group::code_422,
      matrix_group::code_4mm,
      matrix_group::code_4mm,
      matrix_group::code_4mm,
      matrix_group::code_4mm,
      matrix_group::code_4mm,
      matrix_group::code_4mm,
      matrix_group::code_4mm,
      matrix_group::code_4mm,
      matrix_group::code_4mm,
      matrix_group::code_4mm,
      matrix_group::code_4mm,
      matrix_group::code_4mm,
      matrix_group::code_4b2m,
      matrix_group::code_4b2m,
      matrix_group::code_4b2m,
      matrix_group::code_4b2m,
      matrix_group::code_4bm2,
      matrix_group::code_4bm2,
      matrix_group::code_4bm2,
      matrix_group::code_4bm2,
      matrix_group::code_4bm2,
      matrix_group::code_4bm2,
      matrix_group::code_4b2m,
      matrix_group::code_4b2m,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_4_mmm,
      matrix_group::code_3,
      matrix_group::code_3,
      matrix_group::code_3,
      matrix_group::code_3,
      matrix_group::code_3b,
      matrix_group::code_3b,
      matrix_group::code_312,
      matrix_group::code_321,
      matrix_group::code_312,
      matrix_group::code_321,
      matrix_group::code_312,
      matrix_group::code_321,
      matrix_group::code_32,
      matrix_group::code_3m1,
      matrix_group::code_31m,
      matrix_group::code_3m1,
      matrix_group::code_31m,
      matrix_group::code_3m,
      matrix_group::code_3m,
      matrix_group::code_3b1m,
      matrix_group::code_3b1m,
      matrix_group::code_3bm1,
      matrix_group::code_3bm1,
      matrix_group::code_3bm,
      matrix_group::code_3bm,
      matrix_group::code_6,
      matrix_group::code_6,
      matrix_group::code_6,
      matrix_group::code_6,
      matrix_group::code_6,
      matrix_group::code_6,
      matrix_group::code_6b,
      matrix_group::code_6_m,
      matrix_group::code_6_m,
      matrix_group::code_622,
      matrix_group::code_622,
      matrix_group::code_622,
      matrix_group::code_622,
      matrix_group::code_622,
      matrix_group::code_622,
      matrix_group::code_6mm,
      matrix_group::code_6mm,
      matrix_group::code_6mm,
      matrix_group::code_6mm,
      matrix_group::code_6bm2,
      matrix_group::code_6bm2,
      matrix_group::code_6b2m,
      matrix_group::code_6b2m,
      matrix_group::code_6_mmm,
      matrix_group::code_6_mmm,
      matrix_group::code_6_mmm,
      matrix_group::code_6_mmm,
      matrix_group::code_23,
      matrix_group::code_23,
      matrix_group::code_23,
      matrix_group::code_23,
      matrix_group::code_23,
      matrix_group::code_m3b,
      matrix_group::code_m3b,
      matrix_group::code_m3b,
      matrix_group::code_m3b,
      matrix_group::code_m3b,
      matrix_group::code_m3b,
      matrix_group::code_m3b,
      matrix_group::code_432,
      matrix_group::code_432,
      matrix_group::code_432,
      matrix_group::code_432,
      matrix_group::code_432,
      matrix_group::code_432,
      matrix_group::code_432,
      matrix_group::code_432,
      matrix_group::code_4b3m,
      matrix_group::code_4b3m,
      matrix_group::code_4b3m,
      matrix_group::code_4b3m,
      matrix_group::code_4b3m,
      matrix_group::code_4b3m,
      matrix_group::code_m3bm,
      matrix_group::code_m3bm,
      matrix_group::code_m3bm,
      matrix_group::code_m3bm,
      matrix_group::code_m3bm,
      matrix_group::code_m3bm,
      matrix_group::code_m3bm,
      matrix_group::code_m3bm,
      matrix_group::code_m3bm,
      matrix_group::code_m3bm
// END_COMPILED_IN_REFERENCE_DATA
    };
    return table[i];
  }

}}} // namespace cctbx::sgtbx::reference_settings
