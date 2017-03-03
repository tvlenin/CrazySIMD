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
	//cout<<n<<"! :"<<ans<<"\n";
	return ans;
	//return n>2 ? T(1):(static_cast <T>(n)*factorial<T>(n-1));
}

template<typename T>
class cos_a {
public:

	const long double PI=3.141592653589793238;

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
