/*
 * Constants.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: abrahamon
 */

#include "Constants.h"

Constants* Constants::_instance=0;

string Constants::IP;
int Constants::PORT = 0;
int Constants::N = 0;
int Constants::X0 = 0;
//long double Constants::PI = 0;

Constants* Constants::getInstance(){
	if(_instance == 0){
		_instance = new Constants();
	}
	return _instance;
}


Constants::Constants(){
	//XML Reader
	srand(time(0));
	XMLReader* reader = new XMLReader();
	reader->loadXMLFile("configs.xml");

	//General Constants
	//PI=3.141592653589793238;
	IP = reader->getParameter("IP");
	PORT = atoi(reader->getParameter("PORT"));
	N = atoi(reader->getParameter("N"));
	X0 = atoi(reader->getParameter("X0"));
}
