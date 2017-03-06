#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <typeinfo>


template< typename T >
class xArray {
private:
	int size;
	T* myarray;
public:
	xArray (int s) {
		size = s;
		myarray = new T [size];
	}

	void setArray ( int elem, T val) { myarray[elem] = val; }
	int getSize(){ return size; }
	T getItem(int elem){
		return myarray[elem];
	}

	void getArray () {
		cout << std::setprecision(10) << endl;
		for ( int j = 0; j < size; j++ ) {
			cout << setw( 7 ) << j << setw( 13 ) << myarray[ j ]
			<< " type: " << typeid(myarray[ j ]).name() << endl;
		}
	}

};

#endif
