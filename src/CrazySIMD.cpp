#include "ErrorFramework.h"
#include "DataAccess/Constants.h"

using namespace std;
using namespace anpi;


int main() {
	/**
	 * Graphics required a network, because the communication with
	 * Python Graphics uses sockets. The IP should be changed according
	 * to the network. It can be changed and the configs.xml file.
	 */

	Constants::getInstance();

	ErrorFramework* err = new ErrorFramework(1);
	//cout<<std::setprecision(10)<<endl;

	/**
	 * ###### Test Function using the Reference Function and the
	 * aproximation.
	 * Param1: Reference Function
	 * Param2: Aprox Function
	 * Param3: x to evaluate (type definition required)
	 * Param4: NumTests
	 */
	//anpi::cos<double> cosref(0,36);
	//anpi::cos_a<double> cos(0,36);
	//err->testFunction(cosref,cos,(double)6,1000);

	//anpi::ln<double> lnref(9,80);
	//anpi::ln_a<double> ln(9,80);
	//err->testFunction(lnref,ln,(double)9.11,1000);

	/**
	 * #### Graph Reference Function vs Aproximated Functions ####
	 * Param1 : 0 or 1 (cos or ln)
	 * Param2 : Step (The smaller the better precision)
	 * Param3 : Coeff Quantity (For Opt, Coeff Quantity must be >= 20)
	 * Param4 : Function Center
	 * Param5 : Range init
	 * Param6 : Range end
	 */
	//err->graphRealvsAprox(1,0.1,25,9,(double)9.01,(double)18);
	//err->graphRealvsAprox(0,0.2,40,0,(double)1,(double)6);

	/**
	 * #### Graph Time vs Coeff Terms (n)
	 * Param1 : 0 or 1 (cos or ln)
	 * Param2 : Step (For this graph it must be 0.5 or greater)
	 * Param3 : Function center.
	 * Param4 : Coeff Quantity
	 * Param5 : Number of tests (10000 is a good number)
	 * Param6 : x value where the function will be evaluated
	 */
	//err->graphTime(0,0.5,0,150,1000,(double)3);
	//err->graphTime(1,0.5,1,25,1000,(double)1.3);

	/**
	 * #### Graph Error vs H (in Coeff Terms (n)) ####
	 * Param1 : 0 or 1 (cos or ln)
	 * Param2 : Step (For this graph it must be 0.5 or greater)
	 * Param3 : Function center.
	 * Param4 : Range init
	 * Param5 : Range end
	 */
	//err->graphRelativeError(1,0.5,5,(double)5.01,(double)7);
	//err->graphRelativeError(0,0.1,0,(double)1,(double)2);


	return 0;
}


