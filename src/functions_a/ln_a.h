/*
 * ln_a.h
 *
 *  Created on: Feb 28, 2017
 *      Author: abrahamon
 */

#ifndef FUNCTIONS_A_LN_A_H_
#define FUNCTIONS_A_LN_A_H_

#include "../ref.h"
<<<<<<< HEAD
#include "../DataAccess/Constants.h"
=======
#include "../opt.h"
>>>>>>> bf8fc8adf46cc13f39c5b4fe7c4a01a0e13b2482

namespace anpi {


//Nuestra implementación del factorial
template<typename T>
class ln_a {

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
		T tmp;
		unsigned int blocks = ((terms*sizeof(T)+(_alignment-1))/_alignment);	//Redondear hacia arriba
		_coef = static_cast <T*>(aligned_alloc(_alignment,blocks*_alignment));
<<<<<<< HEAD
		for(int i = 0; i < _terms; i++){
			_coef[i] = 0;
=======
		for(int i=0;i<_terms;i++){
			_coef[i]=0;
>>>>>>> bf8fc8adf46cc13f39c5b4fe7c4a01a0e13b2482
		}
		for(unsigned int i =0; i<terms; ++i){
			tmp=diff(center,i)/factorial<T>(i);
			if(tmp!=tmp){
				cout<<"nan alert in coef calc!\n";
				break;
			}else{
				_coef[i]=tmp;
			}
		}

	}
public:
<<<<<<< HEAD
	opt<T>* _optt = new opt<T>();
	ref<T>* _reff = new ref<T>();
=======
	ref<T>* reff = new ref<T>();
	opt<T>* optt = new opt<T>();

>>>>>>> bf8fc8adf46cc13f39c5b4fe7c4a01a0e13b2482

	/* Único constructor obliga a dar centro y número de términos de la aproximación */
	ln_a(const T center ,const unsigned int terms) {
		init (center, terms) ;
	}

	///Destructor debe liberar memoria reservada
	~ln_a(){free(_coef);}


	inline T operator()(const T val)const{
<<<<<<< HEAD
		if(Constants::Optt == 0)
			return _reff->EstrinPol(_coef,val-_center,_terms);
		else if(Constants::Optt == 1)
			return _optt->EstrinPol(_coef,val-_center,_terms);
=======
		//return reff->EstrinPol(_coef,val-_center,_terms);
		return optt->EstrinPol(_coef,val-_center,_terms);
>>>>>>> bf8fc8adf46cc13f39c5b4fe7c4a01a0e13b2482
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
