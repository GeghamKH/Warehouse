#include "Warehouse.h"
#include "AMaterial.h"

#include <iostream>
#include "Warehouse.h"

#define TemporaryCapacity 10


size_t Warehouse::mIDCounter = 0;

Warehouse::Warehouse(std::string Name) : mId(mIDCounter), mName(Name), mSize(0), mCapacity(TemporaryCapacity)
{

	++mIDCounter;
}

void Warehouse::Information()
{
	std::cout << "Was called void Werehouse::Information() for ID: " << mId << "  Name: " << mName << std::endl ;
	for (auto i : mWarehouse)
	{
		for (auto j : i.second)
		{
			j->HelperPrintAll();
		}
	}


}

void Warehouse::SetMaterial(AMaterial* Material)
{
	if (mWarehouse[Material->GetType()].empty())
	{
		mWarehouse[Material->GetType()].push_back(Material);
		mSize++;

	}
	else
	{
		std::vector<AMaterial*> MaterialVector = mWarehouse[Material->GetType()];
		AMaterial* TempMaterial = MaterialVector.back();

		if (TempMaterial->GetEmptyPlace() >= Material->GetQuantity())
		{
			TempMaterial->SetMaterial(Material->GetMaterial());
		}
		else
		{
			size_t CanBeAdd = TempMaterial->GetEmptyPlace();
			size_t NewMaterial = Material->GetMaterial() - CanBeAdd;

			TempMaterial->SetMaterial(CanBeAdd);
			mWarehouse[Material->GetType()].push_back(new AMaterial(Material->GetType(), NewMaterial, Material->GetName() + (char)MaterialVector.size(),
				Material->GetDescription() + (char)MaterialVector.size(), Material->GetIcon() + (char)MaterialVector.size()));
			mSize++;
		}
	}
}


AMaterial* Warehouse::GetMaterial(MaterialType Type, size_t Quantity)
{
	if (!mWarehouse[Type].empty())
	{
		if (Quantity < mWarehouse[Type].back()->GetCapacity())
		{
			//auto TmpVec = mWarehouse[Type];

			for (auto i = mWarehouse[Type].back(); i >= mWarehouse[Type].front(); --i)
			{
				if (i == mWarehouse[Type].front() && i->GetQuantity() < Quantity)
				{
					throw std::string("Not enough materials"); // or return nullptr 
				}
				else if (i->GetQuantity() >= Quantity)
				{
					size_t Value = i->GetMaterial(Quantity);
					if (i->GetQuantity() == 0)
					{
						auto LocalCopy = *mWarehouse[Type].back();
						mWarehouse[Type].pop_back();
						mSize--;
						return new AMaterial(Type, Value, LocalCopy.GetName(), LocalCopy.GetDescription(), LocalCopy.GetIcon());
					}
					return new AMaterial(Type, Value, mWarehouse[Type].front()->GetName(), mWarehouse[Type].front()->GetDescription(), mWarehouse[Type].front()->GetIcon());
				}
				else
				{
					size_t Value = i->GetMaterial(i->GetQuantity());
					mWarehouse[Type].pop_back();
					mSize--;

					if (mWarehouse[Type].empty())
						throw std::string("Not enough materials"); // or return nullptr 
					else
					{
						i = mWarehouse[Type].back();
						Value += i->GetMaterial(Quantity - Value);
						return new AMaterial(Type, Value, mWarehouse[Type].front()->GetName(), mWarehouse[Type].front()->GetDescription(), mWarehouse[Type].front()->GetIcon());
					}

				}
			}
		}
		else
			throw std::string("Requested materials exceed capacity"); // or return nullptr 
	}
	else
		throw std::string("Warehouse is empty"); // or return nullptr 
}

std::string Warehouse::GetName()
{
	return mName;
}

size_t Warehouse::EmptyPlaces()
{
	return mCapacity - mSize;
}


bool Warehouse::isEmpty()
{
	return mWarehouse.empty();
}

bool Warehouse::isFull()
{
	return mSize == mCapacity ? true : false;
}

Warehouse::~Warehouse()
{
	--mIDCounter;
}

