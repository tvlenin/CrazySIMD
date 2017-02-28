/*
 * PyFacade.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: fasm22
 */

#include "PyFacade.h"

PyFacade* PyFacade::_instance = 0;
int PyFacade::_prueba = 0;

PyFacade* PyFacade::getInstance(int x){
	if(_instance == 0){
		_instance = new PyFacade();
	}
	return _instance;
}

PyFacade::PyFacade() {
}

