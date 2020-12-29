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
	j["name"] = "Ivan";
	j["surname"] = "Ivanov";
	j["age"] = 32;
	j["adr"] = { {"city", "Minsk"}, {"streetAddress", "Pushkina, 11"} };
	
	std::vector<Person> persons;
	persons.resize(3);
	persons.at(0) = j.get<Person>();
	j["name"] = "Misha";
	persons.at(1) = j.get<Person>();
	j["name"] = "Maksim";
	persons.at(2) = j.get<Person>();

	json j_vec(persons);

	try {
		std::ifstream inpt("file.json");
		if (!inpt) {
			
			//inpt >> j;
			//std::cout << j << std::endl << std::endl;
			std::unique_ptr<std::vector<Person>> persons = PersonBuilder::getObject().createPersons(j_vec, BaseChecker());

			json j2;
			for (std::vector<Person>::iterator it = persons->begin(); it != persons->end(); ++it) {
				j2 = *it;
				std::cout << j2 << '\n';
			}
		}
		inpt.close();
	}
	catch (std::exception& exception)
	{
		std::cerr << exception.what() << '\n';
	}
	return 0;

	return 0;
}