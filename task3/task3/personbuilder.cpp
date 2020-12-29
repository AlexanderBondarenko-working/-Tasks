#include "personbuilder.h"



PersonBuilder* PersonBuilder::builderPtr = nullptr;

PersonBuilderDestroyer PersonBuilder::destroyer;

PersonBuilder::PersonBuilder() {}
PersonBuilder::PersonBuilder(const PersonBuilder&) {}
PersonBuilder::~PersonBuilder() {}

PersonBuilderDestroyer::~PersonBuilderDestroyer() {
    if (builderPtr != nullptr) {
        delete builderPtr;
    }
}

void PersonBuilderDestroyer::initialize(PersonBuilder* p) {
    builderPtr = p;
}

PersonBuilder& PersonBuilder::getObject() {
    if (!builderPtr) {
        builderPtr = new PersonBuilder();
        destroyer.initialize(builderPtr);
    }
    return *builderPtr;
}

std::unique_ptr<std::vector<Person>> PersonBuilder::createPersons(json& j, const BaseChecker& checker){
    std::unique_ptr<std::vector<Person>> persons = std::make_unique<std::vector<Person>>();
    if (j.is_object()) {
        if (checker.checkJSON(j)) {
            persons->push_back(j.get<Person>());
        }
    }
    if (j.is_array()) {
        for (json::iterator it = j.begin(); it != j.end(); ++it) {
            if (checker.checkJSON(*it)) {
                persons->push_back((*it).get<Person>());
            }
        }
    }
   // for (json::iterator it = j.begin(); it != j.end(); ++it) {
        //persons->push_back(it-> get<Person>());
   // }

    return persons;
}