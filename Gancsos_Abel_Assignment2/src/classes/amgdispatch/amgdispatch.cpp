#include "amgdispatch.h"
namespace amgdispatch {

	/**
	 * This method prepares the system with the simulated data
	 * @precondition  (The instance of the object must exist)
	 * @postcondition (The simulated data has been created in memory)
	 * @todo Create these objects using an Abstract Factory.  
	 * There was no time in module 2 to redesign implementation
	 */
	void AMGDispatch::FillSimulatedData(){
		// Create customers
		vector<AMGCustomer *> customers;
		for(int i = 0; i < order_count; i++){
			AMGCustomer *temp = new AMGCustomer("Test" + to_string(i), "Customer", (rand() % 80 + 18));
			temp->SetDistance(rand() % order_count + 1);
			temp->SetBirthday(((rand() % 1) == 1 ? true : false));
			customers.push_back(temp);
		}

		// Create vehicles
		for(int i = 0; i < driver_count; i++){
			AMGVehicle *temp = new AMGVehicle("Vehicle" + to_string(i), ((rand() % 2 + 1) == 1 ? true : false));
			vehicles.push_back(temp);
		}

		// Create shops
		vector<AMGShop *> shops;
		for(int i = 0; i < shop_count; i++){
			// Add products to shops
			vector<AMGProduct *> store_products;
			for(int j = 0; j < product_count; j++){

				// Randomize the product type (food or flower)
				int temp_type = (rand() % 2 + 1);

				// Food
				if(temp_type == 1){
					// Randomize food type (hot or cold)
					int temp_type2 = (rand() % 3 == 0 ? 1 : 0);
					store_products.push_back(new AMGProductFood("Store" + to_string(i) + "Item" + to_string(j), (temp_type2 == 1 ? FOOD_TYPE::HOT : FOOD_TYPE::COLD)));
				}
				// Flower
				else if(temp_type == 2){
					store_products.push_back(new AMGProductFlowers("Store" + to_string(i) + "Item" + to_string(j)));
				}
			}
			shops.push_back(new AMGShop("Shop" + to_string(i), (rand() % shop_count + 1), store_products));
		}
		// Create orders
		for(int i = 0; i < order_count; i++){
			AMGOrder *temp = new AMGOrder();
			int rand_customer_index = (rand() % customers.size());
			temp->SetCustomer(customers[rand_customer_index]);
			customers.erase(customers.begin() + rand_customer_index);    

            AMGShop *temp_store = shops[(rand() % shops.size())];
	
		    // Add items to orders
			for(int j = 0; j < (rand() % 3 + 1); j++){
				AMGProduct *temp_product = temp_store->GetProducts()[(rand() % temp_store->GetProducts().size())];
				AMGItem *temp_item = new AMGItem(temp_product, (rand() % 5 + 1));
				temp->AddItem(temp_item);
			}

    	    // Add to orders collection
			orders.push_back(temp);
		}
	}

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
    AMGDispatch::AMGDispatch(){
        this->batchable = false;
		this->env = new AMGDispatchCentralSystem(high_traffic_count);
    }

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGDispatch::~AMGDispatch(){
		orders.clear();
		vehicles.clear();
        delete env;
    }

    /**
     * This method sets the mode to batchable
     * @param a Value to set for the flag
     * @precondition  (The instance of the object exists)
     * @postcondition (The value of the flag is set)
     */
    void AMGDispatch::SetBatchable(bool a){
        batchable = a;
    }

    /**
     * This method retrieves the batchable flag
     * @return        (Value of the flag)
     * @precondition  (The instance of the object exists)
     * @postcondition (The value of the flag is returned)
     */
    bool AMGDispatch::GetBatchable(){
        return batchable;
    }

    /**
     * This method is the main entry to the controller and prepares the session
     * @precondition  (The instance of the object exists)
     * @postcondition (The patron is prompted or the operations are ran in batch mode)
     */
    void AMGDispatch::AMGDispatch::Run(){
        FillSimulatedData();

		// Register the vehicles as observers
		for(AMGVehicle *cursor : vehicles){
			this->env->RegisterObserver(new AMGVehicleObserver(cursor));			
		}
		env->SetOrders(orders);
    }
}