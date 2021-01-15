#pragma once
#include <iostream>
#include <string>
#include "body.h"
#include "head.h"
#include <map>
using namespace std;

class Parser {
	virtual string parse(ifstream inputSource, Body & bodyTarget, Head headTarget);
};
