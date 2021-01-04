#include <iostream>
#include <nlohmann/json.hpp>
#include "person.h"
#include "address.h"
#include <string>
#include "person.h"
#include "toandfromjson.h"
#include <vector>
#include <fstream>
#include <exception>
#include "personbuilder.h"



int main() {

	json j;

	try {
		std::ifstream inpt("file.json");
		if (inpt.is_open()) {
			
			json j = json::parse(inpt);
		
			std::unique_ptr<std::vector<Person>> persons = PersonBuilder::getObject().createPersons(j, BaseChecker());

			for (std::vector<Person>::iterator it = persons->begin(); it != persons->end(); ++it) {
				j = *it;
				std::cout << j << '\n';
			}
		}
		inpt.close();
	}
	catch (std::exception& exception)
	{
		std::cerr << exception.what() << '\n';
	}

	return 0;
}
//[{"adr":{"city":"Minsk", "streetAddress" : "Pushkina, 11"}, "age" : 32, "name" : "Ivan", "surname" : "Ivanov"}, { "adr":{"city":"Minsk","streetAddress" : "Pushkina, 11"},"age" : 32,"name" : "Misha","surname" : "Ivanov" }, { "adr":{"city":"Minsk","streetAddress" : "Pushkina, 11"},"age" : 32,"name" : "Ivan","surname" : "Ivanov" }]