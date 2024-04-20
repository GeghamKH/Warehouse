#include <iostream>
#include "Warehouse.h"
#include "AMaterial.h"
#include "Player.h"


int main()
{
	try
	{
	Player PPlayer("Jack");
	Warehouse Inventory("MyInventory");
	Warehouse Inventory2("Second Inventory");

	// Materials 
	AMaterial Gold(MaterialType::Gold, 100, "Gold");
	AMaterial Silver(MaterialType::Silver, 200, "Silver");
	AMaterial Gold_2(MaterialType::Gold, 1000, "Gold");
	AMaterial Metal(MaterialType::Metal, 1000, "Metal");

	
		PPlayer.TakeMaterial(&Gold);
		PPlayer.SetToWerehouse(&Inventory); // 100 Gold 
	
		PPlayer.TakeMaterial(&Silver);
		PPlayer.SetToWerehouse(&Inventory); // 100 Gold and 200 Silver 
	
		PPlayer.TakeMaterial(&Gold_2);
		PPlayer.SetToWerehouse(&Inventory); // 1000 Gold, 100 Gold and 200 Silver

		//Inventory.Information();
		//Inventory2.Information();
		std::cout << "\n\n\n";


		PPlayer.SMToAnotherWarehouse(&Inventory, &Inventory2, MaterialType::Gold, 300); // MyInventory 800 Gould, 200 Silver  | Second inventory 300 Gould
		PPlayer.SMToAnotherWarehouse(&Inventory, &Inventory2, MaterialType::Silver, 200); // MyInventory 800 Gould  | Second inventory 300 Gould and 200 silver

		Inventory.Information(); 
		Inventory2.Information();
		std::cout << "\n\n\n";


		PPlayer.TakeMaterial(&Metal,500);
		PPlayer.SetToWerehouse(&Inventory);

		Inventory.Information();
		//std::cout << "\n\n\n";

		//Metal.HelperPrintAll();

		std::cout << "\n\n\n";

		PPlayer.TakeMaterial(&Metal, Metal.GetQuantity());
		PPlayer.SetToWerehouse(&Inventory2);

		Inventory2.Information();

	}
	catch (const std::string& str)
	{
		std::cout << str;	
	}


}