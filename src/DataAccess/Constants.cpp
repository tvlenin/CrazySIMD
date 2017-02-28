/*
 * Constants.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: abrahamon
 */

#include "Constants.h"

Constants* Constants::_instance=0;

string Constants::IP;
int Constants::PORT=0;
int Constants::N=0;

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
	reader->loadXMLFile("src/configs.xml");

	//General Constants
	IP = reader->getParameter("IP");
	PORT = atoi(reader->getParameter("PORT"));
	N = atoi(reader->getParameter("N"));

}
