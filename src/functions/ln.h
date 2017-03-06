/*
 * ln.h
 *
 *  Created on: Feb 28, 2017
 *      Author: abrahamon
 */

#ifndef FUNCTIONS_A_LN_H_
#define FUNCTIONS_A_LN_H_

#include "../functions_a/cos_a.h"
#include "../ref.h"
namespace anpi {


//Nuestra implementación del factorial
template<typename T>
class ln {

private:
	T *_coef; //Coeficientes de la serie de Taylor
	static const unsigned int _alignment=32u; //Alignment in bytes
	T _center;
	T _terms;

	/*
	∗Inicialice los coeficientes de la serie de Taylor centrada en center
	∗ para el número dado de términos.
	*/
	void init(const T center, const unsigned int terms) {
		_center= center;
		_terms= terms;
		unsigned int blocks = ((terms*sizeof(T)+(_alignment-1))/_alignment);	//Redondear hacia arriba
		_coef = static_cast <T*>(aligned_alloc(_alignment,blocks*_alignment));
		for(unsigned int i =0; i<terms; ++i){
			_coef[i]=diff(center,i)/factorial<T>(i);
		}
	}
public:


	/* Único constructor obliga a dar centro y número de términos de la aproximación */
	ln(const T center ,const unsigned int terms) {
		init (center, terms) ;
	}

	///Destructor debe liberar memoria reservada
	~ln(){free(_coef);}


	inline T operator()(const T val)const{
		return std::log(val);
	}

	///Evaluación de la n−ésima derivada
	inline T diff( T x , int n ){
		if(n==0){
			return std::log(x);
		}else{
			T val=(factorial<T>((T)n-1))/pow(x,n);
			if( n%2 != 1)
				val=-val;
			return val;}
		//return ((n%1)==0)? -val:val;
	}



};




} /* namespace anpi */

#endif /* FUNCTIONS_A_LN_A_H_ */
