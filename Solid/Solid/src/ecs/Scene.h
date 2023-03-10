#pragma once

#include "Entity.h"

class SceneState {
public:
	std::map<std::string, EntityState*> entities;
};

class SceneLogic {
public:
	static void Start(SceneState* scene) {
		for (auto pair : scene->entities) {
			EntityLogic::Start(pair.second);
		}
	}
	static void Update(SceneState* scene) {
		for (auto pair : scene->entities) {
			EntityLogic::Update(pair.second);
		}
	}

	static void AddEntity(SceneState* scene, std::string name) {
		if (!scene->entities.count(name)) {
			scene->entities[name] = new EntityState();
		}
	}

	static void RemoveEntity(SceneState* scene, std::string name) {
		if (scene->entities.count(name)) {
			delete scene->entities[name];
			scene->entities.erase(name);
		}
	}

	static EntityState* GetEntity(SceneState* scene, std::string name) {
		if (scene->entities.count(name)) {
			return scene->entities[name];
		}
		return nullptr;
	}
};
