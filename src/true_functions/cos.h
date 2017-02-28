/*
 * cos.h
 *
 *  Created on: Feb 27, 2017
 *      Author: abrahamon
 */

#ifndef TRUE_FUNCTIONS_COS_H_
#define TRUE_FUNCTIONS_COS_H_

namespace anpi {

template<typename T>
class cos {
public:
	///Evaluación de la función logarítmica
	inline T operator()(const T val)const{
		return cos(val);
	}

	///Evaluación de la n−ésima derivada
	inline T diff( const T x , const unsigned int n ){
		// la  n-ésima derivada del logaritmo es
	}
};

} /* namespace anpi */

#endif /* TRUE_FUNCTIONS_COS_H_ */






