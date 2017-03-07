/*
 * cos_a.h
 *
 *  Created on: Feb 28, 2017
 *      Author: abrahamon
 */

#ifndef FUNCTIONS_A_COS_H_
#define FUNCTIONS_A_COS_H_

#include <cmath>
#include "../ref.h"

namespace anpi {




template<typename T>
class cos{

private:
	T*_coef;									//Coeficientes de la serie de Taylor
	static const unsigned int _alignment=32u;	//Alignment in bytes
	T _center;									//Centro de la serie
	T _terms;
	const long double PI=3.141592653589793238;	//Valor de PI

	/*Inicialice los coeficientes de la serie de Taylor centrada en _center
	∗para el número dado de términos.*/
	void init(const T center, const unsigned int terms ){
//		_center = center;
//		_terms = terms;
//		//Redondear hacia arriba
//		unsigned int blocks = ((terms*sizeof(T))+(_alignment-1)/_alignment);
//		_coef = static_cast<T*>(aligned_alloc(_alignment,blocks*_alignment));
//		//cos<T> logn;
//		for(unsigned int i =0; i<terms;++ i ) {
//			_coef[i] = diff(center,i)/factorial<T>(i);
//		}
	}

public:
	ref<T>* _reff = new ref<T>();

	/**Único constructor obliga dar centro y número de términos de la
	 * aproximación*/
	cos(const T center, const unsigned int terms){
		init(center,terms);
	}

	//Destructor debe liberar memoria reserveda
	~cos(){free(_coef);}

	//Evaluación de la función cos(x)
	inline T operator()(T val)const{//Val era const
		return std::cos(val);
	}

	//Evaluación de la n-énesima derivada
	inline T diff( T x , unsigned int n ){
		T val;
		if( n%2 == 0){	//par
			val=pow(-1,n/2+2)*std::cos(x);
		}else{		    //impar
			val=pow(-1,(n+1)/2)*std::sin(x);
		}
		return val;
	}
};
} /* namespace anpi */

#endif /* FUNCTIONS_A_COS_A_H_ */
