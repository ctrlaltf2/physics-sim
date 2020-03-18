#pragma once
#include <stdexcept>
#include <tuple>

#include "Vec3Physical.hpp"

namespace ode {

    namespace method {
        enum class euler;
        enum class RKF45; // Runge-Kutta-Fehlberg (See: http://maths.cnam.fr/IMG/pdf/RungeKuttaFehlbergProof.pdf)
        // To be implemented
        enum class verlet; // Stormer's method
        enum class RK4; // Runge-Kutta 4th order
    }

    // Base case
    template<typename Solver> inline
    std::tuple<Position, Velocity> solve(Position pos, Velocity v, Acceleration accel, std::uint64_t timestep) {
        throw std::logic_error("Error: This solve method is not yet implemented.");
    }

    /*
     * Euler's method (apparently is what this is called)
     *
     * Pretty self explanatory method that anyone could discover for themselves without any crazy math background.
     */
    template<> inline
    std::tuple<Position, Velocity> solve<ode::method::euler>(Position pos, Velocity velocity, Acceleration accel, std::uint64_t timestep) {
        // First, update velocity from acceleration
        // NOTE: div by 10^6 because time in in microseconds. This corrects to give meters / microsecond.
        velocity.plusEq(
                accel.dividedBy(10'000'000)
                        .multipliedBy(timestep)
        );

        // Then, position from velocity
        pos.plusEq(
                velocity.dividedBy(10'000'000)
                        .multipliedBy(timestep)
        );

        return {pos, velocity};
    }

}

// auto [position, velocity] = ode::solve<ode::method::euler> (position, velocity, acceleration, timestep);