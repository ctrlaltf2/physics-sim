#include "ParticleSystem.h"

void ParticleSystem::add(const Particle& p) {
    particles_.emplace_back(p);
}

void ParticleSystem::update() {
    // Gravitational forces
    for(int a = 0; a < particles_.size(); ++a) {
        for(int b = a + 1; b < particles_.size(); ++b) {
            // Unit vec from a to b (https://math.stackexchange.com/questions/273236/finding-the-unit-vector-indicating-direction-from-a-to-b)
            Vec3Physical& aPos = particles_[a].position_, bPos = particles_[b].position_;
            const auto unitV =
                    bPos
                    .minus(aPos)
                    .unit();

            // Find F_g
            const physicalDouble F_g = universeConstant::G * particles_[a].mass_ * particles_[b].mass_ /
                                                    pow(aPos.distance(bPos).magnitude(), 2);

            // Add F_g * unitV to a's forces
            particles_[a].addForce(unitV.multipliedBy(F_g));

            // Subtract F_g * unitV from b's forces
            particles_[b].addForce(unitV.multipliedBy(F_g).opposite());
        }
    }

    // Magnetic force (moving charge through a field)
    // For now just having a static hard-coded field to see how things work out.
    const static Vec3Physical B(2, 0, 0); // Tesla
    for(auto& particle : particles_) {
        // F_b = q * v x B
        const Vec3Physical& F_b = particle.velocity_.cross(B).multipliedBy(particle.charge_);
        particle.addForce(F_b);
    }

    // Update!
    const auto& now = std::chrono::steady_clock::now();
    const auto timeSinceLastUpdate = std::chrono::duration_cast<std::chrono::microseconds>(now - lastUpdate_);
    for(auto& particle : particles_) {
        particle.update(timeSinceLastUpdate.count());
    }
    lastUpdate_ = now;
}

std::vector<ofVec3f> ParticleSystem::positions() {
    std::vector<ofVec3f> v;
    for(const auto& particle : particles_) {
        const auto& pos = particle.position_;
        v.push_back( ofVec3f(static_cast<double>(kWorldScale * pos.i()), static_cast<double>(kWorldScale * pos.j()), static_cast<double>(kWorldScale * pos.k())) );
    }
    return v;
}