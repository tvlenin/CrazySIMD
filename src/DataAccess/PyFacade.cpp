/*
 * PyFacade.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: fasm22
 */

#include "PyFacade.h"

PyFacade* PyFacade::_instance = 0;

PyFacade* PyFacade::getInstance(){
	if(_instance == 0){
		_instance = new PyFacade();
	}
	return _instance;
}

PyFacade::PyFacade() {
}

