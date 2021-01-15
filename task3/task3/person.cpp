#include "person.h"

std::string Person::getName() const {
	return name;
}

std::string Person::getSurname() const {
	return surname;
}

int Person::getAge() const {
	return age;
}

const Address* Person::getAdr() const {
	return & adr;
}

Person::Person(){}

Person::Person(std::string& name, std::string& surname, int age, Address& adr) {
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->adr = adr;
}