//============================================================================
// Name        : CrazySIMD.cpp
// Author      : Abraham Arias, Lenin Torres, Fabian Solano
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include <string>
#include <chrono>

#include "ErrorFramework.h"
#include "functions/cos.h"
#include "functions/ln.h"
#include "functions_a/cos_a.h"
#include "functions_a/ln_a.h"
#include "DataAccess/Constants.h"

using namespace std;
using namespace anpi;


int main() {
	Constants::getInstance();//Declare and initialize all the constants from the XML file


	anpi::ln_a<float> a1;
	a1(2.0);
	//float b = ((a.diff(0.12,1.0)-40187757.2)/40187757.2 *100);


	cout << "!!!Hello World from Abraham!!!  "<< endl; // prints !!!Hello World!!!


	return 0;
}
