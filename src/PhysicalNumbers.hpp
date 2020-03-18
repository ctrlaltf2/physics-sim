#pragma once

#include <boost/multiprecision/cpp_dec_float.hpp>

// Double that should, with reasonable enough precision, be able to represent the small numbers involved in small particle calculations
using physicalDouble = boost::multiprecision::cpp_dec_float_50;

// Useful typedefs for expressiveness
using Mass = physicalDouble;
using Charge = physicalDouble;

// Physical constants
namespace universeConstant {
    // Gravitational constant
    const physicalDouble G = physicalDouble("+6.67430E-11");

    // Elementary charge
    const physicalDouble e = physicalDouble("+1.602176634E-19");

    // Vacuum electric permittivity
    const physicalDouble e_0 = physicalDouble("+8.8541878128E-12");

    // Vacuum magnetic permittivity
    const physicalDouble u_0 = physicalDouble("+1.25663706212E-6");

    // Mass of an electron
    const physicalDouble m_e = physicalDouble("+9.1093837015E-31");

    // Mass of a proton
    const physicalDouble m_p = physicalDouble("+1.67262192369E-27");
}