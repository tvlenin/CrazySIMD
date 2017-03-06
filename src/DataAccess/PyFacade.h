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
	bool create2DPlot(string pGraphic,xArray<T> pX, xArray<T> pY, xArray<T> pYRef){
		if(pX.getSize() == pY.getSize()){
			ostringstream pX_List;
			ostringstream pY_List;
			ostringstream pYRef_List;
			//s << i;

			pX_List << "[";
			pY_List << "[";
			pYRef_List << "[";

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

			for(int i = 0; i < pYRef.getSize(); i++){
				pYRef_List << pYRef.getItem(i) ;

				if(i+1 != pYRef.getSize()){
					pYRef_List << ",";
				}
			}

			pX_List << "]";
			pY_List << "]";
			pYRef_List << "]";

			//cout << pX_List.str() << endl;
			//cout << pY_List.str() << endl;

			string sendData = "RvsA#" + pGraphic + "#" +
								pX_List.str() + "#" +
								pY_List.str() + "#" +
								pYRef_List.str() +"#";

			ss->sendMessage(sendData.c_str());

			return true;
		}
		else{
			cout << "Arrays must have the same size" << endl;
			return false;
		}
	}

	template<class T>
	bool create2DPlotError(string pGraphic,xArray<T> pX, xArray<T> pY1, xArray<T> pY2, xArray<T> pY3,
						   xArray<T> pY4, xArray<T> pY5){
		if(pX.getSize() == pY1.getSize()){
			ostringstream pX_List;
			ostringstream pY1_List;
			ostringstream pY2_List;
			ostringstream pY3_List;
			ostringstream pY4_List;
			ostringstream pY5_List;

			pX_List << "[";
			pY1_List << "[";
			pY2_List << "[";
			pY3_List << "[";
			pY4_List << "[";
			pY5_List << "[";

			for(int i = 0; i < pX.getSize(); i++){
				pX_List << pX.getItem(i) ;

				if(i+1 != pX.getSize()){
					pX_List << ",";
				}
			}

			for(int i = 0; i < pY1.getSize(); i++){
				pY1_List << pY1.getItem(i) ;

				if(i+1 != pY1.getSize()){
					pY1_List << ",";
				}
			}

			for(int i = 0; i < pY2.getSize(); i++){
				pY2_List << pY2.getItem(i) ;

				if(i+1 != pY2.getSize()){
					pY2_List << ",";
				}
			}

			for(int i = 0; i < pY3.getSize(); i++){
				pY3_List << pY3.getItem(i) ;

				if(i+1 != pY3.getSize()){
					pY3_List << ",";
				}
			}

			for(int i = 0; i < pY4.getSize(); i++){
				pY4_List << pY4.getItem(i) ;

				if(i+1 != pY4.getSize()){
					pY4_List << ",";
				}
			}

			for(int i = 0; i < pY5.getSize(); i++){
				pY5_List << pY5.getItem(i) ;

				if(i+1 != pY5.getSize()){
					pY5_List << ",";
				}
			}

			pX_List << "]";
			pY1_List << "]";
			pY2_List << "]";
			pY3_List << "]";
			pY4_List << "]";
			pY5_List << "]";

			//cout << pX_List.str() << endl;
			//cout << pY1_List.str() << endl;

			string sendData = "EvsH#" + pGraphic + "#" +
								pX_List.str() + "#" +
								pY1_List.str() + "#" +
								pY2_List.str() + "#" +
								pY3_List.str() + "#" +
								pY4_List.str() + "#" +
								pY5_List.str() +"#";

			ss->sendMessage(sendData.c_str());

			return true;
		}
		else{
			cout << "Arrays must have the same size" << endl;
			return false;
		}
	}

	template<class T>
	bool create2DPlotTime(string pGraphic,xArray<T> pX, xArray<T> pY){
		if(pX.getSize() == pY.getSize()){
			ostringstream pX_List;
			ostringstream pY_List;

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

			pX_List << "]";
			pY_List << "]";

			//cout << pX_List.str() << endl;
			//cout << pY_List.str() << endl;

			string sendData = "TvsH#" + pGraphic + "#" +
								pX_List.str() + "#" +
								pY_List.str() + "#";

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
