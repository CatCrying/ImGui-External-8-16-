#include <iostream>
#include <vector>
#include <memory>
#include "{64}MemoryTools.h"
#include "Graphics/Renderer.hpp"
#include "ImGui/imgui.h"
#include "dependencies/Touch.hpp"


int main() {
int gs;
void *jg;
FILE *fp;
char ch, wjm[51];


char packageName[] = "com.gta.real.gangster.crime.two";  //Your game package name
    //char modeRoot[] = "MODE_ROOT"; 
    char modeNoRoot[] = "MODE_ROOT";
    initXMemoryTools(packageName, modeNoRoot);

auto renderer = std::make_unique<Renderer>();
auto displayInfo = renderer->getDisplayInfo();
if (!renderer->init()) {
    return 1;
}
bool is_running = true;
while (is_running) {
    renderer->beginFrame();
    static bool feature_on = false;
    if (ImGui::Begin("Main Menu")) {
        ImGui::Text("Control Panel");
        ImGui::Separator();
        ImGui::Checkbox("Enable Function", &feature_on);
        if (feature_on) {
            //ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "Status: Working...");
            SetSearchRange(CODE_APP); 
            MemorySearch("1.12",TYPE_FLOAT);
            MemoryOffset("-0.50283700228",4,TYPE_FLOAT);
            MemoryOffset("-0.1019269824",16,TYPE_FLOAT);
            MemoryWrite("0.3",0,TYPE_FLOAT);
            ClearResults();
        } else {
            SetSearchRange(CODE_APP); 
            MemorySearch("0.3",TYPE_FLOAT);
            MemoryOffset("-0.50283700228",4,TYPE_FLOAT);
            MemoryOffset("-0.1019269824",16,TYPE_FLOAT);
            MemoryWrite("",0,TYPE_FLOAT);
            ClearResults();
            //ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Status: Stopped");
        }
        ImGui::Separator();
        ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.8f, 0.1f, 0.1f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 0.2f, 0.2f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.5f, 0.1f, 0.1f, 1.0f));
        if (ImGui::Button("Kill Menu", ImVec2(-1.0f, 40.0f))) {
            is_running = false;
        }
        ImGui::PopStyleColor(3);
    }
    ImGui::End();
    renderer->endFrame();
}
return 0;
}