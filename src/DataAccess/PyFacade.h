/*
 * PyFacade.h
 *
 *  Created on: Feb 28, 2017
 *      Author: fasm22
 */

#ifndef SRC_PYFACADE_H_
#define SRC_PYFACADE_H_

#include <stdlib.h>


class PyFacade {
public:
	static PyFacade* _instance;
	static PyFacade* getInstance();

private:
	PyFacade();
};

#endif /* SRC_PYFACADE_H_ */
