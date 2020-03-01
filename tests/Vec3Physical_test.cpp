#include <Vec3Physical.hpp>

#include "catch.hpp"

TEST_CASE("adding_works") {
    Vec3Physical a(1, -2 ,3);
    Vec3Physical b(-9, 2, -1);

    REQUIRE(a.plus(b) == Vec3Physical(-8, 0, 2));
    REQUIRE(b.plus(a) == Vec3Physical(-8, 0, 2));
}