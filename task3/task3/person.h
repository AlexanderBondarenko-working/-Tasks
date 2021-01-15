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

	public:
		Person();
		Person(std::string& name, std::string& surname, int age, Address& adr);
		std::string getName() const;
		std::string getSurname() const;
		int getAge() const;
		const Address* getAdr() const;
		friend void to_json(json& j, const Person& p);
		friend void from_json(const json& j, Person& p);
		friend class PersonBuilder;
	};

#endif //TASK3_PERSON_H_ 