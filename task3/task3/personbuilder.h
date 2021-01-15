#ifndef TASK3_PERSONBUILDER_H_  
#define TASK3_PERSONBUILDER_H_ 

#include "person.h"
#include "BaseChecker.h"

class PersonBuilder;

class PersonBuilderDestroyer
{
private:
    PersonBuilder* builderPtr;

public:
    ~PersonBuilderDestroyer();
    void initialize(PersonBuilder* p);
};

class PersonBuilder {
private:
    static PersonBuilder* builderPtr;
    static PersonBuilderDestroyer destroyer;
    PersonBuilder();
    PersonBuilder(const PersonBuilder&);
    PersonBuilder& operator=(PersonBuilder&);
    ~PersonBuilder();
    friend class PersonBuilderDestroyer;
public:
    static PersonBuilder& getObject();
    std::unique_ptr<std::vector<Person>> createPersons(json& j, const BaseChecker& checker);
};

#endif //TASK3_PERSONBUILDER_H_ 