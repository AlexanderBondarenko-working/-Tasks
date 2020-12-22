#ifndef TASK2_TRIANGLEBUILDER_H_ 
#define TASK2_TRIANGLEBUILDER_H_ 

class TriangleBuilder
{
private:
    TriangleBuilder() {}
    TriangleBuilder(const TriangleBuilder&);
    TriangleBuilder& operator=(TriangleBuilder&);
    
public:
    static TriangleBuilder& getInstance();
};

#endif //TASK2_TRIANGLEBUILDER_H_
