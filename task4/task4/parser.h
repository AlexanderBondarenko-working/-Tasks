#pragma once
#include <iostream>
#include <string>
#include "body.h"
#include "head.h"
using namespace std;

class Parser {
	virtual string parse(ifstream inputSource, Body & bodyTarget, Head headTarget);
};
