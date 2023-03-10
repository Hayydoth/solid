#pragma once

#include "Entity.h"

class Scene
{
public:
	std::map<std::string, Entity*> entities;
	void Start() {
		for (auto pair : entities) {
			pair.second->Start();
		}
	}
	void Update() {
		for (auto pair : entities) {
			pair.second->Update();
		}
	}

	void AddEntity(std::string name) {
		if (!entities.count(name)) {
			entities[name] = new Entity();
		}
	}

	void RemoveEntity(std::string name) {
		if (entities.count(name)) {
			delete entities[name];
			entities.erase(name);
		}
	}

	Entity* GetEntity(std::string name) {
		if (entities.count(name)) {
			return entities[name];
		}
		return nullptr;
	}
};
