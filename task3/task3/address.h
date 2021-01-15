#ifndef TASK3_ADDRESS_H_ 
#define TASK3_ADDRESS_H_ 

#include <string>
#include "nlohmann/json.hpp"
using nlohmann::json;

class Address {
	std::string city;
	std::string streetAddress;
public:
	Address(std::string& city, std::string& streetAddress);
	Address();
	std::string getCity() const;
	std::string getStreetAddress() const;
	friend void to_json(json& j, const Address& adr);
	friend void from_json(const json& j, Address& adr);
};

#endif //TASK3_ADRESS_H_