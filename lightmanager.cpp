#include "lightmanager.h"
#include "shader.h"
#include <glm/glm.hpp>

void LightManager::initLights() {
    // Initialize point lights
    pointLights.push_back(Light(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f), 1.0f));
    pointLights.push_back(Light(glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(1.0f), 1.0f));
    // Initialize other lights
    directionalLight = Light(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f), 0.8f);
    spotlight = Light(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f), 1.0f);
}

void LightManager::renderLights(Shader& shader) {
    // Point Lights
    for (size_t i = 0; i < pointLights.size(); i++) {
        shader.setVec3("pointLights[" + std::to_string(i) + "].position", pointLights[i].position);
        shader.setVec3("pointLights[" + std::to_string(i) + "].color", pointLights[i].color);
        shader.setFloat("pointLights[" + std::to_string(i) + "].intensity", pointLights[i].intensity);
    }
    // Directional Light
    shader.setVec3("directionalLight.position", directionalLight.position);
    shader.setVec3("directionalLight.color", directionalLight.color);
    shader.setFloat("directionalLight.intensity", directionalLight.intensity);
    // Spotlight
    shader.setVec3("spotlight.position", spotlight.position);
    shader.setVec3("spotlight.color", spotlight.color);
    shader.setFloat("spotlight.intensity", spotlight.intensity);
}

void LightManager::togglePointLights() {
    // Toggle point lights on/off
    for (auto& light : pointLights) {
        light.intensity = (light.intensity == 0.0f) ? 1.0f : 0.0f;
    }
}

void LightManager::toggleDirectionalLight() {
    directionalLight.intensity = (directionalLight.intensity == 0.0f) ? 0.8f : 0.0f;
}

void LightManager::toggleSpotlight() {
    spotlight.intensity = (spotlight.intensity == 0.0f) ? 1.0f : 0.0f;
}
