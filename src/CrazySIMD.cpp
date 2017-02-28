//============================================================================
// Name        : CrazySIMD.cpp
// Author      : Abraham Arias, Lenin Torres, Fabian Solano
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "true_functions/ln.h"
#include <math.h>
#include <string>
#include <chrono>

using namespace std;
using namespace anpi;


int main() {

	ln<float> a;
	float b = a.diff(0.120,5);
	//float b = ((a.diff(0.12,1.0)-40187757.2)/40187757.2 *100);



	cout << "!!!Hello World from Abraham!!!  "<<b<< endl; // prints !!!Hello World!!!
	return 0;
}
