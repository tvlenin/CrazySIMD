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

	int cont = 0;
	int cont1 = 0;
	int cont2 = 0;
	double result = 0.0;

public:
	opt(){};
	virtual ~opt(){};

	T EstrinPol(T* coePol, T x0,int size){
		//cout<<(size/4)+1<<"\n";
		__m256d impar[(size/4)+1];
		__m256d par[(size/4)+1];
		__m256d xValue = {x0,x0,x0,x0};
		__m256d powP[2];
		powP[0][0] = pow(x0,0);
		powP[0][1] = pow(x0,2);
		powP[0][2] = pow(x0,4);
		powP[0][3] = pow(x0,6);
		powP[1][0] = pow(x0,8);
		powP[1][1] = pow(x0,10);
		powP[1][2] = pow(x0,12);
		powP[1][3] = pow(x0,14);
		//powP[2][0] = pow(x0,16);
		//powP[2][1] = pow(x0,18);
		//powP[2][2] = pow(x0,20);
		//powP[2][3] = pow(x0,22);
		//powP[3][0] = pow(x0,24);
		//powP[3][1] = pow(x0,26);
		//powP[3][2] = pow(x0,28);
		//powP[3][3] = pow(x0,30);
		cont =0;
		for (int i = 0; i < size; i++){
			if ((i+1)%8 == 0){cont++;cont1 += 4;cont2 += 4;}
			if (i%2==0){par[cont][i-cont1] = coePol[i];cont1++;}
			if (i%2!=0){impar[cont][i-1-cont2] = coePol[i]*x0;cont2++;}//OPtimizar el *x0
		}
		for (int k = 0; k < (size/4)+1; k++){//sumar impar con par y guarda en impar
			//impar[k] = _mm256_mul_pd(impar[k],xValue);
			par[k] = _mm256_add_pd(impar[k],par[k]);
			par[k] = _mm256_mul_pd(powP[k],par[k]);

		}
		cont = 0;
		cont1 = 0;

		for (int m = 0; m < (size/4)+1; m++){
			if ((m+1)%4 == 0){cont++;cont1 += 4;}
			result += par[cont][m-cont1];


		}
/*
		for(int j = 0; j < 3; j++){
			cout<<"*********************"<<"\n";
			cout<<par[j][0]<<"\n";
			cout<<par[j][1]<<"\n";
			cout<<par[j][2]<<"\n";
			cout<<par[j][3]<<"\n";
			cout<<"*********************"<<"\n";
			cout<<impar[j][0]<<"\n";
			cout<<impar[j][1]<<"\n";
			cout<<impar[j][2]<<"\n";
			cout<<impar[j][3]<<"\n";
			cout<<"*********************"<<"\n";
		}*/
		return result;
	}






};

} /* namespace anpi */


#endif /* OPT_H_ */
