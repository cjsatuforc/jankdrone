#pragma once

#include <vector>
#include <Servo.h>
#include "shm.h"

class Thrust {
	public:
		Thrust();
		void operator()();

	private:
		class Thruster {
			public:
				Thruster(int pin, Shm::Var* thrustValue);
				void operator()(); // Thrust value from shm
				void operator()(float thrustValue); // Thrust this value

			private:
				Servo m_esc;
				Shm::Var* m_thrustValue;

				void thrustNoKillCheck(float thrustValue);
		};

		std::vector<Thruster> m_thrusters;
};
