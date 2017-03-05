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


	T HornerPol(T* coePol,T x0, int size){
		T result = coePol[size-1];
		for (int i = 0; i < size-1 ; i++){
			result += pow(x0,size-(i+1))*coePol[i];
		}
		return result;
	}



<<<<<<< HEAD
	T EstrinPol(T* coePol, T x0,int size){
		T result = 0.0;
		T temp = 0;
=======
	template <class E, class E1>
	E1 EstrinPol( E coePol, E1 x0,int size){

		//std::cout<<size<<std::endl;

		E1 result = 0.0;
		E1 temp = 0;
>>>>>>> a5555daecff1d3237e71b02a9707c8aa7aa879ed
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

	template <class P, class P1>
	P1 EstrinOPTI( P coePol, P1 x0,int size){







		}





};

} /* namespace anpi */

#endif /* SRC_REF_H_ */
