#include "trianglebuilder.h"

TriangleBuilder& TriangleBuilder::getInstance() {
    static TriangleBuilder  builder;
   /* MonkeyHandler* monkey = new MonkeyHandler;
    SquirrelHandler* squirrel = new SquirrelHandler;
    DogHandler* dog = new DogHandler;
    monkey->SetNext(squirrel)->SetNext(dog);*/
    //EquilateTriangleBuilder * equilateTriangle = new EquilateTriangleBuilder;
    return builder;
}