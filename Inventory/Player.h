#pragma once

#include "Warehouse.h"



class Player
{
private:
	size_t mID;
	std::string mName;
	AMaterial* mMaterial;
	static size_t mIDCounter;


public:
	Player(std::string);
	void TakeMaterial(AMaterial*);
	void TakeMaterial(AMaterial*, const  size_t);
	void SetToWerehouse(Warehouse*);
	AMaterial* GetMaterialCopyInstance();
	void SMToAnotherWarehouse(Warehouse*, Warehouse*, const MaterialType&, size_t); // Send materials to another werehouse

	
};

