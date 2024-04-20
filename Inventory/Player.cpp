#include "Player.h"
#include <iostream>

Player::Player(std::string Name) : mName(Name), mID(mIDCounter), mMaterial(nullptr)
{
	++mIDCounter;
}

size_t Player::mIDCounter = 0;

void Player::TakeMaterial(AMaterial* Material)
{
	if (Material != nullptr)
	{
		mMaterial = new AMaterial(*Material); 
		Material->ResetMaterialQuantity();
	}
	else
		throw std::string("The argument is nullptr"); // Throw exception 
}

void Player::TakeMaterial(AMaterial* Material, const size_t Quantity)
{
	if (Material != nullptr)
	{
		auto Value = Material->GetMaterial(Quantity);
		if (mMaterial == nullptr)
		{
			mMaterial = new AMaterial(Material->GetType(), Quantity, Material->GetName(), Material->GetDescription(), Material->GetIcon());
		}
		else
		{
			if (mMaterial->GetType() == Material->GetType())
			{
				mMaterial->SetMaterial(Quantity);
			}
			else
			{
				throw std::string("The player can hold onlye one type of material in the same time");
			}
		}

	}
	else
		throw std::string("The argument is nullptr"); // Throw exception 


}

void Player::SetToWerehouse(Warehouse* Inventory)
{
	if (!Inventory->isFull())
	{
		if (mMaterial != nullptr)
		{
			Inventory->SetMaterial(new AMaterial(*mMaterial));
			delete mMaterial;
			mMaterial = nullptr;
		}
		else
		{
			throw std::string("The player holds nothing");
		}
	}
	else
		throw std::string("No place in the warehouse");; // throw exception

}

AMaterial* Player::GetMaterialCopyInstance()
{
	return new AMaterial(*mMaterial);
}

// Send materials to another Warehouse

void Player::SMToAnotherWarehouse(Warehouse* From, Warehouse* To, const MaterialType& Type, size_t Quantity = 0)
{

	if (From == nullptr && From->isEmpty())
	{
		throw "The parameter is nullptr";
	}
	else
	{
		auto TempMaterial = From->GetMaterial(Type, Quantity);
		if (TempMaterial != nullptr)
			To->SetMaterial(TempMaterial);
		else
			throw std::string();
	}

}