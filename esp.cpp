#include "esp.hpp"
#include <list>
#include "../GameFunctions/game_functions.hpp"
#include "../BaseStructures/base_structures.hpp"

namespace gamehacking::esp
{
	std::list<ESPInformation> esp_information_data;

	void Tick(void)
	{
		esp_information_data.clear();
		for (auto& player : gamehacking::base_structures::players)
		{
			if (gamehacking::math::Vector3D::IsInFieldOfView(gamehacking::base_structures::my_player.location_, gamehacking::base_structures::my_player.forward_, player.location_))
			{
				ESPInformation esp_information;
				esp_information.projection_ = gamehacking::game_functions::Project(player.location_);
				esp_information.team_ = player.team_;
				esp_information_data.push_back(esp_information);
			}

		}
	}
}