/*
 * ref.h
 *
 *  Created on: Feb 27, 2017
 *      Author: tvlenin
 */

#ifndef SRC_REF_H_
#define SRC_REF_H_

#include <math.h>
#include <iostream>
#include "immintrin.h"
namespace anpi {
template <class T, class T1>
class ref {
public:
	ref();
	virtual ~ref();


	T1 HornerPol(T* coePol,T1 x0, int size){
		T1 result = coePol[size-1];
		for (int i = 0; i < size-1 ; i++){
			result += pow(x0,size-(i+1))*coePol[i];
		}
		return result;
	}


	T1 EstrinPol( T* coePol, T1 x0,int size){
		T1 result = 0.0;
		T1 temp = 0;
		for (int i = 0; i < size; i++ ){
			if((i+1)%2 == 1 && (i != size-1)){
				temp += coePol[i];
			}
			else if((i+1)%2 == 0){
				result += (temp +coePol[i]*x0) * pow(x0,i-1);
				temp = 0;
			}
			else if((i+1)%2 == 1 && (i == size-1)){
				result += (temp +coePol[i]*x0) * pow(x0,i-1);
			}
		}
		return result;





	}


	T1 EstrinOPTI( T coePol, T1 x0,int size){

		}

	T1 mPow (T num, int exp){}



};

} /* namespace anpi */

#endif /* SRC_REF_H_ */
