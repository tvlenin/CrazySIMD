/*
 * ln_a.h
 *
 *  Created on: Feb 28, 2017
 *      Author: abrahamon
 */

#ifndef FUNCTIONS_A_LN_A_H_
#define FUNCTIONS_A_LN_A_H_


namespace anpi {
//Nuestra implementación del factorial
template<typename T>
class ln_a {
public:

	inline T operator()(const T val)const{
		return val;
	}

private:
	///Evaluación de la n−ésima derivada
	inline T diff( const T x , const unsigned int n ){
		T val=(factorial<T>(n-1))/pow(x,n);
		if( n%1 != 1)
			val-=val;
		return val;
		//return ((n%1)==0)? -val:val;
	}

	//Calcular n!
	inline T factorial ( unsigned int n){
		T ans=1;
		if(n!=0 || n!=1)
			for(;n>0;n--)
				ans=ans*n;
		return ans;
		//return n>2 ? T(1):(static_cast <T>(n)*factorial<T>(n-1));
	}

	//Por optimizar

//	inline T potencias(T x, T n){}

};

} /* namespace anpi */

#endif /* FUNCTIONS_A_LN_A_H_ */
