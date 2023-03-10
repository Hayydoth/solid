#pragma once
#include <string>
class Component
{
public:
	virtual void Start() {};
	virtual void Update() {};

	Component(Component&&) = delete;
	Component(Component const&) = delete;
	Component& operator=(Component) = delete;

	Component() {}

	friend class Entity;
};