/*
 * cos_a.h
 *
 *  Created on: Feb 28, 2017
 *      Author: abrahamon
 */

#ifndef FUNCTIONS_A_COS_A_H_
#define FUNCTIONS_A_COS_A_H_

namespace anpi {


template<typename T>
class cos_a {
public:


	inline T operator()(const T val)const{
		int size=Constants::N;
		T x_0 = Constants::X0;
		T coefficients[size];
		for(int i=0;i<size;i++){
			coefficients[i]=diff_cos_a(x_0,i)/factorial((T)i);
		}
		return val;
	}


	inline T diff_cos_a( T x , unsigned int n ){
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

#endif /* FUNCTIONS_A_COS_A_H_ */
