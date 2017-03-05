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
#include "DataStructures/xArray.h"
#include "DataAccess/PyFacade.h"
#include "functions/cos.h"
#include "functions/ln.h"
#include "functions_a/cos_a.h"
#include "functions_a/ln_a.h"

using namespace std;

namespace anpi {


class ErrorFramework {
public:
	ErrorFramework(){

	}
	virtual ~ErrorFramework(){

	}

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

		cout<< "Relative Error: " << getAverageError(pRefFunction(pX),pFunction(pX)) << endl;
		cout<< "Elapsed Time: " << static_cast<double>(ms)/numTests << "ms"<<endl;
	}

	template<class dataType>
	void graphRealvsAprox(int pFunctionMode, double pH, int pCoeffQuantity, int pCenter,
						  dataType pInitRange, dataType pEndRange){
		PyFacade* xx = PyFacade::getInstance();

		if(pFunctionMode == 0){
			anpi::cos_a<dataType> pFunction(pCenter,pCoeffQuantity);
			anpi::cos<dataType> pRefFunction(pCenter,pCoeffQuantity);

			int iMax = pEndRange / pH;

			xArray<dataType> yValues(iMax);
			xArray<dataType> xValues(iMax);
			xArray<dataType> yRefValues(iMax);


			double valueX = 0.2;
			for(int i = 0; i < iMax; i++){

				dataType yValue = pFunction(valueX);
				dataType yRefValue = pRefFunction(valueX);

				yValues.setArray(i,yValue);
				yRefValues.setArray(i,yRefValue);
				xValues.setArray(i,valueX);

				cout << valueX << " | " << yValue << " | " << yRefValue << endl;

				valueX+=pH;

			}
			xx->create2DPlot(xValues,yValues,yRefValues);
		}
	}
};

}

#endif
