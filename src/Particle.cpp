#include "Particle.h"

#include <iomanip>

void Particle::addForce(const Force& f) {
    runningForce_.plusEq(f);
}

// Get a new acceleration based on the forces
// Interval param is roughly how much time has passed since the last update, and basically how much we need to 'catch up'
// Smaller interval ---implies--> more calling ---results in-->  more accurate and less discrete-feeling simulations
void Particle::update(const std::uint64_t timeInterval) { // Time is in microseconds
    // Set our new acceleration based on runningForce_
    acceleration_ = runningForce_.dividedBy(mass_);

    // std::cout << std::scientific << "Force: " << runningForce_.magnitude() << " Accel: " << acceleration_.magnitude() << '\n';

    // Reset the running force
    runningForce_.zero();

    std::tie(position_, velocity_) = ode::solve<ode::method::euler>(position_, velocity_, acceleration_, timeInterval);

    // std::cout << std::scientific << velocity_.magnitude() << '\n';
    // std::cout << std::scientific << position_.i() << ' ' << position_.j() << ' ' << position_.k() << '\n';
    //velocity_.magnitude() << '\n';
}


void Particle::charge(const Charge c) {
    charge_ = c;
}