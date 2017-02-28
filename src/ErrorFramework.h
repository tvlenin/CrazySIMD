/*
 * ErrorFramework.h
 *
 *  Created on: Feb 27, 2017
 *      Author: fasm22
 */

#ifndef SRC_ERRORFRAMEWORK_H_
#define SRC_ERRORFRAMEWORK_H_
#include <iostream>
#include <chrono>

using namespace std;

namespace anpi {


class ErrorFramework {
public:
	ErrorFramework();
	virtual ~ErrorFramework();

	template <typename dataType>
	dataType getAverageError(dataType trueValue, dataType aproxValue){
		dataType result = (trueValue - aproxValue)/(trueValue) *100;
		return result;
	}

	template<class fType, class fRefType, class dataType>
	void testFunction(fRefType pRefFunction, fType pFunction, dataType pX, const int numTests){
		dataType result;

		dataType step = (2.f-pX)/numTests;

		auto start = chrono::high_resolution_clock::now();
		for(int i = 0; i < numTests; i++, pX+=step){
			result = pFunction(pX);
		}
		auto end = chrono::high_resolution_clock::now();
		auto ms = chrono::duration_cast<chrono::milliseconds>(end-start).count();

		cout<< static_cast<double>(ms)/numTests << "ms"<<endl;
	}
};

}

#endif
