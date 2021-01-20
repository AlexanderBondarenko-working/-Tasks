#include "head.h"

//void Head::parseElementsFromString(const string& source) {
//	int firstPos = 0;
//	int lastPos = 0;
//	string tempString;
//	string nameOfElement;
//	string valueOfElement;
//
//	while (source.find("<", lastPos) != string::npos) {
//		firstPos = source.find("<", lastPos);
//		/*if((source.find(" ", firstPos) != string::npos)
//			&& (source.find(">", firstPos) != string::npos)
//			&& (source.find(" ", firstPos) < source.find(">", firstPos)))
//		{
//			lastPos = source.find(" ", firstPos);
//			nameOfElement = source.substr(firstPos + 1, lastPos - firstPos);
//			firstPos = source.find(">", lastPos);
//			lastPos = firstPos;
//		}*/
//		
//		if ((source.find(">", firstPos) != string::npos) && (firstPos != source.find("<\/", lastPos)))
//		{
//			lastPos = source.find(">", firstPos);
//			selectNameAndValueOfSubelement(nameOfElement, valueOfElement, source, firstPos, lastPos);
//		}
//		else if ((source.find(">", firstPos) != string::npos) && (firstPos == source.find("<\/", lastPos))) {
//			firstPos = source.find("<\/", lastPos);
//			lastPos = source.find(">", firstPos);
//			firstPos = lastPos;
//		}
//		
//	}

	/////////////////////
	//string tempString;
	//int firstPos;
	//int lastPos;
	//getline(inpt, tempString);
	//target += tempString;
	//if (target.find("<head") != string::npos)
	//{
	//	firstPos = tempString.find("<head") + 5;
	//	//attributes
	//	while (!inpt.eof() && (target.find(">", firstPos) == string::npos)) {
	//		getline(inpt, tempString);
	//		target += tempString;
	//	}
	//	if (target.find(">", firstPos) != string::npos) {
	//		lastPos = target.find(">", firstPos);
	//		tempString = target.substr(0, lastPos + 1);
	//		headTarget.parseAttributesFromString(tempString);
	//		target = target.erase(0, lastPos + 1);
	//	}
	//	//elements
	//	while (!inpt.eof() && (target.find("<\/htad>") == string::npos)) {
	//		getline(inpt, tempString);
	//		target += tempString;
	//	}
	//	if (target.find("<\/head>", firstPos) != string::npos) {
	//		lastPos = target.find("<\/head>", firstPos);
	//		tempString = target.substr(0, lastPos);
	//		headTarget.parseElementsFromString(tempString);
	//		target = target.erase(0, lastPos + 7);
	//	}
	//}

	////////////////////////////////////
	////none
	//string attrName;
	//string attrValue;
	//int firstPos = 0;
	//int lastPos = 0;
	//while (source.find("=\"", lastPos) != string::npos) {
	//	if (firstPos == 0) {
	//		firstPos = source.find(" ", lastPos) + 1;
	//	}
	//	else {
	//		firstPos = source.find("\" ", lastPos) + 2;
	//	}
	//	lastPos = source.find("=\"", lastPos);
	//	attrName = source.substr(firstPos, lastPos - firstPos);

	//	firstPos = lastPos;
	//	lastPos = source.find("\"", lastPos + 2);
	//	attrValue = source.substr(firstPos + 2, lastPos - firstPos - 2);
	//	addAttributeInVector(attrName, attrValue, attributes);
	//}

//}
string Head::getNameOfElement() const {
	return "head";
}