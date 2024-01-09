#pragma once

#include <list>
#include "../Math/math.hpp"

namespace gamehacking::esp
{
	struct ESPInformation
	{
		gamehacking::math::Vector3D projection_;
		int team_;
	};

	extern std::list<ESPInformation> esp_information_data;

	void Tick(void);
}