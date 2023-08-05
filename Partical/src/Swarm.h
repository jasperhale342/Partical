#include "Particle.h"

namespace particle {
	class Swarm
	{
	public:
		const static int NPARTICLE = 5000;

	private:
		Particle * m_pParticles;
		int lastTime;

	public:
		Swarm();
		virtual ~Swarm();
		const Particle* const getParticles() { return m_pParticles; }
		void update(int elapsed);
	};

}


