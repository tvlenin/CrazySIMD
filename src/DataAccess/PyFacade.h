/*
 * PyFacade.h
 *
 *  Created on: Feb 28, 2017
 *      Author: fasm22
 */

#ifndef SRC_PYFACADE_H_
#define SRC_PYFACADE_H_

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "SocketCliente.h"
#include "../DataStructures/xArray.h"

using namespace std;

class PyFacade {
public:
	static PyFacade* _instance;
	SocketCliente* ss;
	static PyFacade* getInstance();

	template<class T>
	bool create2DPlot(xArray<T> pX, xArray<T> pY){
		if(pX.getSize() == pY.getSize()){
			ostringstream pX_List;
			ostringstream pY_List;
			//s << i;

			pX_List << "[";
			pY_List << "[";

			for(int i = 0; i < pX.getSize(); i++){
				pX_List << pX.getItem(i) ;

				if(i+1 != pX.getSize()){
					pX_List << ",";
				}
			}

			for(int i = 0; i < pY.getSize(); i++){
				pY_List << pY.getItem(i) ;

				if(i+1 != pY.getSize()){
					pY_List << ",";
				}
			}

			pY_List << "]";
			pX_List << "]";

			cout << pX_List.str() << endl;
			cout << pY_List.str() << endl;

			string sendData = "plot2D#" + pX_List.str() + "#" + pY_List.str() +"#";

			ss->sendMessage(sendData.c_str());

			return true;
		}
		else{
			cout << "Arrays must have the same size" << endl;
			return false;
		}
	}

private:
	PyFacade();
};

#endif /* SRC_PYFACADE_H_ */
