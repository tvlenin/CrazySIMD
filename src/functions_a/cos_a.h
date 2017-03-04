/*
 * cos_a.h
 *
 *  Created on: Feb 28, 2017
 *      Author: abrahamon
 */

#ifndef FUNCTIONS_A_COS_A_H_
#define FUNCTIONS_A_COS_A_H_

#include "../ref.h"
#include <iostream>
#include "../DataAccess/Constants.h"

using namespace std;
namespace anpi {

//Implementación del factorial
template<typename T>
T factorial_a ( T n){
	T ans=1;
	if(n!=0 || n!=1)
		for(;n>0;n--)
			ans=ans*n;
	return ans;
}

template<typename T>
class cos_a {

private:
	T*_coef;									//Coeficientes de la serie de Taylor
	static const unsigned int _alignment=32u;	//Alignment in bytes
	T _center;									//Centro de la serie
	const long double PI=3.141592653589793238;	//Valor de PI

	/*Inicialice los coeficientes de la serie de Taylor centrada en _center
	∗para el número dado de términos.*/
	void init(const T center, const unsigned int terms ){
		_center = center;
		//Redondear hacia arriba
		unsigned int blocks = ((terms*sizeof(T))+(_alignment-1)/_alignment);
		_coef = static_cast<T*>(aligned_alloc(_alignment,blocks*_alignment));
		cos<T> logn;
		for(unsigned int i =0; i<terms;++ i ) {
			_coef[i] = logn.diff(center,i)/factorial<T>(i);
		}
	}

public:

	/**Único constructor obliga dar centro y número de términos de la
	 * aproximación*/
	cos_a(const T center, const unsigned int terms){
		init(center,terms);
	}

	//Destructor debe liberar memoria reserveda
	~cos_a(){free(_coef);}

	//Evaluación de la función cos(x)
	inline T operator()(T val)const{//Val era const
		int size=val/(2*PI);
		val= val-(size*2*PI);
		size=Constants::N;
		T x_0 = Constants::X0;
		T coefficients[size];
		for(int i=0;i<size;i++){
			coefficients[i]=diff_cos_a(x_0,i)/factorial_a((T)i);
		}
		ref* reff = new ref();
		std::cout<<reff->EstrinPol(coefficients,val,Constants::N)<<" \n";
		return reff->EstrinPol(coefficients,val,Constants::N);
	}

	//Evaluación de la n-énesima derivada
	inline T diff_cos_a( T x , unsigned int n ){
	// la  n-ésima derivada del coseno es
		T val;
		if( n%2 == 0){	//par
			val=pow(-1,n/2+2);
		}else{		    //impar
			val=0;
		}
		return val;
	}
};

} /* namespace anpi */

#endif /* FUNCTIONS_A_COS_A_H_ */
