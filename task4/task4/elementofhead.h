#pragma once
#include <iostream> 
#include <sstream> 
#include <map> 
#include <string>
using namespace std;

class ElementOfHead {

	virtual string getTipe() const = 0;
	virtual string objToString() const = 0;
};
