#ifndef TASK3_BASECHECKER_H_ 
#define TASK3_BASECHECKER_H_ 

#include "abstractchecker.h"
#include "nlohmann/json.hpp"
using nlohmann::json;

class BaseChecker : public AbstractChecker{
public:

	virtual bool checkJSON(const json& j) const{
		return  ((j.at("age").get<int>() >= 0) && (j.at("age").get<int>() <= 130));
	}
};

#endif //TASK3_BASECHECKER_H_