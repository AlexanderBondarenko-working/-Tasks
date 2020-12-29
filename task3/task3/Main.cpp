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

	//Person p;
	//

	//json j;
	////Person p2;
	//std::vector<Person> persons;

	//j["name"] = "Ivan";
	//j["surname"] = "Ivanov";
	//j["age"] = 32;
	//j["adr"] = { {"city", "Minsk"}, {"streetAddress", "Pushkina, 11"} };
	//std::cout << j << std::endl << std::endl;

	//persons.resize(3);
	//persons.at(0) = j.get<Person>();
	//j["name"] = "Misha";
	//persons.at(1) = j.get<Person>();
	//j["name"] = "Maksim";
	//persons.at(2) = j.get<Person>();


	//json j_vec(persons);
	//std::cout << j_vec.size() << "  " << j.size() << std::endl;
	//std::cout << "jvec_obj " << j_vec.is_object() << " " << "jvec_arr " << j_vec.is_array() << " j_obj " << j.is_object() << " j_arr " << j.is_array() << std::endl;
	try {
		std::ifstream inpt("file.json");
		if (!inpt) {
			json j;
			std::string str;
			std::getline(inpt, str);
			std::cout << str;
			//inpt >> j;
			std::cout << j << std::endl;
			std::unique_ptr<std::vector<Person>> persons = PersonBuilder::getObject().createPersons(j, BaseChecker());

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