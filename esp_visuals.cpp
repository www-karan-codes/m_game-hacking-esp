#include "esp_visuals.hpp"
#include "esp.hpp"
#include "../ImGui/imgui.h"
#include "../GameFunctions/game_functions.hpp"

namespace gamehacking::esp::visuals
{
	void Draw(void)
	{
		ImGui::SetNextWindowPos({ 0, 0 });
		ImGui::SetNextWindowSize(gamehacking::game_functions::GetResolution());
		ImGui::Begin("esp", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBringToFrontOnFocus);

		auto imgui_draw_list = ImGui::GetWindowDrawList();

		auto& esp_information_data = gamehacking::esp::esp_information_data;

		for (auto& esp_information : esp_information_data)
		{
			imgui_draw_list->AddCircle(esp_information.projection_, 3, ImColor(255, 255, 0));
		}

		ImGui::End();
	}
}