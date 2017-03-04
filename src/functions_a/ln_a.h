/*
 * ln_a.h
 *
 *  Created on: Feb 28, 2017
 *      Author: abrahamon
 */

//#ifndef FUNCTIONS_A_LN_A_H_
//#define FUNCTIONS_A_LN_A_H_


namespace anpi {


//Nuestra implementación del factorial
template<typename T>
class ln_a {

private:
	T *_coef; //Coeficientes de la serie de Taylor
	static const unsigned int _alignment=32u; //Alignment in bytes
	T _center;
	T _terms;
	/*
	∗Inicialice los coeficientes de la serie de Taylor centrada en center
	∗ para el número dado de términos.
	*/
	void init(const T center, const unsigned int terms) {
		_center= center;
		_terms= terms;
		unsigned int blocks = ((terms*sizeof(T)+(_alignment-1))/_alignment);	//Redondear hacia arriba
		_coef = static_cast <T*>(aligned_alloc(_alignment,blocks*_alignment));
		ln<T>logn;
		for(unsigned int i =0; i<terms; ++i){
			_coef[i]=logn.diff(center,i)/factorial<T>(i);

		}
	}
public:

	ln_a(){
		_coef=0;
		_center=0;
		_terms=0;
	}
	/* Único constructor obliga a dar centro y número de términos de la aproximación */
	ln_a(const T center ,const unsigned int terms) {
		init (center, terms) ;
	}

	///Destructor debe liberar memoria reservada
	~ln_a(){free(_coef);}


	inline T operator()(const T val)const{
		cout<<"asaaa\n";
		int size=Constants::N;
		T coefficients[size];
		for(int i=0;i<size;i++){
			coefficients[i]=diff_ln_a(_center,i)/factorial_a((T)i);
		}
		ref* reff = new ref();
		cout<<"a[0]"<<coefficients[0]<<"\n";
		cout<<"a[1]"<<coefficients[1]<<"\n";
		cout<<"a[2]"<<coefficients[2]<<"\n";
		cout<<"a[3]"<<coefficients[3]<<"\n";
		cout<<"a[4]"<<coefficients[4]<<"\n";
		cout<<reff->EstrinPol(coefficients,val,Constants::N)<<" \n";
		return reff->EstrinPol(coefficients,val,Constants::N);
	}

	///Evaluación de la n−ésima derivada
	inline T diff( T x , int n ){
		//cout<<"Calculando la "<<n<<"-enésima derivada, en:"<<x<<"\n";
		if(n==0 && x==1)
			return 0;
		T val=(factorial<T>((T)n-1))/pow(x,n);
		if( n%2 != 1)
			val=-val;
		//cout<<"vale: "<<val<<"\n";
		return val;
		//return ((n%1)==0)? -val:val;
	}



};




} /* namespace anpi */

//#endif /* FUNCTIONS_A_LN_A_H_ */
