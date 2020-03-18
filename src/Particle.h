#pragma once

#include "PhysicalNumbers.hpp"
#include "Vec3Physical.hpp"

class ParticleSystem;

class Particle {
    friend ParticleSystem;

    const physicalDouble mass_; // kg

    physicalDouble charge_; // Coulombs

    Position position_; // m

    Velocity velocity_; // m/s

    Acceleration acceleration_; // m/s^2

    Force runningForce_; // N, Sum of all the forces that are to be popped into its acceleration
public:
    Particle() = delete;

    Particle(const Mass mass, const Position& position) {
        Particle(mass, position, Vec3Physical(0, 0, 0));
    }

    Particle(const Mass mass, const Position& position, const Velocity& velocity) : position_{position}, velocity_{velocity}, mass_{mass} {
        acceleration_ = Vec3Physical(0, 0, 0);
    }

    void addForce(const Force& f);

    // Get a new acceleration based on the forces
    // Interval param is roughly how much time has passed since the last update, and basically how much we need to 'catch up'
    // Smaller interval ---implies--> more calling ---results in-->  more accurate and less discrete-feeling simulations
    void update(const std::uint64_t timeInterval); // Time is in microseconds

    // Assign a charge to the particle.
    void charge(const Charge c);
    /*
    Vec3Physical position() const {
        return position_;
    }*/
};