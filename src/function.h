/*
 * function.h
 *
 *  Created on: Feb 27, 2017
 *      Author: abrahamon
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

namespace anpi {

template <typename T>
class function {
public:
	function();
	virtual ~function();


	//Evaluacion de la funcion
	inline T operator()(const T val) const{

	};

	////Evaluacion de la n-enesima derivada
	inline T diff(const T val, const unsigned int n) const;

};

} /* namespace anpi */

#endif /* FUNCTION_H_ */


