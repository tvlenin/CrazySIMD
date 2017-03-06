//============================================================================
// Name        : CrazySIMD.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ErrorFramework.h"
#include "ref.h"
#include "opt.h"
#include <sstream>
#include <chrono>
#include "immintrin.h"
#include <math.h>
#include "functions_a/cos_a.h"
#include <iomanip>

using namespace std;
using namespace anpi;






int main() {
	double num = 1.0;
	//int pp = 40;

	//double arreglo[18] ={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0,14.0,15.0,16.0,17.0,18.0};
	double arreglo[10] ={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
	//ref<double>* _reff = new ref<double>();
	//cout<<_reff->mPow(num,pp)<<endl;
	//cout<<pow(num,pp)<<endl;
	//opt<double>*  _optt= new opt<double>();
	//cout<<_optt->EstrinPol(arreglo,num,18)<<endl;


	cout<<setprecision(20)<<endl;
	double x=1;
	double ans;
	cos_a<double> c1(0,10);
	ans=c1(x);
	cout<<ans<<endl;

	//cout<<_optt->EstrinPol(arreglo,num,18)<<endl;






	int numTests = 10000;

		auto start = chrono::high_resolution_clock::now();

		for(int i = 0; i < numTests; i++){
			ans=c1(x);
		}

		auto end = chrono::high_resolution_clock::now();
		auto ms = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
		cout<< "Elapsed Time: " << static_cast<double>(ms)/numTests << "ns"<<endl;
		cout<<ans<<endl;
		/*

		auto start2 = chrono::high_resolution_clock::now();

		for(int i = 0; i < numTests; i++){
			_reff->inPow(num,pp);
		}
		auto end2 = chrono::high_resolution_clock::now();
		auto ms2 = chrono::duration_cast<chrono::nanoseconds>(end2-start2).count();
		cout<< "Elapsed Time: " << static_cast<double>(ms2)/numTests << "ns"<<endl;
*/


































	//anpi::cos_a<double> cosa(3,2);

	//cout<<cosa(4.2)<<endl;

	//__m256d result;



	//ref *re = new ref();


	//double pol[] = {0,1,-0.5,0.33333333333,-0.25};
	//double pol[] = {-0.25,0.333333333,-0.5,1.0,0.0};
	//double pol[] = {-2.0,3,-1};
	//double pol1[] = {-1.0,3,-2};
	//int size = sizeof(pol)/sizeof(pol[1]);

	//cout<< sizeof(pol[0])<<endl;

	//cout<<re->HornerPol(pol,2,size)<<endl;


	//double ans = re->EstrinPol(pol,2.0,size);
	//cout<<ans<<endl;


	//testFunction(funcion de referencia, funcion, x,cantidad)




	return 0;
}
