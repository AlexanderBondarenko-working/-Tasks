#ifndef TASK3_PERSON_H_ 
#define TASK3_PERSON_H_ 

#include <string>
#include "address.h"
#include "nlohmann/json.hpp"

using nlohmann::json;

	class Person {
		std::string name;
		std::string surname;
		int age;
		Address adr;


		friend void to_json(json& j, const Person& p);
		friend void from_json(const json& j, Person& p);
		friend class PersonBuilder;
	};

#endif //TASK3_PERSON_H_ 