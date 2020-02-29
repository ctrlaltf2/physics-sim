#pragma once
#include "Particle.h"
#include "PhysicalNumbers.hpp"
#include "Vec3Physical.hpp"

#include "math/ofVec3f.h"

#include <chrono>
#include <vector>


constexpr double kWorldScale = 1000000000000000; // Multiply up/down the world scale. If this = 100, then 100 internal coordinates == 1 meter


class ParticleSystem {
    std::vector<Particle> particles_;

    /*
     * The last time update() was called. This allows us to accurately simulate things despite the fact that this is of
     * course a discretized model of physics. Every call of update() will check ::now() vs lastUpdate, and update the
     * particle system from that.
     */
    std::chrono::time_point<std::chrono::steady_clock> lastUpdate_;

public:

    ParticleSystem() : lastUpdate_{std::chrono::steady_clock::now()} {}

    // Add a particle to the system. It's physics will be calculated on next call to update()
    // NOTE: Not meant to be called while update is called (data races!). Breaking the law of conservation of mass will be supported in future revisions.
    void add(const Particle& p);

    void update();

    std::vector<ofVec3f> positions();
};