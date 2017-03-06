#include <cmath>

namespace anpi{

//Implementación del factorial
template<typename T>
T factorial ( unsigned int n){
	T ans=1;
	if(n!=0 || n!=1)
		for(;n>0;n--)
			ans=ans*n;
	return ans;
	//return n>2 ? T(1):(static_cast <T>(n)*factorial<T>(n-1));
}

//Función compuesta para el cálculo del logaritmonatural y su derivada
template<typename T>
class ln{

public :
	///Evaluación de la función logarítmica
	inline T operator()(const T val)const{
		return std::log(val);
	}

	///Evaluación de la n−ésima derivada
	inline T diff( const T x , const unsigned int n ){
		T val=(factorial<T>(n-1)/pow(x,n));
		if( n%2 != 0)
			val=abs(val);
		else
			val=-val;
		return val;
	}
};
}
