#pragma once
#include "box.h"
#include "gameobject.h"
#include <sgg/graphics.h>
#include <string>

class Player : public GameObject, public Box
{
    graphics::Brush m_brush_player;
    std::vector<std::string> m_sprites;

    const float m_gravity = 10.0f;
    const float m_accel_vertical = 200.0f;
    const float m_accel_horizontal = 40.0f;
    const float m_max_velocity = 10.0f;

    void movePlayer(float dt);

public:
    float m_vx = 0.0f;
    float m_vy = 0.0f;

    void update(float dt) override;
    void init() override;
    void draw() override;
    Player(std::string name) :GameObject(name) {}

protected:
    void debugDraw();
};

