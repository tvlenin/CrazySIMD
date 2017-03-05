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


template <class T>
class ref {
public:
	ref(){};
	virtual ~ref(){};



	T HornerPol(T coePol,T x0, int size){
		T result = coePol[size-1];
		for (int i = 0; i < size-1 ; i++){
			result += pow(x0,size-(i+1))*coePol[i];
		}
		return result;
	}


	T EstrinPol(T* coePol, T x0,int size){
		T result = 0.0;
		T temp = 0;
		for (int i = 0; i < size; i++ ){
			if((i+1)%2 == 1 && (i != size-1)){
				temp += coePol[i];
			}
			else if((i+1)%2 == 0){
				//result += (temp +coePol[i]*x0) * pow(x0,i-1);
				result += (temp +coePol[i]*x0) * std::exp((i-1)*std::log(x0));
				temp = 0;
			}
			else if((i+1)%2 == 1 && (i == size-1)){
				result += (temp +coePol[i]*x0) * std::exp((i-1)*std::log(x0));
			}
		}
		return result;





	}



	T mPow(T data, int num){
		__m256d a = {data,data,data,data};
		__m256d result = {data,data,data,data};
		//double exp[];

		result = _mm256_mul_pd(result,a);
		for (int j = 0 ; j < 8 ;j++){
			result = _mm256_mul_pd(result,a);
		}


		double res = 1.0;
		for (int i = 0; i < 4; i++){
			res *= result[i];
		}
		return res;
	}

	//T1 mPow (T num, int exp)



};

} /* namespace anpi */

#endif /* SRC_REF_H_ */
