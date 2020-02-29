#pragma once

#include "PhysicalNumbers.hpp"
#include "Vec3Physical.cpp"

class ParticleSystem;

class Particle {
    friend ParticleSystem;

    const physicalDouble mass_; // kg

    physicalDouble charge_; // Coulombs

    Vec3Physical position_, velocity_, acceleration_; // m, m/s, m/s^2

    Vec3Physical runningForce_; // N, Sum of all the forces that are to be popped into its acceleration
public:
    Particle() = delete;

    Particle(const physicalDouble mass, const Vec3Physical& position) {
        Particle(mass, position, Vec3Physical(0, 0, 0));
    }

    Particle(const physicalDouble mass, const Vec3Physical& position, const Vec3Physical& velocity) : position_{position}, velocity_{velocity}, mass_{mass} {
        acceleration_ = Vec3Physical(0, 0, 0);
    }

    void addForce(const Vec3Physical& f);

    // Get a new acceleration based on the forces
    // Interval param is roughly how much time has passed since the last update, and basically how much we need to 'catch up'
    // Smaller interval ---implies--> more calling ---results in-->  more accurate and less discrete-feeling simulations
    void update(const std::uint64_t timeInterval); // Time is in microseconds

    // Assign a charge to the particle.
    void charge(const physicalDouble n);
    /*
    Vec3Physical position() const {
        return position_;
    }*/
};