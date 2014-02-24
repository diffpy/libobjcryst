// Test program for checking the installation of ObjCryst shared library.
// Compile and run this code using:
//
//      c++ testlib.cpp -lObjCryst
//      ./a.out


#include <iostream>
#include <ObjCryst/ObjCryst/Crystal.h>

int main(int argc, char* argv[])
{
    using ObjCryst::Crystal;
    Crystal nickel(3.523, 3.523, 3.523, 90, 90, 90, "F m -3 m");
    std::cout << "Installation of ObjCryst shared library works!\n";
    return 0;
}
