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
#include "functions_a/ln_a.h"

using namespace std;
using namespace anpi;


int main() {

	//anpi::ln<float> bb;

	//anpi::ln_a<float> aa;
	//float asd = aa.diff(0,5);
	//float b = ((a.diff(0.12,1.0)-40187757.2)/40187757.2 *100);


	cout << "!!!Hello World from Abraham!!!  "<< endl; // prints !!!Hello World!!!

	float d=0;
	float a =1.555;
	float b = modf(a,&d);
	cout << "!"<<endl;

	cout<<b<<endl;
	cout<<d<<endl;

	return 0;
}
