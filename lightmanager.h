#ifndef LIGHTMANAGER_H
#define LIGHTMANAGER_H

#include <glm/glm.hpp>
#include <vector>

class Light {
public:
    glm::vec3 position;
    glm::vec3 color;
    float intensity;
    Light(glm::vec3 pos, glm::vec3 col, float intens)
        : position(pos), color(col), intensity(intens) {}
};

class LightManager {
public:
    void initLights();
    void renderLights(Shader& shader);
    void togglePointLights();
    void toggleDirectionalLight();
    void toggleSpotlight();

private:
    std::vector<Light> pointLights;
    Light directionalLight;
    Light spotlight;
};

#endif
