#include "condimentsugar.h"

/**
 * This is the default constructor
 * @precondition  (There is a need for a new instance of the class)
 * @postcondition (A new instance of the object is created)
 */
CondimentSugar::CondimentSugar(){
    quantity = 1;
}

/**
 * This is the common constructor
 * @param a Value to use for the quantity field
 * @precondition  (There is a need for a new instance of the class)
 * @postcondition (A new instance of the object is created)
 */
CondimentSugar::CondimentSugar(int a){
	quantity = a;
}

/**
 * This is the deconstructor
 * @precondition  (The instance of the class is no longer needed)
 * @postcondition (The instance is removed from memory)
 */
CondimentSugar::~CondimentSugar(){
}

/**
 * This method returns the object as a string representation
 * @return        (A string representation of the object)
 * @precondition  (The instance exists)
 * @postcondition (The string representation of the class is returned)
 */
string CondimentSugar::ToString(){
    return (GetType() + "(" + to_string(quantity) + ")");
}

/**
 * This method returns the type of the instance
 * @return        (Type name of the instance)
 * @precondition  (The instance exists)
 * @postcondition (The type name is returned)
 */
string CondimentSugar::GetType(){
    return "Sugar";
}
