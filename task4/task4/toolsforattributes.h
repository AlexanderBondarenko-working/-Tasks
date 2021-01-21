#pragma once
#include "headersofattributes.h"
#include <vector>
#include <iostream>

void addAttributeInVector(const string& attributeName, const string& attrubuteValue, vector <pair<string, unique_ptr<Attribute>>>& attributes);
void selectAndAddInVectorAttributes(const string& source, vector <pair<string, unique_ptr<Attribute>>>& attributes);
//"asynck" "charset" "class" "content" "data-template-style" "href" "http-equiv" "id" "media" "name" "property" "rel" "src" "type"
