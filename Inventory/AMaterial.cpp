#include "AMaterial.h"
#include <iostream>

#define DMaxCapacity 1000


AMaterial::AMaterial(const MaterialType Type, const size_t Quantity, const std::string Name,
	const std::string Description, const std::string Icon)
	: mType(Type), mName(Name), mDescription(Description), mIcon(Icon), mCapacity(DMaxCapacity)
{
	if (Quantity > mCapacity)
	{
		std::string str = std::string("Max Capacity for ")+ mName + " is a " + std::to_string(DMaxCapacity); // exception from constructor hmmmmmm ?????
		throw str;

	}
	else
	{
		mQuantity = Quantity;
	}
}

size_t AMaterial::SetMaterial(const size_t& Quantity)
{
	if (mCapacity - mQuantity >= Quantity)
	{
		mQuantity += Quantity;
		return 0;
	}
	else
	{
		mQuantity += mCapacity - mQuantity;
		return Quantity - (mCapacity - mQuantity);
	}
}

size_t AMaterial::GetMaterial(const size_t& Quantity)
{
	if (mQuantity - Quantity >= 0)
	{
		mQuantity -= Quantity;
		return Quantity;
	}

	throw std::string("Not a lot of materials"); 
}


size_t AMaterial::GetMaterial()
{
	size_t TempQuantity = mQuantity;
	mQuantity = 0;
	return TempQuantity;
}

size_t AMaterial::GetEmptyPlace()
{
	return mCapacity - mQuantity;
}

void AMaterial::ResetMaterialQuantity()
{
	mQuantity = 0;
}


size_t AMaterial::GetCapacity()
{
	return mCapacity;
}

size_t AMaterial::GetQuantity()
{
	return mQuantity;
}

std::string AMaterial::GetName()
{
	return mName;
}

std::string AMaterial::GetDescription()
{
	return mDescription;
}

std::string AMaterial::GetIcon()
{
	return mIcon;
}

size_t AMaterial::GetCapacity() const
{
	return mCapacity;
}

size_t AMaterial::GetQuantity() const
{
	return mQuantity;
}

MaterialType AMaterial::GetType() const
{
	return mType;
}

std::string AMaterial::GetName() const
{
	return mName;
}

std::string AMaterial::GetDescription() const
{
	return mDescription;
}

std::string AMaterial::GetIcon() const
{
	return mIcon;
}

void AMaterial::HelperPrintAll()
{
	std::cout << "Material Name: " << mName << std::endl;
	std::cout << "Material Description: " << mDescription << std::endl;
	std::cout << "Material Icon: " << mIcon << std::endl;
	std::cout << "Material Type: " << MaterialIdentifier(mType) << std::endl;
	std::cout << "Material Quantity: " << mQuantity << std::endl;
	std::cout << "Material Capacity: " << mCapacity << std::endl;
	std::cout << "\n";

}

std::string AMaterial::MaterialIdentifier(MaterialType type)
{

	switch (type)
	{
	case MaterialType::Gold:
		return "Gold";
	case MaterialType::Silver:
		return "Silver";
	case MaterialType::Metal:
		return "Metal";
	default:
		return "No kinde of Material";
	}

	return "No kinde of Material";

}
