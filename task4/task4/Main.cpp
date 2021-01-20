#include <iostream>
#include "htmldoc.h"
#include "parserfromfile.h"

using namespace std;
int main() {
	ParserFromFile* parser = new ParserFromFile("Source.txt");
	HTMLDoc htmldoc(parser);
	htmldoc.parse();
	cout << htmldoc.objectToString() << endl;
	return 0;
}