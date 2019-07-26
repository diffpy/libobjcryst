// Test program for checking the installation of ObjCryst shared library.
// Compile and run this code using:
//
//      c++ testlib.cpp -lObjCryst
//      ./a.out


#include <iostream>
#include <sstream>
#include <ObjCryst/ObjCryst/Crystal.h>
#include <ObjCryst/ObjCryst/CIF.h>

int main(int argc, char* argv[])
{
    using namespace ObjCryst;
    // check simple crystal
    Crystal fcc(3.523, 3.523, 3.523, 90, 90, 90, "F m -3 m");
    // verify parsing of space group specification in COD4316154
    const char* cod4316154_sg_segment =
        "data_4316154\n"
        "_space_group_IT_number           179\n"
        "_symmetry_cell_setting           hexagonal\n"
        "_symmetry_space_group_name_Hall  'P 65 2 (0 0 1)'\n"
        "_symmetry_space_group_name_H-M   'P 65 2 2'\n"
        "_cell_length_a                   11.6980(17)\n"
        "_cell_length_b                   11.6980(17)\n"
        "_cell_length_c                   48.265(10)\n"
        "loop_\n"
        "_atom_site_label\n"
        "_atom_site_type_symbol\n"
        "_atom_site_fract_x\n"
        "_atom_site_fract_y\n"
        "_atom_site_fract_z\n"
        "Re1 Re 0.38627(5) 0.14503(5) 0.710514(10)\n"
        ;
    std::istringstream in1(cod4316154_sg_segment);
    CIF cif1(in1);
    Crystal* crst1 = CreateCrystalFromCIF(cif1);
    crst1->GetSpaceGroup().Print();
    delete crst1;
    std::cout << "Installation of ObjCryst shared library works!\n";
    return 0;
}
