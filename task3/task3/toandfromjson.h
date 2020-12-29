#ifndef TASK3_TOANDFROMJSON_H_ 
#define TASK3_TOANDFROMJSON_H_ 

void to_json(json& j, const Address& adr) {
	j = json{ {"city", adr.city}, {"streetAddress", adr.streetAddress} };
}

void from_json(const json& j, Address& adr) {
	j.at("city").get_to(adr.city);
	j.at("streetAddress").get_to(adr.streetAddress);
}

void to_json(json& j, const Person& p) {
	j = json{ {"name", p.name}, {"surname", p.surname}, {"age", p.age}, {"adr", p.adr} };
}

void from_json(const json& j, Person& p) {
	j.at("name").get_to(p.name);
	j.at("surname").get_to(p.surname);
	j.at("age").get_to(p.age);
	j.at("adr").get_to(p.adr);
}

#endif //TOANDFROMJSON