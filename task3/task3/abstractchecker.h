#ifndef TASK3_ABSTRACTCHECKER_H_ 
#define TASK3_ABSTRACTCHECKER_H_ 

#include "person.h"
#include "nlohmann/json.hpp"
using nlohmann::json;

class AbstractChecker {
public:
	virtual bool checkJSON(const json& j) const  = 0;
};

#endif //TASK3_ABSTRACTCHECKER_H_

