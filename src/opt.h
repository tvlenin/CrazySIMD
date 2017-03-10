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
#include <typeinfo>
#include "immintrin.h"

namespace anpi {

template <class T>
class opt {

private:



public:
	opt(){};
	virtual ~opt(){};

	T EstrinPol(T* coePol, T x0, int const size1){
		int size = size1;
		int cont = 0;
		int cont1 = 0;
		int cont2 = 0;
		int contp = 0;
		double prueba = 0;
		if (typeid(T).name()== typeid(prueba).name() ){
			double powV = x0;
			__m256d impar[(size/8)+1];
			__m256d par[(size/8)+1];
			__m256d powP[(size/16)+1];
			/*power numbers of x0, that is more efficient than std::pow()
			 *because dont need calculate again the coefficients
			 */
			for (int p = 0;p < size;p++){
				powV *= x0;
				if ((p+1)%8 == 0){cont++;contp += 4;}
				if (p == 0){powP[0][0] = 0;powV=x0;}
				if (p == 1){powV=x0;}
				if (p%2==0 && p != 0){powP[cont][p-(p/2)-contp] = powV;}
			}
			/*
			 * fill a matrix of __m256d with the coefficients
			 * one matrix to the odd coefficients and one to the pair coefficients
			 */
			cont =0;
			for (int i = 0; i < size; i++){
				if ((i+1)%8 == 0){cont++;cont1 += 4;cont2 += 4;}
				if (i%2==0){par[cont][i-cont1] = coePol[i];cont1++;}
				if (i%2!=0){impar[cont][i-1-cont2] = coePol[i]*x0;cont2++;}//More efficient use *X0 and not SIMD
			}
			/*
			 * multiply and add the __m256d Arrays
			 * */
			for (int k = 0; k < (size/4)+4; k++){
				par[k] = _mm256_mul_pd(powP[k],_mm256_add_pd(impar[k],par[k]));
			}
			cont = 0;
			cont1 = 0;
			//Add all the terms
			double result = 1;
			for (int m = 0; m < (size/4); m++){
				if ((m+1)%4 == 0 ){cont++;cont1 += 4;}
				if(par[cont][m-cont1]!=par[cont][m-cont1]){break;}
				result += par[cont][m-cont1];
			}
			//cout<<result<<"\n";
			return result;
		}else{
			//cout<<"entra"<<endl;
			double powV = x0;
					__m256 impar[(size/16)+1];
					__m256 par[(size/16)+1];
					__m256 powP[(size/32)+1];
					/*power numbers of x0, that is more efficient than std::pow()
					 *because dont need calculate again the coefficients
					 */
					for (int p = 0;p < size;p++){
						powV *= x0;
						if ((p+1)%16 == 0){cont++;contp += 8;}
						if (p == 0){powP[0][0] = 0;powV=x0;}
						if (p == 1){powV=x0;}
						if (p%2==0 && p != 0){powP[cont][p-(p/2)-contp] = powV;}
					}
					/*
					 * fill a matrix of __m256d with the coefficients
					 * one matrix to the odd coefficients and one to the pair coefficients
					 */
					cont =0;
					for (int i = 0; i < size; i++){
						if ((i+1)%16 == 0){cont++;cont1 += 8;cont2 += 8;}
						if (i%2==0){par[cont][i-cont1] = coePol[i];cont1++;}
						if (i%2!=0){impar[cont][i-1-cont2] = coePol[i]*x0;cont2++;}//More efficient use *X0 and not SIMD
					}
					/*
					 * multiply and add the __m256d Arrays
					 * */
					for (int k = 0; k < (size/8)+8; k++){
						par[k] = _mm256_mul_ps(powP[k],_mm256_add_ps(impar[k],par[k]));
					}
					cont = 0;
					cont1 = 0;
					//Add all the terms
					double result = 1;
					for (int m = 0; m < (size/8); m++){
						if ((m+1)%8 == 0 ){cont++;cont1 += 8;}
						if(par[cont][m-cont1]!=par[cont][m-cont1]){break;}
						result += par[cont][m-cont1];
					}
					//cout<<result<<"\n";
					return result;
		}
	}






};

} /* namespace anpi */


#endif /* OPT_H_ */
