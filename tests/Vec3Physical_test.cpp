#include <Vec3Physical.hpp>

#include "catch.hpp"

TEST_CASE("adding_vectors") {
    Vec3Physical a(1, -2 ,3);
    Vec3Physical b(-9, 2, -1);

    REQUIRE(a.plus(b) == Vec3Physical(-8, 0, 2));
    REQUIRE(b.plus(a) == Vec3Physical(-8, 0, 2));
}

TEST_CASE("opposite") {
    Vec3Physical a(1, -2 ,3);
    REQUIRE(a.opposite() == Vec3Physical(-1, 2, -3));
}

TEST_CASE("opposite_zero") {
    Vec3Physical b(0, 0, 0);
    REQUIRE(b.opposite() == Vec3Physical(0, 0, 0));
}

TEST_CASE("magnitude") {
    Vec3Physical a(0, 0, 0);
    REQUIRE( fabs(a.magnitude() - 0) <= 0.0001);

    Vec3Physical b(2, 2, 1);
    REQUIRE( fabs(b.magnitude() - 3) <= 0.0001);

    Vec3Physical c(2, 3, 6);
    REQUIRE( fabs(c.magnitude() - 7) <= 0.0001);

    Vec3Physical d(2, 5, 14);
    REQUIRE( fabs(d.magnitude() - 15) <= 0.0001);
}

TEST_CASE("unit") {
    REQUIRE(Vec3Physical(0, 0, 0).unit() == Vec3Physical(0, 0, 0));

    REQUIRE(Vec3Physical(0, 0, 20).unit() == Vec3Physical(0, 0, 1));

    // TODO: Unit vectors that point in weird directions and have decimal values
}

TEST_CASE("cross_product") {
    Vec3Physical a(1, 2, 3);
    Vec3Physical b(4, 5, 6);
    Vec3Physical c(0, 0, 1);
    Vec3Physical d(1, 0, 0);
    Vec3Physical e(0, 0, -1);

    REQUIRE(a.cross(b) == Vec3Physical(-3, 6, -3));
    REQUIRE(b.cross(c) == Vec3Physical(5, -4, 0));
    REQUIRE(c.cross(d) == Vec3Physical(0, 1, 0));
    REQUIRE(c.cross(e) == Vec3Physical(0, 0, 0));
}

TEST_CASE("distance") {
    Vec3Physical a(physicalDouble("1.2"), physicalDouble("2"), physicalDouble("3"));
    Vec3Physical b(physicalDouble("4.2"), physicalDouble("0"), physicalDouble("4.2"));

    REQUIRE(a.distance(b) == Vec3Physical(physicalDouble("3.0"), physicalDouble("2"), physicalDouble("1.2")));
}