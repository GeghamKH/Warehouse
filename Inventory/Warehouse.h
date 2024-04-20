#pragma once
#include <string>
#include <unordered_map>
#include "AMaterial.h"

class AMaterial;


class Warehouse
{
private:
	static size_t mIDCounter;
	const size_t mId;
	const std::string mName;
	size_t mSize;
	size_t mCapacity;

	std::unordered_map<MaterialType, std::vector<AMaterial*>> mWarehouse;


public:
	Warehouse(std::string Name);
	void Information();
	void SetMaterial(AMaterial * Material);
	AMaterial* GetMaterial(MaterialType Type, size_t Quantity);
	bool isEmpty();
	bool isFull();
	~Warehouse();
};

