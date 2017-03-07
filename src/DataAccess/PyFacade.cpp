/*
 * PyFacade.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: fasm22
 */

#include "PyFacade.h"
#include "Constants.h"

using namespace std;

PyFacade* PyFacade::_instance = 0;

PyFacade* PyFacade::getInstance(){
	if(_instance == 0){
		_instance = new PyFacade();
	}
	return _instance;
}


PyFacade::PyFacade() {
	ss = new SocketCliente();

	//string pIP = "192.168.0.13";
	//int pPort = 9092;
	string pIP = Constants::IP;
	int pPort = Constants::PORT;

	bool status = ss->connect(pIP.c_str(),pPort);
	if(status)
		cout << "Succesfully connected to: " << pIP <<":"<<pPort << endl;
	else
		cout << "ERROR: Could not connect to " << pIP <<":"<<pPort << endl;
}

