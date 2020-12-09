#ifndef TASK1_BASEMATRIX_H_ 
#define TASK1_BASEMATRIX_H_ 

class BaseMatrix {
	int numberOflines;
	int numberOfcolums;
	int** matrix;
public:
	BaseMatrix();
	BaseMatrix(const int numberOflines, const int numberOfcolums, const int*
		       fillingArray, const int sizeOfarray);
	BaseMatrix(const BaseMatrix& source);
	BaseMatrix& operator=(const BaseMatrix& source);
	virtual ~BaseMatrix();


};

#endif  // TASK1_BASEMATRIX_H_ 