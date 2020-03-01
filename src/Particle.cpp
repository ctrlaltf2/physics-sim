#include "Particle.h"

#include <iomanip>

void Particle::addForce(const Vec3Physical& f) {
    runningForce_.plusEq(f);
}

// Get a new acceleration based on the forces
// Interval param is roughly how much time has passed since the last update, and basically how much we need to 'catch up'
// Smaller interval ---implies--> more calling ---results in-->  more accurate and less discrete-feeling simulations
void Particle::update(const std::uint64_t timeInterval) { // Time is in microseconds
    // Set our new acceleration based on runningForce_
    acceleration_ = runningForce_.dividedBy(mass_);

    // Reset the running force
    runningForce_.zero();

    // Update velocity from this
    // NOTE: div by 10^6 because time in in microseconds. This corrects to give meters / microsecond.
    velocity_.plusEq(
            acceleration_.dividedBy(100'000'000)
                    .multipliedBy(timeInterval)
    );

    // Update position from velocity
    position_.plusEq(
            velocity_.dividedBy(100'000'000)
                    .multipliedBy(timeInterval)
    );

    //std::cout << std::scientific << position_.i() << ' ' << position_.j() << ' ' << position_.k() << '\n';
}


void Particle::charge(const physicalDouble n) {
    charge_ = n;
}