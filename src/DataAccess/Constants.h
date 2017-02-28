/*
 * Constants.h
 *
 *  Created on: Feb 28, 2017
 *      Author: abrahamon
 */

#ifndef DATAACCESS_CONSTANTS_H_
#define DATAACCESS_CONSTANTS_H_

#include "XMLReader.h"
#include <string>

using namespace std;

class Constants {
public:
	static Constants* _instance;
	static Constants* getInstance();

	static string IP;
	static int PORT;
	static int N;
	static int X0;

private:
	Constants();
};

#endif /* DATAACCESS_CONSTANTS_H_ */
