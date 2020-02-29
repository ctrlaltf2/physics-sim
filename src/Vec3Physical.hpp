#pragma once

#include "PhysicalNumbers.hpp"

class Vec3Physical {
    // Holds scalar multiplier on the unit vector (named)
    physicalDouble i_, j_, k_;

public:
    Vec3Physical() {
        i_ = 0.0, j_ = 0.0, k_ = 0.0;
    }

    Vec3Physical(const physicalDouble i, const physicalDouble j, const physicalDouble k) : i_{i}, j_{j}, k_{k} {}

    // Vector that's pointing the complete opposite direction
    Vec3Physical opposite() const {
        return Vec3Physical(-i_, -j_, -k_);
    }

    // Magnitude of this vector
    physicalDouble magnitude() const {
        return sqrt( i_*i_ + j_*j_ + k_*k_);
    }

    Vec3Physical unit() const {
        return this->dividedBy(this->magnitude());
    }

    Vec3Physical cross(const Vec3Physical& other) const {
        return Vec3Physical(
                    j_ * other.k_ - k_ * other.j_,
                    k_ * other.i_ - i_ * other.k_,
                    i_ * other.j_ - j_ * other.i_
                    );
    }

    physicalDouble dot(const Vec3Physical& other) const {
        return i_ * other.i_ + j_ * other.j_ + k_ * other.k_;
    }

    Vec3Physical distance(const Vec3Physical& other) const {
        return Vec3Physical(
                abs(i_ - other.i_),
                abs(j_ - other.j_),
                abs(k_ - other.k_)
                );
    }

    void zero() {
        i_ = 0, j_ = 0, k_ = 0;
    }

    // TODO: Change these to operator overloads
    Vec3Physical plus(const Vec3Physical& other) const {
        return Vec3Physical(
                    i_ + other.i_,
                    j_ + other.j_,
                    k_ + other.k_
                );
    }

    Vec3Physical minus(const Vec3Physical& other) const {
        return this->plus(other.opposite());
    }

    Vec3Physical multipliedBy(const physicalDouble scalar) const {
        return Vec3Physical(
               i_ * scalar,
               j_ * scalar,
               k_ * scalar
        );
    }

    Vec3Physical dividedBy(const physicalDouble scalar) const {
        return this->multipliedBy(physicalDouble(1) / scalar);
    }

    void plusEq(const Vec3Physical x) {
        i_ += x.i_;
        j_ += x.j_;
        k_ += x.k_;
    }
    // End TODO

    physicalDouble i() const { return i_; }
    physicalDouble j() const { return j_; }
    physicalDouble k() const { return k_; }
};