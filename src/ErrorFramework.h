/*
 * ErrorFramework.h
 *
 *  Created on: Feb 27, 2017
 *      Author: fasm22
 */

#ifndef SRC_ERRORFRAMEWORK_H_
#define SRC_ERRORFRAMEWORK_H_
#include <iostream>
#include <stdlib.h>
#include <vector>
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
	ErrorFramework(int mode){
		if(mode == 1){
			system("python src/graphics.py &");
			usleep(3000000);
		}

	}
	virtual ~ErrorFramework(){

	}

	template <typename dataType>
	dataType getAverageError(dataType trueValue, dataType aproxValue){
		dataType result = abs((trueValue - aproxValue)/(trueValue)) *100;
		return result;
	}

	template<class fType, class fRefType, class dataType>
	void testFunction(fRefType pRefFunction, fType pFunction, dataType pX, const int numTests){
		dataType result = pFunction(pX);
		dataType refResult = pRefFunction(pX);

		dataType tempResult;
		dataType d = (pX)/numTests;

		auto start = chrono::high_resolution_clock::now();
		for(int i = 0; i < numTests; i++,pX+=d){
			tempResult = pFunction(pX);
		}
		cout<<"Final Temp Result: "<< tempResult << endl;
		auto end = chrono::high_resolution_clock::now();
		auto ms = chrono::duration_cast<chrono::nanoseconds>(end-start).count();

		cout<< "Relative Error: " << getAverageError(refResult,result) << endl;
		cout<< "Elapsed Time: " << static_cast<double>(ms)/numTests << "ns"<<endl;
		cout<< "Reference Result: " << refResult << endl;
		cout<< "Aprox Result: " << result << endl;
	}

	template<class dataType>
	void graphTime(int pFunctionMode, double pH, int pCenter, int pCoeffQuantity,int numTests, dataType pX){
		PyFacade* xx = PyFacade::getInstance();

		if(pFunctionMode == 0){
			xArray<dataType> xValues(pCoeffQuantity);
			xArray<dataType> y1Values(pCoeffQuantity);

			dataType result;
			dataType tempPX = pX;

			for(int i = 1; i <= pCoeffQuantity; i++){
				anpi::cos_a<dataType> pFunction(pCenter,i);

				tempPX = pX;
				auto start = chrono::high_resolution_clock::now();
				for(int j = 0; j < numTests; j++,tempPX+=0.1){
					result = pFunction(tempPX);
				}
				auto end = chrono::high_resolution_clock::now();
				auto ms = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
				cout << "Last Result " << result <<endl;
				cout << "Num Coeff " << i << ": "<< static_cast<dataType>(ms)/numTests << " ns"<< endl;
				y1Values.setArray(i-1,static_cast<dataType>(ms)/numTests);
				xValues.setArray(i-1,i);
			}
			xx->create2DPlotTime("Time (ns)",xValues,y1Values);
		}

		else if(pFunctionMode == 1){
			xArray<dataType> xValues(pCoeffQuantity);
			xArray<dataType> y1Values(pCoeffQuantity);

			dataType result;

			for(int i = 1; i <= pCoeffQuantity; i++){
				anpi::ln_a<dataType> pFunction(pCenter,i);

				auto start = chrono::high_resolution_clock::now();
				for(int i = 0; i < numTests; i++,pX+=0.1){
					result = pFunction(pX);
				}
				auto end = chrono::high_resolution_clock::now();
				auto ms = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
				cout << "Last Result " << result <<endl;
				cout << "Num Coeff " << i << ": "<<static_cast<dataType>(ms)/numTests << endl;
				y1Values.setArray(i-1,static_cast<dataType>(ms)/numTests);
				xValues.setArray(i-1,i);
			}

			xx->create2DPlotTime("Time (ns)",xValues,y1Values);
		}

	}

	template<class dataType>
	void graphRelativeError(int pFunctionMode, double pH, int pCenter,
			  	  	  	  	dataType pInitRange, dataType pEndRange){
		PyFacade* xx = PyFacade::getInstance();

		if(pFunctionMode == 0){
			int iMax = pEndRange / pH;

			xArray<dataType> xValues(iMax);
			xArray<dataType> y1Values(iMax);
			xArray<dataType> y2Values(iMax);
			xArray<dataType> y3Values(iMax);
			xArray<dataType> y4Values(iMax);
			xArray<dataType> y5Values(iMax);

			int coeffValues[5] = {3,5,7,9,11};

			//int coeffValues[5] = {20,20,20,20,20};

			for(int n = 0; n < 5; n++ ){

				cout << "N: --> " << coeffValues[n] << endl;

				anpi::cos_a<dataType> pFunction(pCenter,coeffValues[n]);
				anpi::cos<dataType> pRefFunction(pCenter,coeffValues[n]);

				double valueX = pInitRange;

				for(int i = 0; i < iMax; i++){
					dataType yValue = pFunction(valueX);
					dataType yRefValue = pRefFunction(valueX);

					dataType currentErrorPercent = getAverageError(yRefValue,yValue);

					cout << "COS("<<valueX<<"): " << yRefValue << " | COS_A: " << yValue << endl;
					cout << "% Error" << currentErrorPercent << endl;

					if(n == 0)
						y1Values.setArray(i,currentErrorPercent);
					if(n == 1)
						y2Values.setArray(i,currentErrorPercent);
					if(n == 2)
						y3Values.setArray(i,currentErrorPercent);
					if(n == 3)
						y4Values.setArray(i,currentErrorPercent);
					if(n == 4)
						y5Values.setArray(i,currentErrorPercent);

					xValues.setArray(i,valueX-pCenter);
					valueX+=pH;
				}

			}

			xx->create2DPlotError("% Error",xValues,y1Values,y2Values,y3Values,y4Values,y5Values);

		}
		else if(pFunctionMode == 1){
			int iMax = pEndRange / pH;

			xArray<dataType> xValues(iMax);
			xArray<dataType> y1Values(iMax);
			xArray<dataType> y2Values(iMax);
			xArray<dataType> y3Values(iMax);
			xArray<dataType> y4Values(iMax);
			xArray<dataType> y5Values(iMax);

			int coeffValues[5] = {1,2,3,4,5};

			//int coeffValues[5] = {20,20,20,20,20};

			for(int n = 0; n < 5; n++ ){

				cout << "N: --> " << n << endl;

				anpi::ln_a<dataType> pFunction(pCenter,coeffValues[n]);
				anpi::ln<dataType> pRefFunction(pCenter,coeffValues[n]);

				double valueX = pInitRange;

				for(int i = 0; i < iMax; i++){
					dataType yValue = pFunction(valueX);
					dataType yRefValue = pRefFunction(valueX);

					dataType currentErrorPercent = getAverageError(yRefValue,yValue);

					cout << "LN("<<valueX<<"): " << yRefValue << " | LN_A: " << yValue << endl;
					cout << "% Error" << currentErrorPercent << endl;

					if(n == 0)
						y1Values.setArray(i,currentErrorPercent);
					if(n == 1)
						y2Values.setArray(i,currentErrorPercent);
					if(n == 2)
						y3Values.setArray(i,currentErrorPercent);
					if(n == 3)
						y4Values.setArray(i,currentErrorPercent);
					if(n == 4)
						y5Values.setArray(i,currentErrorPercent);

					xValues.setArray(i,valueX-pCenter);
					valueX+=pH;
				}

			}

			xx->create2DPlotError("% Error",xValues,y1Values,y2Values,y3Values,y4Values,y5Values);

		}
	}

	template<class dataType>
	void graphRealvsAprox(int pFunctionMode, double pH, int pCoeffQuantity, int pCenter,
						  dataType pInitRange, dataType pEndRange){
		PyFacade* xx = PyFacade::getInstance();

		if(pFunctionMode == 0){
			anpi::cos_a<dataType> pFunction(pCenter,pCoeffQuantity);
			anpi::cos<dataType> pRefFunction(pCenter,pCoeffQuantity);

			int iMax = (pEndRange) / pH;

			xArray<dataType> yValues(iMax);
			xArray<dataType> xValues(iMax);
			xArray<dataType> yRefValues(iMax);


			double valueX = pInitRange;
			for(int i = 0; i < iMax; i++){

				dataType yValue = pFunction(valueX);
				dataType yRefValue = pRefFunction(valueX);

				yValues.setArray(i,yValue);
				yRefValues.setArray(i,yRefValue);
				xValues.setArray(i,valueX);

				cout << valueX << " | " << yValue << " | " << yRefValue << endl;

				valueX+=pH;

			}
			xx->create2DPlot("cos",xValues,yValues,yRefValues);
		}
		else if(pFunctionMode == 1){
			anpi::ln_a<dataType> pFunction(pCenter,pCoeffQuantity);
			anpi::ln<dataType> pRefFunction(pCenter,pCoeffQuantity);

			int iMax = (pEndRange - pInitRange) / pH;

			xArray<dataType> yValues(iMax);
			xArray<dataType> xValues(iMax);
			xArray<dataType> yRefValues(iMax);


			double valueX = pInitRange;
			for(int i = 0; i < iMax; i++){

				dataType yValue = pFunction(valueX);
				dataType yRefValue = pRefFunction(valueX);

				yValues.setArray(i,yValue);
				yRefValues.setArray(i,yRefValue);
				xValues.setArray(i,valueX);

				cout << valueX << " | " << yValue << " | " << yRefValue << endl;

				valueX+=pH;

			}
			xx->create2DPlot("ln",xValues,yValues,yRefValues);
		}
		else{
			cout << "pFunctionMode debe ser 0 o 1" << endl;
		}
	}
};

}

#endif
