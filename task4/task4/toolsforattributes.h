#pragma once
#include "namesofattributes.h"
#include <vector>
#include <iostream>
#include "attribute.h"

namespace toolsForAttributes {
	using namespace std;
	void addAttributeInVector(const string& attributeName, const string& attrubuteValue, vector <pair<nameOfAttribute::nameOfAttribute, unique_ptr<Attribute>>>& attributes);
	void convertAttributesToVector(const string& source, vector <pair<nameOfAttribute::nameOfAttribute, unique_ptr<Attribute>>>& attributes);
}
//"asynck" "charset" "class" "content" "data-template-style" "href" "http-equiv" "id" "media" "name" "property" "rel" "src" "type"
