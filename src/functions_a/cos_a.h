/*
 * cos_a.h
 *
 *  Created on: Feb 28, 2017
 *      Author: abrahamon
 */

#ifndef FUNCTIONS_A_COS_A_H_
#define FUNCTIONS_A_COS_A_H_

#include <cmath>
#include "../ref.h"
#include "../opt.h"
#include "../DataAccess/Constants.h"

namespace anpi {


//Implementación del factorial
template<typename T>
T factorial ( T n){
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
	T _terms;
	const long double PI=3.141592653589793238;	//Valor de PI

	/*Inicialice los coeficientes de la serie de Taylor centrada en _center
	∗para el número dado de términos.*/
	void init(const T center, const unsigned int terms ){
		_center = center;
		_terms = terms;
		T tmp;
		//Redondear hacia arriba
		unsigned int blocks = ((terms*sizeof(T))+(_alignment-1)/_alignment);
		_coef = static_cast<T*>(aligned_alloc(_alignment,blocks*_alignment));
<<<<<<< HEAD
		for(int i = 0; i < _terms; i++){
			_coef[i] = 0;
=======
		for(int i=0;i<_terms;i++){
			_coef[i]=0;
>>>>>>> bf8fc8adf46cc13f39c5b4fe7c4a01a0e13b2482
		}
		for(unsigned int i =0; i<terms;++ i ) {
			tmp= diff(center,i)/factorial<T>(i);
			if(tmp!=tmp){
				cout<<"nan alert in coef calc!\n";
				break;
			}else{
				_coef[i]=tmp;
			}
		}
	}

public:
	ref<T>* _reff = new ref<T>();
	opt<T>* _optt = new opt<T>();


	/**Único constructor obliga dar centro y número de términos de la
	 * aproximación*/
	cos_a(const T center, const unsigned int terms){
		init(center,terms);
	}

	//Destructor debe liberar memoria reserveda
	~cos_a(){free(_coef);}

	//Evaluación de la función cos(x)
	inline T operator()(T val)const{//Val era const
		int times=val/(2*PI);
		val= val-(times*2*PI);
		if(Constants::Optt == 0)
			return _reff->EstrinPol(_coef,val-_center,_terms);
		else if(Constants::Optt == 1)
			return _optt->EstrinPol(_coef,val-_center,_terms);
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
//}/* namespace opt */
} /* namespace anpi */

#endif /* FUNCTIONS_A_COS_A_H_ */
