#include "address.h"

std::string Address::getCity() const{
	return city;
}

std::string Address::getStreetAddress() const{
	return streetAddress;
}

Address::Address(std::string& city, std::string& streetAddress) {
	this->city = city;
	this->streetAddress = streetAddress;
}

Address::Address(){}