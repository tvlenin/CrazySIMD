/*
 * opt.h
 *
 *  Created on: Mar 5, 2017
 *      Author: abrahamon
 */

#ifndef OPT_H_
#define OPT_H_


#include <math.h>
#include <iostream>
#include "immintrin.h"

namespace anpi {

template <class T>
class opt {

private:

//	int cont = 0;
//	int cont1 = 0;
//	int cont2 = 0;
	//double result;

public:
	opt(){};
	virtual ~opt(){};

	T EstrinPol(T* coePol, T x0,int size){
		int cont = 0;
		int cont1 = 0;
		int cont2 = 0;
		int contp = 0;
		double result = 1;
		double powV = x0;


		__m256d impar[(size/8)+1];
		__m256d par[(size/8)+1];

		__m256d powP[(size/16)+1];

		for (int p = 0;p < size;p++){
			powV *= x0;
			if ((p+1)%8 == 0){cont++;contp += 4;}
			if (p == 0){powP[0][0] = 0;powV=x0;}
			if (p == 1){powV=x0;}
			if (p%2==0 && p != 0){powP[cont][p-(p/2)-contp] = powV;}
		}

		cont =0;
		for (int i = 0; i < size; i++){
			if ((i+1)%8 == 0){cont++;cont1 += 4;cont2 += 4;}
			else if (i%2==0){par[cont][i-cont1] = coePol[i];cont1++;}
			else if (i%2!=0){impar[cont][i-1-cont2] = coePol[i]*x0;cont2++;}//OPtimizar el *x0
		}
		for (int k = 0; k < (size/4)+4; k++){//sumar impar con par y guarda en impar
			par[k] = _mm256_mul_pd(powP[k],_mm256_add_pd(impar[k],par[k]));

		}
		cont = 0;
		cont1 = 0;

		for (int m = 0; m < (size/4)+4; m++){
			if ((m+1)%4 == 0){cont++;cont1 += 4;}
			result += par[cont][m-cont1];


		}

		return result;
	}






};

} /* namespace anpi */


#endif /* OPT_H_ */
