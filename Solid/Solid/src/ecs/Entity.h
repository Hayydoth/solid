#pragma once

#include <map>
#include <string>

#include "Component.h"

class Entity
{
private:
	Entity(Entity&&) = delete;
	Entity(Entity const&) = delete;
	Entity& operator=(Entity) = delete;

	std::map<std::string, Component*> componentMap;
	void Start() {
		for (auto pair : componentMap) {
			pair.second->Start();
		}
	}
	void Update() {
		for (auto pair : componentMap) {
			pair.second->Update();
		}
	}
	Entity() {}
	friend class Scene;
public:
	template<typename T>
	void AddComponent() {
		static_assert(std::is_base_of<Component, T>::value);
		if (!componentMap.count(typeid(T).name())) {
			componentMap[typeid(T).name()] = new T();
		}
	}

	template<typename T>
	void RemoveComponent() {
		static_assert(std::is_base_of<Component, T>::value);
		if (componentMap.count(typeid(T).name())) {
			delete componentMap[typeid(T).name()];
			componentMap.erase(typeid(T).name());
		}
	}

	template<typename T>
	T* GetComponent() {
		static_assert(std::is_base_of<Component, T>::value);
		if (componentMap.count(typeid(T).name())) {
			return dynamic_cast<T*>(componentMap[typeid(T).name()]);
		}
		return nullptr;
	}
};

