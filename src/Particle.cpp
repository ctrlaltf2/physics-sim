#include "Particle.h"

#include <iomanip>

void Particle::addForce(const Vec3Physical& f) {
    runningForce_.plusEq(f);
}

// Get a new acceleration based on the forces
// Interval param is roughly how much time has passed since the last update, and basically how much we need to 'catch up'
// Smaller interval ---implies--> more calling ---results in-->  more accurate and less discrete-feeling simulations
void Particle::update(const std::uint64_t timeInterval) { // Time is in microseconds
    std::cout << timeInterval << '\n';
    // Set our new acceleration based on runningForce_
    acceleration_ = runningForce_.dividedBy(mass_);

    std::cout << std::scientific << acceleration_.i() << ' ' << acceleration_.j() << ' ' << acceleration_.k() << '\n';
    // Reset the running force
    runningForce_.zero();

    // Update velocity from this
    // NOTE: div by 10^6 because time in in milliseconds. This corrects to give meters / microsecond.
    velocity_.plusEq(
            acceleration_.dividedBy(1'000'000)
            .multipliedBy(timeInterval)
            );

    // Update position from velocity
    position_.plusEq(
            velocity_.dividedBy(1'000'000)
            .multipliedBy(timeInterval)
            );
}