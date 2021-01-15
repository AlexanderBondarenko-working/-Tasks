#include "pch.h"
#include "gmock/gmock.h"

#include "../task3/abstractchecker.h"
#include "../task3/BaseChecker.h"
#include "../task3/address.h"
#include "../task3/person.h"
#include "../task3/personbuilder.h"
#include "../task3/toandfromjson.h"
#include "../include/nlohmann/json.hpp"
#include <string>
#include <stdio.h>
#include <vector>

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

	TEST(Person, to_json_ComparisonOfEntryAndExit_EqualJsons) {
		// Arrange
		nlohmann::json j1;
		Person p(std::string("Ivan"), std::string("Ivanov"), 32, Address(std::string("Minsk"), std::string("Pushkina, 11")));
		nlohmann::json j2;

		// Act
		j1["name"] = "Ivan";
		j1["surname"] = "Ivanov";
		j1["age"] = 32;
		j1["adr"] = { {"city", "Minsk"}, {"streetAddress", "Pushkina, 11"} };

		j2 = p;

		// Assert
		ASSERT_EQ(j1, j2, "Incorrect convert to json");  //, L"Incorrect convert to json"
	}

	TEST(Person, from_json_ComparisonOfEntryAndExit_EqualJsons) {
		// Arrange
		nlohmann::json j1;
		nlohmann::json j2;

		// Act
		j1["name"] = "Ivan";
		j1["surname"] = "Ivanov";
		j1["age"] = 32;
		j1["adr"] = { {"city", "Minsk"}, {"streetAddress", "Pushkina, 11"} };

		Person p = j1.get<Person>();

		j2["name"] = p.getName();
		j2["surname"] = p.getSurname();
		j2["age"] = p.getAge();
		j2["adr"] = { {"city", p.getAdr()->getCity()}, {"streetAddress", p.getAdr()->getStreetAddress()} };

		// Assert
		ASSERT_EQ(j1, j2, L"Incorrect convert from json");
	}

	TEST(Person, from_json_ProvidingOfIncorrectJson_Exeption) {
		// Arrange
		nlohmann::json j;

		// Act
		j["nname"] = "Ivan"; //error
		j["surname"] = "Ivanov";
		j["age"] = 32;
		j["adr"] = { {"city", "Minsk"}, {"streetAddress", "Pushkina, 11"} };

		//Assert
		ASSERT_ANY_THROW(Person p = j.get<Person>());

	}


	TEST(Address, to_json_ComparisonOfEntryAndExit_EqualJsons)
	{
		//Arrange
		nlohmann::json j1;
		j1["city"] = "Minsk";
		j1["streetAddress"] = "Pushkina, 11";
		nlohmann::json j2;
        Address adr(std::string("Minsk"), std::string("Pushkina, 11"));

		//Act
		j2 = adr;

		//Assert
		ASSERT_EQ(j1, j2, L"Incorrect convert to json");
	}

	TEST(Address, from_json_ComparisonOfEntryAndExit_EqualJsons)
	{
		//Arrange
		nlohmann::json j1;
		j1["city"] = "Minsk";
		j1["streetAddress"] = "Pushkina, 11";
		nlohmann::json j2;
		Address adr;
			
		//Act
		adr  = j1.get<Address>();
		j2["city"] = adr.getCity();
		j2["streetAddress"] = adr.getStreetAddress();


		//Assert
		ASSERT_EQ(j1, j2, L"Incorrect convert from json");
	}

	TEST(Address, from_json_ProvidingOfIncorrectJson_Exeption)
	{
		//Arrange
		nlohmann::json j;
		j["ccity"] = "Minsk"; //error
		j["streetAddress"] = "Pushkina, 11";

		//Assert
		ASSERT_ANY_THROW(Person p = j.get<Person>());

	}

	class MockBaseChecker : public BaseChecker {
	public:
		MOCK_CONST_METHOD1(checkJSON, bool(const json& j));
	};

	TEST(PersonBuilder, checkJSON_ProvidingSuitableJson_True)
	{
		// Arrange
		nlohmann::json j;
		nlohmann::json j2 = "[{\"adr\":{\"city\":\"Minsk\", \"streetAddress\" : \"Pushkina, 11\"}, \"age\" : 32, \"name\" : \"Ivan\", \"surname\" : \"Ivanov\"},\
                                {\"adr\":{\"city\":\"Minsk\",\"streetAddress\" : \"Pushkina, 11\"},\"age\" : 32,\"name\" : \"Misha\",\"surname\" : \"Ivanov\" },\
                                {\"adr\":{\"city\":\"Minsk\",\"streetAddress\" : \"Pushkina, 11\"},\"age\" : 32,\"name\" : \"Ivan\",\"surname\" : \"Ivanov\" }]"_json;
		MockBaseChecker mockChecker;
		EXPECT_CALL(mockChecker, checkJSON(_))
			.Times(AtLeast(3))
			.WillRepeatedly(Return(true));
		
		//Act
		int size = PersonBuilder::getObject().createPersons(j2, mockChecker)->size();

		//Assert
		ASSERT_EQ(size, 3, L"Incorrect voctor of persons");

	}


		//TEST_METHOD(checkJSON_ProvidingSuitableJson_True)
		//{
		//	BaseChecker bch;
		//	nlohmann::json j;
		//	j["name"] = "Ivan";
		//	j["surname"] = "Ivanov";
		//	j["adr"] = { {"city", "Minsk"}, {"streetAddress", "Pushkina, 11"} };


		//	j["age"] = 32;
		//	Assert::IsTrue((bch.checkJSON(j)), L"Expected true but received false");

		//	j["age"] = 0;
		//	Assert::IsTrue((bch.checkJSON(j)), L"Expected true but received false");

		//	j["age"] = 130;
		//	Assert::IsTrue((bch.checkJSON(j)), L"Expected true but received false");

		//}

		//TEST_METHOD(checkJSON_ProvidingAnSuitableJson_False)
		//{
		//	BaseChecker bch;
		//	nlohmann::json j;
		//	j["name"] = "Ivan";
		//	j["surname"] = "Ivanov";
		//	j["adr"] = { {"city", "Minsk"}, {"streetAddress", "Pushkina, 11"} };

		//	j["age"] = -1;
		//	Assert::IsTrue(!(bch.checkJSON(j)), L"Expected false but received true");

		//	j["age"] = 131;
		//	Assert::IsTrue(!(bch.checkJSON(j)), L"Expected false but received true");

		//}

		//TEST_METHOD(checkJSON_ProvidingOfIncorrectAgeInJson_Exeption)
		//{
		//	nlohmann::json j;
		//	j["name"] = "Ivan";
		//	j["surname"] = "Ivanov";
		//	j["adr"] = { {"city", "Minsk"}, {"streetAddress", "Pushkina, 11"} };
		//	j["aage"] = 32;//error
		//	std::string exepString;
		//	BaseChecker bch;

		//	try {
		//		bch.checkJSON(j);

		//	}

		//	catch (std::exception& exception)
		//	{
		//		exepString = exception.what();
		//	}

		//	Assert::IsTrue((exepString.length() != 0), L"No exception");
		//}