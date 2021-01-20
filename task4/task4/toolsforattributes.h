#pragma once
#include "headersofattributes.h"
#include <vector>

void addAttributeInVector(const string& attributeName, const string& attrubuteValue, vector <pair<string, Attribute*>>& attributes);
void selectAndAddInVectorAttributes(const string& source, vector <pair<string, Attribute*>>& attributes);
//"asynck" "charset" "class" "content" "data-template-style" "href" "http-equiv" "id" "media" "name" "property" "rel" "src" "type"
