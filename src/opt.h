/*
 * opt.h
 *
 *  Created on: Mar 5, 2017
 *      Author: abrahamon
 */

#ifndef OPT_H_
#define OPT_H_


#include <math.h>
#include <iostream>

namespace anpi {

template <class T>
class opt {
public:
	opt(){};
	virtual ~opt(){};


	T HornerPol(T* coePol,T x0, int size){
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




};

} /* namespace anpi */


#endif /* OPT_H_ */