namespace particle {
	struct Particle
	{
	
	double m_x; // want to be able to change position gradually 
	double m_y;
	double m_speed;
	double m_direction;

	Particle();
	void init();
	virtual ~Particle();
	void update(int interval);
	
	};
}


