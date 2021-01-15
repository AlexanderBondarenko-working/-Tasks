#include "pch.h"
#include "CppUnitTest.h"
#include "../task3/abstractchecker.h"
#include "../task3/BaseChecker.h"
#include "../task3/address.h"
#include "../task3/person.h"
#include "../task3/personbuilder.h"
#include "../task3/toandfromjson.h"
#include "../include/nlohmann/json.hpp"
#include <string>
#include <stdio.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTask3
{
	TEST_CLASS(Person_tests)
	{
	public:
		
		TEST_METHOD(to_json_ComparisonOfEntryAndExit_EqualJsons)
		{
			nlohmann::json j1;
			j1["name"] = "Ivan";
	        j1["surname"] = "Ivanov";
	        j1["age"] = 32;
	        j1["adr"] = { {"city", "Minsk"}, {"streetAddress", "Pushkina, 11"} };
			
			Person p(std::string("Ivan"), std::string("Ivanov"), 32, Address(std::string("Minsk"), std::string("Pushkina, 11")));
			nlohmann::json j2 = p;
			
			Assert::IsTrue(j1 == j2, L"Incorrect convert to json");
		}

		TEST_METHOD(from_json_ComparisonOfEntryAndExit_EqualJsons)
		{
			nlohmann::json j1;
			j1["name"] = "Ivan";
			j1["surname"] = "Ivanov";
			j1["age"] = 32;
			j1["adr"] = { {"city", "Minsk"}, {"streetAddress", "Pushkina, 11"} };

			Person p = j1.get<Person>();
			nlohmann::json j2;
			j2["name"] = p.getName();
			j2["surname"] = p.getSurname();
			j2["age"] = p.getAge();
			j2["adr"] = { {"city", p.getAdr()->getCity()}, {"streetAddress", p.getAdr()->getStreetAddress()} };

			Assert::IsTrue(j1 == j2, L"Incorrect convert from json");
		}

		TEST_METHOD(from_json_ProvidingOfIncorrectJson_Exeption)
		{
			nlohmann::json j;
			j["nname"] = "Ivan"; //error
			j["surname"] = "Ivanov";
			j["age"] = 32;
			j["adr"] = { {"city", "Minsk"}, {"streetAddress", "Pushkina, 11"} };
			std::string exepString;

			try {
				Person p = j.get<Person>();
				nlohmann::json j2;
			}

			catch (std::exception& exception)
			{
				exepString = exception.what();
			}

			Assert::IsTrue((exepString.length() != 0), L"No exception");
		}
	};

	TEST_CLASS(Address_tests)
	{
	public:

		TEST_METHOD(to_json_ComparisonOfEntryAndExit_EqualJsons)
		{
			/*j.at("city").get_to(adr.city);
			j.at("streetAddress").get_to(adr.streetAddress);*/
			nlohmann::json j1;
			j1["city"] = "Minsk";
			j1["streetAddress"] = "Pushkina, 11";

			Address adr(std::string("Minsk"), std::string("Pushkina, 11"));
			nlohmann::json j2 = adr;

			Assert::IsTrue(j1 == j2, L"Incorrect convert to json");
		}

		TEST_METHOD(from_json_ComparisonOfEntryAndExit_EqualJsons)
		{
			nlohmann::json j1;
			j1["city"] = "Minsk";
			j1["streetAddress"] = "Pushkina, 11";

			Address adr = j1.get<Address>();
			nlohmann::json j2;
			j2["city"] = adr.getCity();
			j2["streetAddress"] = adr.getStreetAddress();

			Assert::IsTrue(j1 == j2, L"Incorrect convert from json");
		}

		TEST_METHOD(from_json_ProvidingOfIncorrectJson_Exeption)
		{
			nlohmann::json j;
			j["ccity"] = "Minsk"; //error
			j["streetAddress"] = "Pushkina, 11";
			std::string exepString;

			try {
				Person p = j.get<Person>();

			}

			catch (std::exception& exception)
			{
				exepString = exception.what();
			}

			Assert::IsTrue((exepString.length() != 0), L"No exception");
		}
	};

	TEST_CLASS(BaseChecker_tests)
	{
	public:

		TEST_METHOD(checkJSON_ProvidingSuitableJson_True)
		{
			BaseChecker bch;
			nlohmann::json j;
			j["name"] = "Ivan";
			j["surname"] = "Ivanov";
			j["adr"] = { {"city", "Minsk"}, {"streetAddress", "Pushkina, 11"} };

			
			j["age"] = 32;
			Assert::IsTrue((bch.checkJSON(j)), L"Expected true but received false");

			j["age"] = 0;
			Assert::IsTrue((bch.checkJSON(j)), L"Expected true but received false");

			j["age"] = 130;
			Assert::IsTrue((bch.checkJSON(j)), L"Expected true but received false");
			
		}

		TEST_METHOD(checkJSON_ProvidingAnSuitableJson_False)
		{
			BaseChecker bch;
			nlohmann::json j;
			j["name"] = "Ivan";
			j["surname"] = "Ivanov";
			j["adr"] = { {"city", "Minsk"}, {"streetAddress", "Pushkina, 11"} };

			j["age"] = -1;
			Assert::IsTrue(!(bch.checkJSON(j)), L"Expected false but received true");

			j["age"] = 131;
			Assert::IsTrue(!(bch.checkJSON(j)), L"Expected false but received true");

		}

		TEST_METHOD(checkJSON_ProvidingOfIncorrectAgeInJson_Exeption)
		{
			nlohmann::json j;
			j["name"] = "Ivan";
			j["surname"] = "Ivanov";
			j["adr"] = { {"city", "Minsk"}, {"streetAddress", "Pushkina, 11"} };
			j["aage"] = 32;//error
			std::string exepString;
			BaseChecker bch;

			try {
				bch.checkJSON(j);

			}

			catch (std::exception& exception)
			{
				exepString = exception.what();
			}

			Assert::IsTrue((exepString.length() != 0), L"No exception");
		}

	};

	TEST_CLASS(PersonBuilder_tests)
	{
	public:
		TEST_METHOD(GetObject_GetObject_PointerNotNull) {
			Assert::IsTrue((&PersonBuilder::getObject() != nullptr), L"nullptr");
		}

		TEST_METHOD(createPersons_ProvidingJsonOfArrayAndChecker_VectorOfPersons) {
			nlohmann::json j = "[{\"adr\":{\"city\":\"Minsk\", \"streetAddress\" : \"Pushkina, 11\"}, \"age\" : 32, \"name\" : \"Ivan\", \"surname\" : \"Ivanov\"},\
                                {\"adr\":{\"city\":\"Minsk\",\"streetAddress\" : \"Pushkina, 11\"},\"age\" : 32,\"name\" : \"Misha\",\"surname\" : \"Ivanov\" },\
                                {\"adr\":{\"city\":\"Minsk\",\"streetAddress\" : \"Pushkina, 11\"},\"age\" : 32,\"name\" : \"Ivan\",\"surname\" : \"Ivanov\" }]"_json;
			
			Assert::IsTrue((PersonBuilder::getObject().createPersons(j, BaseChecker())->size() == 3), L"Incorrect voctor of persons");


		}

		TEST_METHOD(createPersons_ProvidingJsonOfObjectAndChecker_VectorOfPersonsWith_1_Elements) {
			nlohmann::json j;
			j["name"] = "Ivan";
			j["surname"] = "Ivanov";
			j["age"] = 32;
			j["adr"] = { {"city", "Minsk"}, {"streetAddress", "Pushkina, 11"} };

			Assert::IsTrue((PersonBuilder::getObject().createPersons(j, BaseChecker())->size() == 1), L"Incorrect voctor of persons");

		}
	};
}
