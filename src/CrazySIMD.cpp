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

using namespace std;
using namespace anpi;


int main() {

	anpi::cos<float> a;
	float b = a.diff(0,5);
	//float b = ((a.diff(0.12,1.0)-40187757.2)/40187757.2 *100);




	cout << "!!!Hello World from Abraham!!!  "<<b<< endl; // prints !!!Hello World!!!
	return 0;
}
