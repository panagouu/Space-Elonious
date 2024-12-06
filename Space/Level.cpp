#include "Level.h"
#include "GameState.h"
#include "Player.h"

Level::Level(const std::string& name)
{
}

void Level::update(float dt)
{
	if (m_state->getPlayer()->isActive())
	{
		m_state->getPlayer()->update(dt);
	}

	GameObject::update(dt);
}

void Level::init()
{
	m_brush_back.outline_opacity = 0.0f;
	m_brush_back.texture = m_state-> getFullAssetPath("background4.png");

	for (auto p : m_static_objects) 
	{
		if (p) { p->init(); }
	}

	for (auto p : m_dynamic_objects)
	{
		if (p) { p->init(); }
	}
}

void Level::draw()
{
	float w = m_state-> getCanvasWidth();
	float h = m_state-> getCanvasHeight();

	float offset_x = m_state->m_global_offset_x + w / 2.0f;
	float offset_y = m_state->m_global_offset_y + h / 2.0f;

	graphics::drawRect(offset_x, offset_y, w * 4.0f, h * 2.0f, m_brush_back);

	if (m_state->getPlayer()->isActive())
	{
		m_state->getPlayer()->draw();
		m_state->getPlayer()->drawHealth();
	}

	if (m_state->getWeapon()->isActive())
	{
		m_state->getWeapon()->draw();
	}

	for (auto p : m_static_objects)
	{
		if (p) { p->draw(); }
	}

	for (auto p : m_dynamic_objects)
	{
		if (p) { p->draw(); }
	}


}

Level::~Level()
{
	for (auto p : m_static_objects)
	{
		if (p) { delete p; }
	}

	for (auto p : m_dynamic_objects)
	{
		if (p) { delete p; }
	}
}
