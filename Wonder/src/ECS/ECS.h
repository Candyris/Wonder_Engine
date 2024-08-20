#pragma once

#include "Entity.h"
#include "Component.h"
#include "System.h"
#include <unordered_map>
#include <vector>
#include <typeindex>
#include <memory>

class ECS
{
public:
	template<typename T>
	void addComponent(Entity entity, T component)
	{
		// auto is doing std::unordered_map<int, std::unique_ptr<Component>>& components 
		auto& components = m_ComponentMap[typeid(T)];
		// we check if this component is not there
		if (component.find(entity.getID()) == component.end())
		{
			components[entity.getID()] = std::make_unique<T>(component);
		}
	}
	template<typename T>
	T* getComponent(Entity entity)
	{
		// auto is doing std::unordered_map<int, std::unique_ptr<Component>>& components 
		auto& components = m_ComponentMap[typeid(T)];
		// we check if this component is there
		if (component.find(entity.getID()) == component.end())
		{
			return static_cast<T*>(component[entity.getID()].get());
		}
		return nullptr;
	}

	void update()
	{
		for (std::unique_ptr<System>& system : m_System)
		{
			system->update();
		}
	}


	template <typename T>
	void registerSystem(std::unique_ptr<System> system)
	{
		m_System.push_back(std::move(system));
	}

private:
	std::unordered_map<std::type_index, std::unordered_map<int, std::unique_ptr<Component>>> m_ComponentMap;
	std::vector<std::unique_ptr<System>> m_System;
};