#include "Swarm.h"


namespace particle {
	Swarm::Swarm(): lastTime(0){
		m_pParticles = new Particle[NPARTICLE];
	}
	Swarm::~Swarm() {
		delete[] m_pParticles;
	}

	void Swarm::update(int elapsed){
		int interval = elapsed - lastTime;
		for (int i = 0; i < Swarm::NPARTICLE; i++) {
			m_pParticles[i].update(interval);
		}

		lastTime = elapsed;
	
	}
}
