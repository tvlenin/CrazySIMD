/*
 * cos.h
 *
 *  Created on: Feb 27, 2017
 *      Author: abrahamon
 */

#ifndef FUNCTIONS_COS_H_
#define FUNCTIONS_COS_H_

#include <cmath>

namespace anpi {

template<typename T>
class cos{
public:
	///Evaluación de la función coseno
	inline T operator()(const T val)const{
		return std::cos(val);
	}

	///Evaluación de la n−ésima derivada
	inline T diff( const T x , const unsigned int n ){
		// la  n-ésima derivada del coseno es
		T val;
		if( n%2 == 0)	//par
			val=pow(-1,n/2+2)*std::cos(x);
		else		    //impar
			val=pow(-1,(n+1)/2)*std::sin(x);
		return val;
	}
};

} /* namespace anpi */

#endif /* FUNCTIONS_COS_H_ */






