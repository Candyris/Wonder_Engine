#pragma once

#include <unordered_map>
#include <typeindex>

class Entity
{
	Entity() : id(nextID++) {}

	int getID() const{ return id; }

private:
	int id;
	static int nextID;

};


