#pragma once
#include <string>


enum class MaterialType
{
	Gold,
	Silver,
	Metal
};


class AMaterial
{
private:
	MaterialType mType;
	size_t mCapacity;
	size_t mQuantity;
	std::string mName;
	std::string mDescription;
	std::string mIcon;

public:

	AMaterial(const MaterialType Type, const size_t Quantity = 0, const std::string Name = "No Name", const std::string Description = "No Description", const std::string Icon = "No Icon");
	//AMaterial(const AMaterial&); // default constturctor working fine in our case 
	size_t SetMaterial(const size_t& Quantity);
	size_t GetMaterial(const size_t& Quantity);

	size_t GetMaterial();
	size_t GetEmptyPlace();
	void ResetMaterialQuantity();

	size_t GetCapacity();
	size_t GetQuantity();
	std::string GetName();
	std::string GetDescription();
	std::string GetIcon();


	// consts 

	size_t GetCapacity() const;
	size_t GetQuantity()const;
	MaterialType GetType()const;
	std::string GetName()const;
	std::string GetDescription()const;
	std::string GetIcon()const;

	
	void HelperPrintAll();
	std::string MaterialIdentifier(MaterialType type);




};

