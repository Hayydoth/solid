#pragma once

#include <map>
#include <string>

#include "Component.h"

class EntityState {
public:
	std::map<std::string, Component*> componentMap;

	EntityState(EntityState&&) = delete;
	EntityState(EntityState const&) = delete;
	EntityState& operator=(EntityState) = delete;

	EntityState() {}

};
class EntityLogic {
public:

	static void Start(EntityState* e) {
		for (auto pair : e->componentMap) {
			pair.second->Start();
		}
	}
	static void Update(EntityState* e) {
		for (auto pair : e->componentMap) {
			pair.second->Update();
		}
	}

	template<typename T>
	static void AddComponent(EntityState* e) {
		static_assert(std::is_base_of<Component, T>::value);
		if (!e->componentMap.count(typeid(T).name())) {
			e->componentMap[typeid(T).name()] = new T();
		}
	}

	template<typename T>
	static void RemoveComponent(EntityState* e) {
		static_assert(std::is_base_of<Component, T>::value);
		if (e->componentMap.count(typeid(T).name())) {
			delete e->componentMap[typeid(T).name()];
			e->componentMap.erase(typeid(T).name());
		}
	}

	template<typename T>
	static T* GetComponent(EntityState* e) {
		static_assert(std::is_base_of<Component, T>::value);
		if (e->componentMap.count(typeid(T).name())) {
			return dynamic_cast<T*>(e->componentMap[typeid(T).name()]);
		}
		return nullptr;
	}
};
