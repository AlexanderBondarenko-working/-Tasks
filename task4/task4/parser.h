#pragma once
#include <iostream>
#include <string>
#include "body.h"
#include "head.h"
#include <map>
using namespace std;

class Parser {
public:
	virtual string parse(HTMLDoc & htmlDocTarget, Body & bodyTarget, Head headTarget) = 0;
};
